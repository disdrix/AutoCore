// =============================================================================
// FUN_009a0294
// -----------------------------------------------------------------------------
// Stable ID: aa_009a0294
// Address:   0x009a0294  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009a0294 @ 0x009a0294
// Stable ID: aa_009a0294
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: ExitThread, FUN_009a0294.
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

void FUN_009a0294(void)



{

  int unaff_EBP;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 8) != 0) {

                    /* WARNING: Subroutine does not return */

    ExitThread(0);

  }

  ExceptionList = *(void **)(unaff_EBP + -0xc);

  return;

}
