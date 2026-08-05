// =============================================================================
// FUN_00894360
// -----------------------------------------------------------------------------
// Stable ID: aa_00894360
// Address:   0x00894360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00894360 @ 0x00894360
// Stable ID: aa_00894360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_00894360.
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

void FUN_00894360(void)



{

  char cVar1;

  char *pcVar2;

  char *unaff_ESI;

  int unaff_EDI;

  

  if (*(void **)(unaff_EDI + 0x530) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_EDI + 0x530));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x530) = 0;

  if ((unaff_ESI != (char *)0x0) && (*unaff_ESI != '\0')) {

    pcVar2 = unaff_ESI;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(unaff_ESI + 1))));

    *(char **)(unaff_EDI + 0x530) = pcVar2;

    do {

      cVar1 = *unaff_ESI;

      *pcVar2 = cVar1;

      unaff_ESI = unaff_ESI + 1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

  return;

}
