// =============================================================================
// FUN_007272f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007272f0
// Address:   0x007272f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007272f0 @ 0x007272f0
// Stable ID: aa_007272f0
// Embedded strings (evidence for future rename):
//   - "_lxx.ogg"
//   - ".ogg"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×7, do×4, while×4, return×3, for×2, goto×1.
//  - Notable callees: FUN_007b6a20×2, FUN_00726850, FUN_007272f0, FUN_007b69e0, FUN_007b6f90.
//  - Strings: "_lxx.ogg"; ".ogg".
//  - Return sites: 3.

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

void FUN_007272f0(int param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  uint uVar6;

  int *piVar7;

  int *piVar8;

  char *pcVar9;

  char *pcVar10;

  char local_105;

  char local_104 [260];

  

  piVar7 = (int *)**(int **)(param_1 + 0x314);

  if (piVar7 != *(int **)(param_1 + 0x314)) {

    do {

      pcVar1 = (char *)piVar7[2];

      iVar3 = *(int *)(pcVar1 + 0x158);

      if (iVar3 < 6) {

        pcVar4 = pcVar1;

        do {

          cVar2 = *pcVar4;

          pcVar4[(int)(local_104 + -(int)pcVar1)] = cVar2;

          pcVar4 = pcVar4 + 1;

        } while (cVar2 != '\0');

        pcVar5 = "_lxx.ogg";

        pcVar4 = pcVar5;

        if (*(char *)(param_1 + 0x308) == '\0') {

          pcVar5 = ".ogg";

          pcVar4 = pcVar5;

        }

        do {

          cVar2 = *pcVar5;

          pcVar5 = pcVar5 + 1;

        } while (cVar2 != '\0');

        pcVar10 = &local_105;

        do {

          pcVar9 = pcVar10 + 1;

          pcVar10 = pcVar10 + 1;

        } while (*pcVar9 != '\0');

        pcVar9 = pcVar4;

        for (uVar6 = (uint)((int)pcVar5 - (int)pcVar4) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar9;

          pcVar9 = pcVar9 + 4;

          pcVar10 = pcVar10 + 4;

        }

        for (uVar6 = (int)pcVar5 - (int)pcVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

          *pcVar10 = *pcVar9;

          pcVar9 = pcVar9 + 1;

          pcVar10 = pcVar10 + 1;

        }

        FUN_007b6a20();

        cVar2 = FUN_007b6f90();

        if (cVar2 == '\0') {

          iVar3 = *(int *)(pcVar1 + 0x158);

          if (0 < iVar3) goto LAB_0072731f;

          pcVar1[0x158] = '\b';

          pcVar1[0x159] = '\0';

          pcVar1[0x15a] = '\0';

          pcVar1[0x15b] = '\0';

          FUN_007b6a20();

          FUN_007b69e0();

          piVar8 = (int *)*piVar7;

        }

        else {

          local_105 = FUN_00726850(param_1);

          *(char **)pcVar1 = DAT_00d219e8;

          piVar8 = (int *)*piVar7;

          DAT_00d219e8 = pcVar1;

          if (piVar7 != *(int **)(param_1 + 0x314)) {

            *(int **)piVar7[1] = piVar8;

            *(int *)(*piVar7 + 4) = piVar7[1];

                    /* WARNING: Subroutine does not return */

            operator_delete(piVar7);

          }

          if (local_105 != '\0') {

            return;

          }

        }

      }

      else {

LAB_0072731f:

        *(int *)(pcVar1 + 0x158) = iVar3 + -1;

        piVar8 = (int *)*piVar7;

      }

      piVar7 = piVar8;

    } while (piVar8 != *(int **)(param_1 + 0x314));

  }

  return;

}
