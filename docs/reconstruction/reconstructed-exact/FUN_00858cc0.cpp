// =============================================================================
// FUN_00858cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00858cc0
// Address:   0x00858cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00858cc0 @ 0x00858cc0
// Stable ID: aa_00858cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~164 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_004141c0×4, FUN_00757890×2, FUN_00858cc0.
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

void FUN_00858cc0(void)



{

  int *in_EAX;

  int iVar1;

  int *piVar2;

  float *pfVar3;

  float *pfVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float *pfVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uVar14;

  int iStack_d0;

  float fStack_cc;

  float fStack_c8;

  float fStack_c4;

  float fStack_c0;

  float fStack_bc;

  float local_b8;

  float fStack_b4;

  float fStack_b0;

  float fStack_ac;

  float fStack_a8;

  float fStack_a0;

  uint8_t auStack_98 [4];

  float fStack_94;

  uint8_t auStack_90 [4];

  float fStack_8c;

  float fStack_88;

  float fStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  float fStack_7c;

  float fStack_78;

  float fStack_74;

  uint32_t /* width from decompiler */ uStack_6c;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  uint32_t /* width from decompiler */ uStack_58;

  float fStack_54;

  float fStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_44;

  float fStack_40;

  float fStack_3c;

  

  iVar1 = (**(code **)(*in_EAX + 0x140))(&local_b8,1);

  fStack_84 = (float)*(int *)(iVar1 + 4);

  uVar14 = 1;

  pfVar4 = &fStack_b0;

  piVar2 = (int *)(**(code **)(*in_EAX + 0x140))(pfVar4,1);

  fVar6 = (float)*piVar2;

  uVar13 = 1;

  pfVar12 = &fStack_c8;

  (**(code **)(*in_EAX + 0x140))(pfVar12,1,pfVar4,uVar14,fVar6);

  if (iStack_d0 < (int)fStack_cc) {

    fStack_cc = (float)iStack_d0;

  }

  iVar1 = (int)fStack_cc;

  if (DAT_00af9320 <= DAT_00af931c) {

    if (DAT_00af9320 < DAT_00af931c) {

      iVar1 = (int)(((float)(int)fStack_cc / DAT_00af931c) * DAT_00af9320);

    }

  }

  else {

    fStack_cc = (float)(int)(((float)(int)fStack_cc / DAT_00af9320) * DAT_00af931c);

  }

  fVar7 = (float)(int)fStack_cc * (float)in_EAX[0x141] * fVar6;

  fVar6 = (float)iVar1 * (float)in_EAX[0x141] * fVar6;

  local_b8 = 0.0;

  fStack_b4 = 0.0;

  fStack_b0 = g_flOne;

  fStack_ac = 0.0;

  fStack_c0 = g_flOne;

  fStack_bc = g_flOne;

  fStack_cc = g_flOne;

  fStack_a8 = 0.0;

  fStack_a0 = DAT_00af9320;

  pfVar3 = (float *)FUN_004141c0(&stack0xffffff20);

  fStack_c8 = (float)in_EAX[0x164] + *pfVar3;

  fStack_c4 = (float)in_EAX[0x165] + pfVar3[1];

  if (fStack_c8 < 0.0) {

    local_b8 = (DAT_00aaa668 / fVar7) * fStack_c8;

    fStack_c8 = 0.0;

  }

  if (fStack_c4 < 0.0) {

    fStack_b4 = (DAT_00aaa668 / fVar6) * fStack_c4;

    fStack_c4 = 0.0;

  }

  fStack_a8 = DAT_00af931c;

  fStack_a0 = DAT_00af9320;

  pfVar3 = (float *)FUN_004141c0(&stack0xffffff20);

  if ((float)pfVar4 <= (float)in_EAX[0x164] + *pfVar3) {

    fStack_b0 = g_flOne - (((float)in_EAX[0x164] + *pfVar3) - (float)pfVar4) / fVar7;

  }

  if ((float)in_EAX[0x165] + pfVar3[1] < 0.0) {

    fStack_ac = (DAT_00aaa668 / fVar6) * ((float)in_EAX[0x165] + pfVar3[1]);

  }

  fStack_a8 = DAT_00af931c;

  fStack_a0 = 0.0;

  pfVar3 = (float *)FUN_004141c0(auStack_90);

  fVar8 = (float)in_EAX[0x164] + *pfVar3;

  fVar11 = (float)in_EAX[0x165] + pfVar3[1];

  if ((float)pfVar4 <= fVar8) {

    fStack_c0 = g_flOne - (fVar8 - (float)pfVar4) / fVar7;

    fVar8 = (float)pfVar4 - g_flOne;

  }

  if (fStack_94 <= fVar11) {

    fStack_bc = g_flOne - (fVar11 - fStack_94) / fVar6;

    fVar11 = fStack_94 - g_flOne;

  }

  fStack_a8 = 0.0;

  fStack_a0 = 0.0;

  pfVar4 = (float *)FUN_004141c0(auStack_90);

  fVar9 = (float)in_EAX[0x164] + *pfVar4;

  fVar10 = (float)in_EAX[0x165] + pfVar4[1];

  if (fVar9 < 0.0) {

    fVar9 = 0.0;

  }

  if (fStack_94 <= fVar10) {

    fStack_cc = g_flOne - (fVar10 - fStack_94) / fVar6;

    fVar10 = fStack_94 - g_flOne;

  }

  uVar14 = 0;

  puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*in_EAX + 0x164))(0,pfVar12,uVar13,fVar9,fVar10);

  uStack_80 = *puVar5;

  fStack_8c = fStack_cc;

  fStack_88 = fStack_c8;

  fStack_7c = fStack_bc;

  uVar13 = 0;

  fStack_78 = local_b8;

  puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*in_EAX + 0x164))(0);

  uStack_6c = *puVar5;

  fStack_68 = local_b8;

  fStack_64 = fStack_b4;

  fStack_78 = fVar8;

  fStack_74 = fVar11;

  puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*in_EAX + 0x164))(0);

  uStack_58 = *puVar5;

  fStack_54 = fStack_cc;

  fStack_50 = fStack_c8;

  fStack_64 = fVar10;

  fStack_60 = fVar7;

  puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*in_EAX + 0x164))(0);

  uStack_44 = *puVar5;

  fStack_50 = (float)uVar13;

  uStack_4c = uVar14;

  fStack_40 = fVar8;

  fStack_3c = fVar11;

  iVar1 = (**(code **)(*in_EAX + 700))();

  puVar5 = &DAT_00d1ecac;

  uVar13 = 1;

  if (iVar1 != 0) {

    uVar14 = (**(code **)(*in_EAX + 700))();

    FUN_00757890(auStack_98,4,uVar14,uVar13,puVar5);

    return;

  }

  FUN_00757890(auStack_98,4,&DAT_00d1ec78,1,&DAT_00d1ecac);

  return;

}
