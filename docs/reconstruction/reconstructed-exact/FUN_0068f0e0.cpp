// =============================================================================
// FUN_0068f0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068f0e0
// Address:   0x0068f0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068f0e0 @ 0x0068f0e0
// Stable ID: aa_0068f0e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~171 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, for×1, return×1.
//  - Notable callees: FUN_0068ea30×4, FUN_00404d80×2, FUN_0068eba0, FUN_0068ec20, FUN_0068eca0, FUN_0068ef70, FUN_0068f0e0, FUN_006998b0.
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

void __thiscall

FUN_0068f0e0(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3,float param_4,float param_5,float param_6)



{

  int iVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  float *pfVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  bool bVar11;

  float10 fVar12;

  float local_e4;

  uint local_d8;

  float local_d4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  uint32_t /* width from decompiler */ local_b8;

  uint32_t /* width from decompiler */ local_b4;

  uint32_t /* width from decompiler */ local_b0;

  uint32_t /* width from decompiler */ local_ac;

  uint32_t /* width from decompiler */ local_a8;

  uint32_t /* width from decompiler */ local_a4;

  uint32_t /* width from decompiler */ local_a0;

  uint32_t /* width from decompiler */ local_9c;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  uint32_t /* width from decompiler */ local_90;

  uint32_t /* width from decompiler */ local_8c;

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  float local_68;

  float local_64;

  uint32_t /* width from decompiler */ local_60;

  float local_5c;

  float local_58;

  uint32_t /* width from decompiler */ local_54;

  float local_50;

  float local_4c;

  uint32_t /* width from decompiler */ local_48;

  float local_44;

  float local_40;

  float local_34;

  uint8_t local_30 [12];

  uint8_t local_24 [12];

  uint8_t local_18 [12];

  uint8_t local_c [12];

  

  if ((((*(int *)(param_1 + 0x2c) != 0) && ((ushort)param_3 < *(ushort *)(param_1 + 0x28))) &&

      (*(int *)(param_1 + 0x10) != 0)) &&

     (((*(int *)(param_1 + 0x24) != 0 && (*(int *)(param_1 + 0x20) != 0)) &&

      ((*(int *)(param_1 + 4) != 0 && (*(int *)(param_1 + 0xc) != 0)))))) {

    uVar8 = param_3 & 0xffff;

    puVar10 = (uint32_t /* width from decompiler */ *)(uVar8 * 0x44 + *(int *)(param_1 + 0x2c));

    if (*(char *)(puVar10 + 0xf) == '\0') {

      if (*(int *)(*(int *)(param_1 + 4) + 0x10) == 1) {

        FUN_0068ef70(param_3);

      }

      local_e4 = 1.0;

      if ((ushort)param_3 != 0) {

        local_e4 = (float)uVar8 * param_6 + g_flOne;

      }

      FUN_00404d80(&local_6c,0xc,4,&LAB_00685ce0);

      FUN_00404d80(&local_c0,0xc,4,&LAB_00685ce0);

      local_d8 = 0;

      if (*(short *)(param_1 + 0x1c) != 0) {

        uVar7 = (uint)*(ushort *)(param_1 + 8);

        do {

          iVar9 = ((int)local_d8 / 2) * 0xc;

          pfVar4 = (float *)(*(int *)(param_1 + 0x24) + iVar9);

          local_d4 = *pfVar4;

          fVar2 = pfVar4[1];

          uVar5 = local_d8 & 0x80000001;

          bVar11 = uVar5 == 0;

          if ((int)uVar5 < 0) {

            bVar11 = (uVar5 - 1 | 0xfffffffe) == 0xffffffff;

          }

          if (bVar11) {

            local_d4 = g_flOne - local_d4;

          }

          pfVar4 = (float *)(*(int *)(param_1 + 0x20) + iVar9);

          iVar9 = 0;

          local_64 = (g_flOne - local_d4) * *pfVar4 * local_e4;

          local_68 = (g_flOne - fVar2) * local_e4 * pfVar4[1];

          local_58 = -(local_d4 * *pfVar4 * local_e4);

          local_6c = 0;

          local_60 = 0;

          local_54 = 0;

          local_48 = 0;

          local_50 = -(fVar2 * pfVar4[1] * local_e4);

          if (uVar7 != 0) {

            local_5c = local_68;

            local_4c = local_58;

            local_44 = local_50;

            local_40 = local_64;

            local_34 = local_50;

            do {

              fVar12 = (float10)FUN_006998b0((float)(int)(local_d8 + 1) *

                                             *(float *)(*(int *)(param_1 + 0xc) + iVar9 * 4));

              iVar1 = *(ushort *)(param_1 + 8) * local_d8 + iVar9;

              local_90 = 0x3f800000;

              local_8c = 0;

              local_88 = 0;

              local_84 = 0;

              local_80 = 0x3f800000;

              local_7c = 0;

              local_78 = 0;

              local_74 = 0;

              local_70 = 0x3f800000;

              FUN_0068ec20(param_4 + *(float *)(&DAT_00af54c0 + iVar1 * 4));

              FUN_0068eca0(param_5 + *(float *)(&DAT_00af5534 + iVar1 * -4));

              FUN_0068eba0(-(float)fVar12);

              puVar6 = (uint32_t /* width from decompiler */ *)FUN_0068ea30(local_30,&local_90);

              uVar3 = *puVar6;

              local_bc = puVar6[1];

              local_b8 = puVar6[2];

              local_c0 = uVar3;

              puVar6 = (uint32_t /* width from decompiler */ *)FUN_0068ea30(local_24,&local_90);

              local_b4 = *puVar6;

              local_b0 = puVar6[1];

              local_ac = puVar6[2];

              puVar6 = (uint32_t /* width from decompiler */ *)FUN_0068ea30(local_c,&local_90);

              local_a8 = *puVar6;

              local_a4 = puVar6[1];

              local_a0 = puVar6[2];

              puVar6 = (uint32_t /* width from decompiler */ *)FUN_0068ea30(local_18,&local_90);

              local_9c = *puVar6;

              local_98 = puVar6[1];

              local_94 = puVar6[2];

              puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 * 0x40 + *(int *)(*(int *)(param_1 + 0x10) + uVar8 * 4))

              ;

              *puVar6 = uVar3;

              puVar6[1] = local_bc;

              puVar6[2] = local_b8;

              puVar6[4] = local_b4;

              puVar6[5] = local_b0;

              puVar6[6] = local_ac;

              puVar6[8] = local_a8;

              puVar6[9] = local_a4;

              puVar6[10] = local_a0;

              puVar6[0xc] = local_9c;

              puVar6[0xd] = local_98;

              puVar6[0xe] = local_94;

              uVar7 = (uint)*(ushort *)(param_1 + 8);

              iVar9 = iVar9 + 1;

            } while (iVar9 < (int)uVar7);

          }

          local_d8 = local_d8 + 1;

        } while ((int)local_d8 < (int)((uint)*(ushort *)(param_1 + 0x1c) * 2));

      }

      *(uint8_t *)(puVar10 + 0xf) = 1;

    }

    puVar6 = param_2;

    for (iVar9 = 0xf; iVar9 != 0; iVar9 = iVar9 + -1) {

      *puVar6 = *puVar10;

      puVar10 = puVar10 + 1;

      puVar6 = puVar6 + 1;

    }

    *(uint8_t *)param_2 = 1;

    param_2[2] = uVar8;

  }

  return;

}
