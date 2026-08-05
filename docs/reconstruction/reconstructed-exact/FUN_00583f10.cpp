// =============================================================================
// FUN_00583f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00583f10
// Address:   0x00583f10  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX multi-host fan-out
// Dual A/B:  2026-07-29 accept (W25-D) — named twin: NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte-sealed this.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

/*
 * Walks two host* vectors (base+0x128/0x12c and base+0x13c/0x140) after
 * vbase adjust; each entry → FUN_004b7030 with passthrough stack args.
 * thiscall; ret 0x10.
 */

void __thiscall FUN_00583f10(
    int param_1,
    unsigned int param_2,
    unsigned int param_3,
    unsigned int param_4,
    unsigned int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;
  iVar2 = *(int *)(iVar1 + 0x128);
  if (iVar2 != *(int *)(iVar1 + 0x12c)) {
    do {
      /* ECX = *(int *)iVar2 — sealed by bytes; decompiler omits */
      FUN_004b7030(param_2, param_3, param_4, param_5);
      iVar2 = iVar2 + 4;
    } while (iVar2 !=
             *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x12c + param_1));
  }
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
  iVar3 = *(int *)(iVar2 + 0x13c + param_1);
  iVar1 = iVar2 + param_1;
  if (iVar3 != *(int *)(iVar2 + 0x140 + param_1)) {
    do {
      /* ECX = *(int *)iVar3 */
      iVar1 = FUN_004b7030(param_2, param_3, param_4, param_5);
      iVar3 = iVar3 + 4;
    } while (iVar3 !=
             *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x140 + param_1));
  }
  return; /* retail leaves EAX = last base */
}
