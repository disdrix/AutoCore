// =============================================================================
// FUN_00506f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00506f50
// Address:   0x00506f50  (autoassault.exe, image base 0x400000)
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

void __fastcall FUN_00506f50(int param_1)

{
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;
  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0;
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;
  *(float *)(param_1 + 0x7c) = g_flMsToSeconds_Inferred;
  return;
}
