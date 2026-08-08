// =============================================================================
// FUN_00441720  — twin of StdTree_EraseAll_Shell10_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00441720
// Address:   0x00441720 (autoassault.exe, image base 0x400000)
// See:       StdTree_EraseAll_Shell10_Inferred.cpp  (canonical clean)
// Generated: 2026-08-05 MEGA-135 dual seal
// =============================================================================

#include <cstdint>

// Ghidra name retained as thin twin. Prefer StdTree_EraseAll_Shell10_Inferred.

extern "C" uint32_t *StdTree_EraseAll_Shell10_Inferred(
    uint32_t *outIt,
    int *first,
    int *last);

// Scaffold signature (decompiler shape). Real ABI: EDI=tree; RET 0xC.
extern "C" uint32_t *FUN_00441720(uint32_t *param_1, int *param_2, int *param_3)
{
  return StdTree_EraseAll_Shell10_Inferred(param_1, param_2, param_3);
}
