// =============================================================================
// FUN_00469f10  (= StdVector_DwordEraseRange_EbxVec_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00469f10
// Address:   0x00469f10  (autoassault.exe, image base 0x400000)
// System:    STL dword vector erase-range
// Generated: 2026-08-04 W38-N (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite. Bit-for-bit: DEFERRED.
// Named clean: StdVector_DwordEraseRange_EbxVec_Inferred.cpp
// =============================================================================

#include <cstdint>

// Ghidra-facing twin of the named clean.
// Real ABI: EBX=vec*, EAX=outIt*, stack first+last, RET 8.
// See StdVector_DwordEraseRange_EbxVec_Inferred.cpp for plate + algorithm.

extern "C" void FUN_00469f10(uint32_t* first, uint32_t* last)
{
  // Register formals EBX/EAX are caller-bound (see sole caller FUN_0044a380).
  // Decompiler shows unaff_EBX / in_EAX; bytes seal them.
  (void)first;
  (void)last;

  // CF (sealed):
  // if (first != last) {
  //   end = *(EBX+8);
  //   dest = first;
  //   for (; last != end; last++, dest++) *dest = *last;
  //   *(EBX+8) = dest;
  // }
  // *EAX = first;
  // RET 8
}
