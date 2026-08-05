// =============================================================================
// StdVector_DwordResize_EaxCount_Inferred  (Ghidra: FUN_0044a380)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044a380
// Address:   0x0044a380  (autoassault.exe, image base 0x400000)
// System:    STL / container utility (NestedHash + multi hash-map rehash)
// Generated: 2026-08-04 W37-Z dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   MSVC-style vector<uint32_t>::resize(n, value) with non-standard register ABI:
//     ECX = vec*
//     EAX = newCount          (NOT a stack formal; decompiler "in_EAX")
//     [esp+4] = fill dword
//     RET 4
//   Twin of FUN_004367f0 (stack newCount + fill, RET 8) — different call form.
//
// LAYOUT (vec control block):
//   +0x04 begin (uint32_t*)
//   +0x08 end
//   +0x0C capacity end (grow callee only)
//
// CALLEES (unowned here):
//   FUN_00463e30 — InsertN / grow-realloc at end
//   FUN_00469f10 — erase [new_end, end); EBX=vec
//
// BODY: 0x0044a380–0x0044a3e9 exclusive (105 B). Dual: accept.
// =============================================================================

#include <cstdint>

struct VecDwordControl {
  uint32_t reserved0;  // +0x00 (unused in this unit)
  uint32_t* begin;     // +0x04
  uint32_t* end;       // +0x08
  // uint32_t* capacity_end; // +0x0C — grow callee
};

// Unowned callees — declarations only.
extern "C" void __thiscall FUN_00463e30(VecDwordControl* vec,
                                        uint32_t* where_end,
                                        uint32_t count,
                                        const uint32_t* fill);
extern "C" void FUN_00469f10(uint32_t* first, uint32_t* last);  // EBX=vec

// Documentary signature — real ABI is register-heavy (see plate).
// Ports must: ECX=vec, EAX=n, push fill, call, expect RET 4.
extern "C" void StdVector_DwordResize_EaxCount_Inferred(
    VecDwordControl* vec,
    uint32_t new_count,
    uint32_t fill)
{
  uint32_t* begin = vec->begin;
  uint32_t size = 0;
  if (begin != nullptr) {
    // Bytes: (end - begin) SAR 2
    size = static_cast<uint32_t>(
        (reinterpret_cast<uint8_t*>(vec->end) -
         reinterpret_cast<uint8_t*>(begin)) >> 2);
  }

  if (size < new_count) {
    FUN_00463e30(vec, vec->end, new_count - size, &fill);
    return;
  }

  if (begin != nullptr && new_count < size) {
    // Bytes: MOV EBX, ECX; LEA EAX,[begin+n*4]; call erase
    uint32_t* new_end = begin + new_count;
    FUN_00469f10(new_end, vec->end);
  }
}
