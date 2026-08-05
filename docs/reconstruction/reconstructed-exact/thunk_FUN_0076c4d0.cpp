// =============================================================================
// thunk_FUN_0076c4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c5c0
// Address:   0x0076c5c0  (autoassault.exe, image base 0x400000)
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

void __fastcall thunk_FUN_0076c4d0(int param_1)

{
  uint64_t uVar1;
  
  uVar1 = rdtsc();
  *(int *)(param_1 + 8) = (int)uVar1;
  *(int *)(param_1 + 0xc) = (int)((ulonglong)uVar1 >> 0x20);
  *(uint8_t *)(param_1 + 0x18) = 1;
  return;
}
