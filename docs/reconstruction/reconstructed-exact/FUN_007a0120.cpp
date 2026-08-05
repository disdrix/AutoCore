// =============================================================================
// FUN_007a0120
// -----------------------------------------------------------------------------
// Stable ID: aa_007a0120
// Address:   0x007a0120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a0120 @ 0x007a0120
// Stable ID: aa_007a0120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~188 non-empty decompiler lines.
//  - Control keywords: if×8, for×1, return×1.
//  - Notable callees: FUN_00404d80, FUN_00424b50, FUN_0076f5f0, FUN_007a0120, SQRT.
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

int * __thiscall

FUN_007a0120(int param_1,int param_2,uint8_t param_3,int param_4,uint param_5,float param_6,

            int param_7,int param_8,int param_9,int param_10,int param_11,int param_12,int param_13,

            int param_14,float param_15,float param_16,float param_17,float param_18,float param_19,

            float param_20,float param_21,float param_22,float param_23,float param_24,

            float param_25,float param_26,int param_27,int param_28,int param_29,uint8_t param_30

            )



{

  int *piVar1;

  float fVar2;

  int *piVar3;

  float *pfVar4;

  int iVar5;

  uint uVar6;

  int *piVar7;

  float fVar8;

  float fVar9;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009acea0;

  local_c = ExceptionList;

  piVar1 = *(int **)(*(int *)(param_1 + 0x2dc) + 4);

  ExceptionList = &local_c;

  piVar3 = operator_new(0xa8);

  if (piVar3 == (int *)0x0) {

    piVar3 = (int *)0x0;

  }

  else {

    *(uint8_t *)((int)piVar3 + 0xe) = 0xff;

    *(uint8_t *)((int)piVar3 + 0xd) = 0xff;

    *(uint8_t *)(piVar3 + 3) = 0xff;

    *(uint8_t *)((int)piVar3 + 0xf) = 0xff;

    *(uint8_t *)((int)piVar3 + 0x12) = 0xff;

    *(uint8_t *)((int)piVar3 + 0x11) = 0xff;

    *(uint8_t *)(piVar3 + 4) = 0xff;

    *(uint8_t *)((int)piVar3 + 0x13) = 0xff;

    *(uint8_t *)((int)piVar3 + 0x16) = 0xff;

    *(uint8_t *)((int)piVar3 + 0x15) = 0xff;

    *(uint8_t *)(piVar3 + 5) = 0xff;

    *(uint8_t *)((int)piVar3 + 0x17) = 0xff;

    piVar3[0x1b] = 0;

  }

  piVar7 = piVar3;

  for (iVar5 = 0x2a; iVar5 != 0; iVar5 = iVar5 + -1) {

    *piVar7 = 0;

    piVar7 = piVar7 + 1;

  }

  *(int **)(*piVar1 + 4) = piVar3;

  *piVar3 = *piVar1;

  *piVar1 = (int)piVar3;

  *(uint8_t *)(piVar3 + 0x29) = param_30;

  *(char *)(piVar3 + 2) = (char)param_2;

  piVar3[1] = (int)piVar1;

  if (param_2 == 2) {

    local_30 = param_23 * param_25 - param_22 * param_26;

    local_2c = param_26 * param_21 - param_23 * param_24;

    local_28 = param_22 * param_24 - param_25 * param_21;

    local_24 = local_30;

    local_20 = local_2c;

    local_1c = local_28;

    FUN_0076f5f0(&local_30,&local_30);

    pfVar4 = operator_new__(0x30);

    local_4 = 0;

    if (pfVar4 == (float *)0x0) {

      pfVar4 = (float *)0x0;

    }

    else {

      FUN_00404d80(pfVar4,0xc,4,FUN_005edf20);

    }

    fVar8 = DAT_00aaa6cc;

    fVar2 = DAT_00a0f298;

    local_1c = param_26 * DAT_00aaa6cc;

    local_18 = local_30 * DAT_00a0f298;

    local_24 = param_24 * DAT_00aaa6cc;

    local_14 = local_2c * DAT_00a0f298;

    piVar3[0x1b] = (int)pfVar4;

    local_10 = local_28 * fVar2;

    local_30 = local_24 + local_18;

    *pfVar4 = local_30;

    local_2c = param_25 * fVar8 + local_14;

    pfVar4[1] = local_2c;

    local_28 = local_1c + local_10;

    pfVar4[2] = local_28;

    iVar5 = piVar3[0x1b];

    local_20 = param_25 * fVar2;

    *(float *)(iVar5 + 0xc) = param_24 * fVar2 + local_18;

    *(float *)(iVar5 + 0x10) = local_20 + local_14;

    *(float *)(iVar5 + 0x14) = param_26 * fVar2 + local_10;

    iVar5 = piVar3[0x1b];

    *(float *)(iVar5 + 0x18) = local_24 - local_18;

    *(float *)(iVar5 + 0x1c) = param_25 * fVar8 - local_14;

    *(float *)(iVar5 + 0x20) = local_1c - local_10;

    iVar5 = piVar3[0x1b];

    *(float *)(iVar5 + 0x24) = param_24 * fVar2 - local_18;

    *(float *)(iVar5 + 0x28) = local_20 - local_14;

    *(float *)(iVar5 + 0x2c) = param_26 * fVar2 - local_10;

  }

  else {

    piVar3[0x1b] = 0;

  }

  piVar3[5] = param_13;

  piVar3[3] = param_13;

  piVar3[0x20] = param_7;

  *(uint8_t *)((int)piVar3 + 9) = param_3;

  piVar3[4] = param_14;

  piVar3[0x24] = param_9;

  pfVar4 = (float *)(piVar3 + 0x15);

  if (param_4 == 3) {

    *pfVar4 = param_18 - param_15;

    piVar3[0x16] = (int)(param_19 - param_16);

    piVar3[0x17] = (int)(param_20 - param_17);

    FUN_00424b50(pfVar4,piVar3 + 0x16,piVar3 + 0x17);

  }

  else {

    *pfVar4 = param_21;

    piVar3[0x16] = (int)param_22;

    piVar3[0x17] = (int)param_23;

  }

  piVar3[0x12] = (int)param_15;

  piVar3[0x13] = (int)param_16;

  piVar3[0x14] = (int)param_17;

  piVar3[0xc] = (int)param_15;

  piVar3[0xd] = (int)param_16;

  piVar3[0xf] = (int)param_18;

  piVar3[0x10] = (int)param_19;

  piVar3[0x11] = (int)param_20;

  piVar3[0x22] = param_8;

  piVar3[0x23] = param_8;

  piVar3[0xe] = (int)param_17;

  piVar3[6] = param_27;

  piVar3[0x1c] = param_10;

  piVar3[0x1d] = param_11;

  piVar3[7] = param_28;

  piVar3[0x1e] = param_12;

  *(char *)((int)piVar3 + 10) = (char)param_4;

  piVar3[0x21] = (int)param_6;

  piVar3[8] = param_29;

  if (param_4 == 9) {

    piVar3[9] = (int)(param_6 * *pfVar4);

    piVar3[10] = (int)((float)piVar3[0x16] * param_6);

    piVar3[0xb] = (int)((float)piVar3[0x17] * param_6);

  }

  fVar2 = (float)piVar3[0x14] - *(float *)(param_1 + 0x230);

  fVar9 = (float)piVar3[0x13] - *(float *)(param_1 + 0x22c);

  fVar8 = (float)piVar3[0x12] - *(float *)(param_1 + 0x228);

  piVar3[0x1f] = (int)SQRT(fVar2 * fVar2 + fVar9 * fVar9 + fVar8 * fVar8);

  fVar8 = DAT_00a1e8b8;

  fVar2 = DAT_00a14000;

  if ((int)param_5 < 0x40) {

    uVar6 = param_5 & 0x80000007;

    if ((int)uVar6 < 0) {

      uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;

    }

    piVar3[0x25] = (int)((float)(int)uVar6 * DAT_00a1e8b4 + DAT_00a1e8b8);

    fVar9 = DAT_00aaa978;

    fVar8 = (float)((int)(param_5 + ((int)param_5 >> 0x1f & 7U)) >> 3) * DAT_00a1e8b4 + fVar8;

    piVar3[0x26] = (int)fVar8;

    piVar3[0x27] = (int)(((float)piVar3[0x25] + DAT_00a1e8b4) - fVar9);

    fVar9 = (fVar8 + DAT_00a1e8b4) - fVar9;

  }

  else {

    param_5 = param_5 - 0x40;

    uVar6 = param_5 & 0x8000000f;

    if ((int)uVar6 < 0) {

      uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;

    }

    piVar3[0x25] = (int)((float)(int)uVar6 * DAT_00a14000 + DAT_00a1e8b8);

    fVar9 = DAT_00aaa978;

    fVar8 = (float)((int)(param_5 + ((int)param_5 >> 0x1f & 0xfU)) >> 4) * fVar2 + fVar8;

    piVar3[0x26] = (int)fVar8;

    piVar3[0x27] = (int)(((float)piVar3[0x25] + fVar2) - fVar9);

    fVar9 = (fVar8 + fVar2) - fVar9;

  }

  piVar3[0x28] = (int)fVar9;

  ExceptionList = local_c;

  return piVar3;

}
