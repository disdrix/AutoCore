// =============================================================================
// FUN_00507120
// -----------------------------------------------------------------------------
// Stable ID: aa_00507120
// Address:   0x00507120  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ * __thiscall FUN_00507120(uint32_t /* width from decompiler */ *param_1,byte param_2)

{
  *param_1 = &PTR_FUN_009d81e8;
  if ((short)*(ushort *)(param_1 + 1) < 0) {
    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;
    FUN_005ffdb0(0);
  }
  *param_1 = &PTR_LAB_009cc290;
  if ((param_2 & 1) != 0) {
    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(uint16_t *)(param_1 + 1),0x10);
  }
  return param_1;
}
