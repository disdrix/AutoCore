// =============================================================================
// FUN_007fc490
// -----------------------------------------------------------------------------
// Stable ID: aa_007fc490
// Address:   0x007fc490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fc490 @ 0x007fc490
// Stable ID: aa_007fc490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_007fc490.
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

void FUN_007fc490(int param_1)



{

  int *piVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  

  if (((*(int *)(param_1 + 0x111c) != 0) && (*(int *)(param_1 + 0xf40) != 0)) &&

     (cVar2 = (**(code **)(**(int **)(param_1 + 0x111c) + 0x3d8))(), cVar2 != '\0')) {

    if (**(int **)(param_1 + 0xf40) != 0) {

      (**(code **)(*(int *)**(int **)(param_1 + 0xf40) + 0xb0))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x111c));

    }

    (**(code **)(**(int **)(param_1 + 0x111c) + 0x440))();

    if (*(int *)(param_1 + 0xf38) != 0) {

      iVar4 = 0;

      piVar3 = (int *)(param_1 + 0x1030);

      while (((iVar4 == 0x16 || (piVar1 = (int *)*piVar3, piVar1 == (int *)0x0)) ||

             ((cVar2 = (**(code **)(*piVar1 + 0x3d8))(), cVar2 == '\0' || (piVar1[0x140] != 1))))) {

        iVar4 = iVar4 + 1;

        piVar3 = piVar3 + 1;

        if (0x39 < iVar4) {

                    /* WARNING: Could not recover jumptable at 0x007fc548. Too many branches */

                    /* WARNING: Treating indirect jump as call */

          (**(code **)(**(int **)(param_1 + 0xf38) + 0x3c4))();

          return;

        }

      }

    }

  }

  return;

}
