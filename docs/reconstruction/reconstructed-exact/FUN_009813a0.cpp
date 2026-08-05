// =============================================================================
// FUN_009813a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009813a0
// Address:   0x009813a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009813a0 @ 0x009813a0
// Stable ID: aa_009813a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~215 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, return×2, while×1.
//  - Notable callees: FUN_0046c300×6, FUN_0076f5f0×2, FUN_0076f240, FUN_0076f6e0, FUN_009813a0, fcos, fsin.
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



void FUN_009813a0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  float10 fVar5;

  float fVar6;

  float local_154;

  float local_150;

  float local_14c;

  float local_148;

  float local_144;

  float local_140;

  float local_13c;

  float local_138;

  float local_134;

  float local_130;

  float local_12c;

  int local_128;

  float local_124;

  float local_120;

  float local_11c;

  float local_118;

  uint32_t /* width from decompiler */ local_114;

  float local_10c;

  float local_108;

  float local_104;

  int local_100;

  int local_fc;

  float local_f8;

  float local_f4 [4];

  float local_e4;

  float local_e0;

  uint32_t /* width from decompiler */ local_dc;

  float local_d8;

  uint32_t /* width from decompiler */ local_d4;

  float local_d0;

  float local_cc;

  float local_c8;

  float local_c4 [4];

  float local_b4;

  float local_b0;

  uint32_t /* width from decompiler */ local_ac;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  float local_7c;

  float local_78;

  float local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_58 [6];

  uint8_t local_40;

  uint8_t local_3f;

  uint8_t local_3e;

  uint8_t local_3d;

  float local_34 [6];

  uint8_t local_1c;

  uint8_t local_1b;

  uint8_t local_1a;

  uint8_t local_19;

  

  local_100 = param_1 + 4;

  if (*(void **)(param_1 + 8) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    local_154 = *(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x20);

    local_150 = *(float *)(param_1 + 0x18) - *(float *)(param_1 + 0x24);

    local_14c = *(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x28);

    FUN_0076f5f0(&local_154,&local_154);

    local_88 = local_14c;

    local_8c = local_150;

    local_90 = local_154;

    fVar6 = 0.0;

    local_148 = local_14c - local_150 * 0.0;

    local_140 = local_150 * 0.0 - local_154;

    local_144 = local_154 * 0.0 - local_14c * 0.0;

    if (g_flMsToSeconds_Inferred <=

        local_140 * local_140 + local_144 * local_144 + local_148 * local_148) {

      local_154 = local_148;

      local_150 = local_144;

      local_14c = local_140;

      local_13c = local_148;

      local_138 = local_144;

      local_134 = local_140;

      FUN_0076f5f0(&local_154,&local_154);

    }

    else {

      local_154 = g_flOne;

      local_150 = 0.0;

      local_14c = 0.0;

    }

    local_148 = local_150 * local_88 - local_14c * local_8c;

    local_144 = local_14c * local_90 - local_154 * local_88;

    local_140 = local_154 * local_8c - local_150 * local_90;

    local_9c = local_150;

    local_fc = param_2 / 2;

    local_98 = local_14c;

    local_64 = g_flOne;

    local_f8 = DAT_00a1e8fc / (float)local_fc;

    local_a0 = local_154;

    local_1a = 0xff;

    local_1b = 0xff;

    local_1c = 0xff;

    local_19 = 0xff;

    local_3e = 0xff;

    local_3f = 0xff;

    local_40 = 0xff;

    local_3d = 0xff;

    local_128 = 0;

    local_13c = local_148;

    local_138 = local_144;

    local_134 = local_140;

    local_130 = fVar6;

    local_94 = fVar6;

    local_84 = fVar6;

    local_80 = local_148;

    local_7c = local_144;

    local_78 = local_140;

    local_74 = fVar6;

    local_70 = fVar6;

    local_6c = fVar6;

    local_68 = fVar6;

    if (-1 < local_fc) {

      while( true ) {

        fVar5 = (float10)fcos((float10)local_130);

        local_12c = (float)fVar5;

        fVar5 = (float10)fsin((float10)local_130);

        local_124 = (float)fVar5;

        local_154 = local_12c * *(float *)(param_1 + 0x2c);

        local_14c = local_124 * *(float *)(param_1 + 0x2c);

        local_150 = fVar6;

        FUN_0076f6e0();

        local_148 = local_d0;

        local_144 = local_cc;

        local_140 = local_c8;

        local_154 = local_d0;

        local_120 = local_12c;

        local_150 = local_cc;

        local_14c = local_c8;

        local_11c = 0.0;

        local_118 = local_124;

        local_114 = 0;

        FUN_0076f240(&local_120);

        iVar2 = local_128;

        local_13c = local_120;

        local_138 = local_11c;

        local_134 = local_118;

        local_108 = local_11c;

        fVar6 = *(float *)(param_1 + 0x30);

        local_104 = local_118;

        local_10c = local_120;

        local_f4[0] = *(float *)(param_1 + 0x14) + local_154;

        local_f4[1] = local_150 + *(float *)(param_1 + 0x18);

        local_f4[2] = local_14c + *(float *)(param_1 + 0x1c);

        local_f4[3] = local_120 * fVar6;

        local_e4 = local_11c * fVar6;

        local_e0 = local_118 * fVar6;

        local_dc = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

        local_d4 = 0;

        local_c4[3] = local_120 * fVar6;

        local_d8 = local_130 * _DAT_00a27c50;

        local_c4[0] = *(float *)(param_1 + 0x20) + local_154;

        local_c4[1] = *(float *)(param_1 + 0x24) + local_150;

        local_c4[2] = *(float *)(param_1 + 0x28) + local_14c;

        local_b4 = local_11c * fVar6;

        local_b0 = local_118 * fVar6;

        local_ac = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

        local_a8 = local_130 * _DAT_00a27c50;

        local_a4 = g_flOne;

        if (0 < local_128) {

          FUN_0046c300();

          FUN_0046c300();

          FUN_0046c300();

          FUN_0046c300();

          FUN_0046c300();

          FUN_0046c300();

        }

        pfVar3 = local_f4;

        pfVar4 = local_34;

        for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {

          *pfVar4 = *pfVar3;

          pfVar3 = pfVar3 + 1;

          pfVar4 = pfVar4 + 1;

        }

        local_128 = iVar2 + 1;

        pfVar3 = local_c4;

        pfVar4 = local_58;

        for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

          *pfVar4 = *pfVar3;

          pfVar3 = pfVar3 + 1;

          pfVar4 = pfVar4 + 1;

        }

        if (local_fc < local_128) break;

        fVar6 = 0.0;

        local_130 = local_130 + local_f8;

      }

    }

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 8));

}
