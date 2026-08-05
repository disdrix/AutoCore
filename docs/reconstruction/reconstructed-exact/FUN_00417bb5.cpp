// =============================================================================
// FUN_00417bb5
// -----------------------------------------------------------------------------
// Stable ID: aa_00417bb5
// Address:   0x00417bb5  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00417bb5 @ 0x00417bb5
// Stable ID: aa_00417bb5
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: LeaveCriticalSection×2, FUN_00417bb5, InterlockedIncrement.
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

uint8_t FUN_00417bb5(void)



{

  int unaff_EBP;

  int unaff_ESI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_EBP + -4) = 0xffffffff;

  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x10));

  if (*(char *)(unaff_EBP + -0x11) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x28));

  }

  InterlockedIncrement((LONG *)(unaff_ESI + 0xc));

  ExceptionList = *(void **)(unaff_EBP + -0xc);

  return *(uint8_t *)(unaff_EBP + -0x12);

}
