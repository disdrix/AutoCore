// =============================================================================
// FUN_0072f970
// -----------------------------------------------------------------------------
// Stable ID: aa_0072f970
// Address:   0x0072f970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072f970 @ 0x0072f970
// Stable ID: aa_0072f970
// Embedded strings (evidence for future rename):
//   - "MatDiffuse"
//   - "MatAmbient"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~220 non-empty decompiler lines.
//  - Control keywords: if×16, for×2, goto×1, return×1.
//  - Notable callees: FUN_00972e50×6, FUN_00752370×4, FUN_00753160×4, FUN_0043f4b0×2, FUN_00734550×2, FUN_00752df0×2, FUN_00967150×2, FUN_0044b930.
//  - Strings: "MatDiffuse"; "MatAmbient".
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



void FUN_0072f970(int param_1)



{

  byte bVar1;

  float *pfVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float *pfVar5;

  int iVar6;

  float fVar7;

  float local_110;

  float local_10c;

  float local_108;

  float local_104;

  int local_100;

  float local_fc;

  float *local_f8;

  float local_f4;

  float local_f0;

  float local_ec;

  float local_e8;

  float local_e4;

  uint32_t /* width from decompiler */ local_e0;

  uint8_t local_dc [4];

  float local_d8;

  uint8_t local_d4 [4];

  float local_d0 [4];

  float local_c0;

  float local_bc;

  float local_b8;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_90 [4];

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_40;

  float local_3c;

  float local_38;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  

  fVar7 = *(float *)(param_1 + 0x10);

  pfVar2 = (float *)((int)fVar7 + 0x30);

  local_fc = fVar7;

  local_f8 = pfVar2;

  if ((*(byte *)((int)fVar7 + 0xec) & 1) != 0) {

    pfVar2 = (float *)FUN_00972e50();

  }

  pfVar5 = local_d0;

  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {

    *pfVar5 = *pfVar2;

    pfVar2 = pfVar2 + 1;

    pfVar5 = pfVar5 + 1;

  }

  local_d0[0] = local_d0[0] * DAT_00aaa8fc;

  local_d0[1] = local_d0[1] * DAT_00aaa8fc;

  local_d0[2] = local_d0[2] * DAT_00aaa8fc;

  local_c0 = local_c0 * DAT_00aaa8fc;

  local_bc = local_bc * DAT_00aaa8fc;

  local_b8 = local_b8 * DAT_00aaa8fc;

  local_b0 = local_b0 * DAT_00aaa8fc;

  local_ac = local_ac * DAT_00aaa8fc;

  local_a8 = local_a8 * DAT_00aaa8fc;

  if ((_DAT_00d20c74 & 1) == 0) {

    _DAT_00d20c74 = _DAT_00d20c74 | 1;

    _DAT_00d20c68 = g_flOne;

    _DAT_00d20c6c = g_flOne;

    _DAT_00d20c70 = g_flOne;

  }

  local_e0 = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  FUN_00752df0(local_e0,local_d0,1,&DAT_00d20c68,0,0);

  if (*(int *)((int)fVar7 + 0x148) < 0) {

    iVar3 = 0xfa;

    iVar6 = 0x32;

  }

  else {

    iVar6 = 200;

    if (*(int *)((int)fVar7 + 0x150) == 0) {

      iVar3 = 0x32;

      bVar1 = 0x32;

      goto LAB_0072fac2;

    }

    iVar3 = 200;

  }

  bVar1 = 0;

LAB_0072fac2:

  local_d8 = (float)iVar3;

  local_110 = local_d8 * DAT_00b017e8;

  local_f0 = (float)iVar6;

  local_10c = local_f0 * DAT_00b017e8;

  local_f4 = (float)bVar1;

  local_108 = local_f4 * DAT_00b017e8;

  local_104 = DAT_00b017e8 * DAT_00aaa6f8;

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_00752370(local_dc,"MatDiffuse");

  FUN_00753160(*puVar4,local_110,local_10c,local_108,local_104);

  local_110 = local_d8 * DAT_00b017e8;

  local_10c = local_f0 * DAT_00b017e8;

  local_108 = local_f4 * DAT_00b017e8;

  local_104 = DAT_00b017e8 * DAT_00aaa6f8;

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_00752370(local_d4,"MatAmbient");

  FUN_00753160(*puVar4,local_110,local_10c,local_108,local_104);

  if (*(int *)(local_100 + 0x10) != 0) {

    FUN_0043f4b0();

    fVar7 = local_fc;

  }

  iVar6 = local_100;

  if (*(int *)(*(int *)(local_100 + 0x10) + 0x34) == 0) {

    FUN_00967150(*(int *)(local_100 + 0x10) + 0x24);

  }

  FUN_00734550();

  if (*(int *)(iVar6 + 0x18) != 0) {

    FUN_0044b930(0);

  }

  FUN_0075e9f0(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x2c),0,*(uint32_t /* width from decompiler */ *)(iVar6 + 0x1c),0,0);

  if (-1 < *(int *)((int)fVar7 + 0x148)) {

    iVar6 = (*(int *)((int)fVar7 + 0x148) - *(int *)((int)fVar7 + 0x144)) * 0x160;

    local_ec = *(float *)(iVar6 + 0xc0 + (int)fVar7) - *(float *)((int)fVar7 + 0xc0);

    iVar6 = iVar6 + 0xc0 + (int)fVar7;

    local_e8 = *(float *)(iVar6 + 4) - *(float *)((int)fVar7 + 0xc4);

    local_e4 = *(float *)(iVar6 + 8) - *(float *)((int)fVar7 + 200);

    local_110 = 0.0;

    local_10c = g_flOne;

    local_108 = 0.0;

    FUN_00972580(&local_ec,&local_110);

    pfVar2 = local_f8;

    if (((uint)local_f8[0x2f] & 1) != 0) {

      local_f8 = (float *)FUN_00972e50();

    }

    local_f8 = (float *)local_f8[3];

    pfVar5 = pfVar2;

    if (((uint)pfVar2[0x2f] & 1) != 0) {

      pfVar5 = (float *)FUN_00972e50();

    }

    local_fc = pfVar5[7];

    pfVar5 = pfVar2;

    if (((uint)pfVar2[0x2f] & 1) != 0) {

      pfVar5 = (float *)FUN_00972e50();

    }

    local_f4 = pfVar5[0xb];

    pfVar5 = pfVar2;

    if (((uint)pfVar2[0x2f] & 1) != 0) {

      pfVar5 = (float *)FUN_00972e50();

    }

    local_f0 = pfVar5[0xf];

    local_110 = local_50 * DAT_00a0f718;

    local_10c = local_4c * DAT_00a0f718;

    local_108 = local_48 * DAT_00a0f718;

    local_ec = local_40 * DAT_00a0f718;

    local_e8 = local_3c * DAT_00a0f718;

    local_e4 = local_38 * DAT_00a0f718;

    if (((uint)pfVar2[0x2f] & 1) != 0) {

      pfVar2 = (float *)FUN_00972e50();

    }

    local_90[3] = (float)local_f8;

    local_74 = local_fc;

    local_70 = local_30;

    local_6c = local_2c;

    local_68 = local_28;

    local_64 = local_f4;

    local_60 = pfVar2[0xc];

    local_5c = pfVar2[0xd];

    local_58 = pfVar2[0xe];

    local_90[0] = local_110;

    local_90[1] = local_10c;

    local_90[2] = local_108;

    local_80 = local_ec;

    local_7c = local_e8;

    local_78 = local_e4;

    local_54 = local_f0;

    pfVar2 = local_90;

    pfVar5 = local_d0;

    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {

      *pfVar5 = *pfVar2;

      pfVar2 = pfVar2 + 1;

      pfVar5 = pfVar5 + 1;

    }

    if ((_DAT_00d20c74 & 2) == 0) {

      _DAT_00d20c74 = _DAT_00d20c74 | 2;

      _DAT_00d20c5c = g_flOne;

      _DAT_00d20c60 = g_flOne;

      _DAT_00d20c64 = g_flOne;

    }

    FUN_00752df0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),local_d0,1,&DAT_00d20c5c,0,0);

    local_110 = DAT_00b017e8 * DAT_00a27c24;

    local_10c = DAT_00b017e8 * DAT_00aaaa24;

    local_104 = DAT_00b017e8 * DAT_00aaa6f8;

    local_108 = local_10c;

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00752370(local_d4,"MatDiffuse");

    FUN_00753160(*puVar4,local_110,local_10c,local_108,local_104);

    local_110 = DAT_00b017e8 * DAT_00a27c24;

    local_10c = DAT_00b017e8 * DAT_00aaaa24;

    local_104 = DAT_00b017e8 * DAT_00aaa6f8;

    local_108 = local_10c;

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00752370(local_dc,"MatAmbient");

    FUN_00753160(*puVar4,local_110,local_10c,local_108,local_104);

    if (*(int *)(local_100 + 8) != 0) {

      FUN_0043f4b0();

    }

    if (*(int *)(*(int *)(local_100 + 8) + 0x34) == 0) {

      FUN_00967150(*(int *)(local_100 + 8) + 0x24);

    }

    FUN_00734550();

    FUN_0075e8e0(*(uint32_t /* width from decompiler */ *)(local_100 + 0x2c),0,*(uint32_t /* width from decompiler */ *)(local_100 + 0x20));

  }

  return;

}
