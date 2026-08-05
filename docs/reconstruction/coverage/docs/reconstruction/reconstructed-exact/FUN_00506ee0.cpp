// =============================================================================
// FUN_00506ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00506ee0
// Address:   0x00506ee0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __fastcall FUN_00506ee0(uint32_t /* width from decompiler */ param_1)

{
  int iVar1;
  
  FUN_00506f50();
  FUN_00506f50();
  FUN_00506f50();
  FUN_00506f50();
  FUN_00506f50();
  FUN_00506f50();
  FUN_00506f50();
  iVar1 = 3;
  do {
    FUN_00506f50();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return param_1;
}
