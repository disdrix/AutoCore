// =============================================================================
// FUN_00653260
// -----------------------------------------------------------------------------
// Stable ID: aa_00653260
// Address:   0x00653260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00653260 @ 0x00653260
// Stable ID: aa_00653260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004f3540, FUN_00653260.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00653260(uint32_t /* width from decompiler */ *param_1,byte param_2)



{

  *param_1 = &PTR_FUN_009e5bf4;

  if (param_1[0x14] != 0) {

    FUN_004f3540(1);

    param_1[0x14] = 0;

  }

  *param_1 = &PTR_LAB_009cc290;

  if ((param_2 & 1) != 0) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1,*(uint16_t *)(param_1 + 1),8);

  }

  return param_1;

}
