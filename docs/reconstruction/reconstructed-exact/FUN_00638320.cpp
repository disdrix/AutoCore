// =============================================================================
// FUN_00638320
// -----------------------------------------------------------------------------
// Stable ID: aa_00638320
// Address:   0x00638320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00638320 @ 0x00638320
// Stable ID: aa_00638320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: free×4, FUN_00638320.
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

void __fastcall FUN_00638320(uint32_t /* width from decompiler */ *param_1)



{

  if ((void *)*param_1 != (void *)0x0) {

    free((void *)*param_1);

  }

  if (param_1[1] != 0) {

    free(param_1 + 1);

  }

  if ((void *)param_1[2] != (void *)0x0) {

    free((void *)param_1[2]);

  }

  if ((void *)param_1[3] != (void *)0x0) {

    free((void *)param_1[3]);

  }

  return;

}
