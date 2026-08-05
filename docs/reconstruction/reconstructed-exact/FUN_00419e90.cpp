// =============================================================================
// FUN_00419e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00419e90
// Address:   0x00419e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00419e90 @ 0x00419e90
// Stable ID: aa_00419e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00419d40, FUN_00419e90, _com_issue_errorex.
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

void FUN_00419e90(void)



{

  ULONG UVar1;

  IUnknown *unaff_ESI;

  

  UVar1 = (*unaff_ESI->lpVtbl[8].Release)(unaff_ESI);

  if ((int)UVar1 < 0) {

    _com_issue_errorex(UVar1,unaff_ESI,(_GUID *)&DAT_00a86128);

  }

  FUN_00419d40(0);

  return;

}
