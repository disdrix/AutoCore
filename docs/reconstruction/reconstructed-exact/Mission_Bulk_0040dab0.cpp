// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0040dab0.
//  - Return sites: 2.

// =============================================================================
// Mission_Bulk_0040dab0
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "bulk@0040dab0"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_0040dab0 clean capture (not modernized).
//
// Address:  0x0040dab0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0040dab0
// Stable ID: aa_0040dab0
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_0040dab0_*.md
//           Original Ghidra symbol: FUN_0040dab0
//
// Exactness: Body mirrors reconstructed-exact/FUN_0040dab0*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Bulk_0040dab0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040dab0
// Address:   0x0040dab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "bulk@0040dab0"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Mission_Bulk_0040dab0(float param_1)



{

  if (param_1 < 0.0) {

    return (int)(param_1 - g_flMissionXpRoundBias);

  }

  return (int)(param_1 + g_flMissionXpRoundBias);

}
