// =============================================================================
// FUN_0062ad40
// -----------------------------------------------------------------------------
// Stable ID: aa_0062ad40
// Address:   0x0062ad40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062ad40 @ 0x0062ad40
// Stable ID: aa_0062ad40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×5, while×4, return×2.
//  - Notable callees: FUN_00600080×2, SQRT×2, FUN_0055f210, FUN_0062a5d0, FUN_0062ad40, FUN_00651790.
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



uint __thiscall FUN_0062ad40(float param_1,int param_2,int param_3,int param_4,uint32_t /* width from decompiler */ *param_5)



{

  uint32_t /* width from decompiler */ uVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  float *unaff_EBX;

  float fVar8;

  int iStack_84;

  uint32_t /* width from decompiler */ *puStack_80;

  int *piStack_7c;

  int local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68 [2];

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  uint8_t local_50 [12];

  uint16_t auStack_44 [4];

  int iStack_3c;

  int iStack_38;

  float fStack_28;

  int iStack_24;

  

  if (*(int *)((int)param_1 + 0xa4) < 0xfb) {

    iVar4 = *(int *)(param_2 + 0xc);

    iVar3 = param_2;

    while (iVar6 = iVar4, iVar6 != 0) {

      iVar3 = iVar6;

      iVar4 = *(int *)(iVar6 + 0xc);

    }

    fVar2 = *(float *)(iVar3 + 0x20);

    iVar4 = *(int *)(param_3 + 0xc);

    iVar3 = param_3;

    while (iVar6 = iVar4, iVar6 != 0) {

      iVar3 = iVar6;

      iVar4 = *(int *)(iVar6 + 0xc);

    }

    local_74 = *(float *)(iVar3 + 0x20);

    local_6c = param_1;

    local_68[0] = fVar2;

    if (*(int *)((int)param_1 + 0xa4) == 0) {

      FUN_0055f210((int)param_1 + 0x10);

    }

    uVar7 = FUN_00651790(&local_70,&local_78);

    (**(code **)(**(int **)((int)fVar2 + 0x3c) + 0x58))(param_5,local_50);

    (**(code **)(*(int *)piStack_7c[0xf] + 0x58))(param_5,local_68);

    local_74 = (float)param_5[6] * (local_68[0] - fStack_58) +

               (float)param_5[5] * (local_6c - fStack_5c) +

               (local_70 - fStack_60) * (float)param_5[4];

    iVar4 = *(int *)(param_2 + 0xc);

    iVar3 = param_2;

    while (iVar6 = iVar4, iVar6 != 0) {

      iVar3 = iVar6;

      iVar4 = *(int *)(iVar6 + 0xc);

    }

    iVar3 = *(int *)(iVar3 + 0x20);

    iVar6 = *(int *)(param_3 + 0xc);

    iVar4 = param_3;

    while (iVar5 = iVar6, iVar5 != 0) {

      iVar4 = iVar5;

      iVar6 = *(int *)(iVar5 + 0xc);

    }

    iVar4 = *(int *)(iVar4 + 0x20);

    auStack_44[0] = (uint16_t)uVar7;

    iStack_38 = param_3;

    iStack_24 = 0;

    unaff_EBX[2] = SQRT(*(float *)(iVar4 + 0x4c) * *(float *)(iVar3 + 0x4c));

    unaff_EBX[3] = SQRT(*(float *)(iVar4 + 0x50) * *(float *)(iVar3 + 0x50));

    uVar1 = param_5[3];

    *puStack_80 = *param_5;

    puStack_80[1] = param_5[1];

    puStack_80[2] = param_5[2];

    puStack_80[3] = param_5[3];

    puStack_80[4] = param_5[4];

    puStack_80[5] = param_5[5];

    puStack_80[6] = param_5[6];

    puStack_80[7] = param_5[7];

    puStack_80[3] = uVar1;

    iStack_3c = param_2;

    fStack_28 = local_74;

    FUN_0062a5d0(piStack_7c[2],auStack_44);

    if (*(int *)(local_78 + 100) != 0) {

      FUN_00600080(local_78,auStack_44);

    }

    if (*(int *)(iStack_84 + 100) != 0) {

      FUN_00600080(iStack_84,auStack_44);

    }

    if (iStack_24 != 1) {

      fVar8 = unaff_EBX[3] * *(float *)(param_4 + 0x30) * local_74 * DAT_00aaaa4c;

      unaff_EBX[1] = fVar8;

      fVar2 = g_flOne;

      unaff_EBX[5] = (float)param_5[3] + fVar8;

      *unaff_EBX = (fVar2 / (*(float *)(*(int *)(iStack_84 + 0x3c) + 0x2c) +

                             *(float *)(*(int *)(local_78 + 0x3c) + 0x2c) + _DAT_00a13fe4)) *

                   (unaff_EBX[3] + fVar2) * local_74 * DAT_00a0f70c;

      return uVar7 & 0xffff;

    }

    (**(code **)(*piStack_7c + 8))(uVar7);

  }

  return 0xffff;

}
