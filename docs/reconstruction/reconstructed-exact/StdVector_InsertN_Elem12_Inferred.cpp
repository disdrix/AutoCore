// =============================================================================
// StdVector_InsertN_Elem12_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004082f0
// Address:   0x004082f0  (autoassault.exe, image base 0x400000)
// Body:      0x004082f0–0x00408587 (663 B / 0x297); ret 0xC; pad CC
// System:    util / container (std::vector insert-n, POD stride 0xC)
// Generated: 2026-08-04 WQ9H-B dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_004082f0
// =============================================================================
//
// PURPOSE:
//   Insert `count` copies of a 12-byte POD `*value` at iterator `where` in an
//   MSVC-style vector (begin@+4 / end@+8 / capEnd@+0xC). Grows 1.5x when
//   capacity is insufficient; otherwise relocates in-place.
//
// ABI (thiscall — sealed from ret C2 0C 00 + parent FUN_00406e70):
//   ECX        = VecPod12* this
//   stack arg0 = Pod12* where
//   stack arg1 = uint count
//   stack arg2 = const Pod12* value
//   return     = void; ret 0xC
//
// CALLEES (roles):
//   FUN_00409b40 / FUN_0040a590 — uninitialized_copy stride 0xC
//   FUN_00406ee0                — Ufill N (WQ9G-I sealed)
//   FUN_00480fb0                — copy_backward 3-dword elems
//   FUN_0042ac90                — assign-fill hole with template
//   FUN_00480c80                — size()
//   FUN_00418130                — length_error
//   operator_new / operator_delete
//
// PARENT:
//   FUN_00406e70 InsertOne+rebind forces count=1 then rebinds out-iterator.
//
// TWINS:
//   0x00408050 InsertN elem 0x28; 0x004073a0 InsertN dword.
// =============================================================================

#include <cstdint>
#include <cstdlib>
#include <new>

struct Pod12 {
  uint32_t d0, d1, d2;
};

struct VecPod12 {
  void* _unused0;   // +0
  Pod12* begin;     // +4
  Pod12* end;       // +8
  Pod12* capEnd;    // +0xC
};

// Residuals — roles sealed; signatures simplified for readability.
extern "C" void FUN_00418130(); // length_error / noreturn-ish
extern "C" int  FUN_00480c80(/*ECX*/ VecPod12* vec); // size()
extern "C" Pod12* FUN_00409b40(Pod12* first, Pod12* last /*, dest via regs */);
extern "C" Pod12* FUN_00406ee0(/*EDI*/ Pod12* dest, /*ESI*/ int count,
                               /*stack*/ const Pod12* value);
extern "C" Pod12* FUN_0040a590(Pod12* first, Pod12* last /*, dest */);
extern "C" void FUN_00480fb0(/* copy_backward 3-dword */);
extern "C" void FUN_0042ac90(/* assign-fill with template */);

static constexpr uint32_t kMaxElems = 0x15555555u; // ~INT_MAX/12

extern "C" void StdVector_InsertN_Elem12_Inferred(
    VecPod12* self /*ECX*/,
    Pod12* where,
    uint32_t count,
    const Pod12* value)
{
  // Snap template (3 dwords) so value* may alias into the buffer during grow.
  Pod12 tmp = *value;

  Pod12* begin = self->begin;
  uint32_t capacity = 0;
  if (begin != nullptr) {
    capacity = static_cast<uint32_t>(
        (reinterpret_cast<char*>(self->capEnd) - reinterpret_cast<char*>(begin)) / 12);
  }
  if (count == 0) {
    return;
  }

  uint32_t size = 0;
  if (begin != nullptr) {
    size = static_cast<uint32_t>(
        (reinterpret_cast<char*>(self->end) - reinterpret_cast<char*>(begin)) / 12);
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
      // FUN_00480c80(self) re-reads size; + count
      newCap = static_cast<uint32_t>(FUN_00480c80(self)) + count;
    }

    uint32_t bytes = newCap * 12;
    void* raw = operator new(bytes);
    Pod12* fresh = static_cast<Pod12*>(raw);

    // prefix: begin..where → fresh
    // hole: Ufill count copies of tmp
    // suffix: where..end → after hole
    // (register choreography matches FUN_00409b40 / FUN_00406ee0 call sites)
    Pod12* mid = FUN_00409b40(begin, where);
    (void)mid;
    // Ufill at mid with tmp (EDI/ESI customcc — modeled as call)
    FUN_00406ee0(reinterpret_cast<Pod12*>(
                     reinterpret_cast<char*>(fresh) +
                     (reinterpret_cast<char*>(where) - reinterpret_cast<char*>(begin))),
                 static_cast<int>(count), &tmp);
    FUN_00409b40(where, self->end);

    if (begin != nullptr) {
      operator delete(begin);
    }
    self->capEnd = reinterpret_cast<Pod12*>(static_cast<char*>(raw) + bytes);
    self->end = reinterpret_cast<Pod12*>(
        reinterpret_cast<char*>(fresh) + (size + count) * 12);
    self->begin = fresh;
    return;
  }

  // In-place capacity path (two sub-cases by tail length vs count).
  // near-end: uninit_copy where..end to where+count; Ufill; end += count*12
  // far:      uninit_copy end-count..end to end; copy_backward; assign-fill
  // Exact helper argument packing follows raw decompile order:
  //   FUN_0040a590 / FUN_00406ee0 / FUN_00480fb0 / FUN_0042ac90
  Pod12* end = self->end;
  uint32_t tail = static_cast<uint32_t>(
      (reinterpret_cast<char*>(end) - reinterpret_cast<char*>(where)) / 12);
  if (tail < count) {
    FUN_0040a590(where, where + count /*, dest = where+count via parent */);
    FUN_00406ee0(end, static_cast<int>(count - tail), &tmp);
    self->end = reinterpret_cast<Pod12*>(
        reinterpret_cast<char*>(self->end) + count * 12);
  } else {
    Pod12* split = end - count;
    self->end = FUN_0040a590(split, end /*, dest = end */);
    FUN_00480fb0(); // copy_backward mid segment
  }
  FUN_0042ac90(); // assign-fill insertion window with tmp
  // ret 0xC
}
