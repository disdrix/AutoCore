// =============================================================================
// FUN_00793db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00793db0
// Address:   0x00793db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00793db0 @ 0x00793db0
// Stable ID: aa_00793db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, while×4, do×2.
//  - Notable callees: FUN_00793db0.
//  - Return sites: 4.

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

int FUN_00793db0(char *param_1)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  char *unaff_EDI;

  

  if ((param_1 == (char *)0x0) || (unaff_EDI == (char *)0x0)) {

    return -1;

  }

  cVar2 = *param_1;

  pcVar3 = param_1;

  while (cVar2 != '\0') {

    pcVar3 = pcVar3 + 1;

    cVar2 = *pcVar3;

  }

  iVar4 = (int)pcVar3 - (int)param_1;

  pcVar3 = unaff_EDI;

  cVar2 = *unaff_EDI;

  while (cVar2 != '\0') {

    pcVar3 = pcVar3 + 1;

    cVar2 = *pcVar3;

  }

  iVar5 = (int)pcVar3 - (int)unaff_EDI;

  if (((iVar5 <= iVar4) && (0 < iVar4)) && (0 < iVar5)) {

    iVar4 = iVar4 - iVar5;

    do {

      if (iVar4 < 0) {

        return -1;

      }

      pcVar3 = param_1 + iVar4;

      pcVar6 = unaff_EDI;

      if (param_1[iVar4] == *unaff_EDI) {

        do {

          pcVar1 = pcVar6 + 1;

          pcVar3 = pcVar3 + 1;

          if (*pcVar1 == '\0') {

            return iVar4;

          }

          pcVar6 = pcVar6 + 1;

        } while (*pcVar3 == *pcVar1);

      }

      iVar4 = iVar4 + -1;

    } while( true );

  }

  return -1;

}
