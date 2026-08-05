// =============================================================================
// FUN_0074dfd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074dfd0
// Address:   0x0074dfd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074dfd0 @ 0x0074dfd0
// Stable ID: aa_0074dfd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_0073e480, FUN_0074dfd0.
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

uint32_t /* width from decompiler */ FUN_0074dfd0(int param_1)



{

  int *piVar1;

  code *pcVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  

  if ((*(int *)(param_1 + 0x3c) != 0) && (*(char *)(*(int *)(param_1 + 0x3c) + 0xd0) != '\0')) {

    iVar4 = 0;

    if (0 < *DAT_00d1f62c) {

      iVar5 = 0;

      piVar3 = DAT_00d1f62c;

      do {

        if ((*(int *)(param_1 + 0x3c) == 0) || (*(int *)(*(int *)(param_1 + 0x3c) + 0xd8) != iVar4))

        {

          if (*(int *)(DAT_00d1f05c + 4) != 0) {

            piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

            (**(code **)(*piVar1 + 0x50))(piVar1,piVar3[iVar4 + 0x2d],&g_flZero,0xffffffff);

            piVar3 = DAT_00d1f62c;

          }

          (&DAT_00d1a56c)[iVar4] = 0;

          pcVar2 = *(code **)(iVar5 + 0x28 + (int)piVar3);

          if (pcVar2 != (code *)0x0) {

            (*pcVar2)(0);

            piVar3 = DAT_00d1f62c;

          }

        }

        else {

          if (*(int *)(DAT_00d1f05c + 4) != 0) {

            piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

            (**(code **)(*piVar1 + 0x50))(piVar1,piVar3[iVar4 + 0x2d],&DAT_00aa0464,0xffffffff);

            piVar3 = DAT_00d1f62c;

          }

          (&DAT_00d1a56c)[iVar4] = 1;

        }

        iVar4 = iVar4 + 1;

        iVar5 = iVar5 + 0x2c;

      } while (iVar4 < *piVar3);

    }

    (**(code **)(**(int **)(param_1 + 0x3c) + 0x3c))(0);

    (**(code **)(**(int **)(param_1 + 0x3c) + 0x38))();

    FUN_0073e480();

    return 1;

  }

  return 0;

}
