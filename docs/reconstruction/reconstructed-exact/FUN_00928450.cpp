// =============================================================================
// FUN_00928450
// -----------------------------------------------------------------------------
// Stable ID: aa_00928450
// Address:   0x00928450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00928450 @ 0x00928450
// Stable ID: aa_00928450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00928390, FUN_00928450.
//  - Return sites: 1.

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



void FUN_00928450(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ extraout_ECX;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &DAT_009abd10;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_LAB_00a2f028;

  *(uint8_t *)(param_1 + 1) = 1;

  param_1[0x42] = 3;

  local_4 = 0;

  *param_1 = &PTR_FUN_00a2f064;

  _DAT_00d17740 = FUN_00928390();

  *(char *)(_DAT_00d17740 + 4) = (char)extraout_ECX;

  DAT_00d17744 = extraout_ECX;

  DAT_00d17748 = extraout_ECX;

  DAT_00d17750 = extraout_ECX;

  ExceptionList = local_c;

  return;

}
