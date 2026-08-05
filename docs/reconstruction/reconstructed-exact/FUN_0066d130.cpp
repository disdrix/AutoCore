// =============================================================================
// FUN_0066d130
// -----------------------------------------------------------------------------
// Stable ID: aa_0066d130
// Address:   0x0066d130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066d130 @ 0x0066d130
// Stable ID: aa_0066d130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×17, do×6, while×6, goto×3, return×1.
//  - Notable callees: FUN_00507310×3, FUN_00507210×2, FUN_005b3300, FUN_0066d130.
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

void __thiscall FUN_0066d130(int param_1,int *param_2)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int iVar8;

  

  iVar5 = 0;

  if (0 < *(int *)(param_1 + 0x20)) {

    iVar6 = param_1 + 0x18;

    do {

      iVar8 = *(int *)(*(int *)(param_1 + 0x1c) + iVar5 * 8);

      iVar2 = *(int *)(iVar8 + 0x80);

      iVar3 = 0;

      if (0 < iVar2) {

        piVar7 = *(int **)(iVar8 + 0x7c);

        do {

          if (*piVar7 == iVar6) {

            if (-1 < iVar3) {

              FUN_00507210(iVar6);

            }

            break;

          }

          iVar3 = iVar3 + 1;

          piVar7 = piVar7 + 1;

        } while (iVar3 < iVar2);

      }

      iVar8 = *(int *)(*(int *)(param_1 + 0x1c) + 4 + iVar5 * 8);

      iVar2 = *(int *)(iVar8 + 0x80);

      iVar3 = 0;

      if (0 < iVar2) {

        piVar7 = *(int **)(iVar8 + 0x7c);

        do {

          if (*piVar7 == iVar6) {

            if (-1 < iVar3) {

              FUN_00507210(iVar6);

            }

            break;

          }

          iVar3 = iVar3 + 1;

          piVar7 = piVar7 + 1;

        } while (iVar3 < iVar2);

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_1 + 0x20));

  }

  iVar5 = param_2[1];

  uVar4 = *(uint *)(param_1 + 0x24) & 0x7fffffff;

  if ((int)uVar4 < iVar5) {

    iVar6 = uVar4 * 2;

    if (iVar6 <= iVar5) {

      iVar6 = iVar5;

    }

    FUN_005b3300((int *)(param_1 + 0x1c),iVar6,8);

  }

  iVar6 = 0;

  *(int *)(param_1 + 0x20) = iVar5;

  if (0 < iVar5) {

    iVar8 = param_1 + 0x18;

    do {

      uVar4 = *(uint *)(*param_2 + iVar6 * 4);

      puVar1 = (uint *)(*(int *)(param_1 + 0x1c) + iVar6 * 8);

      if (*(uint *)(param_2[3] + iVar6 * 4) < uVar4) {

        *puVar1 = uVar4;

        puVar1[1] = *(uint *)(param_2[3] + iVar6 * 4);

      }

      else {

        puVar1[1] = uVar4;

        *puVar1 = *(uint *)(param_2[3] + iVar6 * 4);

      }

      iVar2 = *(int *)(*puVar1 + 0x80);

      iVar3 = 0;

      if (iVar2 < 1) {

LAB_0066d26a:

        FUN_00507310(iVar8);

      }

      else {

        piVar7 = *(int **)(*puVar1 + 0x7c);

        do {

          if (*piVar7 == iVar8) {

            if (-1 < iVar3) goto LAB_0066d27a;

            goto LAB_0066d26a;

          }

          iVar3 = iVar3 + 1;

          piVar7 = piVar7 + 1;

        } while (iVar3 < iVar2);

        FUN_00507310(iVar8);

      }

LAB_0066d27a:

      iVar2 = *(int *)(puVar1[1] + 0x80);

      iVar3 = 0;

      if (0 < iVar2) {

        piVar7 = *(int **)(puVar1[1] + 0x7c);

        do {

          if (*piVar7 == iVar8) {

            if (-1 < iVar3) goto LAB_0066d2b2;

            break;

          }

          iVar3 = iVar3 + 1;

          piVar7 = piVar7 + 1;

        } while (iVar3 < iVar2);

      }

      FUN_00507310(iVar8);

LAB_0066d2b2:

      iVar6 = iVar6 + 1;

    } while (iVar6 < iVar5);

  }

  return;

}
