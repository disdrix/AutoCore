// =============================================================================
// FUN_004b7030
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7030
// Address:   0x004b7030  (autoassault.exe, image base 0x400000)
// Body:      004b7030–004b708a (90 B)
// System:    client-fx / NDSpecialFX owned-child apply
// Dual A/B:  2026-07-29 accept (W24-D)
// Named twin: NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte-sealed
//            callee this (ECX = child). Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Walk host owned-child list at +0x204. For each child with +0x90e bit7 set,
 * dispatch FX start/stop helper:
 *   use_slot_filter==0 -> FUN_0058e300(child, want_start, want_stop)
 *   else               -> FUN_0058e270(child, want_start, want_stop, slot_filter)
 *
 * thiscall; ret 0x10.
 */

void __thiscall FUN_004b7030(
    int param_1,
    uint32_t param_2,
    uint32_t param_3,
    char param_4,
    uint32_t param_5)
{
  int *piVar1;

  piVar1 = (int *)**(int **)(param_1 + 0x204);
  if (piVar1 != *(int **)(param_1 + 0x204)) {
    do {
      if ((*(byte *)(piVar1[2] + 0x90e) & 0x80) != 0) {
        /* ECX = piVar1[2] sealed by bytes (mov ecx,[esi+8]) before call */
        if (param_4 == '\0') {
          FUN_0058e300(/*this=*/piVar1[2], param_2, param_3);
        } else {
          FUN_0058e270(/*this=*/piVar1[2], param_2, param_3, param_5);
        }
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0x204));
  }
  return;
}
