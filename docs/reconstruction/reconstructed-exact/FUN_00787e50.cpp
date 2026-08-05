// =============================================================================
// FUN_00787e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00787e50
// Address:   0x00787e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00787e50 @ 0x00787e50
// Stable ID: aa_00787e50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00787db0, FUN_00787e50, SafeArrayAccessData, SafeArrayCreate, SafeArrayUnaccessData.
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

SAFEARRAY * FUN_00787e50(void)



{

  SAFEARRAY *psa;

  int unaff_EDI;

  ULONG local_10;

  void *local_c;

  SAFEARRAYBOUND local_8;

  

  local_10 = *(ULONG *)(unaff_EDI + 0x1004);

  local_8.lLbound = 0;

  if (*(int *)(unaff_EDI + 0x100c) != 0) {

    local_10 = local_10 + *(int *)(unaff_EDI + 0x100c);

  }

  local_8.cElements = local_10;

  psa = SafeArrayCreate(0x11,1,&local_8);

  SafeArrayAccessData(psa,&local_c);

  FUN_00787db0(&local_c,&local_10,0);

  SafeArrayUnaccessData(psa);

  return psa;

}
