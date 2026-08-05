// =============================================================================
// FUN_00859260
// -----------------------------------------------------------------------------
// Stable ID: aa_00859260
// Address:   0x00859260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00859260 @ 0x00859260
// Stable ID: aa_00859260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~221 non-empty decompiler lines.
//  - Control keywords: if×17, return×2, goto×2, do×1, while×1.
//  - Notable callees: CONCAT13×2, SQRT×2, CONCAT11, CONCAT12, CONCAT31, FUN_004141c0, FUN_00757890, FUN_00857100.
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

void __thiscall FUN_00859260(int *param_1,int param_2,int *param_3,char param_4)



{

  byte *pbVar1;

  int *in_EAX;

  float *pfVar2;

  int iVar3;

  uint3 unaff_EBX;

  uint uVar4;

  float unaff_ESI;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int unaff_retaddr;

  int *in_stack_0000001c;

  char cVar10;

  float fStack_c8;

  uint8_t uStack_c4;

  int iStack_b8;

  uint8_t uStack_b4;

  float local_b0;

  float fStack_ac;

  float afStack_a8 [9];

  float fStack_84;

  float fStack_80;

  float fStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  uint uStack_74;

  float fStack_70;

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint uStack_5c;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint uStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint uStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  float afStack_10 [3];

  uint *puStack_4;

  

  (**(code **)(*param_1 + 0x140))(&local_b0,1);

  pfVar2 = (float *)FUN_004141c0(afStack_10);

  fVar6 = g_flOne;

  fVar5 = pfVar2[1] + (float)param_1[0x165];

  fStack_1c = (float)param_1[0x15d];

  fStack_18 = *pfVar2 + (float)param_1[0x164];

  afStack_10[0] = (float)param_1[0x15c];

  fStack_84 = fVar5 - fStack_1c;

  fStack_ac = fStack_18 - afStack_10[0];

  fVar9 = (float)(uint)unaff_EBX;

  fStack_c8 = g_flOne;

  fStack_80 = (float)CONCAT31(fStack_80._1_3_,*(uint8_t *)((int)in_EAX + 0x8d));

  (**(code **)(*in_EAX + 0x24))(0);

  if ((((0.0 <= fStack_1c) || (fStack_1c < 0.0)) || ((float)iStack_b8 <= unaff_ESI)) ||

     (unaff_ESI < 0.0)) {

    fVar5 = 2.3509887e-38;

  }

  else if ((((float)-(unaff_retaddr / 2) <= fStack_1c) || (fStack_1c < (float)(unaff_retaddr / 2)))

          || (((float)(iStack_b8 - param_2 / 2) <= unaff_ESI || (unaff_ESI < (float)(param_2 / 2))))

          ) {

    (**(code **)(*in_EAX + 0x24))(1);

  }

  cVar10 = (char)((uint)fVar5 >> 0x18);

  if ((param_4 == '\0') && (cVar10 != '\0')) {

    return;

  }

  if ((in_stack_0000001c == (int *)0x0) || (param_3 == (int *)0x0)) {

    fVar5 = 0.0;

  }

  else {

    fVar6 = (float)*(int *)(*param_3 + 0x1c);

    fVar9 = (float)in_stack_0000001c[2] / fVar6;

    fVar6 = (float)*in_stack_0000001c / fVar6;

    fVar5 = (float)*(int *)(*param_3 + 0x20);

    fStack_c8 = (float)in_stack_0000001c[3] / fVar5;

    fVar5 = (float)in_stack_0000001c[1] / fVar5;

  }

  uVar4 = *puStack_4;

  uStack_74 = 0xffffffff;

  uStack_5c = 0xffffffff;

  uStack_44 = 0xffffffff;

  uStack_2c = 0xffffffff;

  uStack_78 = 0;

  uStack_60 = 0;

  uStack_48 = 0;

  uStack_30 = 0;

  if (param_1[0x89] != 0) {

    pbVar1 = (byte *)param_1[0x89];

    uStack_c4 = (uint8_t)(((uint)*pbVar1 * (uVar4 & 0xff)) / 0xff);

    uStack_b4 = (uint8_t)(((uint)pbVar1[1] * (uVar4 >> 8 & 0xff)) / 0xff);

    uVar4 = CONCAT13((char)(((uint)pbVar1[3] * (uVar4 >> 0x18)) / 0xff),

                     CONCAT12((char)(((uint)pbVar1[2] * (uVar4 >> 0x10 & 0xff)) / 0xff),

                              CONCAT11(uStack_b4,uStack_c4)));

  }

  if ((char)(uVar4 >> 0x18) == -1) {

    uVar4 = CONCAT13(0xfe,(int3)uVar4);

  }

  fVar7 = afStack_a8[8] * afStack_a8[8] + local_b0 * local_b0;

  if (((DAT_00a0f74c * 0.0 <= SQRT(fVar7)) && (*(char *)((int)param_1 + 0x5b9) == '\0')) ||

     (cVar10 != '\0')) {

    if (param_4 == '\0') goto LAB_00859a65;

    fStack_ac = g_flOne / SQRT(fVar7);

    fVar6 = local_b0 * fStack_ac;

    fStack_ac = fStack_ac * afStack_a8[8];

    iVar3 = iStack_b8;

    if (0 < iStack_b8) {

      iVar3 = 0;

    }

    fVar7 = (float)iVar3 * DAT_00a0f720 * fVar6 + fStack_14;

    fVar5 = (float)iVar3 * DAT_00a0f720 * fStack_ac + fStack_20;

    fVar9 = (float)((int)(param_1[0x14e] + (param_1[0x14e] >> 0x1f & 3U)) >> 2);

    local_b0 = fVar6;

    if (*(char *)((int)param_1 + 0x5b9) != '\0') {

      FUN_00857100(fStack_1c,unaff_ESI,fStack_14,fStack_20,0,0,0,iStack_b8,&stack0xffffff34);

    }

    fVar8 = fStack_ac * fVar9;

    fVar6 = fVar6 * fVar9;

    afStack_a8[0] = fVar6 + fVar8 + fVar7;

    afStack_a8[3] = fVar6 + fVar8 + fVar5;

    fStack_7c = (fVar5 - fVar6) + fVar8;

    fStack_68 = (fVar6 + fVar7) - fVar8;

    fStack_50 = (fVar7 - fVar6) - fVar8;

    fStack_4c = (fVar6 + fVar5) - fVar8;

    fStack_38 = (fVar7 - fVar6) + fVar8;

    afStack_a8[1] = fStack_7c;

    afStack_a8[2] = fStack_68;

    afStack_a8[4] = fStack_50;

    afStack_a8[5] = fStack_4c;

    afStack_a8[6] = fStack_38;

    afStack_a8[7] = (fVar5 - fVar6) - fVar8;

    iVar3 = 0;

    do {

      if (((afStack_a8[iVar3 * 2] <= 0.0 && afStack_a8[iVar3 * 2] != 0.0) ||

          (0.0 <= afStack_a8[iVar3 * 2])) && (fVar6 = 0.0 - afStack_a8[iVar3 * 2], fVar6 != 0.0)) {

        afStack_a8[0] = fVar6 + afStack_a8[0];

        fStack_68 = fVar6 + fStack_68;

        fStack_50 = fVar6 + fStack_50;

        fStack_38 = fVar6 + fStack_38;

        afStack_a8[2] = fStack_68;

        afStack_a8[4] = fStack_50;

        afStack_a8[6] = fStack_38;

      }

      if (0.0 < afStack_a8[iVar3 * 2 + 1] || afStack_a8[iVar3 * 2 + 1] == 0.0) {

        fVar6 = (float)iStack_b8;

        if (fVar6 <= afStack_a8[iVar3 * 2 + 1]) goto LAB_00859926;

      }

      else {

        fVar6 = 0.0;

LAB_00859926:

        fVar6 = fVar6 - afStack_a8[iVar3 * 2 + 1];

        if (fVar6 != 0.0) {

          fStack_7c = fVar6 + fStack_7c;

          afStack_a8[3] = fVar6 + afStack_a8[3];

          fStack_4c = fVar6 + fStack_4c;

          afStack_a8[1] = fStack_7c;

          afStack_a8[5] = fStack_4c;

          afStack_a8[7] = fVar6 + afStack_a8[7];

          fStack_38 = afStack_a8[6];

        }

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < 4);

    param_3 = (int *)param_1[0x173];

    fStack_80 = afStack_a8[0];

    fStack_64 = afStack_a8[3];

    fStack_54 = 0.0;

    fStack_40 = g_flOne;

    fStack_34 = afStack_a8[7];

    fStack_28 = 0.0;

    fStack_24 = g_flOne;

    if (param_3 == (int *)0x0) {

      param_3 = (int *)&DAT_00d1ec78;

    }

  }

  else {

    fStack_80 = fStack_1c - (float)unaff_retaddr * DAT_00a0f298;

    fStack_7c = unaff_ESI - (float)param_2 * DAT_00a0f298;

    fStack_68 = (float)unaff_retaddr * DAT_00a0f298 + fStack_1c;

    fStack_4c = unaff_ESI + (float)param_2 * DAT_00a0f298;

    fStack_24 = fStack_c8;

    fStack_64 = fStack_7c;

    fStack_54 = fVar5;

    fStack_50 = fStack_68;

    fStack_40 = fVar9;

    fStack_38 = fStack_80;

    fStack_34 = fStack_4c;

    fStack_28 = fVar6;

    if (param_3 == (int *)0x0) {

      param_3 = (int *)&DAT_00d1ec78;

    }

  }

  uStack_74 = uVar4;

  fStack_70 = fStack_28;

  fStack_6c = fStack_54;

  uStack_5c = uVar4;

  fStack_58 = fStack_40;

  uStack_44 = uVar4;

  fStack_3c = fStack_24;

  uStack_2c = uVar4;

  FUN_00757890(&fStack_80,4,param_3,1,&DAT_00d1ecac);

LAB_00859a65:

  if (*(char *)((int)in_EAX + 0x8d) != fStack_84._0_1_) {

    (**(code **)(*in_EAX + 0x24))(fStack_84);

  }

  return;

}
