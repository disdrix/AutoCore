// =============================================================================
// FUN_004c8110
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8110
// Address:   0x004c8110  (autoassault.exe, image base 0x400000)
// System:    client-fx / dual effect-slot apply
// Dual A/B:  2026-07-29 accept (W25-D) — named twin: Object_ApplyDualFxSlots_SlotFilterWild_Inferred.cpp
// Exactness: Behavior-preserving rewrite; tail-call sealed by bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

/*
 * Dual effect slots at this-0x27c / this-0x280.
 * Non-null → FUN_00583f10(this-0x4c0, 0, effect, 1, -1) then local host*
 * vector FUN_004b7030 with same args; tail jmp FUN_00584330(this-0x430).
 */

void __thiscall FUN_004c8110(int param_1)
{
  int iVar1;
  int iVar2;

  if (*(int *)(param_1 + -0x27c) != 0) {
    FUN_00583f10(0, *(int *)(param_1 + -0x27c), 1, 0xffffffff);
    /* ECX = param_1 - 0x4c0 sealed by lea before call */
    iVar1 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);
    iVar2 = *(int *)(iVar1 + -0x3c4 + param_1);
    if (iVar2 != *(int *)(iVar1 + -0x3c0 + param_1)) {
      do {
        /* ECX = *(int *)iVar2 */
        FUN_004b7030(0, *(unsigned int *)(param_1 + -0x27c), 1, 0xffffffff);
        iVar2 = iVar2 + 4;
      } while (iVar2 !=
               *(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x3c0
                        + param_1));
    }
  }
  if (*(int *)(param_1 + -0x280) != 0) {
    FUN_00583f10(0, *(int *)(param_1 + -0x280), 1, 0xffffffff);
    iVar1 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);
    iVar2 = *(int *)(iVar1 + -0x3c4 + param_1);
    if (iVar2 != *(int *)(iVar1 + param_1 + -0x3c0)) {
      do {
        FUN_004b7030(0, *(unsigned int *)(param_1 + -0x280), 1, 0xffffffff);
        iVar2 = iVar2 + 4;
      } while (iVar2 !=
               *(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x3c0
                        + param_1));
    }
  }
  /* tail: lea ecx,[param_1-0x430]; jmp FUN_00584330 */
  FUN_00584330();
}
