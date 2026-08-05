// =============================================================================
// FUN_00745e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00745e20
// Address:   0x00745e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00745e20 @ 0x00745e20
// Stable ID: aa_00745e20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: EnterCriticalSection, FUN_00745e20, LeaveCriticalSection.
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

bool FUN_00745e20(void)



{

  int iVar1;

  int unaff_EDI;

  

  if (*(char *)(unaff_EDI + 0x38) != '\0') {

    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x20));

  }

  iVar1 = *(int *)(unaff_EDI + 0x10);

  if (*(char *)(unaff_EDI + 0x38) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0x20));

  }

  return iVar1 != 0;

}
