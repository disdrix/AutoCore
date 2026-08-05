// =============================================================================
// FUN_004e2f20
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2f20
// Address:   0x004e2f20  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall FUN_004e2f20(int param_1,uint param_2)

{
  void *pvVar1;
  
  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;
  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;
  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;
  if (param_2 == 0) {
    return 0;
  }
  if (0x1fffffff < param_2) {
    param_2 = FUN_00418130();
  }
  pvVar1 = operator_new(param_2 * 8);
  *(void **)(param_1 + 0xc) = (void *)(param_2 * 8 + (int)pvVar1);
  *(void **)(param_1 + 4) = pvVar1;
  *(void **)(param_1 + 8) = pvVar1;
  return 1;
}
