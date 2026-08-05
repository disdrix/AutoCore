// READABILITY (auto CF):
//  - Body size: ~251 non-empty decompiler lines.
//  - Control keywords: if×15, for×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00414b60×3, FUN_00982100×3, CONCAT31×2, FUN_00414c20×2, _eh_vector_destructor_iterator_×2, FUN_004451c0, FUN_0044bbc0, FUN_00730b50.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp".
//  - Return sites: 1.

// =============================================================================
// Named_gfxDeviceVB_00730b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00730b50
// Address:   0x00730b50  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ Named_gfxDeviceVB_00730b50(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint64_t uVar10;

  int local_124;

  undefined **local_120;

  int *local_11c;

  float local_118;

  int local_114;

  uint32_t /* width from decompiler */ *local_110;

  int local_10c;

  uint8_t local_108 [4];

  int local_104;

  int local_100;

  uint32_t /* width from decompiler */ local_fc;

  uint32_t /* width from decompiler */ local_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint8_t local_f0 [8];

  int local_e8;

  int local_e4;

  uint32_t /* width from decompiler */ local_dc;

  uint32_t /* width from decompiler */ local_d8;

  uint32_t /* width from decompiler */ local_d4;

  float local_d0;

  uint32_t /* width from decompiler */ local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint32_t /* width from decompiler */ local_c0;

  uint32_t /* width from decompiler */ local_bc;

  uint32_t /* width from decompiler */ local_b8;

  uint32_t /* width from decompiler */ local_b0;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  uint32_t /* width from decompiler */ local_90;

  uint32_t /* width from decompiler */ local_8c;

  float local_88;

  uint32_t /* width from decompiler */ local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  float local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_28;

  uint8_t local_24 [24];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1f4c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  _eh_vector_constructor_iterator_(local_f0,0x44,3,FUN_00982040,FUN_004579d0);

  local_4 = 0;

  local_120 = (undefined **)g_flOne;

  local_11c = (int *)0x0;

  local_118 = 0.0;

  local_110 = (uint32_t /* width from decompiler */ *)0xff800000;

  local_bc = DAT_00a10e78;

  local_114 = 0xff008000;

  local_dc = DAT_00d1a6c0;

  local_c4 = DAT_00a0f718;

  local_d8 = DAT_00d1a6c4;

  local_d4 = DAT_00d1a6c8;

  local_d0 = g_flOne;

  local_b8 = DAT_00aaa8f4;

  local_cc = 0;

  local_c8 = 0;

  local_c0 = DAT_00aaa7b8;

  local_b0 = 0xff800000;

  FUN_00982100(3);

  local_120 = (undefined **)0x0;

  local_118 = 0.0;

  local_78 = DAT_00a10e78;

  local_80 = DAT_00a0f718;

  local_98 = DAT_00d1a6c0;

  local_94 = DAT_00d1a6c4;

  local_90 = DAT_00d1a6c8;

  local_11c = (int *)g_flOne;

  local_74 = DAT_00aaa8f4;

  local_8c = 0;

  local_88 = g_flOne;

  local_84 = 0;

  local_7c = DAT_00aaa7b8;

  local_6c = local_114;

  FUN_00982100(3);

  local_120 = (undefined **)0x0;

  local_11c = (int *)0x0;

  local_118 = g_flOne;

  local_34 = DAT_00a10e78;

  local_54 = DAT_00d1a6c0;

  local_3c = DAT_00a0f718;

  local_50 = DAT_00d1a6c4;

  local_4c = DAT_00d1a6c8;

  local_48 = 0;

  local_30 = DAT_00aaa8f4;

  local_44 = 0;

  local_40 = g_flOne;

  local_38 = DAT_00aaa7b8;

  local_28 = 0xff000080;

  FUN_00982100(3);

  if (local_e8 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = (local_e4 - local_e8) / 0x24;

  }

  if (local_e8 == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (local_e4 - local_e8) / 0x24;

  }

  *(uint *)(param_1 + 4 + param_2 * 4) = (uVar5 / 3) * 3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc + param_2 * 4) = 4;

  local_104 = 0;

  local_100 = 0;

  local_fc = 0;

  local_f8 = 0;

  local_f4 = 0;

  local_4._0_1_ = 1;

  local_10c = iVar3 * 3;

  FUN_007478c0(0x152);

  local_11c = (int *)0x0;

  local_120 = &PTR_FUN_00a9db18;

  local_4._0_1_ = 2;

  iVar3 = FUN_00414c20(iVar3 * 3,local_108,8,0);

  if (iVar3 < 0) {

    local_4 = CONCAT31(local_4._1_3_,1);

    if (local_11c != (int *)0x0) {

      piVar6 = local_11c + 1;

      *piVar6 = *piVar6 + -1;

      if (*piVar6 == 0) {

        (**(code **)(*local_11c + 8))();

      }

    }

    FUN_00414b60();

    local_4 = 0xffffffff;

    _eh_vector_destructor_iterator_(local_f0,0x44,3,FUN_004579d0);

    uVar4 = 0xffffffff;

  }

  else {

    piVar6 = (int *)local_11c[4];

    if (piVar6 == (int *)0x0) {

      puVar7 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      piVar2 = (int *)*piVar6;

      if (piVar2 == (int *)0x0) {

        puVar7 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        iVar3 = (**(code **)(*piVar2 + 0x2c))

                          (piVar2,piVar6[2] * local_11c[5],piVar6[2] * local_11c[6],&local_110,0x800

                          );

        if (iVar3 < 0) {

          puVar7 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          piVar6[4] = piVar6[4] + 1;

          puVar7 = local_110;

        }

      }

    }

    if ((local_104 == 0) || (local_100 - local_104 >> 3 == 0)) {

      local_124 = 0;

    }

    else {

      uVar10 = FUN_007467b0();

      local_124 = (int)uVar10 + (uint)*(ushort *)((int)((ulonglong)uVar10 >> 0x20) + 2);

    }

    piVar6 = &local_e8;

    local_114 = 3;

    do {

      puVar8 = (uint32_t /* width from decompiler */ *)*piVar6;

      iVar3 = 0;

      if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

        iVar3 = (piVar6[1] - (int)puVar8) / 0x24;

      }

      puVar9 = puVar7;

      for (uVar5 = (uint)(iVar3 * 0x24) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *puVar9 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

      }

      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {

        *(uint8_t *)puVar9 = *(uint8_t *)puVar8;

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

      }

      iVar3 = 0;

      if (*piVar6 != 0) {

        iVar3 = (piVar6[1] - *piVar6) / 0x24;

      }

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + iVar3 * local_124);

      piVar6 = piVar6 + 0x11;

      local_114 = local_114 + -1;

    } while (local_114 != 0);

    piVar6 = (int *)local_11c[4];

    if ((piVar6 != (int *)0x0) && (piVar2 = (int *)*piVar6, piVar2 != (int *)0x0)) {

      piVar1 = piVar6 + 4;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                       "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

        piVar6[4] = 0;

      }

      else {

        (**(code **)(*piVar2 + 0x30))(piVar2);

      }

    }

    iVar3 = *(int *)(*(int *)(param_1 + 0x34 + param_2 * 8) + 0x14);

    if ((iVar3 == 0) || (uVar4 = 0x10, *(char *)(iVar3 + 0x10) == '\0')) {

      uVar4 = 0x20;

    }

    FUN_004451c0(local_24,local_108);

    local_4._0_1_ = 3;

    FUN_00747390();

    FUN_00414c20(local_10c,local_24,uVar4,0);

    uVar4 = FUN_0044bbc0(&local_120,param_1 + 0x24 + param_2 * 8,0);

    FUN_00414b60();

    local_4 = CONCAT31(local_4._1_3_,1);

    piVar6 = local_11c + 1;

    *piVar6 = *piVar6 + -1;

    if (*piVar6 == 0) {

      (**(code **)(*local_11c + 8))();

    }

    FUN_00414b60();

    local_4 = 0xffffffff;

    _eh_vector_destructor_iterator_(local_f0,0x44,3,FUN_004579d0);

  }

  ExceptionList = pvStack_c;

  return uVar4;

}
