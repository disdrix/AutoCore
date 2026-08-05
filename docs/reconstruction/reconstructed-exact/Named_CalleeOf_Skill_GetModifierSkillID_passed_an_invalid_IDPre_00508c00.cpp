// =============================================================================
// Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00508c00
// LEGACY alias (xref seed name). Prefer HandlerTable54_FindById6c.
// Address:   0x00508c00  (autoassault.exe, image base 0x400000)
// Generated: 2026-07-29 W20-R — body aligned to sealed clean
// Canonical: reconstructed-exact/HandlerTable54_FindById6c.cpp
// =============================================================================

#include <stdint.h>

extern int32_t DAT_00d02988;

int __thiscall Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508c00(
    int param_1, int param_2)
{
  int iVar1;
  int *piVar2;

  iVar1 = 0;
  if ((param_2 != -1) && (0 < DAT_00d02988)) {
    piVar2 = *(int **)(param_1 + 0x54);
    do {
      if (*(int *)(*piVar2 + 0x6c) == param_2) {
        return (*(int **)(param_1 + 0x54))[iVar1];
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < DAT_00d02988);
  }
  return 0;
}
