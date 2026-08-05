// =============================================================================
// FUN_006753b0  (twin of Tree_RotateRight_Isnil15)
// -----------------------------------------------------------------------------
// Stable ID: aa_006753b0
// Address:   0x006753b0  (autoassault.exe, image base 0x400000)
// Body:      0x006753b0–0x00675401 (82 bytes)
// System:    container / map-set tree
// Ghidra:    FUN_006753b0
// Named:     Tree_RotateRight_Isnil15 (see Tree_RotateRight_Isnil15.cpp)
//
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Dual A/B: accept (2026-07-29 W24-O seal).
// =============================================================================

// Scaffold twin keeps Ghidra name; prefer named clean for ports.

void __thiscall FUN_006753b0(int param_1, int *param_2)
{
  int iVar1;
  int *piVar2;

  iVar1 = *param_2;
  *param_2 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x15) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_2;
  }
  *(int *)(iVar1 + 4) = param_2[1];
  if (param_2 == *(int **)(*(int *)(param_1 + 4) + 4)) {
    *(int *)(*(int *)(param_1 + 4) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_2;
    param_2[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_2[1];
  if (param_2 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_2;
    param_2[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_2;
  param_2[1] = iVar1;
  return;
}
