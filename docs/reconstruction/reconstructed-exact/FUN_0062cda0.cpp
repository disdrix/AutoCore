// =============================================================================
// FUN_0062cda0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062cda0
// Address:   0x0062cda0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062cda0 @ 0x0062cda0
// Stable ID: aa_0062cda0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, for×1, while×1.
//  - Notable callees: FUN_005b3370, FUN_0062bca0, FUN_0062cda0.
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

void __thiscall FUN_0062cda0(int param_1,int *param_2,int *param_3)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  uint *puVar7;

  uint *puVar8;

  uint uVar9;

  int *piVar10;

  uint uVar11;

  

  piVar3 = DAT_00b05060;

  iVar2 = *(int *)(param_1 + 0x44);

  piVar1 = DAT_00b05060 + 3;

  uVar11 = ((iVar2 >> 5) + 8) * 4 + 0xfU & 0xfffffff0;

  if (*piVar1 < (int)uVar11) {

    puVar7 = (uint *)(**(code **)(*DAT_00b05060 + 0x24))(uVar11);

  }

  else {

    puVar7 = (uint *)DAT_00b05060[2];

    DAT_00b05060[2] = (int)puVar7 + uVar11;

    piVar3[3] = *piVar1 - uVar11;

  }

  piVar1 = (int *)(*(int *)(param_1 + 0x40) + *param_2 * 0x1c);

  FUN_0062bca0(iVar2,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x4c) + piVar1[4] * 8),piVar1,*param_2,

               puVar7);

  iVar2 = *(int *)(param_1 + 0x44);

  piVar3 = *(int **)(param_1 + 0x40);

  piVar10 = DAT_00b05060;

  for (puVar8 = puVar7; DAT_00b05060 = piVar10, puVar8 < puVar7 + (iVar2 >> 5) + 1;

      puVar8 = puVar8 + 1) {

    uVar9 = *puVar8;

    piVar10 = piVar3;

    while (uVar9 != 0) {

      if ((char)uVar9 == '\0') {

        piVar10 = piVar10 + 0x38;

        uVar9 = uVar9 >> 8;

      }

      else {

        if ((((uVar9 & 1) != 0) &&

            (-1 < (piVar1[3] - piVar10[1] | piVar10[3] - piVar1[1] | piVar1[2] - *piVar10 |

                  piVar10[2] - *piVar1))) && (uVar4 = piVar10[6], (uVar4 & 1) == 0)) {

          if (param_3[1] == (param_3[2] & 0x7fffffffU)) {

            FUN_005b3370(param_3,8);

          }

          iVar5 = param_3[1];

          iVar6 = *param_3;

          *(int **)(iVar6 + iVar5 * 8) = param_2;

          *(uint *)(iVar6 + 4 + iVar5 * 8) = uVar4;

          param_3[1] = param_3[1] + 1;

        }

        piVar10 = piVar10 + 7;

        uVar9 = uVar9 >> 1;

      }

    }

    piVar3 = piVar3 + 0xe0;

    piVar10 = DAT_00b05060;

  }

  if ((uVar11 != 0) && ((puVar7 == (uint *)piVar10[5] || ((uint *)piVar10[5] == (uint *)0x0)))) {

    (**(code **)(*piVar10 + 0x28))(puVar7,uVar11);

    return;

  }

  piVar10[2] = piVar10[2] - uVar11;

  piVar10[3] = piVar10[3] + uVar11;

  return;

}
