// READABILITY (auto CF):
//  - Body size: ~318 non-empty decompiler lines.
//  - Control keywords: if×27, for×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00752370×4, FUN_0096fff0×4, FUN_00414b60×3, FUN_00982100×3, CONCAT31×2, FUN_00414c20×2, _eh_vector_destructor_iterator_×2, FUN_004246a0.
//  - Strings: "PalToolMaterialNoMap.fx"; "MatDiffuse"; "MatAmbient"; "MatSpecular".
//  - Return sites: 1.

// =============================================================================
// Named_gfxDeviceVB_0099d060
// -----------------------------------------------------------------------------
// Stable ID: aa_0099d060
// Address:   0x0099d060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxDeviceVB"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_gfxDeviceVB_0099d060(int param_1)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ **ppuVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int *piVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint64_t uVar12;

  uint32_t /* width from decompiler */ *local_128;

  int local_124;

  undefined **local_120;

  int *local_11c;

  float local_118;

  int local_114;

  int local_110;

  uint32_t /* width from decompiler */ local_10c;

  uint8_t auStack_108 [4];

  int iStack_104;

  int iStack_100;

  uint32_t /* width from decompiler */ uStack_fc;

  uint32_t /* width from decompiler */ uStack_f8;

  uint32_t /* width from decompiler */ uStack_f4;

  uint8_t local_f0 [8];

  int iStack_e8;

  int iStack_e4;

  uint32_t /* width from decompiler */ local_dc;

  uint32_t /* width from decompiler */ local_d8;

  uint32_t /* width from decompiler */ uStack_d4;

  float fStack_d0;

  uint32_t /* width from decompiler */ uStack_cc;

  uint32_t /* width from decompiler */ uStack_c8;

  uint32_t /* width from decompiler */ local_c4;

  float fStack_c0;

  uint32_t /* width from decompiler */ local_bc;

  float fStack_b8;

  uint32_t /* width from decompiler */ uStack_b0;

  uint32_t /* width from decompiler */ uStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  float fStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  float fStack_7c;

  uint32_t /* width from decompiler */ uStack_78;

  float fStack_74;

  uint32_t /* width from decompiler */ uStack_6c;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  float fStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  float fStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  float fStack_30;

  uint32_t /* width from decompiler */ uStack_28;

  uint8_t auStack_24 [24];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1ef4;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  _eh_vector_constructor_iterator_(local_f0,0x44,3,FUN_00982040,FUN_004579d0);

  local_4 = 0;

  local_110 = 0xff800000;

  local_114 = 0xff008000;

  local_124 = 0xff000080;

  FUN_00989e00(&local_128,"PalToolMaterialNoMap.fx");

  piVar10 = (int *)(param_1 + 0x20);

  FUN_009701d0(&local_128);

  ppuVar3 = &local_128;

  if (*piVar10 == 0) {

    local_128 = (uint32_t /* width from decompiler */ *)0xffffffff;

  }

  else {

    ppuVar3 = (uint32_t /* width from decompiler */ **)FUN_00752370(ppuVar3,"MatDiffuse");

  }

  if (-1 < (int)*ppuVar3) {

    FUN_0096fff0(piVar10,*ppuVar3);

  }

  if (*piVar10 == 0) {

    local_128 = (uint32_t /* width from decompiler */ *)0xffffffff;

    ppuVar3 = &local_128;

  }

  else {

    ppuVar3 = (uint32_t /* width from decompiler */ **)FUN_00752370(&local_128,"MatAmbient");

  }

  if (-1 < (int)*ppuVar3) {

    FUN_0096fff0(piVar10,*ppuVar3);

  }

  ppuVar3 = &local_128;

  if (*piVar10 == 0) {

    local_128 = (uint32_t /* width from decompiler */ *)0xffffffff;

  }

  else {

    ppuVar3 = (uint32_t /* width from decompiler */ **)FUN_00752370(ppuVar3,"MatSpecular");

  }

  if (-1 < (int)*ppuVar3) {

    FUN_0096fff0(piVar10,*ppuVar3);

  }

  if (*piVar10 == 0) {

    local_128 = (uint32_t /* width from decompiler */ *)0xffffffff;

    ppuVar3 = &local_128;

  }

  else {

    ppuVar3 = (uint32_t /* width from decompiler */ **)FUN_00752370(&local_128,"MatEmissive");

  }

  if (-1 < (int)*ppuVar3) {

    FUN_0096fff0(piVar10,*ppuVar3);

  }

  local_10c = 1;

  FUN_004246a0();

  piVar4 = (int *)FUN_0073d940(*piVar10);

  if (piVar4 != (int *)0x0) {

    piVar4[1] = piVar4[1] + 1;

    if (piVar4[1] == 1) {

      (**(code **)(*piVar4 + 4))();

    }

    piVar2 = (int *)*piVar10;

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *piVar10 = (int)piVar4;

  }

  local_120 = (undefined **)g_flOne;

  local_11c = (int *)0x0;

  local_118 = 0.0;

  local_bc = DAT_00a0f710;

  local_dc = DAT_00d1a6c0;

  local_c4 = DAT_00a10e78;

  local_d8 = DAT_00d1a6c4;

  uStack_d4 = DAT_00d1a6c8;

  fStack_d0 = g_flOne;

  fStack_b8 = g_flOverheatCoolFrac;

  uStack_cc = 0;

  uStack_c8 = 0;

  fStack_c0 = g_flMultiKillCountBlend;

  uStack_b0 = local_110;

  FUN_00982100(0xa6);

  local_120 = (undefined **)0x0;

  local_118 = 0.0;

  uStack_78 = DAT_00a0f710;

  uStack_98 = DAT_00d1a6c0;

  uStack_80 = DAT_00a10e78;

  uStack_94 = DAT_00d1a6c4;

  uStack_90 = DAT_00d1a6c8;

  local_11c = (int *)g_flOne;

  uStack_8c = 0;

  fStack_74 = g_flOverheatCoolFrac;

  fStack_88 = g_flOne;

  uStack_84 = 0;

  fStack_7c = g_flMultiKillCountBlend;

  uStack_6c = local_114;

  FUN_00982100(0xa6);

  local_120 = (undefined **)0x0;

  local_11c = (int *)0x0;

  local_118 = g_flOne;

  uStack_54 = DAT_00d1a6c0;

  uStack_50 = DAT_00d1a6c4;

  uStack_4c = DAT_00d1a6c8;

  uStack_34 = DAT_00a0f710;

  uStack_48 = 0;

  uStack_44 = 0;

  fStack_40 = g_flOne;

  uStack_3c = DAT_00a10e78;

  fStack_30 = g_flOverheatCoolFrac;

  fStack_38 = g_flMultiKillCountBlend;

  uStack_28 = local_124;

  FUN_00982100(0xa6);

  if (iStack_e8 == 0) {

    iVar5 = 0;

  }

  else {

    iVar5 = (iStack_e4 - iStack_e8) / 0x24;

  }

  if (iStack_e8 == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = (iStack_e4 - iStack_e8) / 0x24;

  }

  *(uint *)(param_1 + 0xa8) = (uVar7 / 3) * 3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = 4;

  iStack_104 = 0;

  iStack_100 = 0;

  uStack_fc = 0;

  uStack_f8 = 0;

  uStack_f4 = 0;

  local_4._0_1_ = 1;

  local_110 = iVar5 * 3;

  FUN_007478c0(0x152);

  local_11c = (int *)0x0;

  local_120 = &PTR_FUN_00a9db18;

  local_4._0_1_ = 2;

  iVar5 = FUN_00414c20(iVar5 * 3,auStack_108,8,0);

  if (iVar5 < 0) {

    local_4 = CONCAT31(local_4._1_3_,1);

    if (local_11c != (int *)0x0) {

      piVar10 = local_11c + 1;

      *piVar10 = *piVar10 + -1;

      if (*piVar10 == 0) {

        (**(code **)(*local_11c + 8))();

      }

    }

    FUN_00414b60();

    local_4 = 0xffffffff;

    _eh_vector_destructor_iterator_(local_f0,0x44,3,FUN_004579d0);

    uVar6 = 0xffffffff;

  }

  else {

    piVar10 = (int *)local_11c[4];

    if (piVar10 == (int *)0x0) {

      puVar8 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      piVar4 = (int *)*piVar10;

      if (piVar4 == (int *)0x0) {

        puVar8 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        iVar5 = (**(code **)(*piVar4 + 0x2c))

                          (piVar4,local_11c[5] * piVar10[2],local_11c[6] * piVar10[2],&local_128,

                           0x800);

        if (iVar5 < 0) {

          puVar8 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          piVar10[4] = piVar10[4] + 1;

          puVar8 = local_128;

        }

      }

    }

    if ((iStack_104 == 0) || (local_124 = iStack_100 - iStack_104 >> 3, local_124 == 0)) {

      local_124 = 0;

    }

    else {

      uVar12 = FUN_007467b0();

      local_124 = (int)uVar12 + (uint)*(ushort *)((int)((ulonglong)uVar12 >> 0x20) + 2);

    }

    piVar10 = &iStack_e8;

    local_114 = 3;

    do {

      puVar9 = (uint32_t /* width from decompiler */ *)*piVar10;

      iVar5 = 0;

      if (puVar9 != (uint32_t /* width from decompiler */ *)0x0) {

        iVar5 = (piVar10[1] - (int)puVar9) / 0x24;

      }

      puVar11 = puVar8;

      for (uVar7 = (uint)(iVar5 * 0x24) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

        *puVar11 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar11 = puVar11 + 1;

      }

      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {

        *(uint8_t *)puVar11 = *(uint8_t *)puVar9;

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        puVar11 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

      }

      iVar5 = 0;

      if (*piVar10 != 0) {

        iVar5 = (piVar10[1] - *piVar10) / 0x24;

      }

      puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + iVar5 * local_124);

      piVar10 = piVar10 + 0x11;

      local_114 = local_114 + -1;

    } while (local_114 != 0);

    piVar10 = (int *)local_11c[4];

    if ((piVar10 != (int *)0x0) && (piVar4 = (int *)*piVar10, piVar4 != (int *)0x0)) {

      piVar2 = piVar10 + 4;

      *piVar2 = *piVar2 + -1;

      if (*piVar2 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                       "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

        piVar10[4] = 0;

      }

      else {

        (**(code **)(*piVar4 + 0x30))(piVar4);

      }

    }

    iVar5 = *(int *)(*(int *)(param_1 + 0x20) + 0x14);

    if ((iVar5 == 0) || (uVar6 = 0x10, *(char *)(iVar5 + 0x10) == '\0')) {

      uVar6 = 0x20;

    }

    FUN_004451c0(auStack_24,auStack_108);

    local_4._0_1_ = 3;

    FUN_00747390();

    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

    FUN_00414c20(local_110,auStack_24,uVar6,0);

    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

    uVar6 = FUN_0044bbc0(&local_120,param_1 + 8,0);

    FUN_00414b60();

    local_4 = CONCAT31(local_4._1_3_,1);

    piVar10 = local_11c + 1;

    *piVar10 = *piVar10 + -1;

    if (*piVar10 == 0) {

      (**(code **)(*local_11c + 8))();

    }

    FUN_00414b60();

    local_4 = 0xffffffff;

    _eh_vector_destructor_iterator_(local_f0,0x44,3,FUN_004579d0);

  }

  ExceptionList = pvStack_c;

  return uVar6;

}
