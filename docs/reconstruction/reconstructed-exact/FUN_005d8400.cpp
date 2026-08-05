// =============================================================================
// FUN_005d8400
// -----------------------------------------------------------------------------
// Stable ID: aa_005d8400
// Address:   0x005d8400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d8400 @ 0x005d8400
// Stable ID: aa_005d8400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005d8400.
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

void FUN_005d8400(int param_1)



{

  if (param_1 != DAT_00bc564c - DAT_00bc5640) {

    (**(code **)(*DAT_00b05060 + 4))(DAT_00bc5640);

    DAT_00bc5640 = (**(code **)*DAT_00b05060)(param_1,0x16);

    DAT_00bc564c = DAT_00bc5640 + param_1;

    DAT_00bc5648 = DAT_00bc564c + -0x10;

    DAT_00bc5644 = DAT_00bc5640;

  }

  return;

}
