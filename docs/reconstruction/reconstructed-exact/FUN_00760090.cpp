// =============================================================================
// FUN_00760090
// -----------------------------------------------------------------------------
// Stable ID: aa_00760090
// Address:   0x00760090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00760090 @ 0x00760090
// Stable ID: aa_00760090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, return×2, do×1.
//  - Notable callees: FUN_00760090.
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

int FUN_00760090(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int unaff_ESI;

  int iVar4;

  

  iVar3 = 0;

  iVar4 = 0;

  while( true ) {

    if (*(int *)(unaff_ESI + 0xc) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = (*(int *)(unaff_ESI + 0x10) - *(int *)(unaff_ESI + 0xc)) / 0x28;

    }

    if (iVar1 <= iVar3) break;

    iVar1 = *(int *)(unaff_ESI + 0xc) + iVar4;

    piVar2 = *(int **)(iVar1 + 4);

    if (piVar2 != *(int **)(iVar1 + 8)) {

      do {

        if (param_1 == *piVar2) {

          return iVar3;

        }

        piVar2 = piVar2 + 1;

      } while (piVar2 != *(int **)(iVar1 + 8));

    }

    iVar3 = iVar3 + 1;

    iVar4 = iVar4 + 0x28;

  }

  return -1;

}
