// =============================================================================
// hkAnalogDI_vtbl1
// -----------------------------------------------------------------------------
// Stable ID: aa_005ffd80
// Address:   0x005ffd80  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall hkAnalogDI_vtbl1(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)

{
  uint32_t /* width from decompiler */ uVar1;
  
  if ((*(byte *)(param_1 + 5) & 0x80) != 0) {
    uVar1 = FUN_005ffc90(param_1,param_2,param_3);
    return uVar1;
  }
  return 0;
}
