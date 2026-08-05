// =============================================================================
// FUN_0073e9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e9b0
// Address:   0x0073e9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073e9b0 @ 0x0073e9b0
// Stable ID: aa_0073e9b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×1.
//  - Notable callees: FUN_00456720, FUN_00456960, FUN_0073e9b0.
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

void FUN_0073e9b0(int param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  int unaff_ESI;

  

  if (*(char *)(DAT_00d1f048 + 0x12) == '\0') {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

    return;

  }

  piVar1 = (int *)(unaff_ESI + 0x10);

  if ((*(int **)(unaff_ESI + 0x10) == (int *)0x0) || (**(int **)(unaff_ESI + 0x10) != param_1)) {

    for (piVar4 = *(int **)(unaff_ESI + 4); piVar4 != *(int **)(unaff_ESI + 8); piVar4 = piVar4 + 1)

    {

      if (*(int *)*piVar4 == param_1) {

        *piVar1 = *piVar4;

        return;

      }

    }

    piVar4 = (int *)FUN_00456720();

    if (piVar4 == (int *)0x0) {

      piVar4 = (int *)0x0;

    }

    else {

      *piVar4 = param_1;

      piVar2 = piVar4 + 4;

      piVar4[1] = (int)piVar2;

      piVar4[2] = (int)piVar2;

      *piVar2 = 0;

      piVar4[5] = 0;

      piVar4[6] = 0;

      piVar4[7] = 0;

      piVar4[8] = 0;

      piVar4[9] = 0;

      piVar4[10] = 0;

      piVar4[0xb] = 0;

    }

    iVar3 = *(int *)(unaff_ESI + 4);

    *piVar1 = (int)piVar4;

    if ((iVar3 != 0) &&

       ((uint)(*(int *)(unaff_ESI + 8) - iVar3 >> 2) <

        (uint)(*(int *)(unaff_ESI + 0xc) - iVar3 >> 2))) {

      piVar4 = *(int **)(unaff_ESI + 8);

      *piVar4 = *piVar1;

      *(int **)(unaff_ESI + 8) = piVar4 + 1;

      return;

    }

    FUN_00456960(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

  }

  return;

}
