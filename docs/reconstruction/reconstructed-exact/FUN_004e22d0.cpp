// =============================================================================
// FUN_004e22d0  (twin of Tree_RotateLeft_Isnil15)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e22d0
// Address:   0x004e22d0  (autoassault.exe, image base 0x400000)
// Body:      0x004e22d0–0x004e231d (78 bytes)
// System:    container / map-set tree
// Ghidra:    FUN_004e22d0
// Named:     Tree_RotateLeft_Isnil15 (see Tree_RotateLeft_Isnil15.cpp)
//
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Dual A/B: accept (2026-07-29 W24-O seal).
// =============================================================================

// Scaffold twin keeps Ghidra symbol; prefer named clean for ports.

void __thiscall FUN_004e22d0(int param_1, int param_2)
{
  int *piVar1;
  int *piVar2;

  piVar1 = *(int **)(param_2 + 8);
  *(int *)(param_2 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x15) == '\0') {
    *(int *)(*piVar1 + 4) = param_2;
  }
  piVar1[1] = *(int *)(param_2 + 4);
  if (param_2 == *(int *)(*(int *)(param_1 + 4) + 4)) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar1;
    *piVar1 = param_2;
    *(int **)(param_2 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_2 + 4);
  if (param_2 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_2;
    *(int **)(param_2 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_2;
  *(int **)(param_2 + 4) = piVar1;
  return;
}
