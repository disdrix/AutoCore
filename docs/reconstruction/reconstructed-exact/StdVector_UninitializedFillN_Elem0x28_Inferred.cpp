// =============================================================================
// StdVector_UninitializedFillN_Elem0x28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00406e50
// Address:   0x00406e50  (autoassault.exe, image base 0x400000)
// Body:      0x00406e50–0x00406e6c (28 B / 0x1c); ret 4; pad CC
// System:    util / container (std::vector elem stride 0x28)
// Generated: 2026-08-04 WQ9G-H dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_00406e50
// =============================================================================
//
// PURPOSE:
//   Uninitialized fill-N for 0x28-byte POD elements:
//     1. ConstructN(dst, count, template) via FUN_00409d40
//     2. return dst + count * 0x28
//
// ABI (customcc — sealed from bytes C2 04 00 + parent FUN_00408050):
//   EDI        = void* dst  (fill start)
//   ESI        = int count
//   stack arg0 = const void* value template (0x28 POD)
//   ECX        = may be live; reloaded from stack formal into ECX for ConstructN
//   return     = EAX = dst + count*0x28; ret 4
//
// CALLEE:
//   FUN_00409d40 — ConstructN: loop count times, PodCopy 10 dwords (0x28)
//                  via FUN_00409f30; advances dest by 0x28 each iter.
//                  ECX=value*, stack dest*, count (caller may push phantoms).
//
// PARENT:
//   FUN_00408050 InsertN — two call sites (realloc hole fill + in-place fill).
//
// TWINS (CF shape):
//   UiToast_UninitializedFillN_0x98 @ 0x00404130 (stride 0x98)
//   CombatFloater_UninitializedFillN_0x38 @ 0x00402ea0
// =============================================================================

#include <cstdint>

// Construct N copies of 0x28-byte template at dest (undualed residual).
extern "C" void FUN_00409d40(
    /*ECX*/ const void* value,
    /*stack*/ void* dest,
    /*stack*/ int count);

extern "C" void* StdVector_UninitializedFillN_Elem0x28_Inferred(
    void* dst /*EDI*/,
    int count /*ESI*/,
    const void* value /*stack*/)
{
  // Bytes: push value; push ecx; mov ecx,value; push count; push dst;
  //        call FUN_00409d40; add esp,0x10
  FUN_00409d40(value, dst, count);
  return reinterpret_cast<uint8_t*>(dst) + static_cast<size_t>(count) * 0x28u;
}
