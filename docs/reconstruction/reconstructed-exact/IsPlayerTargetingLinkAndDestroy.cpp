// =============================================================================
// IsPlayerTargetingLinkAndDestroy  (named alias of FUN_005121d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005121d0
// Address:   0x005121d0
// See:       FUN_005121d0.cpp for full plate / ABI seal
// Dual:      reviews/A_aa_005121d0_IsPlayerTargetingLinkAndDestroy.md
//            reviews/B_aa_005121d0_IsPlayerTargetingLinkAndDestroy.md
// =============================================================================

#include <cstdint>

extern "C" void *CVOGHBBase_RTTI_Type_Descriptor;
extern "C" void *CVOGHBPlayerTargetingLink_RTTI_Type_Descriptor;
extern "C" void *__cdecl __RTDynamicCast(void *in, long VfDelta, void *srcType,
                                         void *targetType, int isReference);

// List-purge predicate: destroy CVOGHBPlayerTargetingLink nodes, return 1 to remove.
extern "C" uint32_t __stdcall IsPlayerTargetingLinkAndDestroy(int *node,
                                                              void * /*ctx1*/,
                                                              void * /*ctx2*/)
{
  int casted;

  casted = (int)__RTDynamicCast(
      node,
      0,
      &CVOGHBBase_RTTI_Type_Descriptor,
      &CVOGHBPlayerTargetingLink_RTTI_Type_Descriptor,
      0);
  if (casted != 0) {
    (*(void (__thiscall **)(int *, int, int))(*node + 0x18))(node, 1, 0);
    return 1;
  }
  return 0;
}
