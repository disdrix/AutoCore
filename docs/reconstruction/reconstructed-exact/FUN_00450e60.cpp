// =============================================================================
// FUN_00450e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00450e60
// Address:   0x00450e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00450e60 @ 0x00450e60
// Stable ID: aa_00450e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0044c150, FUN_00450e60, FUN_00988b50.
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

void FUN_00450e60(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 4) == 0) {

    piVar3 = (int *)FUN_0044c150();

    if (piVar3 == (int *)0x0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3[1] = 0;

      piVar3[2] = 0;

      piVar3[3] = 0;

      *piVar3 = (int)&PTR_FUN_00aa213c;

      piVar3[4] = 0;

      piVar3[5] = 2;

      piVar3[6] = 0;

      piVar3[7] = 0;

      piVar3[8] = 0;

      piVar3[9] = 0;

    }

    if ((piVar3 != (int *)0x0) && (piVar3[1] = piVar3[1] + 1, piVar3[1] == 1)) {

      (**(code **)(*piVar3 + 4))();

    }

    piVar2 = *(int **)(unaff_EDI + 4);

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *(int **)(unaff_EDI + 4) = piVar3;

  }

  FUN_00988b50(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 4),*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_4);

  return;

}
