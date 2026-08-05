// =============================================================================
// FUN_006e09a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e09a0
// Address:   0x006e09a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e09a0 @ 0x006e09a0
// Stable ID: aa_006e09a0
// Embedded strings (evidence for future rename):
//   - "TtSphereBox"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~146 non-empty decompiler lines.
//  - Control keywords: if×15, goto×2, return×1.
//  - Notable callees: ABS×3, rdtsc×2, FUN_005b3370, FUN_005d69a0, FUN_006e09a0, SQRT.
//  - Strings: "TtSphereBox".
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

void __thiscall FUN_006e09a0(int param_1,int *param_2,int *param_3,int param_4,int *param_5)



{

  float fVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  bool bVar6;

  uint64_t uVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  uint16_t uVar11;

  float *pfVar12;

  int iVar13;

  int iVar14;

  float *pfVar15;

  float local_30;

  float local_2c;

  float local_28;

  float local_20 [7];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereBox";

    uVar7 = rdtsc();

    DAT_00bc5644[1] = (int)uVar7;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  piVar2 = (int *)*param_5;

  if (piVar2[1] == (piVar2[2] & 0x7fffffffU)) {

    FUN_005b3370(piVar2,0x30);

  }

  pfVar15 = (float *)(piVar2[1] * 0x30 + *piVar2);

  piVar2[1] = piVar2[1] + 1;

  iVar3 = param_2[2];

  FUN_005d69a0(param_3[2] + 0x20,(float *)(iVar3 + 0x50));

  iVar4 = *param_3;

  fVar8 = ABS(local_20[0]);

  iVar5 = *param_2;

  fVar1 = ABS(local_20[1]);

  fVar9 = ABS(local_20[2]);

  local_30 = fVar8;

  if (*(float *)(iVar4 + 0x10) <= fVar8) {

    local_30 = *(float *)(iVar4 + 0x10);

  }

  local_2c = fVar1;

  if (*(float *)(iVar4 + 0x14) <= fVar1) {

    local_2c = *(float *)(iVar4 + 0x14);

  }

  local_28 = fVar9;

  if (*(float *)(iVar4 + 0x18) <= fVar9) {

    local_28 = *(float *)(iVar4 + 0x18);

  }

  local_30 = local_30 - fVar8;

  local_2c = local_2c - fVar1;

  local_28 = local_28 - fVar9;

  if ((g_flZero <= local_28 && g_flZero <= local_2c) && g_flZero <= local_30) {

    fVar8 = fVar8 - *(float *)(iVar4 + 0x10);

    fVar1 = fVar1 - *(float *)(iVar4 + 0x14);

    fVar9 = fVar9 - *(float *)(iVar4 + 0x18);

    if (fVar8 <= fVar1) {

      iVar13 = param_3[2];

      if (fVar1 <= fVar9) goto LAB_006e0cd4;

      iVar14 = 1;

      pfVar12 = (float *)(iVar13 + 0x30);

    }

    else {

      iVar13 = param_3[2];

      if (fVar8 <= fVar9) {

LAB_006e0cd4:

        iVar14 = 2;

        pfVar12 = (float *)(iVar13 + 0x40);

        fVar1 = fVar9;

      }

      else {

        iVar14 = 0;

        pfVar12 = (float *)(iVar13 + 0x20);

        fVar1 = fVar8;

      }

    }

    bVar6 = local_20[iVar14] < g_flZero;

    pfVar15[4] = *pfVar12;

    pfVar15[5] = pfVar12[1];

    pfVar15[6] = pfVar12[2];

    pfVar15[7] = pfVar12[3];

    if (bVar6) {

      pfVar15[4] = -pfVar15[4];

      pfVar15[5] = -pfVar15[5];

      pfVar15[6] = -pfVar15[6];

      pfVar15[7] = -pfVar15[7];

    }

    fVar8 = (fVar1 - *(float *)(iVar4 + 0xc)) - *(float *)(iVar5 + 0xc);

  }

  else {

    fVar8 = SQRT(local_28 * local_28 + local_30 * local_30 + local_2c * local_2c);

    fVar1 = g_flOne / fVar8;

    fVar8 = fVar8 - (*(float *)(iVar4 + 0xc) + *(float *)(iVar5 + 0xc));

    if (*(float *)(param_4 + 8) < fVar8) {

      *(int *)(*param_5 + 4) = *(int *)(*param_5 + 4) + -1;

      if (*(short *)(param_1 + 0xc) != -1) {

        (**(code **)(**(int **)(param_1 + 8) + 8))(*(short *)(param_1 + 0xc));

        *(uint16_t *)(param_1 + 0xc) = 0xffff;

      }

      goto LAB_006e0de6;

    }

    fVar9 = -(float)((uint)(local_30 * fVar1) ^ (uint)local_20[0] & 0x80000000);

    fVar10 = -(float)((uint)(local_2c * fVar1) ^ (uint)local_20[1] & 0x80000000);

    iVar4 = param_3[2];

    fVar1 = -(float)((uint)(local_28 * fVar1) ^ (uint)local_20[2] & 0x80000000);

    pfVar15[4] = fVar9 * *(float *)(iVar4 + 0x20) +

                 fVar10 * *(float *)(iVar4 + 0x30) + fVar1 * *(float *)(iVar4 + 0x40);

    pfVar15[5] = fVar9 * *(float *)(iVar4 + 0x24) +

                 fVar10 * *(float *)(iVar4 + 0x34) + fVar1 * *(float *)(iVar4 + 0x44);

    pfVar15[6] = fVar9 * *(float *)(iVar4 + 0x28) +

                 fVar10 * *(float *)(iVar4 + 0x38) + fVar1 * *(float *)(iVar4 + 0x48);

    pfVar15[7] = 0.0;

  }

  fVar1 = *(float *)(iVar5 + 0xc);

  *pfVar15 = *(float *)(iVar3 + 0x50);

  fVar1 = -fVar8 - fVar1;

  pfVar15[1] = *(float *)(iVar3 + 0x54);

  pfVar15[2] = *(float *)(iVar3 + 0x58);

  pfVar15[3] = *(float *)(iVar3 + 0x5c);

  *pfVar15 = fVar1 * pfVar15[4] + *pfVar15;

  pfVar15[1] = fVar1 * pfVar15[5] + pfVar15[1];

  pfVar15[2] = fVar1 * pfVar15[6] + pfVar15[2];

  pfVar15[3] = fVar1 * pfVar15[7] + pfVar15[3];

  pfVar15[3] = fVar8;

  if (*(short *)(param_1 + 0xc) == -1) {

    uVar11 = (**(code **)(**(int **)(param_1 + 8) + 4))(param_2,param_3,param_4,pfVar15);

    *(uint16_t *)(param_1 + 0xc) = uVar11;

  }

  if (*(short *)(param_1 + 0xc) == -1) {

    *(int *)(*param_5 + 4) = *(int *)(*param_5 + 4) + -1;

  }

  else {

    *(short *)(pfVar15 + 8) = *(short *)(param_1 + 0xc);

  }

LAB_006e0de6:

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar7 = rdtsc();

    DAT_00bc5644[1] = (int)uVar7;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
