// =============================================================================
// FUN_004eae80
// -----------------------------------------------------------------------------
// Stable ID: aa_004eae80
// Address:   0x004eae80  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_004eae80(int param_1)

{
  if (-1 < *(int *)(param_1 + 0x14)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),*(int *)(param_1 + 0x14) * 8,0x12);
  }
  return;
}
