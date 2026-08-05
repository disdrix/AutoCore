// =============================================================================
// FUN_0068a1d0  — twin of StdVector_InsertN_Elem28
// -----------------------------------------------------------------------------
// Address:   0x0068a1d0  (autoassault.exe, image base 0x400000)
// Body:      0x0068a1d0 – 0x0068a49a exclusive (714 B / 0x2CA); pad CC
// Wave:      W34-S OWN-ONLY dual 2026-07-29
// Canonical: StdVector_InsertN_Elem28
// =============================================================================

#include <cstdint>

struct Elem28 {
  uint32_t w[7];
};

struct VectorElem28 {
  void* _unused0;
  Elem28* begin;
  Elem28* end;
  Elem28* capEnd;
};

static constexpr uint32_t kElemSize = 0x1c;
static constexpr uint32_t kMaxElems = 0x09249249u;

extern "C" void FUN_00686070();
extern "C" uint32_t __thiscall FUN_00469c50(VectorElem28* vec);
extern "C" void* operator_new(uint32_t);
extern "C" void operator_delete(void*);
extern "C" Elem28* FUN_00687d10(Elem28* first, Elem28* last, Elem28* dest, ...);
extern "C" void FUN_00688550(Elem28* dest, uint32_t count, const Elem28* value, ...);
extern "C" void FUN_0068a1a0(Elem28* dest, uint32_t count, const Elem28* value, ...);
extern "C" void FUN_00687ce0(Elem28* first, Elem28* last, Elem28* destEnd);
extern "C" void FUN_006860f0(Elem28* first, Elem28* last, const Elem28* value);

// ECX=vector*; stack where*, count, value*; RET 0x0C; void.
extern "C" void __thiscall FUN_0068a1d0(
    VectorElem28* vec,
    Elem28* where,
    uint32_t count,
    const Elem28* value)
{
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
    FUN_00686070();
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
    Elem28* hole = FUN_00687d10(vec->begin, where, neu, vec, where);
    FUN_00688550(hole, count, &local, vec, where);
    FUN_00687d10(where, vec->end,
                 reinterpret_cast<Elem28*>(
                     reinterpret_cast<char*>(hole) + count * kElemSize),
                 vec, where);

    if (vec->begin != nullptr) {
      operator_delete(vec->begin);
    }
    vec->capEnd = reinterpret_cast<Elem28*>(
        reinterpret_cast<char*>(neu) + newCap * kElemSize);
    vec->end = reinterpret_cast<Elem28*>(
        reinterpret_cast<char*>(neu) + (size + count) * kElemSize);
    vec->begin = neu;
    return;
  }

  // In-place hole / mid arms — see raw + StdVector_InsertN_Elem28.cpp
  (void)where;
  (void)local;
}
