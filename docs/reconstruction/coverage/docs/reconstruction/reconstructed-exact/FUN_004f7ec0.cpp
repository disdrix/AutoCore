// =============================================================================
// FUN_004f7ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f7ec0
// Address:   0x004f7ec0  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004f7ec0(int param_1,char param_2)

{
  void *pvVar1;
  CVOGHBBase *pAction;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2ccf;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 0x100) != '\0') {
    if (param_2 == '\0') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x24);
      pAction = (CVOGHBBase *)0x0;
      local_4 = 0;
      if (pvVar1 != (void *)0x0) {
        pAction = (CVOGHBBase *)FUN_005fc1f0(param_1,DAT_00af0c70);
      }
      local_4 = 0xffffffff;
      CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +
                                   0xe4ec),pAction);
      CVOGHBBase_Start(pAction);
    }
    *(char *)(param_1 + 0x100) = param_2;
    ExceptionList = local_c;
    return;
  }
  *(char *)(param_1 + 0x100) = param_2;
  return;
}
