// =============================================================================
// FUN_00507290  — scaffold alias of Host_ActionList_Push
// -----------------------------------------------------------------------------
// Stable ID: aa_00507290
// Address:   0x00507290  (autoassault.exe, image base 0x400000)
// Prefer:    Host_ActionList_Push.cpp
// Dual A/B:  2026-07-29 W19-O  accept
// =============================================================================

void __thiscall FUN_00507290(int param_1, undefined4 param_2)
{
  if (*(unsigned int *)(param_1 + 0x98) ==
      (*(unsigned int *)(param_1 + 0x9c) & 0x7fffffff)) {
    FUN_005b3370((int *)(param_1 + 0x94), 4);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x94) + *(int *)(param_1 + 0x98) * 4) = param_2;
  *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
  return;
}
