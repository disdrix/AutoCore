// =============================================================================
// FUN_008c6860
// -----------------------------------------------------------------------------
// Stable ID: aa_008c6860
// Address:   0x008c6860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c6860 @ 0x008c6860
// Stable ID: aa_008c6860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00792490, FUN_008c6860, FUN_0097ae30.
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

void __fastcall FUN_008c6860(int *param_1)



{

  if (param_1[0x164] != 0) {

    (**(code **)(*(int *)param_1[0x164] + 0x440))();

  }

  if (param_1[0x165] != 0) {

    FUN_0097ae30();

    (**(code **)(*(int *)param_1[0x165] + 0xcc))(0);

    (**(code **)(*param_1 + 0xb0))(param_1[0x165]);

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
