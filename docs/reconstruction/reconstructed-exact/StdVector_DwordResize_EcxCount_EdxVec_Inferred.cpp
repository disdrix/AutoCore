// =============================================================================
// StdVector_DwordResize_EcxCount_EdxVec_Inferred  (Ghidra: FUN_00456780)
// -----------------------------------------------------------------------------
// Stable ID: aa_00456780
// Address:   0x00456780  (autoassault.exe, image base 0x400000)
// System:    STL / container utility (pool freelists, physics vectors, multi-host)
// Generated: 2026-08-04 W38-H dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   MSVC-style vector<uint32_t>::resize(n, value) with non-standard register ABI:
//     EDX = vec*
//     ECX = newCount
//     [esp+4] = fill dword
//     RET 4
//
//   Twin family (do not merge):
//     FUN_0044a380 — ECX=vec, EAX=n, fill, RET 4 (W37-Z)
//     FUN_004367f0 — stack n + fill, RET 8
//
// LAYOUT (vec control block):
//   +0x04 begin (uint32_t*)
//   +0x08 end
//   +0x0C capacity end (grow callee only)
//
// CALLEES (unowned here):
//   FUN_00456960 — InsertN / grow-realloc at end (fill via EAX=&fill)
//   FUN_00456660 — erase [new_end, end); memmove-publish; EBX scratch
//
// BODY: 0x00456780–0x004567f5 exclusive (117 B). Dual: accept.
// =============================================================================

#include <cstdint>

struct VecDwordControl {
  uint32_t reserved0;  // +0x00 (unused in this unit)
  uint32_t* begin;     // +0x04
  uint32_t* end;       // +0x08
  // uint32_t* capacity_end; // +0x0C — grow callee
};

// Unowned callees — declarations only (register conventions not fully modeled).
extern "C" void FUN_00456960(uint32_t insert_count /*ECX*/,
                             VecDwordControl* vec /*EDX*/,
                             uint32_t* where_end /*stack*/,
                             const uint32_t* fill /*EAX*/);
extern "C" void FUN_00456660(VecDwordControl* vec,
                             uint32_t* first,
                             uint32_t* last);  // EBX = out scratch

// Documentary signature — real ABI is register-heavy (see plate).
// Ports must: EDX=vec, ECX=n, push fill, call, expect RET 4.
extern "C" void StdVector_DwordResize_EcxCount_EdxVec_Inferred(
    VecDwordControl* vec,
    uint32_t new_count,
    uint32_t fill)
{
  uint32_t* begin = vec->begin;
  uint32_t size = 0;
  if (begin != nullptr) {
    size = static_cast<uint32_t>(
        (reinterpret_cast<uint8_t*>(vec->end) -
         reinterpret_cast<uint8_t*>(begin)) >> 2);
  }

  if (size < new_count) {
    // Bytes: empty and non-empty entries both pass (n - size) and &fill.
    FUN_00456960(new_count - size, vec, vec->end, &fill);
    return;
  }

  if (begin != nullptr && new_count < size) {
    uint32_t* new_end = begin + new_count;
    FUN_00456660(vec, new_end, vec->end);
  }
}
