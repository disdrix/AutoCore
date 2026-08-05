// =============================================================================
// FUN_005c2de0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c2de0
// Address:   0x005c2de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c2de0 @ 0x005c2de0
// Stable ID: aa_005c2de0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~242 non-empty decompiler lines.
//  - Control keywords: if×27, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×13, FUN_0076f5f0×3, FUN_005c2de0, SQRT.
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

void FUN_005c2de0(float *param_1,int param_2,float *param_3,char param_4,float *param_5,

                 float *param_6,float *param_7,float param_8)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  byte bVar11;

  ushort uVar12;

  int iVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if (param_4 != '\0') {

    if (((*(byte *)(param_2 + 0x1e4) & 0x10) == 0) ||

       (*(float *)(param_2 + 0x24) * *(float *)(param_2 + 0x24) +

        *(float *)(param_2 + 0x28) * *(float *)(param_2 + 0x28) +

        *(float *)(param_2 + 0x2c) * *(float *)(param_2 + 0x2c) != 0.0)) {

      *param_3 = 0.0;

      param_3[1] = 0.0;

      param_3[2] = 0.0;

    }

    bVar11 = *(byte *)(param_2 + 0x1e5);

    if ((char)bVar11 < '\0') {

      fVar14 = *(float *)(param_2 + 0x2c);

      fVar15 = *(float *)(param_2 + 0x28);

      local_4 = param_6[2] * fVar15;

      fVar16 = *(float *)(param_2 + 0x24);

      local_24 = *param_7 * fVar16 + *param_6 * fVar15 + *param_5 * fVar14;

      local_20 = fVar16 * param_7[1] + param_6[1] * fVar15 + param_5[1] * fVar14;

      local_1c = fVar16 * param_7[2] + local_4 + param_5[2] * fVar14;

      local_18 = local_24;

      local_14 = local_20;

      local_10 = local_1c;

      if ((bVar11 & 1) != 0) {

        iVar13 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar13 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

        }

        uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

        *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

        local_4 = (float)uVar12 * *(float *)(param_2 + 0x38) * DAT_00aaa638;

        local_c = *param_5 * local_4;

        local_8 = param_5[1] * local_4;

        local_4 = param_5[2] * local_4;

        iVar13 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar13 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

        }

        uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

        *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

        local_10 = (float)uVar12 * *(float *)(param_2 + 0x34) * DAT_00aaa638;

        local_18 = *param_6 * local_10;

        local_14 = param_6[1] * local_10;

        local_10 = param_6[2] * local_10;

        iVar13 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar13 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

        }

        uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

        *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

        fVar14 = (float)uVar12 * *(float *)(param_2 + 0x30) * DAT_00aaa638;

        local_24 = fVar14 * *param_7 + local_18 + local_c + local_24;

        local_20 = fVar14 * param_7[1] + local_14 + local_8 + local_20;

        local_1c = fVar14 * param_7[2] + local_10 + local_4 + local_1c;

      }

    }

    else {

      local_24 = *(float *)(param_2 + 0x24);

      local_20 = *(float *)(param_2 + 0x28);

      local_1c = *(float *)(param_2 + 0x2c);

      if ((bVar11 & 1) != 0) {

        iVar13 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar13 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

        }

        uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

        *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

        local_24 = (float)uVar12 * *(float *)(param_2 + 0x30) * DAT_00aaa638 + local_24;

        iVar13 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar13 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

        }

        uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

        *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

        local_20 = (float)uVar12 * *(float *)(param_2 + 0x34) * DAT_00aaa638 + local_20;

        iVar13 = CVOGReaction_RandomUnitScalar();

        if (0xfffff < *(int *)(iVar13 + 0xc)) {

          *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

        }

        uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

        *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

        local_1c = (float)uVar12 * *(float *)(param_2 + 0x38) * DAT_00aaa638 + local_1c;

      }

      if ((*(byte *)(param_2 + 0x1e5) & 0x40) != 0) {

        local_24 = *param_5 + local_24;

        local_20 = param_5[1] + local_20;

        local_1c = param_5[2] + local_1c;

      }

    }

    if ((*(byte *)(param_2 + 0x1e5) & 8) != 0) {

      FUN_0076f5f0(&local_24,&local_24);

    }

    if ((*(byte *)(param_2 + 0x1e4) & 0x80) == 0) {

      fVar14 = *(float *)(param_2 + 0x3c);

      local_1c = fVar14 * local_1c;

    }

    else {

      iVar13 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar13 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

      }

      uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

      *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

      fVar14 = (float)uVar12 * *(float *)(param_2 + 0x40) * DAT_00aaa638 +

               *(float *)(param_2 + 0x3c);

      local_1c = fVar14 * local_1c;

    }

    local_24 = fVar14 * local_24;

    local_20 = fVar14 * local_20;

    *param_3 = *param_3 + local_24;

    param_3[2] = local_1c + param_3[2];

    param_3[1] = param_3[1] + local_20;

    pfVar1 = param_3 + 3;

    *pfVar1 = *(float *)(param_2 + 0x44);

    param_3[4] = *(float *)(param_2 + 0x48);

    param_3[5] = *(float *)(param_2 + 0x4c);

    if ((*(byte *)(param_2 + 0x1e5) & 2) != 0) {

      iVar13 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar13 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

      }

      uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

      *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

      *pfVar1 = (float)uVar12 * *(float *)(param_2 + 0x50) * DAT_00aaa638 + *pfVar1;

      iVar13 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar13 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

      }

      uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

      *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

      param_3[4] = (float)uVar12 * *(float *)(param_2 + 0x54) * DAT_00aaa638 + param_3[4];

      iVar13 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar13 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

      }

      uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

      *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

      param_3[5] = (float)uVar12 * *(float *)(param_2 + 0x58) * DAT_00aaa638 + param_3[5];

    }

    if ((*(byte *)(param_2 + 0x1e5) & 0x10) != 0) {

      FUN_0076f5f0(pfVar1,pfVar1);

    }

    pfVar1 = param_3 + 6;

    *pfVar1 = *(float *)(param_2 + 0x5c);

    param_3[7] = *(float *)(param_2 + 0x60);

    param_3[8] = *(float *)(param_2 + 100);

    if ((*(byte *)(param_2 + 0x1e5) & 4) != 0) {

      iVar13 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar13 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

      }

      uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

      *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

      *pfVar1 = (float)uVar12 * *(float *)(param_2 + 0x68) * DAT_00aaa638 + *pfVar1;

      iVar13 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar13 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

      }

      uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

      *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

      param_3[7] = (float)uVar12 * *(float *)(param_2 + 0x6c) * DAT_00aaa638 + param_3[7];

      iVar13 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar13 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar13 + 0xc) = 0;

      }

      uVar12 = *(ushort *)(*(int *)(iVar13 + 8) + *(int *)(iVar13 + 0xc) * 2);

      *(int *)(iVar13 + 0xc) = *(int *)(iVar13 + 0xc) + 1;

      param_3[8] = (float)uVar12 * *(float *)(param_2 + 0x70) * DAT_00aaa638 + param_3[8];

    }

    if ((*(byte *)(param_2 + 0x1e5) & 0x20) != 0) {

      FUN_0076f5f0(pfVar1,pfVar1);

    }

  }

  if (((*(byte *)(param_2 + 0x1e5) & 0x80) == 0) || ((*(byte *)(param_2 + 0x1e9) & 2) == 0)) {

    fVar14 = param_8 * param_3[2];

    fVar15 = *param_3 * param_8;

    fVar16 = param_3[1] * param_8;

  }

  else {

    fVar2 = *(float *)(param_2 + 0x2c);

    fVar3 = *(float *)(param_2 + 0x24);

    fVar4 = *(float *)(param_2 + 0x28);

    fVar14 = SQRT(*param_3 * *param_3 + param_3[1] * param_3[1] + param_3[2] * param_3[2]) * param_8

    ;

    fVar15 = (fVar3 * *param_7 + *param_6 * fVar4 + *param_5 * fVar2) * fVar14;

    fVar16 = (param_7[1] * fVar3 + param_6[1] * fVar4 + param_5[1] * fVar2) * fVar14;

    fVar14 = (param_7[2] * fVar3 + param_6[2] * fVar4 + param_5[2] * fVar2) * fVar14;

  }

  param_1[1] = fVar16 + param_1[1];

  param_1[2] = fVar14 + param_1[2];

  *param_1 = fVar15 + *param_1;

  fVar15 = param_3[5] * param_8 + param_3[2];

  fVar14 = param_3[4] * param_8 + param_3[1];

  fVar16 = *param_3 + param_3[3] * param_8;

  param_3[2] = fVar15;

  param_3[1] = fVar14;

  *param_3 = fVar16;

  if (DAT_009d9e48 <= param_3[6] * param_3[6] + param_3[7] * param_3[7] + param_3[8] * param_3[8]) {

    fVar2 = param_3[8];

    fVar3 = *param_5;

    fVar4 = param_5[2];

    fVar5 = param_6[2];

    fVar6 = *param_6;

    fVar7 = param_3[7];

    fVar8 = param_7[2];

    fVar9 = param_3[6];

    fVar10 = *param_7;

    param_3[1] = fVar14 + param_7[1] * fVar9 * param_8 + param_6[1] * fVar7 * param_8 +

                          param_5[1] * fVar2 * param_8;

    *param_3 = fVar16 + fVar9 * fVar10 * param_8 + fVar6 * fVar7 * param_8 + fVar3 * fVar2 * param_8

    ;

    param_3[2] = fVar15 + fVar8 * fVar9 * param_8 + fVar5 * fVar7 * param_8 +

                          fVar4 * fVar2 * param_8;

  }

  return;

}
