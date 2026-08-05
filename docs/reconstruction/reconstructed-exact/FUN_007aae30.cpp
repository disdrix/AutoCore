// =============================================================================
// FUN_007aae30
// -----------------------------------------------------------------------------
// Stable ID: aa_007aae30
// Address:   0x007aae30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007aae30 @ 0x007aae30
// Stable ID: aa_007aae30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, goto×2, do×1, while×1.
//  - Notable callees: FUN_007aae30.
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

uint32_t /* width from decompiler */ __fastcall FUN_007aae30(int *param_1)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  int local_8;

  int iStack_4;

  

  piVar3 = (int *)(**(code **)(*param_1 + 0x120))(&local_8,1,1);

  iVar8 = *piVar3 + param_1[0x5c] / 2;

  iVar6 = piVar3[1] + param_1[0x5d] / 2;

  if ((param_1[0xa3] == 0) && (param_1[0x83] != 0)) {

    iVar4 = (**(code **)(*param_1 + 0x210))();

    param_1[0xa3] = iVar4;

  }

  iVar4 = param_1[0xa3];

  if (((iVar4 != 0) && (*(int *)(iVar4 + 0x84) != 0)) &&

     (*(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x84) >> 7 != 0)) {

    iVar4 = 0;

    (**(code **)(*param_1 + 0x26c))();

    iVar1 = param_1[0xa3];

    piVar3 = *(int **)(iVar1 + 0x84);

    if (piVar3 != *(int **)(iVar1 + 0x88)) {

      piVar9 = piVar3 + 4;

      do {

        if ((piVar9[4] == 0) && (piVar9[8] != 0)) {

          if ((((*piVar3 + iVar8 <= local_8) && (iVar6 + piVar9[-3] <= iStack_4)) &&

              (local_8 <= piVar9[0x11] + piVar9[0xb] + piVar9[9] + *piVar3 + iVar8)) &&

             (iStack_4 <= piVar9[0x12] + piVar9[0xc] + piVar9[10] + piVar9[-3] + iVar6)) {

LAB_007aaf68:

            if ((char)piVar3[0x18] == '\0') {

              return 0;

            }

            (**(code **)(*param_1 + 800))

                      ((char)piVar3[0x18],piVar3[0x1a],piVar3[0x1b],piVar3[0x1c],piVar3[0x1d],

                       piVar3[0x1e]);

            return 1;

          }

        }

        else if (piVar9[6] != 0) {

          if (iVar8 + *piVar3 <= local_8) {

            iVar7 = iVar6 + piVar9[-3];

            if ((iVar7 <= iStack_4) &&

               (iStack_4 <= piVar9[-3] + *(int *)(*(int *)piVar9[6] + 0x7c) + iVar6)) {

              piVar5 = piVar9;

              if (7 < (uint)piVar9[5]) {

                piVar5 = (int *)*piVar9;

              }

              cVar2 = (**(code **)(*param_1 + 0x284))

                                (iVar8 + *piVar3,iVar7,piVar5,local_8,iStack_4,&stack0xffffffe0,

                                 iVar4);

              if (cVar2 != '\0') goto LAB_007aaf68;

              if ((char)piVar9[0x14] != '\0') {

                iVar4 = iVar4 + 1;

              }

              goto LAB_007ab02f;

            }

          }

          iVar4 = iVar4 + piVar9[4];

        }

LAB_007ab02f:

        piVar3 = piVar3 + 0x20;

        piVar9 = piVar9 + 0x20;

      } while (piVar3 != *(int **)(iVar1 + 0x88));

    }

  }

  return 0;

}
