// =============================================================================
// FUN_0076ae90
// -----------------------------------------------------------------------------
// Stable ID: aa_0076ae90
// Address:   0x0076ae90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076ae90 @ 0x0076ae90
// Stable ID: aa_0076ae90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, while×2, return×2, do×1.
//  - Notable callees: FUN_0076ae90.
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

char * FUN_0076ae90(void)



{

  char cVar1;

  char *pcVar2;

  char *in_EAX;

  char cVar3;

  char *unaff_EDI;

  

  cVar3 = *in_EAX;

  if (cVar3 != '\0') {

    cVar1 = *unaff_EDI;

    pcVar2 = unaff_EDI;

    do {

      while (cVar1 != '\0') {

        if (cVar3 == cVar1) {

          return in_EAX;

        }

        cVar1 = pcVar2[1];

        pcVar2 = pcVar2 + 1;

      }

      cVar3 = in_EAX[1];

      in_EAX = in_EAX + 1;

      cVar1 = *unaff_EDI;

      pcVar2 = unaff_EDI;

    } while (cVar3 != '\0');

  }

  return in_EAX;

}
