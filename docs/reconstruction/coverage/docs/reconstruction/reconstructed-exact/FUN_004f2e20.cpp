// =============================================================================
// FUN_004f2e20
// -----------------------------------------------------------------------------
// Stable ID: aa_004f2e20
// Address:   0x004f2e20  (autoassault.exe, image base 0x400000)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_004f2e20(uint32_t /* width from decompiler */ *param_1)

{
  if ((_DAT_00b03e74 & 1) == 0) {
    _DAT_00b03e74 = _DAT_00b03e74 | 1;
  }
  _DAT_00b03e68 = *param_1;
  _DAT_00b03e6c = param_1[1];
  _DAT_00b03e70 = param_1[2];
  return &DAT_00b03e68;
}
