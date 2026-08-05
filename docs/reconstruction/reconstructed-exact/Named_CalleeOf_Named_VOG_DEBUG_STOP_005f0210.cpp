// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005f0210
// -----------------------------------------------------------------------------
// Stable ID: aa_005f0210
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x005f0210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~416 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: FUN_005eb040×6, FUN_005b3370×3, FUN_005ee860×3, FUN_00645640×3, SQRT×3, FUN_004f2d70×2, FUN_005d6ae0×2, FUN_005ee680×2.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */

Named_CalleeOf_Named_VOG_DEBUG_STOP_005f0210(float *param_1,float *param_2,float param_3,float param_4,uint32_t /* width from decompiler */ param_5)



{

  float10 fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float local_180;

  float local_17c;

  float local_178;

  float local_174;

  uint32_t /* width from decompiler */ local_170;

  uint local_16c;

  uint local_168;

  float local_164;

  float local_160;

  float local_15c;

  float local_150;

  float local_14c;

  float local_148;

  uint32_t /* width from decompiler */ local_144;

  float local_140;

  float local_13c;

  float local_138;

  uint32_t /* width from decompiler */ local_134;

  float local_130;

  float local_12c;

  float local_128;

  uint32_t /* width from decompiler */ local_124;

  float local_120;

  float local_11c;

  float local_118;

  uint32_t /* width from decompiler */ local_114;

  float local_110 [6];

  uint32_t /* width from decompiler */ local_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint32_t /* width from decompiler */ local_f0;

  uint32_t /* width from decompiler */ local_ec;

  float local_e8;

  uint32_t /* width from decompiler */ local_e4;

  float local_e0;

  float local_dc;

  float local_d8;

  float local_d4;

  float local_c8;

  float local_c4;

  float local_c0 [6];

  uint32_t /* width from decompiler */ local_a8;

  uint32_t /* width from decompiler */ local_a4;

  uint32_t /* width from decompiler */ local_a0;

  uint32_t /* width from decompiler */ local_9c;

  float local_98;

  uint32_t /* width from decompiler */ local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  float local_24;

  uint8_t local_20 [28];

  

  if ((0.0 < param_4) && (0.0 < param_3)) {

    fVar7 = *param_2 - *param_1;

    fVar6 = param_2[2] - param_1[2];

    fVar4 = param_2[1] - param_1[1];

    fVar3 = fVar6 * fVar6 + fVar7 * fVar7 + fVar4 * fVar4;

    fVar2 = SQRT(fVar3);

    if (fVar2 <= g_flZero) {

      local_c0[3] = 0.0;

      local_c0[2] = 0.0;

      local_c0[1] = 0.0;

      local_a4 = 0;

      local_a8 = 0;

      local_c0[4] = 0.0;

      local_94 = 0;

      local_9c = 0;

      local_a0 = 0;

      local_c0[0] = g_flOne;

      local_c0[5] = g_flOne;

      local_98 = g_flOne;

    }

    else {

      if (fVar3 == 0.0) {

        fVar3 = 0.0;

      }

      else {

        fVar3 = g_flOne / SQRT(fVar3);

      }

      fVar5 = fVar4 * fVar3 * 0.0;

      fVar8 = fVar3 * fVar7 * 0.0;

      local_164 = fVar6 * fVar3 + fVar5 + fVar8;

      if (DAT_00aaa948 <= ABS(local_164)) {

        local_c0[3] = 0.0;

        local_c0[2] = 0.0;

        local_c0[1] = 0.0;

        local_a4 = 0;

        local_a8 = 0;

        local_c0[4] = 0.0;

        local_94 = 0;

        local_9c = 0;

        local_a0 = 0;

        local_c0[0] = g_flOne;

        local_c0[5] = g_flOne;

        local_98 = g_flOne;

      }

      else {

        local_180 = fVar6 * fVar3 * 0.0;

        local_17c = fVar3 * fVar7 - local_180;

        fVar5 = fVar5 - fVar8;

        local_180 = local_180 - fVar4 * fVar3;

        fVar3 = fVar5 * fVar5 + local_17c * local_17c + local_180 * local_180;

        if (fVar3 == 0.0) {

          local_174 = 0.0;

        }

        else {

          local_174 = g_flOne / SQRT(fVar3);

        }

        local_17c = local_17c * local_174;

        local_178 = fVar5 * local_174;

        local_180 = local_174 * local_180;

        local_174 = local_174 * 0.0;

        fVar1 = (float10)FUN_0040d0a0(local_164);

        FUN_00567ce0(&local_180,(float)fVar1);

        FUN_005eadb0(local_20);

      }

    }

    local_88 = (param_1[2] + param_2[2]) * DAT_00a0f298;

    local_8c = (param_2[1] + param_1[1]) * DAT_00a0f298;

    local_84 = (param_1[3] + param_2[3]) * DAT_00a0f298;

    local_90 = (*param_1 + *param_2) * DAT_00a0f298;

    local_24 = param_3 * param_3;

    local_c8 = local_24 * param_3 * DAT_00aaa62c;

    local_c4 = fVar2 * param_3 * param_3 * _DAT_009dd01c;

    fVar3 = g_flOne / (local_c4 + local_c8);

    local_170 = 0;

    local_16c = 0;

    fVar4 = fVar3 * local_c8 * param_4;

    local_164 = fVar3 * local_c4 * param_4;

    local_168 = 0x80000000;

    local_160 = 0.0;

    local_15c = 0.0;

    local_144 = 0;

    local_148 = 0.0;

    local_14c = 0.0;

    local_150 = 0.0;

    local_134 = 0;

    local_138 = 0.0;

    local_13c = 0.0;

    local_140 = 0.0;

    local_124 = 0;

    local_128 = 0.0;

    local_12c = 0.0;

    local_130 = 0.0;

    local_114 = 0;

    local_118 = 0.0;

    local_11c = 0.0;

    local_120 = 0.0;

    local_110[3] = 0.0;

    local_110[2] = 0.0;

    local_110[1] = 0.0;

    local_f4 = 0;

    local_f8 = 0;

    local_110[4] = 0.0;

    local_e4 = 0;

    local_ec = 0;

    local_f0 = 0;

    local_110[0] = g_flOne;

    local_110[5] = g_flOne;

    local_e8 = g_flOne;

    local_d4 = 0.0;

    local_d8 = 0.0;

    local_dc = 0.0;

    local_e0 = 0.0;

    FUN_005eb040(local_c0);

    local_150 = 0.0;

    local_14c = 0.0;

    local_148 = 0.0;

    local_144 = 0;

    local_134 = 0;

    local_138 = 0.0;

    local_13c = 0.0;

    local_124 = 0;

    local_128 = 0.0;

    local_130 = 0.0;

    local_114 = 0;

    local_11c = 0.0;

    local_120 = 0.0;

    local_118 = local_24 * DAT_00a0f298;

    local_140 = fVar2 * fVar2 * DAT_00a0f704 * g_flDisplayRateScaleOneThird +

                local_24 * DAT_00a0f704;

    local_12c = local_140;

    FUN_00645640(local_164);

    local_144 = 0;

    local_148 = 0.0;

    local_14c = 0.0;

    local_150 = 0.0;

    local_160 = local_c4;

    local_15c = local_164;

    if (local_16c == (local_168 & 0x7fffffff)) {

      FUN_005b3370(&local_170,0x90);

    }

    local_16c = local_16c + 1;

    FUN_005ee860(&local_160);

    FUN_005eb040(local_110);

    local_160 = 0.0;

    local_15c = 0.0;

    local_144 = 0;

    local_148 = 0.0;

    local_14c = 0.0;

    local_150 = 0.0;

    local_134 = 0;

    local_138 = 0.0;

    local_13c = 0.0;

    local_140 = 0.0;

    local_124 = 0;

    local_128 = 0.0;

    local_12c = 0.0;

    local_130 = 0.0;

    local_114 = 0;

    local_118 = 0.0;

    local_11c = 0.0;

    local_120 = 0.0;

    local_110[3] = 0.0;

    local_110[2] = 0.0;

    local_110[1] = 0.0;

    local_f4 = 0;

    local_f8 = 0;

    local_110[4] = 0.0;

    local_e4 = 0;

    local_ec = 0;

    local_f0 = 0;

    local_110[0] = g_flOne;

    local_110[5] = g_flOne;

    local_e8 = g_flOne;

    local_d4 = 0.0;

    local_d8 = 0.0;

    local_dc = 0.0;

    local_e0 = 0.0;

    FUN_005eb040(local_c0);

    local_178 = fVar2 * DAT_00a0f298;

    local_180 = 0.0;

    local_17c = 0.0;

    local_174 = 0.0;

    local_c4 = local_178;

    FUN_005d6ae0(local_c0,&local_180);

    local_180 = local_e0 + local_180;

    local_17c = local_17c + local_dc;

    local_178 = local_178 + local_d8;

    local_174 = local_174 + local_d4;

    local_148 = param_3 * _DAT_009dd038;

    local_150 = 0.0;

    local_14c = 0.0;

    local_144 = 0;

    local_80 = 0;

    local_7c = 0;

    local_64 = 0;

    local_68 = 0;

    local_6c = 0;

    local_70 = 0;

    local_54 = 0;

    local_58 = 0;

    local_5c = 0;

    local_60 = 0;

    local_44 = 0;

    local_48 = 0;

    local_4c = 0;

    local_50 = 0;

    local_34 = 0;

    local_38 = 0;

    local_3c = 0;

    local_40 = 0;

    local_e0 = local_180;

    local_dc = local_17c;

    local_d8 = local_178;

    local_d4 = local_174;

    FUN_005ee680(param_3,fVar4,&local_80);

    FUN_004f2d70(&local_60);

    FUN_00645640(0x3f000000);

    fVar2 = fVar4 * DAT_00a0f298;

    local_140 = local_140 - (local_14c * local_14c + local_148 * local_148) * fVar2;

    local_12c = local_12c - (local_150 * local_150 + local_148 * local_148) * fVar2;

    local_118 = local_118 - (local_150 * local_150 + local_14c * local_14c) * fVar2;

    local_13c = local_14c * fVar2 * local_150 + local_13c;

    local_128 = local_148 * local_14c * fVar2 + local_128;

    local_138 = local_148 * fVar2 * local_150 + local_120;

    local_160 = local_c8 * DAT_00a0f298;

    local_15c = fVar2;

    local_130 = local_13c;

    local_120 = local_138;

    local_11c = local_128;

    local_c8 = local_160;

    if (local_16c == (local_168 & 0x7fffffff)) {

      FUN_005b3370(&local_170,0x90);

    }

    local_16c = local_16c + 1;

    FUN_005ee860(&local_160);

    FUN_005eb040(local_110);

    local_160 = 0.0;

    local_15c = 0.0;

    local_144 = 0;

    local_148 = 0.0;

    local_14c = 0.0;

    local_150 = 0.0;

    local_134 = 0;

    local_138 = 0.0;

    local_13c = 0.0;

    local_140 = 0.0;

    local_124 = 0;

    local_128 = 0.0;

    local_12c = 0.0;

    local_130 = 0.0;

    local_114 = 0;

    local_118 = 0.0;

    local_11c = 0.0;

    local_120 = 0.0;

    local_110[3] = 0.0;

    local_110[2] = 0.0;

    local_110[1] = 0.0;

    local_f4 = 0;

    local_f8 = 0;

    local_110[4] = 0.0;

    local_e4 = 0;

    local_ec = 0;

    local_f0 = 0;

    local_110[0] = g_flOne;

    local_110[5] = g_flOne;

    local_e8 = g_flOne;

    local_d4 = 0.0;

    local_d8 = 0.0;

    local_dc = 0.0;

    local_e0 = 0.0;

    FUN_005eb040(local_c0);

    local_178 = 0.0 - local_c4;

    local_180 = 0.0;

    local_17c = 0.0;

    local_174 = 0.0;

    FUN_005d6ae0(local_c0,&local_180);

    local_180 = local_e0 + local_180;

    local_17c = local_17c + local_dc;

    local_178 = local_178 + local_d8;

    local_174 = local_174 + local_d4;

    local_148 = param_3 * _DAT_009dd034;

    local_150 = 0.0;

    local_14c = 0.0;

    local_144 = 0;

    local_80 = 0;

    local_7c = 0;

    local_64 = 0;

    local_68 = 0;

    local_6c = 0;

    local_70 = 0;

    local_54 = 0;

    local_58 = 0;

    local_5c = 0;

    local_60 = 0;

    local_44 = 0;

    local_48 = 0;

    local_4c = 0;

    local_50 = 0;

    local_34 = 0;

    local_38 = 0;

    local_3c = 0;

    local_40 = 0;

    local_e0 = local_180;

    local_dc = local_17c;

    local_d8 = local_178;

    local_d4 = local_174;

    FUN_005ee680(param_3,fVar4,&local_80);

    FUN_004f2d70(&local_60);

    FUN_00645640(0x3f000000);

    local_140 = local_140 - (local_14c * local_14c + local_148 * local_148) * fVar2;

    local_12c = local_12c - (local_150 * local_150 + local_148 * local_148) * fVar2;

    local_118 = local_118 - (local_150 * local_150 + local_14c * local_14c) * fVar2;

    local_13c = local_14c * fVar2 * local_150 + local_13c;

    local_128 = local_148 * local_14c * fVar2 + local_128;

    local_138 = local_148 * fVar2 * local_150 + local_120;

    local_160 = local_c8;

    local_15c = fVar2;

    local_130 = local_13c;

    local_120 = local_138;

    local_11c = local_128;

    if (local_16c == (local_168 & 0x7fffffff)) {

      FUN_005b3370(&local_170,0x90);

    }

    local_16c = local_16c + 1;

    FUN_005ee860(&local_160);

    FUN_005eb040(local_110);

    FUN_005ef3d0(&local_170,param_5);

    if (-1 < (int)local_168) {

      (**(code **)(*DAT_00b05060 + 0x14))(local_170,(local_168 & 0x7fffffff) * 0x90,0x12);

    }

    return 0;

  }

  return 1;

}
