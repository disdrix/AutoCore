// =============================================================================
// FUN_0082fe20 (scaffold twin)
// Named: UI_InteractionMenu_PopulateTargetButtons_Inferred
// Stable ID: aa_0082fe20  VA: 0x0082fe20
// Dual: WQ9E-D 2026-08-04 — prefer named clean source.
// =============================================================================

// See: reconstructed-exact/UI_InteractionMenu_PopulateTargetButtons_Inferred.cpp

void __fastcall FUN_0082fe20(int *param_1)
{
  char cVar1;
  int *piVar2;
  int iVar3;

  if (param_1[0x130] != 0) {
    FUN_0082d2b0();
    if (((DAT_00d1b6d8 == 0) ||
        (piVar2 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x15e)), piVar2 == (int *)0x0)) ||
       (cVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +
                            0x298))(piVar2), cVar1 != '\0')) {
      if (param_1[0xac] != 0) {
        FUN_0090d400();
        return;
      }
    }
    else {
      iVar3 = (**(code **)(*piVar2 + 0x210))(0);
      if ((iVar3 == 0) || (iVar3 == DAT_00d1b6d8)) {
        if (param_1[0xac] != 0) {
          FUN_0090d400();
          return;
        }
      }
      else {
        iVar3 = (**(code **)(*param_1 + 0x478))();
        if (iVar3 == 0) {
          FUN_0082f8d0();
          FUN_0082f9a0();
          FUN_0082f810();
          FUN_0082fc40();
          FUN_0082fa60();
          FUN_0082fb30();
          FUN_0082fd50();
          return;
        }
        FUN_0082fd50();
        FUN_0082fb30();
        FUN_0082fa60();
        FUN_0082fc40();
        FUN_0082f810();
        FUN_0082f9a0();
        FUN_0082f8d0();
      }
    }
  }
  return;
}
