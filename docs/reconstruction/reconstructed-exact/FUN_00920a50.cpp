// =============================================================================
// FUN_00920a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00920a50
// Address:   0x00920a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00920a50 @ 0x00920a50
// Stable ID: aa_00920a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~240 non-empty decompiler lines.
//  - Control keywords: if×16, while×3, do×2, return×1.
//  - Notable callees: CONCAT13×3, FUN_004022a0×2, FUN_006a3db0×2, FUN_007a0120×2, FUN_00918a70×2, Client_MaybeShowFirstTimeTip, FUN_00404c90, FUN_0040c700.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00920a50(int param_1,float param_2)



{

  int *piVar1;

  int *piVar2;

  float fVar3;

  uint8_t uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t *puVar7;

  int iVar8;

  int iVar9;

  float fVar10;

  uint32_t /* width from decompiler */ uStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  uint32_t /* width from decompiler */ uStack_a8;

  uint32_t /* width from decompiler */ uStack_a4;

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

  uint32_t /* width from decompiler */ *puStack_78;

  float *pfStack_74;

  uint32_t /* width from decompiler */ local_60;

  float fStack_5c;

  float local_54;

  float fStack_48;

  float local_44;

  uint32_t /* width from decompiler */ local_40;

  uint8_t *local_3c;

  uint8_t *puStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  piVar2 = DAT_00d1d888;

  if (((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&

     (*(char *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x106) != '\0')) {

    if (((DAT_00d1d888 != (int *)0x0) && (((uint)DAT_00d1d888[0x5f] >> 6 & 1) != 0)) &&

       (0 < *(int *)(DAT_00d1d888[0x2a] + 0x34))) {

      pfStack_74 = (float *)0x920ad6;

      iVar5 = (**(code **)(*DAT_00d1d888 + 0x1cc))();

      piVar1 = *(int **)(iVar5 + 8);

      if (piVar1 != (int *)0x0) {

        DAT_00d1d890 = DAT_00d1d890 + param_2;

        if (DAT_00a0f704 <= DAT_00d1d890) {

          fStack_5c = DAT_00aaa690;

          local_60 = 0xffffffff;

          local_54 = 0.0;

          if (DAT_00d1d88c == '\0') {

            DAT_00d1d88c = '\x01';

          }

        }

        else {

          local_54 = g_flOne - DAT_00d1d890 * DAT_00aaa690;

          fStack_5c = local_54 * DAT_00aaa8dc + DAT_00aaa690;

          pfStack_74 = (float *)0x920b4f;

          uVar4 = FUN_006a3db0();

          local_60 = CONCAT13(uVar4,0xffffff);

        }

        pfStack_74 = (float *)0x920b97;

        iVar5 = (**(code **)(*piVar2 + 0x1c8))();

        local_44 = g_flOne;

        if (iVar5 != 0) {

          pfStack_74 = (float *)0x920ba5;

          iVar5 = (**(code **)(*piVar2 + 0x1c8))();

          local_44 = *(float *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xbc + iVar5);

        }

        pfStack_74 = (float *)0x920bcb;

        iVar5 = (**(code **)(*piVar1 + 0x54))();

        fStack_5c = *(float *)(iVar5 + 0xc) * local_44 * _DAT_00a0f724 * fStack_5c;

        pfStack_74 = (float *)0x920bf1;

        pfStack_74 = (float *)(**(code **)(*piVar1 + 0x54))();

        puStack_78 = (uint32_t /* width from decompiler */ *)0x920bf9;

        (**(code **)(*piVar1 + 0xc))();

        puStack_78 = (uint32_t /* width from decompiler */ *)0x920c02;

        puVar6 = (uint32_t /* width from decompiler */ *)FUN_00972fa0();

        uStack_34 = *puVar6;

        uStack_30 = puVar6[1];

        uStack_2c = puVar6[2];

        pfStack_74 = (float *)&uStack_28;

        puStack_78 = &uStack_1c;

        uStack_7c = 0x920c2d;

        FUN_00918a70();

        pfStack_74 = (float *)0x1;

        uStack_80 = DAT_00d1a6c0;

        uStack_7c = DAT_00d1a6c4;

        puStack_78 = (uint32_t /* width from decompiler */ *)DAT_00d1a6c8;

        uStack_8c = uStack_28;

        uStack_88 = uStack_24;

        uStack_84 = uStack_20;

        uStack_98 = uStack_1c;

        uStack_94 = uStack_18;

        uStack_90 = uStack_14;

        local_3c = (uint8_t *)&uStack_b0;

        uStack_a4 = uStack_34;

        uStack_a0 = uStack_30;

        uStack_9c = uStack_2c;

        uStack_b0 = uStack_34;

        uStack_ac = uStack_30;

        uStack_a8 = uStack_2c;

        FUN_007a0120(2,0,4,9,0,*(float *)(param_1 + 0x548) - local_54,0x3f800000,0,fStack_5c,

                     fStack_5c,0,local_60,local_60);

      }

    }

    if (((*(char *)(DAT_00d1b6d8 + 0x6b9) == '\0') && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) &&

       (*(char *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x106) != '\0')) {

      local_44 = 0.0;

      local_40 = 0;

      local_60 = 0xffffffff;

      local_3c = (uint8_t *)0x0;

      iVar5 = DAT_00d1b6d8;

      do {

        puVar7 = local_3c;

        if ((((local_3c != (uint8_t *)0x8) &&

             (iVar8 = *(int *)((int)local_3c + *(int *)(*(int *)(iVar5 + 0x250) + 0x260)),

             iVar8 != 0)) && (iVar8 = *(int *)(iVar8 + 0x13c), iVar8 != 0)) &&

           (*(int *)(iVar8 + 0x24) != 0)) {

          pfStack_74 = (float *)0x16;

          puStack_78 = (uint32_t /* width from decompiler */ *)0x920dbb;

          Client_MaybeShowFirstTimeTip();

          pfStack_74 = (float *)0x920dc2;

          FUN_004294f0();

          pfStack_74 = &local_44;

          puStack_78 = &local_40;

          uStack_7c = 0x920dd3;

          iVar5 = FUN_004022a0();

          fVar3 = DAT_00a0f704;

          while (DAT_00a0f704 = fVar3, iVar5 == 0) {

            piVar2 = *(int **)((int)local_44 + 4);

            if (piVar2 != (int *)0x0) {

              fVar10 = *(float *)((int)local_44 + 0xc) + param_2;

              *(float *)((int)local_44 + 0xc) = fVar10;

              if (fVar3 <= fVar10) {

                fStack_5c = g_flVehicleHpTechCoeff;

                local_60 = CONCAT13(0xff,(undefined3)local_60);

                local_54 = 0.0;

                if (*(char *)((int)local_44 + 8) == '\0') {

                  *(uint8_t *)((int)local_44 + 8) = 1;

                }

              }

              else {

                local_54 = g_flOne - fVar10 * DAT_00aaa690;

                fStack_5c = local_54 * DAT_00aaa688 + g_flVehicleHpTechCoeff;

                pfStack_74 = (float *)0x920e53;

                uVar4 = FUN_006a3db0();

                local_60 = CONCAT13(uVar4,(undefined3)local_60);

              }

              fStack_48 = g_flOne;

              pfStack_74 = (float *)0x920ea3;

              iVar5 = (**(code **)(*piVar2 + 0x1cc))();

              piVar1 = *(int **)(iVar5 + 8);

              if (piVar1 != (int *)0x0) {

                pfStack_74 = (float *)0x920eb1;

                puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar1 + 0x28))();

                uStack_34 = *puVar6;

                uStack_30 = puVar6[1];

                uStack_2c = puVar6[2];

              }

              pfStack_74 = (float *)0x920ecf;

              iVar5 = (**(code **)(*piVar2 + 0x1c8))();

              if (iVar5 != 0) {

                if (piVar1 == (int *)0x0) {

                  pfStack_74 = (float *)0x920ee0;

                  puVar6 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

                  uStack_34 = *puVar6;

                  uStack_30 = puVar6[1];

                  uStack_2c = puVar6[2];

                }

                fStack_48 = *(float *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xbc + iVar5);

              }

              if (piVar1 != (int *)0x0) {

                pfStack_74 = (float *)0x920f20;

                iVar5 = (**(code **)(*piVar1 + 0x54))();

                fStack_48 = *(float *)(iVar5 + 0xc) * fStack_48 * _DAT_00a0f724;

              }

              pfStack_74 = (float *)&uStack_1c;

              puStack_78 = &uStack_28;

              uStack_7c = 0x920f5e;

              FUN_00918a70();

              pfStack_74 = (float *)0x1;

              uStack_80 = DAT_00d1a6c0;

              uStack_7c = DAT_00d1a6c4;

              puStack_78 = (uint32_t /* width from decompiler */ *)DAT_00d1a6c8;

              uStack_8c = uStack_1c;

              uStack_88 = uStack_18;

              uStack_84 = uStack_14;

              uStack_98 = uStack_28;

              uStack_94 = uStack_24;

              uStack_90 = uStack_20;

              puStack_38 = (uint8_t *)&uStack_b0;

              uStack_a4 = uStack_34;

              uStack_a0 = uStack_30;

              uStack_9c = uStack_2c;

              uStack_b0 = uStack_34;

              uStack_ac = uStack_30;

              uStack_a8 = uStack_2c;

              FUN_007a0120(2,0,4,0x71,0,*(float *)(param_1 + 0x548) - local_54,0x3f800000,0x3f800000

                           ,fStack_48 * fStack_5c,fStack_48 * fStack_5c,0,local_60,local_60);

              puVar7 = local_3c;

            }

            pfStack_74 = &local_44;

            puStack_78 = &local_40;

            uStack_7c = 0x92107d;

            iVar5 = FUN_004022a0();

            fVar3 = DAT_00a0f704;

          }

          pfStack_74 = (float *)0x92108c;

          FUN_0040c700();

          iVar5 = DAT_00d1b6d8;

        }

        local_3c = (uint8_t *)((int)puVar7 + 4);

      } while ((int)local_3c < 0xc);

      iVar8 = 0;

      iVar9 = 3;

      do {

        if (*(int *)(iVar8 + *(int *)(*(int *)(iVar5 + 0x250) + 0x260)) != 0) {

          pfStack_74 = (float *)param_2;

          puStack_78 = (uint32_t /* width from decompiler */ *)0x9210c9;

          FUN_0056a9a0();

          iVar5 = DAT_00d1b6d8;

        }

        iVar8 = iVar8 + 4;

        iVar9 = iVar9 + -1;

      } while (iVar9 != 0);

    }

  }

  return;

}
