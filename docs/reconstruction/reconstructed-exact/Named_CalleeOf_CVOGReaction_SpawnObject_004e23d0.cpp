// =============================================================================
// Named_CalleeOf_CVOGReaction_SpawnObject_004e23d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e23d0
// Address:   0x004e23d0  (autoassault.exe, image base 0x400000)
// Alias of:  FUN_004e23d0 / List_FindByDualKeyWithPred_Inferred
// Note:      Parent-seed rename only — NOT exclusive to CVOGReaction_SpawnObject
//            (27 xrefs). Prefer structural List_FindByDualKeyWithPred_Inferred.
// Dual A/B:  reviews/A_aa_004e23d0_List_FindByDualKeyWithPred_Inferred.md
//            reviews/B_aa_004e23d0_List_FindByDualKeyWithPred_Inferred.md
// Generated: 2026-07-23; dual seal 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================

int __thiscall Named_CalleeOf_CVOGReaction_SpawnObject_004e23d0(
    int param_1, int param_2, int param_3, int *param_4)
{
  int iVar1;

  iVar1 = *(int *)(param_1 + 4);
  *param_4 = 0;
  for (; (iVar1 != 0 &&
          ((param_2 != *(int *)(iVar1 + 0x18) ||
            (param_3 != *(int *)(iVar1 + 0x1c)))));
       iVar1 = *(int *)(iVar1 + 0x10)) {
    *param_4 = iVar1;
  }
  return iVar1;
}
