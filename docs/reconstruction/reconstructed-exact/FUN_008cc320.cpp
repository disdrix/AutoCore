// =============================================================================
// FUN_008cc320
// -----------------------------------------------------------------------------
// Stable ID: aa_008cc320
// Address:   0x008cc320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cc320 @ 0x008cc320
// Stable ID: aa_008cc320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_008cc320, strchr.
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

bool FUN_008cc320(void)



{

  int in_EAX;

  char *pcVar1;

  

  if (((-1 < in_EAX) && (in_EAX < 0xc)) && ((&DAT_00d1b6dc)[in_EAX] != 0)) {

    pcVar1 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)((&DAT_00d1b6dc)[in_EAX] + 4) + 4) + 4 +

                                          (&DAT_00d1b6dc)[in_EAX]) + 0x160))();

    pcVar1 = strchr(pcVar1,0x23);

    return pcVar1 != (char *)0x0;

  }

  return false;

}
