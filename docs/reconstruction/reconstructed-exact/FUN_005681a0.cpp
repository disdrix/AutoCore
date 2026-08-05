// =============================================================================
// FUN_005681a0  (canonical: Tree_RotateRight)
// -----------------------------------------------------------------------------
// Stable ID: aa_005681a0
// Address:   0x005681a0 – 0x005681f1  (autoassault.exe, image base 0x400000)
// System:    container / map-set tree
// Generated: 2026-07-29 W23-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named plate: reconstructed-exact/Tree_RotateRight.cpp
// =============================================================================

// PURPOSE: Leaf right-rotate of map/set tree node (isnil @ +0x49).
// Twin: Tree_RotateLeft FUN_00568b70.
// Callers: insert/erase rebalance (FUN_00538ea0, FUN_00538780, FUN_00568c60, FUN_005690a0).

#include <cstdint>

void __thiscall FUN_005681a0(int param_1, int *param_2)
{
  int iVar1;
  int *piVar2;

  iVar1 = *param_2;                              // y = x->left
  *param_2 = *(int *)(iVar1 + 8);                // x->left = y->right
  if (*(char *)(*(int *)(iVar1 + 8) + 0x49) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_2; // !isnil → parent fixup
  }
  *(int *)(iVar1 + 4) = param_2[1];              // y->parent = x->parent
  if (param_2 == *(int **)(*(int *)(param_1 + 4) + 4)) {
    // x was root
    *(int *)(*(int *)(param_1 + 4) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_2;              // y->right = x
    param_2[1] = iVar1;                          // x->parent = y
    return;
  }
  piVar2 = (int *)param_2[1];
  if (param_2 == (int *)piVar2[2]) {
    // x was right child
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_2;
    param_2[1] = iVar1;
    return;
  }
  // x was left child
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_2;
  param_2[1] = iVar1;
  return;
}
