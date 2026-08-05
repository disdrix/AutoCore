// =============================================================================
// FUN_004e2b80
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2b80
// Address:   0x004e2b80  (autoassault.exe, image base 0x400000)
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

void FUN_004e2b80(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,
                 uint8_t param_5)

{
  uint32_t /* width from decompiler */ *puVar1;
  
  puVar1 = operator_new(0x28);
  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[4] = *param_4;
    puVar1[5] = param_4[1];
    puVar1[6] = param_4[2];
    puVar1[7] = param_4[3];
    *(uint8_t *)(puVar1 + 8) = param_5;
    *(uint8_t *)((int)puVar1 + 0x21) = 0;
  }
  return;
}
