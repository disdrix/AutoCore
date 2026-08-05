// =============================================================================
// FUN_004b2b30
// -----------------------------------------------------------------------------
// Stable ID: aa_004b2b30
// Address:   0x004b2b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b2b30 @ 0x004b2b30
// Stable ID: aa_004b2b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004b2b30, ROUND.
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

void FUN_004b2b30(float param_1,int param_2,int param_3,int param_4)



{

  *(float *)(param_2 + 0xc) =

       (float)(int)((uint)*(byte *)(param_3 + 3) +

                   (int)ROUND((float)(int)((uint)*(byte *)(param_4 + 3) -

                                          (uint)*(byte *)(param_3 + 3)) * param_1)) * DAT_009cb150;

  return;

}
