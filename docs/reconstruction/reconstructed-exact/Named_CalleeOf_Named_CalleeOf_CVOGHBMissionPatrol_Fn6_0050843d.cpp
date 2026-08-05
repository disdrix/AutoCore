// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGHBMissionPatrol_Fn6_0050843d
// -----------------------------------------------------------------------------
// Stable ID: aa_0050843d
// LEGACY alias (xref seed). Prefer CVOGHBBase_EndOrDestroy_HardListUnlink.
// Address:   0x0050843d  (autoassault.exe, image base 0x400000)
// Generated: 2026-07-29 W20-R — body aligned to sealed clean
// Canonical: reconstructed-exact/CVOGHBBase_EndOrDestroy_HardListUnlink.cpp
// =============================================================================

#include <stdint.h>

extern void FUN_0050846f(void);
extern uint32_t __thiscall FUN_005085b0(int listMgr, int hb);

void Named_CalleeOf_Named_CalleeOf_CVOGHBMissionPatrol_Fn6_0050843d(void)
{
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;

  *(int *)(unaff_EBP + -4) = unaff_EBX;
  *(uint8_t *)(unaff_EBP + -4) = 3;
  if (((*(char *)(unaff_EBP + 0xc) != (char)unaff_EBX) &&
       (*(int *)(unaff_ESI + 0x18) != unaff_EBX)) &&
      (*(int *)(*(int *)(unaff_ESI + 0x18) + 0xb0) != unaff_EBX)) {
    FUN_005085b0(*(int *)(*(int *)(unaff_ESI + 0x18) + 0xb0), unaff_ESI);
    FUN_0050846f();
    return;
  }
  *(uint8_t *)(unaff_ESI + 0x20) = 1;
  *(int *)(unaff_ESI + 0x18) = unaff_EBX;
  return;
}
