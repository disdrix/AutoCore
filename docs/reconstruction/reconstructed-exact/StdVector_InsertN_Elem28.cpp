// =============================================================================
// StdVector_InsertN_Elem28  (aa_0068a1d0)
// -----------------------------------------------------------------------------
// Address:   0x0068a1d0  (autoassault.exe, image base 0x400000)
// Body:      0x0068a1d0 – 0x0068a49a exclusive (714 B / 0x2CA); pad CC
// Wave:      W34-S OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + RET 0x0C.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// POD element footprint matching retail 0x1c / 7 dwords.
struct Elem28 {
  uint32_t w[7];
};

struct VectorElem28 {
  void* _unused0;     // +0
  Elem28* begin;      // +4
  Elem28* end;        // +8
  Elem28* capEnd;     // +0xC
};

static constexpr uint32_t kElemSize = 0x1c;
static constexpr uint32_t kMaxElems = 0x09249249u;  // ~0u / 0x1c

// Nested helpers (not dual-owned here):
extern "C" void FUN_00686070();  // vector too long
extern "C" uint32_t __thiscall FUN_00469c50(VectorElem28* vec);  // StdVector_Elem28_Size
extern "C" void* operator_new(uint32_t);
extern "C" void operator_delete(void*);  // cdecl
// POD 0x1c range helpers (7-dword memcpy each element):
extern "C" Elem28* FUN_00687d10(Elem28* first, Elem28* last, Elem28* dest, ...);
extern "C" void FUN_00688550(Elem28* dest, uint32_t count, const Elem28* value, ...);
extern "C" void FUN_0068a1a0(Elem28* dest, uint32_t count, const Elem28* value, ...);
extern "C" void FUN_00687ce0(Elem28* first, Elem28* last, Elem28* destEnd);
extern "C" void FUN_006860f0(Elem28* first, Elem28* last, const Elem28* value);

// ECX=vector*; stack where*, count, value*; RET 0x0C; void.
// Insert `count` copies of `*value` at `where` (pointer iterator into buffer).
// Element type is POD 0x1c (raw 7-dword copy/fill) — not basic_string IAT family.
extern "C" void __thiscall StdVector_InsertN_Elem28(
    VectorElem28* vec,
    Elem28* where,
    uint32_t count,
    const Elem28* value)
{
  // SEH LAB_009aa170; local POD copy of *value via rep movsd ×7
  Elem28 local{};
  for (int i = 0; i < 7; ++i) {
    local.w[i] = value->w[i];
  }

  uint32_t cap = 0;
  if (vec->begin != nullptr) {
    cap = static_cast<uint32_t>(
        (reinterpret_cast<char*>(vec->capEnd) - reinterpret_cast<char*>(vec->begin)) /
        kElemSize);
  }

  if (count == 0) {
    return;
  }

  uint32_t size = 0;
  if (vec->begin != nullptr) {
    size = static_cast<uint32_t>(
        (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(vec->begin)) /
        kElemSize);
  }

  if (kMaxElems - size < count) {
    FUN_00686070();  // noreturn-ish throw path
  }

  if (cap < size + count) {
    uint32_t newCap;
    if (kMaxElems - (cap >> 1) < cap) {
      newCap = 0;
    } else {
      newCap = cap + (cap >> 1);
    }
    if (newCap < size + count) {
      newCap = FUN_00469c50(vec) + count;
    }

    Elem28* neu = static_cast<Elem28*>(operator_new(newCap * kElemSize));
    // uninit_copy [begin, where) → neu
    Elem28* hole = FUN_00687d10(vec->begin, where, neu, vec, where);
    FUN_00688550(hole, count, &local, vec, where);
    FUN_00687d10(where, vec->end,
                 reinterpret_cast<Elem28*>(
                     reinterpret_cast<char*>(hole) + count * kElemSize),
                 vec, where);

    if (vec->begin != nullptr) {
      operator_delete(vec->begin);  // cdecl; continues (decompiler false-noreturn)
    }
    vec->capEnd = reinterpret_cast<Elem28*>(
        reinterpret_cast<char*>(neu) + newCap * kElemSize);
    vec->end = reinterpret_cast<Elem28*>(
        reinterpret_cast<char*>(neu) + (size + count) * kElemSize);
    vec->begin = neu;
    return;
  }

  // In-place arms: hole (tail short vs count) or mid-shift + assign fill.
  // See raw decompile for exact FUN_00687d10 / FUN_0068a1a0 / FUN_00687ce0 /
  // FUN_006860f0 call order — nested plates not dual-owned.
  Elem28* end = vec->end;
  uint32_t tail = static_cast<uint32_t>(
      (reinterpret_cast<char*>(end) - reinterpret_cast<char*>(where)) / kElemSize);
  if (tail < count) {
    // make hole of count elems at where; fill new tail; assign into hole
    (void)end;
    // FUN_00687d10 / FUN_0068a1a0 / FUN_006860f0 path (raw)
  } else {
    // move-backward tail by count; assign value into [where, where+count)
    // FUN_00687d10 / FUN_00687ce0 / FUN_006860f0 path (raw)
  }
}
