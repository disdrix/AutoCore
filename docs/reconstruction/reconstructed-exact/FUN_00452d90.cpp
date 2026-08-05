// =============================================================================
// FUN_00452d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00452d90
// Address:   0x00452d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00452d90 @ 0x00452d90
// Stable ID: aa_00452d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00452d90.
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

void FUN_00452d90(void)



{

  char cVar1;

  int iVar2;

  int in_EAX;

  

  iVar2 = *(int *)(in_EAX + 8);

  cVar1 = *(char *)(iVar2 + 0x49);

  while (cVar1 == '\0') {

    iVar2 = *(int *)(iVar2 + 8);

    cVar1 = *(char *)(iVar2 + 0x49);

  }

  return;

}
