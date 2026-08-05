// =============================================================================
// FUN_004f7c50
// -----------------------------------------------------------------------------
// Stable ID: aa_004f7c50
// Address:   0x004f7c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_004f7c50(int param_1)

{
  int iVar1;
  float10 fVar2;
  void *pvStack_c;
  void *pvStack_8;
  int iStack_4;
  
  if (*(char *)(param_1 + -0x57b) == '\0') {
    *(uint8_t *)(param_1 + -0x57b) = 1;
    iVar1 = FUN_004ce940();
    if (iVar1 != 0) {
      fVar2 = (float10)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c +
                                            param_1) + 0x180))();
      iStack_4 = (int)ROUND(fVar2);
      *(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5a8 + param_1) = iStack_4;
      pvStack_c = (void *)0x0;
      pvStack_8 = (void *)0x0;
      FUN_005c9800(&pvStack_c);
      FUN_005c9870(&pvStack_8);
      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1) + 0x154))()
      ;
      FUN_005cad30(pvStack_c,0);
      FUN_005cadd0(pvStack_8,0);
      if (pvStack_c != (void *)0x0) {
        operator_delete__(pvStack_c);
      }
      pvStack_c = (void *)0x0;
      if (pvStack_8 != (void *)0x0) {
        operator_delete__(pvStack_8);
      }
    }
  }
  return;
}
