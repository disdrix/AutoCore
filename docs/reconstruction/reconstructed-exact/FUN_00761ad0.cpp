// =============================================================================
// FUN_00761ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00761ad0
// Address:   0x00761ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00761ad0 @ 0x00761ad0
// Stable ID: aa_00761ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×19, for×3, goto×3, return×1.
//  - Notable callees: FUN_00760830×4, FUN_00456960×3, FUN_007633d0×2, FUN_007647c0×2, FUN_004406e0, FUN_00760020, FUN_00760090, FUN_00761ad0.
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

int __thiscall FUN_00761ad0(int param_1,int param_2,int param_3,char param_4,char param_5)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  byte bVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  

  bVar3 = 0;

  if (*(int *)(param_3 + 0x94) == 0) {

    if (param_4 != '\0') {

      piVar8 = *(int **)(param_3 + 0xc4);

      for (piVar7 = *(int **)(param_3 + 0xc0); piVar7 != piVar8; piVar7 = piVar7 + 1) {

        if (((int *)*piVar7)[0x23] == param_2) {

          bVar3 = 1;

          uVar4 = (**(code **)(*(int *)*piVar7 + 0x7c))();

          if ((*(int *)(param_1 + 0xc) == 0) ||

             ((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28 == 0)) {

            FUN_00760830(1);

          }

          iVar6 = *(int *)(param_1 + 0xc);

          iVar1 = *(int *)(iVar6 + 4);

          if ((iVar1 == 0) ||

             ((uint)(*(int *)(iVar6 + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(iVar6 + 8) - iVar1 >> 2)

             )) {

            FUN_00456960(*(uint32_t /* width from decompiler */ *)(iVar6 + 8));

          }

          else {

            puVar2 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

            *puVar2 = uVar4;

            *(uint32_t /* width from decompiler */ **)(iVar6 + 8) = puVar2 + 1;

          }

          FUN_007647c0(uVar4);

        }

      }

    }

    if (param_5 != '\0') {

      piVar7 = *(int **)(param_3 + 0xd4);

      for (piVar8 = *(int **)(param_3 + 0xd0); piVar8 != piVar7; piVar8 = piVar8 + 1) {

        if (((int *)*piVar8)[0x23] == param_2) {

          bVar3 = 1;

          uVar4 = (**(code **)(*(int *)*piVar8 + 0x7c))();

          if ((*(int *)(param_1 + 0xc) == 0) ||

             ((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28 == 0)) {

            FUN_00760830(1);

          }

          iVar6 = *(int *)(param_1 + 0xc);

          iVar1 = *(int *)(iVar6 + 0x14);

          if ((iVar1 == 0) ||

             ((uint)(*(int *)(iVar6 + 0x1c) - iVar1 >> 2) <=

              (uint)(*(int *)(iVar6 + 0x18) - iVar1 >> 2))) {

            FUN_00456960(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x18));

          }

          else {

            puVar2 = *(uint32_t /* width from decompiler */ **)(iVar6 + 0x18);

            *puVar2 = uVar4;

            *(uint32_t /* width from decompiler */ **)(iVar6 + 0x18) = puVar2 + 1;

          }

          FUN_007633d0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),uVar4);

        }

      }

    }

  }

  else {

    if (param_4 != '\0') {

      piVar8 = *(int **)(param_3 + 0xc4);

      for (piVar7 = *(int **)(param_3 + 0xc0); piVar7 != piVar8; piVar7 = piVar7 + 1) {

        if (((int *)*piVar7)[0x23] == param_2) {

          bVar3 = 1;

          uVar4 = (**(code **)(*(int *)*piVar7 + 0x7c))();

          uVar5 = FUN_00760090(*piVar7);

          if ((int)uVar5 < 0) {

            uVar5 = 0;

          }

          if ((*(int *)(param_1 + 0xc) == 0) ||

             ((uint)((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28) <= uVar5)) {

            FUN_00760830(uVar5 + 1);

          }

          iVar6 = *(int *)(param_1 + 0xc) + uVar5 * 0x28;

          iVar1 = *(int *)(iVar6 + 4);

          if ((iVar1 == 0) ||

             ((uint)(*(int *)(iVar6 + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(iVar6 + 8) - iVar1 >> 2)

             )) {

            FUN_00456960(*(uint32_t /* width from decompiler */ *)(iVar6 + 8));

          }

          else {

            puVar2 = *(uint32_t /* width from decompiler */ **)(iVar6 + 8);

            *puVar2 = uVar4;

            *(uint32_t /* width from decompiler */ **)(iVar6 + 8) = puVar2 + 1;

          }

          FUN_007647c0(uVar4);

        }

      }

    }

    if (param_5 != '\0') {

      piVar8 = *(int **)(param_3 + 0xd0);

      piVar7 = *(int **)(param_3 + 0xd4);

joined_r0x00761dc8:

      if (piVar8 != piVar7) {

        if (((int *)*piVar8)[0x23] == param_2) goto code_r0x00761ddf;

        goto LAB_00761e45;

      }

    }

  }

  return bVar3 - 1;

code_r0x00761ddf:

  bVar3 = 1;

  uVar4 = (**(code **)(*(int *)*piVar8 + 0x7c))();

  iVar6 = FUN_00760020(*piVar8);

  if ((iVar6 < 0) || (iVar6 == 0)) {

    if ((*(int *)(param_1 + 0xc) == 0) ||

       ((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28 == 0)) {

      FUN_00760830(1);

    }

    FUN_004406e0();

    FUN_007633d0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),uVar4);

LAB_00761e45:

    piVar8 = piVar8 + 1;

  }

  goto joined_r0x00761dc8;

}
