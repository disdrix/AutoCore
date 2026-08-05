// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00412c60.
//  - Return sites: 2.

// =============================================================================
// Mission_Bulk_00412c60
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "bulk@00412c60"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_00412c60 clean capture (not modernized).
//
// Address:  0x00412c60  (autoassault.exe, image base 0x400000)
// Stable:   aa_00412c60
// Stable ID: aa_00412c60
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_00412c60_*.md
//           Original Ghidra symbol: FUN_00412c60
//
// Exactness: Body mirrors reconstructed-exact/FUN_00412c60*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Bulk_00412c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00412c60
// Address:   0x00412c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "bulk@00412c60"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

float10 Mission_Bulk_00412c60(float param_1)



{

  param_1 = param_1 * DAT_00a110d8;

  if (param_1 < 0.0) {

    return (float10)(int)(param_1 - g_flMissionXpRoundBias) * (float10)g_flMultiKillCountBlend;

  }

  return (float10)(int)(param_1 + g_flMissionXpRoundBias) * (float10)g_flMultiKillCountBlend;

}
