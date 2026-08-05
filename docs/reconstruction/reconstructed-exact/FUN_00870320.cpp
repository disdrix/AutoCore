// =============================================================================
// FUN_00870320
// -----------------------------------------------------------------------------
// Stable ID: aa_00870320
// Address:   0x00870320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00870320 @ 0x00870320
// Stable ID: aa_00870320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×2.
//  - Notable callees: FUN_00870320.
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

void FUN_00870320(void)



{

  char cVar1;

  char *pcVar2;

  int unaff_ESI;

  char *unaff_EDI;

  

  pcVar2 = *(char **)(unaff_ESI + 0x564);

  if (pcVar2 != unaff_EDI) {

    if (pcVar2 != (char *)0x0) {

      operator_delete__(pcVar2);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x564) = 0;

    if (unaff_EDI != (char *)0x0) {

      pcVar2 = unaff_EDI;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(unaff_EDI + 1))));

      *(char **)(unaff_ESI + 0x564) = pcVar2;

      do {

        cVar1 = *unaff_EDI;

        *pcVar2 = cVar1;

        unaff_EDI = unaff_EDI + 1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

    }

  }

  if (*(int **)(unaff_ESI + 0x5b8) != (int *)0x0) {

    (**(code **)(**(int **)(unaff_ESI + 0x5b8) + 0x1d8))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x564),1,1);

                    /* WARNING: Could not recover jumptable at 0x008703a4. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x5b8) + 0x34c))();

    return;

  }

  return;

}
