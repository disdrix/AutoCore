// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f1ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f1ec0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic
// Address:   0x005f1ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~353 non-empty decompiler lines.
//  - Control keywords: if×15, return×8, do×3, while×3, goto×2, switch×1.
//  - Notable callees: FUN_005f1ec0×6, FUN_005ee860×4, FUN_005eb040×3, FUN_005b3300×2, FUN_005b3370×2, FUN_005d68f0, FUN_005ee680, FUN_005ee750.
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f1ec0(int *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  uint uVar2;

  undefined **ppuVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iStack_1e0;

  undefined **ppuStack_1dc;

  uint uStack_1d8;

  uint uStack_1d4;

  undefined **ppuStack_1d0;

  uint uStack_1cc;

  int iStack_1c8;

  int iStack_1c4;

  uint uStack_1c0;

  int iStack_1bc;

  uint uStack_1b8;

  int iStack_1b4;

  int iStack_1a4;

  float local_1a0;

  float local_19c;

  uint32_t /* width from decompiler */ local_190;

  uint32_t /* width from decompiler */ local_18c;

  uint32_t /* width from decompiler */ local_188;

  uint32_t /* width from decompiler */ local_184;

  float local_180;

  float local_17c;

  float local_178;

  uint32_t /* width from decompiler */ local_174;

  float local_170;

  float local_16c;

  float local_168;

  uint32_t /* width from decompiler */ local_164;

  float local_160;

  float local_15c;

  float local_158;

  uint32_t /* width from decompiler */ local_154;

  uint32_t /* width from decompiler */ uStack_150;

  uint32_t /* width from decompiler */ uStack_14c;

  uint32_t /* width from decompiler */ uStack_148;

  uint32_t /* width from decompiler */ uStack_144;

  uint32_t /* width from decompiler */ uStack_140;

  uint32_t /* width from decompiler */ uStack_13c;

  uint32_t /* width from decompiler */ uStack_138;

  uint32_t /* width from decompiler */ uStack_134;

  uint32_t /* width from decompiler */ uStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint32_t /* width from decompiler */ uStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  uint32_t /* width from decompiler */ uStack_11c;

  uint32_t /* width from decompiler */ uStack_118;

  uint32_t /* width from decompiler */ uStack_114;

  uint32_t /* width from decompiler */ uStack_110;

  uint32_t /* width from decompiler */ uStack_10c;

  uint32_t /* width from decompiler */ uStack_100;

  uint32_t /* width from decompiler */ uStack_fc;

  uint32_t /* width from decompiler */ uStack_f8;

  uint32_t /* width from decompiler */ uStack_f4;

  uint32_t /* width from decompiler */ uStack_f0;

  uint32_t /* width from decompiler */ uStack_ec;

  uint32_t /* width from decompiler */ uStack_e8;

  uint32_t /* width from decompiler */ uStack_e4;

  uint32_t /* width from decompiler */ uStack_e0;

  uint32_t /* width from decompiler */ uStack_dc;

  uint32_t /* width from decompiler */ uStack_d8;

  uint32_t /* width from decompiler */ uStack_d4;

  uint32_t /* width from decompiler */ uStack_d0;

  uint32_t /* width from decompiler */ uStack_cc;

  uint32_t /* width from decompiler */ uStack_c8;

  uint32_t /* width from decompiler */ uStack_c4;

  float afStack_c0 [6];

  uint32_t /* width from decompiler */ uStack_a8;

  uint32_t /* width from decompiler */ uStack_a4;

  uint32_t /* width from decompiler */ uStack_a0;

  uint32_t /* width from decompiler */ uStack_9c;

  float fStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint32_t /* width from decompiler */ uStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  

  local_1a0 = 0.0;

  local_19c = 0.0;

  local_184 = 0;

  local_188 = 0;

  local_18c = 0;

  local_190 = 0;

  local_174 = 0;

  local_178 = 0.0;

  local_17c = 0.0;

  local_180 = 0.0;

  local_164 = 0;

  local_168 = 0.0;

  local_16c = 0.0;

  local_170 = 0.0;

  local_154 = 0;

  local_158 = 0.0;

  local_15c = 0.0;

  local_160 = 0.0;

  uVar4 = (**(code **)(*param_1 + 0x14))();

  switch(uVar4) {

  case 2:

  case 3:

  case 10:

  case 0x13:

    iVar6 = (**(code **)(*param_1 + 0x14))();

    if ((iVar6 == 3) || (iVar6 = (**(code **)(*param_1 + 0x14))(), iVar6 == 0x13)) {

      param_1 = (int *)param_1[3];

    }

    iVar6 = (**(code **)(*param_1 + 0x2c))();

    if (iVar6 == -1) {

      return;

    }

    do {

      iVar7 = (**(code **)(*param_1 + 0x34))(iVar6,&uStack_110);

      if (iVar7 != 0) {

        Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f1ec0(iVar7,param_2,param_3);

      }

      iVar6 = (**(code **)(*param_1 + 0x30))(iVar6);

    } while (iVar6 != -1);

    return;

  case 4:

    FUN_005ee680(param_1[3],0x3f800000,&local_1a0);

    break;

  case 5:

    iStack_1e0 = param_1[4];

    ppuStack_1dc = (undefined **)param_1[5];

    uStack_1d8 = param_1[6];

    uStack_1d4 = param_1[7];

    uStack_1c0 = param_1[8];

    iStack_1bc = param_1[9];

    uStack_1b8 = param_1[10];

    iStack_1b4 = param_1[0xb];

    ppuStack_1d0 = (undefined **)param_1[0xc];

    uStack_1cc = param_1[0xd];

    iStack_1c8 = param_1[0xe];

    iStack_1c4 = param_1[0xf];

    FUN_005f10d0(&iStack_1e0,&uStack_1c0,&ppuStack_1d0,0x3f800000,param_1[3],&local_1a0);

    break;

  case 6:

    ppuStack_1d0 = (undefined **)param_1[4];

    uStack_1cc = param_1[5];

    iStack_1c8 = param_1[6];

    iStack_1c4 = param_1[7];

    FUN_005ee750(&ppuStack_1d0,0x3f800000,&local_1a0);

    break;

  case 7:

    FUN_005f0210(param_1 + 4,param_1 + 8,param_1[3],0x3f800000,&local_1a0);

    break;

  case 8:

    (**(code **)(*param_1 + 0x28))(&ppuStack_1d0);

    uVar2 = uStack_1d4;

    iStack_1c4 = 0;

    uStack_1c0 = 0;

    iStack_1bc = -0x80000000;

    if ((char)ppuStack_1d0 != '\0') {

      if (0 < (int)uStack_1d4) {

        FUN_005b3300(&iStack_1c4,uStack_1d4 & ((int)uStack_1d4 < 0) - 1,0x10);

      }

      uStack_1c0 = uVar2;

    }

    iVar6 = (**(code **)(*param_1 + 0x2c))(iStack_1c4);

    ppuVar3 = ppuStack_1d0;

    iStack_1e0 = 0;

    ppuStack_1dc = (undefined **)0x0;

    uStack_1d8 = 0x80000000;

    if (0 < (int)ppuStack_1d0) {

      FUN_005b3300(&iStack_1e0,(uint)ppuStack_1d0 & ((int)ppuStack_1d0 < 0) - 1,0x10);

    }

    iVar7 = 0;

    ppuStack_1dc = ppuVar3;

    if (0 < (int)ppuStack_1d0) {

      puVar8 = (uint32_t /* width from decompiler */ *)(iVar6 + 8);

      do {

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar8 + iStack_1e0 + (-8 - iVar6));

        iVar7 = iVar7 + 1;

        *puVar5 = puVar8[-2];

        puVar5[1] = puVar8[-1];

        puVar5[2] = *puVar8;

        puVar5[3] = puVar8[1];

        puVar8 = puVar8 + 4;

      } while (iVar7 < (int)ppuStack_1d0);

    }

    FUN_005effa0(iStack_1e0,0x10,ppuVar3,0x3f800000,&local_1a0);

    if ((uStack_1d8 & 0x80000000) == 0) {

      (**(code **)(*DAT_00b05060 + 0x14))(iStack_1e0,uStack_1d8 << 4,0x12);

    }

    if ((uStack_1b8 & 0x80000000) == 0) {

      (**(code **)(*DAT_00b05060 + 0x14))(uStack_1c0,uStack_1b8 << 4,0x12);

    }

    break;

  case 9:

    iStack_1a4 = 0;

    piVar1 = param_1;

    if (param_1[3] < 1) {

      return;

    }

    do {

      uStack_150 = *param_2;

      uStack_14c = param_2[1];

      uStack_148 = param_2[2];

      uStack_144 = param_2[3];

      uStack_140 = param_2[4];

      uStack_13c = param_2[5];

      uStack_138 = param_2[6];

      uStack_134 = param_2[7];

      uStack_130 = param_2[8];

      uStack_12c = param_2[9];

      uStack_128 = param_2[10];

      uStack_124 = param_2[0xb];

      uStack_120 = param_2[0xc];

      uStack_11c = param_2[0xd];

      uStack_118 = param_2[0xe];

      uStack_114 = param_2[0xf];

      FUN_005d68f0(&uStack_150,piVar1 + 4);

      FUN_006c7fa0(piVar1[7]);

      Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f1ec0(&ppuStack_1d0,&uStack_150,param_3);

      ppuStack_1d0 = &PTR_FUN_009d81e8;

      if ((uStack_1cc & 0x8000) != 0) {

        uStack_1cc = uStack_1cc & 0xffff7fff;

        FUN_005ffdb0(0);

      }

      iStack_1a4 = iStack_1a4 + 1;

      ppuStack_1d0 = &PTR_LAB_009cc290;

      piVar1 = piVar1 + 4;

    } while (iStack_1a4 < param_1[3]);

    return;

  default:

    goto switchD_005f1f78_caseD_b;

  case 0x11:

    Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f1ec0(param_1[4],param_2,param_3);

    return;

  case 0x12:

    break;

  case 0x15:

    FUN_0063a190(param_2,param_1 + 4);

    Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f1ec0(param_1[3],&uStack_150,param_3);

    return;

  case 0x17:

    Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005f1ec0(param_1[0xc],param_2,param_3);

    goto switchD_005f1f78_caseD_b;

  }

  if (local_1a0 != 0.0) {

    local_19c = local_19c * local_1a0;

    local_180 = local_180 * local_1a0;

    local_170 = local_170 * local_1a0;

    local_160 = local_160 * local_1a0;

    local_17c = local_17c * local_1a0;

    local_16c = local_16c * local_1a0;

    local_15c = local_15c * local_1a0;

    local_178 = local_178 * local_1a0;

    local_168 = local_168 * local_1a0;

    local_158 = local_158 * local_1a0;

    iStack_1e0 = 0;

    ppuStack_1dc = (undefined **)0x0;

    uStack_1d8 = 0x80000000;

    uStack_110 = 0;

    uStack_10c = 0;

    uStack_f4 = 0;

    uStack_f8 = 0;

    uStack_fc = 0;

    uStack_100 = 0;

    uStack_e4 = 0;

    uStack_e8 = 0;

    uStack_ec = 0;

    uStack_f0 = 0;

    uStack_d4 = 0;

    uStack_d8 = 0;

    uStack_dc = 0;

    uStack_e0 = 0;

    uStack_c4 = 0;

    uStack_c8 = 0;

    uStack_cc = 0;

    uStack_d0 = 0;

    afStack_c0[3] = 0.0;

    afStack_c0[2] = 0.0;

    afStack_c0[1] = 0.0;

    uStack_a4 = 0;

    uStack_a8 = 0;

    afStack_c0[4] = 0.0;

    uStack_94 = 0;

    uStack_9c = 0;

    uStack_a0 = 0;

    afStack_c0[0] = g_flOne;

    afStack_c0[5] = g_flOne;

    fStack_98 = g_flOne;

    uStack_84 = 0;

    uStack_88 = 0;

    uStack_8c = 0;

    uStack_90 = 0;

    FUN_005ee860(param_3);

    if (ppuStack_1dc == (undefined **)(uStack_1d8 & 0x7fffffff)) {

      FUN_005b3370(&iStack_1e0,0x90);

    }

    ppuStack_1dc = (undefined **)((int)ppuStack_1dc + 1);

    FUN_005ee860(&uStack_110);

    FUN_005eb040(afStack_c0);

    uStack_110 = 0;

    uStack_10c = 0;

    uStack_f4 = 0;

    uStack_f8 = 0;

    uStack_fc = 0;

    uStack_100 = 0;

    uStack_e4 = 0;

    uStack_e8 = 0;

    uStack_ec = 0;

    uStack_f0 = 0;

    uStack_d4 = 0;

    uStack_d8 = 0;

    uStack_dc = 0;

    uStack_e0 = 0;

    uStack_c4 = 0;

    uStack_c8 = 0;

    uStack_cc = 0;

    uStack_d0 = 0;

    afStack_c0[3] = 0.0;

    afStack_c0[2] = 0.0;

    afStack_c0[1] = 0.0;

    uStack_a4 = 0;

    uStack_a8 = 0;

    afStack_c0[4] = 0.0;

    uStack_94 = 0;

    uStack_9c = 0;

    uStack_a0 = 0;

    afStack_c0[0] = g_flOne;

    afStack_c0[5] = g_flOne;

    fStack_98 = g_flOne;

    uStack_84 = 0;

    uStack_88 = 0;

    uStack_8c = 0;

    uStack_90 = 0;

    FUN_005ee860(&local_1a0);

    FUN_005eb040(param_2);

    if (ppuStack_1dc == (undefined **)(uStack_1d8 & 0x7fffffff)) {

      FUN_005b3370(&iStack_1e0,0x90);

    }

    ppuStack_1dc = (undefined **)((int)ppuStack_1dc + 1);

    FUN_005ee860(&uStack_110);

    FUN_005eb040(afStack_c0);

    FUN_005ef3d0(&iStack_1e0,param_3);

    if ((uStack_1d8 & 0x80000000) == 0) {

      (**(code **)(*DAT_00b05060 + 0x14))(iStack_1e0,(uStack_1d8 & 0x7fffffff) * 0x90,0x12);

      return;

    }

  }

switchD_005f1f78_caseD_b:

  return;

}
