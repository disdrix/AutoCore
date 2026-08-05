// =============================================================================
// FUN_004e3260
// -----------------------------------------------------------------------------
// Stable ID: aa_004e3260
// Address:   0x004e3260  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ FUN_004e3260(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)

{
  int iVar1;
  
  iVar1 = FUN_004e23d0(param_1,param_2,&param_1);
  if (iVar1 == 0) {
    return 0;
  }
  return *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);
}
