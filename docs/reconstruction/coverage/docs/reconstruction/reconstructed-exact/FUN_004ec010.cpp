// =============================================================================
// FUN_004ec010
// -----------------------------------------------------------------------------
// Stable ID: aa_004ec010
// Address:   0x004ec010  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall FUN_004ec010(int param_1,uint32_t /* width from decompiler */ param_2)

{
  uint32_t /* width from decompiler */ uVar1;
  
  FUN_004eb3b0();
  if (*(int *)(param_1 + 0x88) != 0) {
    uVar1 = FUN_004a16d0(param_2,1,0xffffffff);
    return uVar1;
  }
  return 0;
}
