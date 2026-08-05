// =============================================================================
// StdVector_UninitializedFillN_Elem28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00467320
// Address:   0x00467320–0x0046736e  (autoassault.exe, image base 0x400000)
// System:    containers / std::vector uninitialized_fill_n (POD stride 0x1c)
// Generated: dual A/B seal 2026-07-29 (W35-T); Ghidra FUN_00467320
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Trivial uninitialized_fill_n for POD T size 0x1c (7 dwords).
 * - ABI: ECX=dest, EDX=value*, EAX=count; bare RET; no stack args.
 * - Early-out when count==0 (TEST/JBE after MOV ESI,EAX).
 * - Null dest skips stores but still advances (compiler artifact).
 * - Leaf; sole caller FUN_00466ea0 (StdVector_InsertN_Elem28_CountEcx_Inferred).
 * - Sibling copy: StdVector_UninitializedCopy_Elem28_Inferred @ 0x004673b0.
 * - Name is structural Inferred; product T English open.
 */

#include <cstdint>

struct Pod28 {
  uint32_t d0, d1, d2, d3, d4, d5, d6;
};

// Retail: ECX=dest, EDX=value*, EAX=count; bare RET.
void StdVector_UninitializedFillN_Elem28_Inferred(
    Pod28* dest /*ECX*/,
    const Pod28* value /*EDX*/,
    int count /*EAX*/)
{
  if (count == 0) {
    return;
  }
  do {
    if (dest != nullptr) {
      dest->d0 = value->d0;
      dest->d1 = value->d1;
      dest->d2 = value->d2;
      dest->d3 = value->d3;
      dest->d4 = value->d4;
      dest->d5 = value->d5;
      dest->d6 = value->d6;
    }
    ++dest;
    --count;
  } while (count != 0);
}
