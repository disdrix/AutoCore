// =============================================================================
// FUN_006785e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006785e0
// Address:   0x006785e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006785e0 @ 0x006785e0
// Stable ID: aa_006785e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: free×4, FUN_006785e0, nciFreeDecodeSase6500, nciFreeEncodeSase6500.
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

void __fastcall FUN_006785e0(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009e8728;

  if (param_1[1] == 0) {

    nciFreeEncodeSase6500(param_1 + 0x17);

    free((void *)param_1[0xb]);

    free((void *)param_1[0xd]);

  }

  else if (param_1[1] == 1) {

    nciFreeDecodeSase6500(param_1 + 0x18);

    free((void *)param_1[0x11]);

    free((void *)param_1[0x13]);

    *param_1 = &PTR_LAB_009e84f4;

    return;

  }

  *param_1 = &PTR_LAB_009e84f4;

  return;

}
