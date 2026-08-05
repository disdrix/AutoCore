// =============================================================================
// FUN_007314b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007314b0
// Address:   0x007314b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007314b0 @ 0x007314b0
// Stable ID: aa_007314b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00456960, FUN_007314b0.
//  - Return sites: 2.

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

void FUN_007314b0(uint32_t /* width from decompiler */ param_1)



{

  if ((DAT_00d1ef70 != 0) &&

     ((uint)((int)DAT_00d1ef74 - DAT_00d1ef70 >> 2) < (uint)(DAT_00d1ef78 - DAT_00d1ef70 >> 2))) {

    *DAT_00d1ef74 = param_1;

    DAT_00d1ef74 = DAT_00d1ef74 + 1;

    return;

  }

  FUN_00456960(DAT_00d1ef74);

  return;

}
