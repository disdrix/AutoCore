// =============================================================================
// FUN_004f2e70
// -----------------------------------------------------------------------------
// Stable ID: aa_004f2e70
// Address:   0x004f2e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f2e70 @ 0x004f2e70
// Stable ID: aa_004f2e70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004f2e70.
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



undefined * FUN_004f2e70(uint32_t /* width from decompiler */ *param_1)



{

  if ((_DAT_00b03e88 & 1) == 0) {

    _DAT_00b03e88 = _DAT_00b03e88 | 1;

  }

  _DAT_00b03e78 = *param_1;

  _DAT_00b03e7c = param_1[1];

  _DAT_00b03e80 = param_1[2];

  _DAT_00b03e84 = param_1[3];

  return &DAT_00b03e78;

}
