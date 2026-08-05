// =============================================================================
// FUN_004c8610
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8610
// Address:   0x004c8610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c8610 @ 0x004c8610
// Stable ID: aa_004c8610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×7, while×5, do×1, return×1.
//  - Notable callees: FUN_004c8610, FUN_004cb740.
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

void __thiscall FUN_004c8610(int param_1,char param_2)



{

  char cVar1;

  int iVar2;

  char cVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  

  cVar3 = param_2;

  piVar7 = (int *)**(int **)(param_1 + 0x158);

  if (piVar7 != *(int **)(param_1 + 0x158)) {

    do {

      iVar2 = piVar7[8];

      iVar6 = (int)((float)iVar2 * DAT_00aaa680);

      piVar7[8] = iVar6;

      piVar8 = piVar7;

      if ((cVar3 == '\0') && (iVar6 != iVar2)) {

        if (*(char *)((int)piVar7 + 0x29) == '\0') {

          piVar8 = (int *)piVar7[2];

          if (*(char *)((int)piVar8 + 0x29) == '\0') {

            cVar1 = *(char *)(*piVar8 + 0x29);

            piVar7 = (int *)*piVar8;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar7 + 0x29);

              piVar8 = piVar7;

              piVar7 = (int *)*piVar7;

            }

          }

          else {

            cVar1 = *(char *)(piVar7[1] + 0x29);

            piVar4 = (int *)piVar7[1];

            while ((piVar8 = piVar4, cVar1 == '\0' && (piVar7 == (int *)piVar8[2]))) {

              cVar1 = *(char *)(piVar8[1] + 0x29);

              piVar4 = (int *)piVar8[1];

              piVar7 = piVar8;

            }

          }

        }

      }

      else {

        iVar2 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

        if ((piVar7[4] == *(int *)(iVar2 + 0x44)) &&

           ((piVar7[5] == *(int *)(iVar2 + 0x48) &&

            ((char)piVar7[6] == (char)*(uint32_t /* width from decompiler */ *)(iVar2 + 0x4c))))) {

          (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 600))

                    (DAT_009cb8c0,DAT_009cb8c4,DAT_009cb8c8,DAT_009cb8cc);

        }

        if (*(char *)((int)piVar7 + 0x29) == '\0') {

          piVar8 = (int *)piVar7[2];

          if (*(char *)((int)piVar8 + 0x29) == '\0') {

            cVar1 = *(char *)(*piVar8 + 0x29);

            piVar4 = (int *)*piVar8;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar4 + 0x29);

              piVar8 = piVar4;

              piVar4 = (int *)*piVar4;

            }

          }

          else {

            cVar1 = *(char *)(piVar7[1] + 0x29);

            piVar5 = (int *)piVar7[1];

            piVar4 = piVar7;

            while ((piVar8 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar8[2]))) {

              cVar1 = *(char *)(piVar8[1] + 0x29);

              piVar5 = (int *)piVar8[1];

              piVar4 = piVar8;

            }

          }

        }

        FUN_004cb740(&param_2,piVar7);

      }

      piVar7 = piVar8;

    } while (piVar8 != *(int **)(param_1 + 0x158));

  }

  return;

}
