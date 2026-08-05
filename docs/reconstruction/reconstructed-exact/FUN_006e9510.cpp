// =============================================================================
// FUN_006e9510
// -----------------------------------------------------------------------------
// Stable ID: aa_006e9510
// Address:   0x006e9510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e9510 @ 0x006e9510
// Stable ID: aa_006e9510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, goto×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_006e9510.
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

void __thiscall FUN_006e9510(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,int *param_4)



{

  int iVar1;

  char *pcVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int *piVar7;

  int iVar8;

  int *unaff_EDI;

  int iVar9;

  int *apiStack_140 [2];

  int iStack_138;

  uint32_t /* width from decompiler */ uStack_134;

  int *local_130;

  uint32_t /* width from decompiler */ uStack_128;

  int iStack_124;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ *local_114;

  uint8_t auStack_110 [268];

  

  local_118 = param_2[2];

  piVar7 = (int *)*param_2;

  local_114 = param_2;

  local_130 = piVar7;

  uStack_134 = (**(code **)(*piVar7 + 0x28))();

  iVar1 = (**(code **)(*piVar7 + 0x2c))();

  if (0 < uStack_134) {

    do {

      iVar9 = iVar1;

      iStack_138 = iVar1;

      uStack_128 = (**(code **)(*piVar7 + 0x34))(iVar1,auStack_110);

      iVar8 = 0;

      if (0 < *(int *)(param_1 + 0x10)) {

        piVar7 = *(int **)(param_1 + 0xc);

        do {

          if (*piVar7 == iVar1) goto LAB_006e9597;

          iVar8 = iVar8 + 1;

          piVar7 = piVar7 + 2;

        } while (iVar8 < *(int *)(param_1 + 0x10));

      }

      iVar8 = -1;

LAB_006e9597:

      iStack_124 = iVar1;

      pcVar2 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)param_4[1])

                                 ((int)&uStack_134 + 3,param_4,param_3,param_2,iStack_138,

                                  apiStack_140[0]);

      if (*pcVar2 == '\0') {

        if (iVar8 != -1) {

          (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + 4 + iVar8 * 8) + 0x14))();

          iVar6 = *(int *)(param_1 + 0x10) + -1;

          *(int *)(param_1 + 0x10) = iVar6;

          iVar1 = *(int *)(param_1 + 0xc);

          *(uint32_t /* width from decompiler */ *)(iVar1 + iVar8 * 8) = *(uint32_t /* width from decompiler */ *)(iVar1 + iVar6 * 8);

          *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar8 * 8) = *(uint32_t /* width from decompiler */ *)(iVar1 + 4 + iVar6 * 8);

        }

      }

      else if (iVar8 == -1) {

        piVar7 = (int *)(param_1 + 0xc);

        if (*(uint *)(param_1 + 0x10) == (*(uint *)(param_1 + 0x14) & 0x7fffffff)) {

          FUN_005b3370(piVar7,8);

        }

        iVar1 = *(int *)(param_1 + 0x10) + 1;

        *(int *)(param_1 + 0x10) = iVar1;

        *(int *)(*piVar7 + -8 + iVar1 * 8) = iVar9;

        uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

        iVar1 = *param_4;

        iVar3 = (**(code **)(*apiStack_140[0] + 0x14))();

        iVar4 = (**(code **)(*(int *)*param_3 + 0x14))();

        iVar8 = *(int *)(param_1 + 0x10);

        iVar6 = *piVar7;

        uVar5 = (**(code **)(iVar1 + 0x18c + (iVar3 * 0x20 + iVar4) * 4))

                          (apiStack_140,param_3,param_4,uVar5);

        *(uint32_t /* width from decompiler */ *)(iVar6 + iVar8 * 8 + -4) = uVar5;

      }

      else {

        (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + 4 + iVar8 * 8) + 0x1c))

                  (apiStack_140,param_3,param_4);

      }

      iVar1 = (**(code **)(*unaff_EDI + 0x30))(iVar9);

      uStack_134 = uStack_134 + -1;

      piVar7 = local_130;

    } while (uStack_134 != 0);

  }

  return;

}
