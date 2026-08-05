// =============================================================================
// FUN_00655040
// -----------------------------------------------------------------------------
// Stable ID: aa_00655040
// Address:   0x00655040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00655040 @ 0x00655040
// Stable ID: aa_00655040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~226 non-empty decompiler lines.
//  - Control keywords: if×21, do×7, while×7, return×1.
//  - Notable callees: SQRT×3, FUN_005b3300×2, FUN_0065f500×2, FUN_005d6ae0, FUN_00652e80, FUN_00655040, FUN_0065ebe0.
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

void __fastcall FUN_00655040(int param_1)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  float fVar10;

  int local_cc;

  int local_c8;

  uint32_t /* width from decompiler */ *local_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  int iStack_b0;

  uint uStack_ac;

  uint32_t /* width from decompiler */ uStack_a8;

  float fStack_a4;

  uint32_t /* width from decompiler */ uStack_a0;

  uint32_t /* width from decompiler */ uStack_9c;

  uint32_t /* width from decompiler */ uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint32_t /* width from decompiler */ uStack_74;

  uint32_t /* width from decompiler */ *puStack_70;

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  float afStack_40 [5];

  float fStack_2c;

  float fStack_18;

  

  uVar2 = *(uint *)(param_1 + 8);

  if (*(int *)(param_1 + 0x14) < (int)uVar2) {

    iVar5 = *(int *)(param_1 + 0x14);

    piVar1 = (int *)(param_1 + 0x10);

    if ((int)uVar2 < iVar5) {

      iVar6 = uVar2 * 0x70;

      iVar5 = iVar5 - uVar2;

      do {

        (*(code *)**(uint32_t /* width from decompiler */ **)(*piVar1 + iVar6))(0);

        iVar6 = iVar6 + 0x70;

        iVar5 = iVar5 + -1;

      } while (iVar5 != 0);

    }

    else {

      uVar3 = *(uint *)(param_1 + 0x18);

      if ((int)(uVar3 & 0x7fffffff) < (int)uVar2) {

        uVar4 = (uVar3 & 0x7fffffff) * 2;

        if ((int)uVar4 <= (int)uVar2) {

          uVar4 = uVar2;

        }

        local_c0 = (uint32_t /* width from decompiler */ *)*piVar1;

        *piVar1 = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0x80000000;

        if (0 < (int)uVar4) {

          FUN_005b3300(piVar1,((int)uVar4 < 0) - 1 & uVar4,0x70);

        }

        iVar6 = *piVar1;

        if (0 < iVar5) {

          puVar8 = local_c0 + 0x1b;

          puVar7 = (uint32_t /* width from decompiler */ *)(iVar6 + 100);

          local_cc = iVar5;

          do {

            if (puVar7 != (uint32_t /* width from decompiler */ *)0x64) {

              FUN_00652e80(puVar8 + -0x1b);

              puVar7[-0x19] = &PTR_FUN_009e5db0;

              puVar7[-1] = puVar8[-3];

              *puVar7 = *(uint32_t /* width from decompiler */ *)(((int)local_c0 - iVar6) + (int)puVar7);

              puVar7[1] = puVar8[-1];

              puVar7[2] = *puVar8;

            }

            puVar7 = puVar7 + 0x1c;

            puVar8 = puVar8 + 0x1c;

            local_cc = local_cc + -1;

          } while (local_cc != 0);

        }

        puVar8 = local_c0;

        local_c8 = iVar5;

        if (0 < iVar5) {

          do {

            (**(code **)*puVar8)(0);

            local_c8 = local_c8 + -1;

            puVar8 = puVar8 + 0x1c;

          } while (local_c8 != 0);

        }

        if (-1 < (int)uVar3) {

          (**(code **)(*DAT_00b05060 + 0x14))(local_c0,(uVar3 & 0x7fffffff) * 0x70,0x12);

        }

      }

      else if (iVar5 < (int)uVar2) {

        iVar6 = iVar5 * 0x70 + *piVar1;

        iVar9 = uVar2 - iVar5;

        do {

          if (iVar6 != 0) {

            FUN_0065f500();

          }

          iVar6 = iVar6 + 0x70;

          iVar9 = iVar9 + -1;

        } while (iVar9 != 0);

      }

      if (iVar5 < (int)uVar2) {

        iVar6 = iVar5 * 0x70 + *(int *)(param_1 + 0x10);

        iVar5 = uVar2 - iVar5;

        do {

          if (iVar6 != 0) {

            FUN_0065f500();

          }

          iVar6 = iVar6 + 0x70;

          iVar5 = iVar5 + -1;

        } while (iVar5 != 0);

      }

    }

    *(uint *)(param_1 + 0x14) = uVar2;

  }

  iVar5 = 0;

  if (0 < *(int *)(param_1 + 8)) {

    do {

      fVar10 = *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + iVar5 * 4) + 0x3c) + 0x2c);

      if ((fVar10 != 0.0) && (fVar10 = g_flOne / fVar10, fVar10 != 0.0)) {

        (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + iVar5 * 4) + 0x3c) + 0x24))

                  (afStack_40);

        fVar10 = g_flOne / fVar10;

        fStack_a4 = ((afStack_40[0] - fStack_2c) + fStack_18) * fVar10 * DAT_00aaa8dc;

        if (0.0 <= fStack_a4) {

          fStack_5c = SQRT(fStack_a4);

        }

        else {

          fStack_5c = 0.0;

        }

        fStack_58 = afStack_40[0] * fVar10 * DAT_00aaaad0 - fStack_a4;

        if (0.0 <= fStack_58) {

          fStack_58 = SQRT(fStack_58);

        }

        else {

          fStack_58 = 0.0;

        }

        fStack_a4 = fStack_18 * fVar10 * DAT_00aaaad0 - fStack_a4;

        if (0.0 <= fStack_a4) {

          fStack_60 = SQRT(fStack_a4);

        }

        else {

          fStack_60 = 0.0;

        }

        uStack_54 = 0;

        fStack_60 = fStack_60 * DAT_009e5dbc;

        piVar1 = (int *)(*(int *)(param_1 + 4) + iVar5 * 4);

        fStack_5c = fStack_5c * DAT_009e5dbc;

        fStack_58 = fStack_58 * DAT_009e5dbc;

        iVar6 = *(int *)(*piVar1 + 0x3c);

        uStack_a0 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x80);

        uStack_9c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x84);

        uStack_98 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x88);

        uStack_94 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x8c);

        uStack_90 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x90);

        uStack_8c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x94);

        uStack_88 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x98);

        uStack_84 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x9c);

        uStack_80 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0xa0);

        uStack_7c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0xa4);

        uStack_78 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0xa8);

        uStack_74 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0xac);

        puStack_70 = *(uint32_t /* width from decompiler */ **)(iVar6 + 0xb0);

        fStack_6c = *(float *)(iVar6 + 0xb4);

        fStack_68 = *(float *)(iVar6 + 0xb8);

        fStack_64 = *(float *)(iVar6 + 0xbc);

        iVar6 = *(int *)(*piVar1 + 0x3c);

        uStack_50 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x20);

        uStack_4c = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x24);

        uStack_48 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x28);

        uStack_44 = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x2c);

        FUN_005d6ae0(&uStack_a0,&uStack_50);

        local_c0 = (uint32_t /* width from decompiler */ *)((float)puStack_70 + (float)local_c0);

        fStack_bc = fStack_6c + fStack_bc;

        fStack_b8 = fStack_68 + fStack_b8;

        fStack_b4 = fStack_64 + fStack_b4;

        puStack_70 = local_c0;

        fStack_6c = fStack_bc;

        fStack_68 = fStack_b8;

        fStack_64 = fStack_b4;

        FUN_0065ebe0(&fStack_60,&uStack_a0);

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_1 + 8));

  }

  uVar2 = *(uint *)(param_1 + 0x14);

  iStack_b0 = 0;

  uStack_ac = 0;

  uStack_a8 = 0x80000000;

  if (0 < (int)uVar2) {

    FUN_005b3300(&iStack_b0,((int)uVar2 < 0) - 1 & uVar2,4);

  }

  iVar5 = *(int *)(param_1 + 0x14) + -1;

  if (-1 < iVar5) {

    iVar6 = iVar5 * 0x70;

    do {

      *(int *)(iStack_b0 + iVar5 * 4) = *(int *)(param_1 + 0x10) + iVar6;

      iVar5 = iVar5 + -1;

      iVar6 = iVar6 + -0x70;

    } while (-1 < iVar5);

  }

  uStack_ac = uVar2;

  (**(code **)(**(int **)(param_1 + -8) + 0x24))(&iStack_b0,0xffff00ff,DAT_00d03514);

  if (-1 < (int)fStack_b4) {

    (**(code **)(*DAT_00b05060 + 0x14))(fStack_bc,(int)fStack_b4 * 4,0x12);

  }

  return;

}
