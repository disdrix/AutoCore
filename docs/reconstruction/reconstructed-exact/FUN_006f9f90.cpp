// =============================================================================
// FUN_006f9f90
// -----------------------------------------------------------------------------
// Stable ID: aa_006f9f90
// Address:   0x006f9f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f9f90 @ 0x006f9f90
// Stable ID: aa_006f9f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: ABS, FUN_006f9f90, SQRT.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_006f9f90(int param_1,uint8_t *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  uint uVar8;

  uint uVar9;

  float *pfVar10;

  uint uVar11;

  uint uVar12;

  float local_50 [4];

  float local_40 [4];

  float local_30 [4];

  float local_20 [7];

  

  uVar8 = *(ushort *)(param_3 + 0xe) >> 1 & 0x78;

  local_40[0] = *(float *)(&DAT_00a0ef70 + uVar8) * *(float *)(param_1 + 0x20);

  uVar9 = *(ushort *)((int)param_3 + 0x3a) >> 1 & 0x78;

  uVar12 = *(ushort *)((int)param_3 + 0x3a) & 0xf;

  local_40[1] = *(float *)(param_1 + 0x24) * *(float *)(&DAT_00a0ef74 + uVar8);

  uVar11 = *(ushort *)(param_3 + 0xe) & 0xf;

  local_40[2] = *(float *)(param_1 + 0x28) * *(float *)(&DAT_00a0ef78 + uVar8);

  local_40[3] = *(float *)(param_1 + 0x2c) * *(float *)(&DAT_00a0ef7c + uVar8);

  fVar2 = *(float *)(param_1 + 0x30) * *(float *)(&DAT_00a0ef70 + uVar9);

  fVar3 = *(float *)(param_1 + 0x34) * *(float *)(&DAT_00a0ef74 + uVar9);

  local_20[2] = *(float *)(param_1 + 0x38) * *(float *)(&DAT_00a0ef78 + uVar9);

  pfVar10 = (float *)((uVar12 + 7) * 0x10 + param_1);

  fVar1 = *(float *)(param_1 + 0x30 + uVar12 * 4);

  fVar1 = fVar1 + fVar1;

  local_50[0] = fVar1 * *pfVar10;

  local_50[1] = fVar1 * pfVar10[1];

  local_50[2] = fVar1 * pfVar10[2];

  local_50[3] = fVar1 * pfVar10[3];

  local_20[0] = fVar2 * *(float *)(param_1 + 0x70) +

                fVar3 * *(float *)(param_1 + 0x80) + local_20[2] * *(float *)(param_1 + 0x90) +

                *(float *)(param_1 + 0xa0);

  local_30[0] = local_20[0] - local_40[0];

  local_30[1] = (fVar2 * *(float *)(param_1 + 0x74) +

                 fVar3 * *(float *)(param_1 + 0x84) + local_20[2] * *(float *)(param_1 + 0x94) +

                *(float *)(param_1 + 0xa4)) - local_40[1];

  local_30[2] = (fVar2 * *(float *)(param_1 + 0x78) +

                 fVar3 * *(float *)(param_1 + 0x88) + local_20[2] * *(float *)(param_1 + 0x98) +

                *(float *)(param_1 + 0xa8)) - local_40[2];

  local_30[3] = -local_40[3];

  fVar4 = *(float *)(param_1 + 0x20 + uVar11 * 4) * DAT_00a12f70;

  fVar5 = fVar4 * local_50[uVar11];

  fVar1 = *(float *)(param_1 + 0x30 + uVar12 * 4);

  fVar6 = fVar1 * fVar1 * DAT_00aaa690;

  fVar1 = local_30[0] * local_50[0] + local_30[1] * local_50[1] + local_30[2] * local_50[2];

  fVar2 = ABS(fVar4 * fVar4 * fVar6 - fVar5 * fVar5);

  fVar3 = fVar4 * local_30[uVar11] * fVar6 - fVar1 * fVar5;

  if ((_DAT_00af58c0 * fVar2 < fVar3) &&

     (fVar7 = (g_flOne - _DAT_00af58c0) * fVar2, fVar7 < fVar3 == (fVar7 == fVar3))) {

    fVar1 = (fVar3 / fVar2) * fVar5 - fVar1;

    if ((fVar1 < _DAT_00af58c0 * fVar6 == (fVar1 == _DAT_00af58c0 * fVar6)) &&

       (fVar1 < (g_flOne - _DAT_00af58c0) * fVar6)) {

      local_20[2] = 0.0;

      local_20[1] = 0.0;

      local_20[0] = 0.0;

      local_40[uVar11] = (fVar3 / fVar2) * fVar4 + local_40[uVar11];

      local_20[uVar11] = fVar4 * DAT_00a0f298;

      fVar1 = local_20[1] * local_50[2] - local_20[2] * local_50[1];

      fVar2 = local_20[2] * local_50[0] - local_50[2] * local_20[0];

      local_50[2] = local_50[1] * local_20[0] - local_20[1] * local_50[0];

      fVar3 = SQRT(fVar1 * fVar1 + fVar2 * fVar2 + local_50[2] * local_50[2]);

      local_50[3] = g_flOne / fVar3;

      local_50[0] = fVar1 * local_50[3];

      local_50[1] = fVar2 * local_50[3];

      local_50[2] = local_50[2] * local_50[3];

      local_50[3] = local_50[3] * g_flZero;

      if (*(float *)(param_1 + 100) <= fVar3) {

        if (local_50[2] * *(float *)(&DAT_00a0ef78 + uVar8) +

            local_50[0] * *(float *)(&DAT_00a0ef70 + uVar8) +

            local_50[1] * *(float *)(&DAT_00a0ef74 + uVar8) < g_flZero) {

          local_50[0] = -local_50[0];

          local_50[1] = -local_50[1];

          local_50[2] = -local_50[2];

          local_50[3] = -local_50[3];

        }

        fVar1 = local_50[0] * local_30[0] + local_50[1] * local_30[1] + local_50[2] * local_30[2];

        if (fVar1 <= *(float *)(param_1 + 0x60)) {

          *param_3 = local_40[0];

          param_3[3] = local_40[3];

          param_3[1] = local_40[1];

          param_3[2] = local_40[2];

          param_3[8] = -local_50[0];

          param_3[9] = -local_50[1];

          param_3[10] = -local_50[2];

          param_3[0xb] = -local_50[3];

          param_3[0xd] = fVar1;

          *param_2 = 1;

          return;

        }

      }

    }

  }

  *param_2 = 0;

  return;

}
