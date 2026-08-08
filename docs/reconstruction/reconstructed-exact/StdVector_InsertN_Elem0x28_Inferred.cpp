// =============================================================================
// StdVector_InsertN_Elem0x28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00408050
// Address:   0x00408050  (autoassault.exe, image base 0x400000)
// Body:      0x00408050–0x004082ed exclusive (669 B / 0x29D); ret 0x8; pad CC
// System:    util / container (std::vector insert-n, POD stride 0x28)
// Generated: 2026-08-04 WQ9H-A dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_00408050
// =============================================================================
//
// PURPOSE:
//   Insert `count` copies of a 0x28-byte POD `*value` at iterator `where` in an
//   MSVC-style vector (begin@+4 / end@+8 / capEnd@+0xC). Grows 1.5x when
//   capacity is insufficient; otherwise relocates in-place.
//
// ABI (fastcall-ish — sealed from ret C2 08 00 + parent FUN_00406de0):
//   ECX        = VecPod28* this   (mov ebx,ecx at entry)
//   EDX        = const Pod28* value  (10 dwords snapped to stack)
//   stack arg0 = Pod28* where
//   stack arg1 = uint count
//   return     = void; ret 0x8
//
// CALLEES (roles):
//   FUN_00409ae0                — uninitialized_copy stride 0x28
//   FUN_00406e50                — Ufill N (WQ9G-H sealed)
//   FUN_0040a520                — relocate / open hole
//   FUN_00409b00 / FUN_00409b20 — assign-fill / mid-insert helpers
//   FUN_00437d80                — size() re-read on grow floor
//   FUN_00418130                — length_error
//   operator_new / operator_delete
//
// PARENT:
//   FUN_00406de0 InsertOne+rebind forces count=1 then rebinds out-iterator.
//   FUN_00406220 push_back slow path → InsertOne.
//
// TWINS:
//   0x004082f0 InsertN elem 0xC (thiscall ret 0xC); 0x004073a0 InsertN dword.
// =============================================================================

#include <cstdint>
#include <cstring>
#include <new>

struct Pod28 {
  uint32_t d[10]; // 0x28 bytes
};

struct VecPod28 {
  void *_unused0;  // +0
  Pod28 *begin;    // +4
  Pod28 *end;      // +8
  Pod28 *capEnd;   // +0xC
};

// Residuals — roles sealed; signatures simplified for readability.
extern "C" void FUN_00418130(); // length_error / noreturn-ish
extern "C" int  FUN_00437d80(); // size() re-read (ECX=vec implied in binary)
extern "C" Pod28 *FUN_00409ae0(Pod28 *first, Pod28 *last /*, dest via regs */);
extern "C" Pod28 *FUN_00406e50(/*EDI*/ Pod28 *dest, /*ESI*/ int count,
                               /*stack*/ const Pod28 *value);
extern "C" Pod28 *FUN_0040a520(Pod28 *first, Pod28 *last /*, vec, scratch */);
extern "C" void FUN_00409b20();
extern "C" void FUN_00409b00();

static constexpr uint32_t kMaxElems = 0x06666666u; // ~INT_MAX/0x28

extern "C" void StdVector_InsertN_Elem0x28_Inferred(
    VecPod28 *self /*ECX*/,
    const Pod28 *value /*EDX*/,
    Pod28 *where,
    uint32_t count)
{
  // Snap template (10 dwords) so value* may alias into the buffer during grow.
  Pod28 tmp;
  std::memcpy(&tmp, value, sizeof(Pod28));

  Pod28 *begin = self->begin;
  uint32_t capacity = 0;
  if (begin != nullptr) {
    capacity = static_cast<uint32_t>(
        (reinterpret_cast<char *>(self->capEnd) - reinterpret_cast<char *>(begin)) /
        0x28);
  }
  if (count == 0) {
    return;
  }

  uint32_t size = 0;
  if (begin != nullptr) {
    size = static_cast<uint32_t>(
        (reinterpret_cast<char *>(self->end) - reinterpret_cast<char *>(begin)) /
        0x28);
  }
  if (kMaxElems - size < count) {
    FUN_00418130();
  }

  if (capacity < size + count) {
    // 1.5x growth, then exact size+count floor.
    uint32_t newCap = capacity;
    if (kMaxElems - (capacity >> 1) < capacity) {
      newCap = 0;
    } else {
      newCap = capacity + (capacity >> 1);
    }
    uint32_t need = size + count;
    if (newCap < need) {
      // FUN_00437d80 re-reads size; + count
      newCap = static_cast<uint32_t>(FUN_00437d80()) + count;
    }

    uint32_t bytes = newCap * 0x28;
    void *raw = operator new(bytes);
    Pod28 *fresh = static_cast<Pod28 *>(raw);

    // prefix: begin..where → fresh
    // hole: Ufill count copies of tmp
    // suffix: where..end → after hole
    Pod28 *mid = FUN_00409ae0(begin, where);
    (void)mid;
    // binary: FUN_00406e50 with dest after prefix, count, &tmp
    FUN_00406e50(/*dest*/ nullptr, static_cast<int>(count), &tmp);
    FUN_00409ae0(where, self->end);

    if (begin != nullptr) {
      // Decompiler "does not return" is a false warning — triad rebind follows.
      operator delete(begin);
    }
    self->capEnd = reinterpret_cast<Pod28 *>(
        reinterpret_cast<char *>(fresh) + bytes);
    self->end = fresh + (size + count);
    self->begin = fresh;
    return; // ret 0x8
  }

  // In-place: near-end vs mid-insert (helpers FUN_0040a520 / 00409b20 / 00409b00)
  const uint32_t tailElems = static_cast<uint32_t>(
      (reinterpret_cast<char *>(self->end) - reinterpret_cast<char *>(where)) /
      0x28);
  if (tailElems < count) {
    const int holeBytes = static_cast<int>(count * 0x28);
    FUN_0040a520(where, reinterpret_cast<Pod28 *>(
                            reinterpret_cast<char *>(where) + holeBytes));
    FUN_00406e50(/*dest*/ nullptr, static_cast<int>(count), &tmp);
    self->end = reinterpret_cast<Pod28 *>(
        reinterpret_cast<char *>(self->end) + holeBytes);
  } else {
    Pod28 *oldEnd = self->end;
    Pod28 *src = reinterpret_cast<Pod28 *>(
        reinterpret_cast<char *>(oldEnd) - static_cast<int>(count * 0x28));
    self->end = FUN_0040a520(src, oldEnd);
    FUN_00409b20();
  }
  FUN_00409b00(); // shared plant / assign-fill of hole with tmp
  // ret 0x8
}
