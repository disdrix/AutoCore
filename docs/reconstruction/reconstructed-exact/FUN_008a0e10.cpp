// =============================================================================
// FUN_008a0e10  (Ghidra name twin of QuickBar_RebindPageColumns_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008a0e10
// Address:   0x008a0e10  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 W22-D dual A/B (replaces 2026-07-23 scaffold)
// Exactness: Decompiler-surface CF preserved. Named plate adds callee ABI notes.
// Named plate: reconstructed-exact/QuickBar_RebindPageColumns_Inferred.cpp
// =============================================================================

void FUN_008a0e10(int *param_1)
{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;

  cVar3 = (**(code **)(*param_1 + 0x3d8))();
  if ((cVar3 != '\0') && (DAT_00d1b6d8 != 0)) {
    FUN_007fce10(&DAT_00d1a840);
    iVar5 = 0;
    piVar4 = param_1 + 399;
    do {
      iVar1 = iVar5 + param_1[0x143] * 10;
      iVar2 = *(int *)(&DAT_00d1da60 + iVar1 * 0x18);
      if (iVar2 == 1) {
        FUN_00826860(*piVar4);
      }
      else if (iVar2 == 2) {
        FUN_008283a0();
      }
      else if (iVar2 == 5) {
        FUN_00827670(*(undefined4 *)(&DAT_00d1da68 + iVar1 * 0x18));
      }
      else {
        QuickBar_ClearActiveSlot_INFERRED();
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar5 < 10);
  }
  return;
}
