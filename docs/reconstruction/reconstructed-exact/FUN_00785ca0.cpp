// =============================================================================
// FUN_00785ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00785ca0
// Address:   0x00785ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00785ca0 @ 0x00785ca0
// Stable ID: aa_00785ca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00785ca0.
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

uint32_t /* width from decompiler */ FUN_00785ca0(int param_1)



{

  if ((((param_1 != -0x2020203) && (param_1 != -0x32323233)) && (param_1 != -0x1110112)) &&

     (((param_1 != -0x22222223 && (param_1 != -0x14141415)) && (param_1 != -0x3030304)))) {

    return 0;

  }

  return 1;

}
