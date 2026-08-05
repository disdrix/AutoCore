// =============================================================================
// FUN_007fea50
// -----------------------------------------------------------------------------
// Stable ID: aa_007fea50
// Address:   0x007fea50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fea50 @ 0x007fea50
// Stable ID: aa_007fea50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_007fea50.
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

void FUN_007fea50(void)



{

  char cVar1;

  int unaff_EBX;

  int iVar2;

  int *piVar3;

  char *pcVar4;

  

  pcVar4 = (char *)(unaff_EBX + 0x5c);

  piVar3 = (int *)(unaff_EBX + 0x1030);

  iVar2 = 0x3a;

  do {

    if ((*pcVar4 != '\0') && (*piVar3 != 0)) {

      cVar1 = (**(code **)(*(int *)*piVar3 + 0x3d8))();

      if ((cVar1 != '\0') && (*pcVar4 != '\0')) {

        (**(code **)(*(int *)*piVar3 + 4))(1);

      }

    }

    piVar3 = piVar3 + 1;

    pcVar4 = pcVar4 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  if (*(int *)(unaff_EBX + 0x1164) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_EBX + 0x1164) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_EBX + 0x1164) + 4))(1);

    }

  }

  if (((*(int **)(unaff_EBX + 0xf40) != (int *)0x0) &&

      (iVar2 = *(int *)(unaff_EBX + 0xf38), **(int **)(unaff_EBX + 0xf40) == iVar2)) && (iVar2 != 0)

     ) {

    if (*(int *)(iVar2 + 0xcb0) != 0) {

      (**(code **)(**(int **)(iVar2 + 0xcb0) + 4))(1);

    }

    if (*(int *)(*(int *)(unaff_EBX + 0xf38) + 0xcc0) != 0) {

      piVar3 = *(int **)(*(int *)(unaff_EBX + 0xf38) + 0xcc0);

      (**(code **)(*piVar3 + 0x444))(piVar3[0x158]);

    }

  }

  return;

}
