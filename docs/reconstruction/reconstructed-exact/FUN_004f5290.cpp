// =============================================================================
// FUN_004f5290  →  Vehicle_CanFireAnyPrimaryHeatOK_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5290
// Address:   0x004f5290  (autoassault.exe, image base 0x400000)
// System:    combat / vehicle weapon heat
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Canonical clean: Vehicle_CanFireAnyPrimaryHeatOK_Inferred.cpp
// Dual: reviews/A_aa_004f5290_Vehicle_CanFireAnyPrimaryHeatOK_Inferred.md
// =============================================================================

/*
 * Vehicle primary heat quantifier (∃):
 *   for each weapon* in *(vehicle+0x260)[0..2]:
 *     if non-null && vtbl+0x38() && Weapon_CanFireHeatCheck → return 1
 *   return 0
 *
 * Twin secondary FUN_004f52e0: vtbl+0x3C + ∀ heat OK.
 */

#include <cstdint>

extern bool __fastcall Weapon_CanFireHeatCheck(void* pWeapon);

uint32_t /* decompiler width; AL bool */ __fastcall FUN_004f5290(int param_1 /* vehicle ECX */)
{
  int *pWeapon;
  char cVar1;
  bool bVar2;
  int iVar3;

  iVar3 = 0;
  do {
    pWeapon = *(int **)(iVar3 + *(int *)(param_1 + 0x260));
    if (pWeapon != (int *)0x0) {
      cVar1 = (**(code **)(*pWeapon + 0x38))();
      if (cVar1 != '\0') {
        bVar2 = Weapon_CanFireHeatCheck(pWeapon);
        if (bVar2) {
          return 1;
        }
      }
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 < 0xc);
  return 0;
}
