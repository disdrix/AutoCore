// =============================================================================
// Weapon_CanFireHeatCheck
// -----------------------------------------------------------------------------
// Stable ID: aa_0056aca0
// Address:   0x0056aca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Weapon_CanFireHeatCheck — returns true if vehicle heat < MaxHeat (can fire).
   
   Resolves owner character → vehicle (+0x250), then:
     return vehicle.CurrentHeat(+0x150) < vehicle.MaxHeat(+0x244)
   
   Overheat lock: heat >= max blocks all weapon fire. */

bool __fastcall Weapon_CanFireHeatCheck(void *pWeapon)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pWeapon + 4) + 4) + 4 + (int)pWeapon) + 0x214
                      ))();
  if (iVar1 != 0) {
    iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1dc))();
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar1 + 0x250);
      goto compare_heat_to_max;
    }
  }
  iVar1 = 0;
compare_heat_to_max:
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 0x150) < *(int *)(iVar1 + 0x244);
  }
  return true;
}
