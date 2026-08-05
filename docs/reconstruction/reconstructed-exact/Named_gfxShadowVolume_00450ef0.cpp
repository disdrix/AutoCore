// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00450ef0, vog_LogMessage.
//  - Strings: "..\\palantir/graphics/gfxShadowVolume.h"; "Unimplemented code reached".
//  - Return sites: 2.

// =============================================================================
// Named_gfxShadowVolume_00450ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_00450ef0
// Address:   0x00450ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxShadowVolume"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall Named_gfxShadowVolume_00450ef0(int param_1)



{

  int in_EAX;

  

  if (in_EAX == 4) {

    param_1 = param_1 / 3;

  }

  else {

    if ((in_EAX < 5) || (6 < in_EAX)) {

      vog_LogMessage("..\\palantir/graphics/gfxShadowVolume.h",0x61,3,"Unimplemented code reached");

      return 0;

    }

    param_1 = param_1 + -2;

  }

  if (param_1 < 2) {

    param_1 = 0;

  }

  return param_1;

}
