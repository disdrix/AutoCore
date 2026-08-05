// =============================================================================
// FUN_004f4ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f4ce0
// Address:   0x004f4ce0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __fastcall FUN_004f4ce0(int param_1)

{
  int iVar1;
  uint32_t /* width from decompiler */ uVar2;
  
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0);
  if ((iVar1 != 0) || (uVar2 = 0xc, *(char *)(param_1 + 0x103) != '\0')) {
    uVar2 = 10;
  }
  return uVar2;
}
