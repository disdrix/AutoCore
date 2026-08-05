// =============================================================================
// FUN_00711110
// -----------------------------------------------------------------------------
// Stable ID: aa_00711110
// Address:   0x00711110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711110 @ 0x00711110
// Stable ID: aa_00711110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00711110, FUN_00711cb0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00711110(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  if ((param_1 != (int *)0x0) && (*param_1 == 0xface)) {

    if ((char)param_1[3] != '\n') {

      return 0x17de;

    }

    FUN_00711cb0(param_1[4],param_2);

    return 0;

  }

  return 0x17d4;

}
