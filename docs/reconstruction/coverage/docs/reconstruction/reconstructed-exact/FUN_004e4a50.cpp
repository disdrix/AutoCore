// =============================================================================
// FUN_004e4a50
// -----------------------------------------------------------------------------
// Stable ID: aa_004e4a50
// Address:   0x004e4a50  (autoassault.exe, image base 0x400000)
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

void __thiscall FUN_004e4a50(int param_1,byte param_2)

{
  if (*(char *)(param_1 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:Recreate, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  FUN_004e3720();
  *(byte *)(param_1 + 0x1c) = param_2;
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;
  *(int *)(param_1 + 8) = 1 << (param_2 & 0x1f);
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;
  FUN_004e1ca0();
  return;
}
