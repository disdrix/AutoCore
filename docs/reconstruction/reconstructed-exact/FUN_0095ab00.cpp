// =============================================================================
// FUN_0095ab00
// -----------------------------------------------------------------------------
// Stable ID: aa_0095ab00
// Address:   0x0095ab00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095ab00 @ 0x0095ab00
// Stable ID: aa_0095ab00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×4, do×4, while×4, return×1.
//  - Notable callees: FUN_0095ab00.
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

void FUN_0095ab00(char *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ in_EAX;

  char *pcVar2;

  int unaff_ESI;

  char *unaff_EDI;

  

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = in_EAX;

  if (*(void **)(unaff_ESI + 4) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 4));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

  if (*(void **)(unaff_ESI + 8) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 8));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  if (unaff_EDI != (char *)0x0) {

    pcVar2 = unaff_EDI;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(unaff_EDI + 1))));

    *(char **)(unaff_ESI + 4) = pcVar2;

    do {

      cVar1 = *unaff_EDI;

      *pcVar2 = cVar1;

      unaff_EDI = unaff_EDI + 1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

  if (param_1 != (char *)0x0) {

    pcVar2 = param_1;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(param_1 + 1))));

    *(char **)(unaff_ESI + 8) = pcVar2;

    do {

      cVar1 = *param_1;

      *pcVar2 = cVar1;

      param_1 = param_1 + 1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

  return;

}
