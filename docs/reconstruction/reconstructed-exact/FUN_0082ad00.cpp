// =============================================================================
// FUN_0082ad00
// -----------------------------------------------------------------------------
// Stable ID: aa_0082ad00
// Address:   0x0082ad00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082ad00 @ 0x0082ad00
// Stable ID: aa_0082ad00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0082ad00.
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

void FUN_0082ad00(void)



{

  char cVar1;

  char *pcVar2;

  char *unaff_ESI;

  int *unaff_EDI;

  

  if ((void *)unaff_EDI[0x146] != (void *)0x0) {

    operator_delete__((void *)unaff_EDI[0x146]);

  }

  unaff_EDI[0x146] = 0;

  if (unaff_ESI != (char *)0x0) {

    pcVar2 = unaff_ESI;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(unaff_ESI + 1))));

    unaff_EDI[0x146] = (int)pcVar2;

    do {

      cVar1 = *unaff_ESI;

      *pcVar2 = cVar1;

      unaff_ESI = unaff_ESI + 1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

  (**(code **)(*unaff_EDI + 0x444))();

                    /* WARNING: Could not recover jumptable at 0x0082ad63. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_EDI + 0x34c))();

  return;

}
