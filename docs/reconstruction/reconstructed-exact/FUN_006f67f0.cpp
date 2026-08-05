// =============================================================================
// FUN_006f67f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f67f0
// Address:   0x006f67f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f67f0 @ 0x006f67f0
// Stable ID: aa_006f67f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~140 non-empty decompiler lines.
//  - Control keywords: if×10, return×7, do×1, while×1.
//  - Notable callees: FUN_006e8880, FUN_006f67f0.
//  - Return sites: 7.

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

void __thiscall

FUN_006f67f0(int *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,int *param_5,

            int *param_6)



{

  int iVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  undefined **ppuStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint uStack_128;

  float fStack_124;

  float fStack_120;

  float fStack_11c;

  float fStack_118;

  uint32_t /* width from decompiler */ uStack_114;

  uint32_t /* width from decompiler */ *puStack_110;

  uint32_t /* width from decompiler */ uStack_10c;

  char cStack_f8;

  undefined **local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint local_e8;

  float fStack_e4;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  uint32_t /* width from decompiler */ local_d4;

  uint8_t auStack_d0 [16];

  undefined **local_c0;

  uint32_t /* width from decompiler */ local_bc;

  float local_b8;

  uint32_t /* width from decompiler */ local_b4;

  undefined **ppuStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  uint uStack_a8;

  float fStack_a4;

  float fStack_a0;

  float fStack_9c;

  float fStack_98;

  uint32_t /* width from decompiler */ uStack_94;

  uint32_t /* width from decompiler */ uStack_90;

  uint32_t /* width from decompiler */ uStack_8c;

  uint8_t *puStack_88;

  uint32_t /* width from decompiler */ *puStack_84;

  uint8_t auStack_80 [80];

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  

  local_c0 = (undefined **)*param_4;

  local_bc = param_4[1];

  local_b8 = (float)param_4[2] + (float)param_4[9];

  local_b4 = param_4[3];

  local_f0 = &PTR_LAB_00a0e9d8;

  local_e8 = local_e8 & 0xffffff00;

  local_d4 = 0x7f7fffff;

  local_ec = 0x7f7fffff;

  (**(code **)(*param_1 + 8))(param_2,param_3,&local_c0,&local_f0);

  if (cStack_f8 != '\0') {

    fStack_120 = fStack_e0;

    uStack_114 = local_d4;

    uStack_10c = param_3;

    fStack_11c = fStack_dc;

    uStack_128 = local_e8;

    fStack_118 = fStack_d8;

    ppuStack_130 = local_f0;

    puStack_110 = param_2;

    uStack_12c = local_ec;

    fStack_124 = fStack_e4;

    if ((fStack_e4 < (float)param_4[2]) && (param_6 != (int *)0x0)) {

      (**(code **)(*param_6 + 4))(&ppuStack_130);

    }

    fVar2 = fStack_dc * (float)param_4[5] +

            fStack_d8 * (float)param_4[6] + fStack_e0 * (float)param_4[4];

    fVar3 = fStack_e4 + fVar2;

    if ((fVar3 <= g_flZero) && (fVar2 + (float)param_4[8] < g_flZero)) {

      if (fStack_e4 < *(float *)(param_4[3] + 0x18) == (fStack_e4 == *(float *)(param_4[3] + 0x18)))

      {

        fStack_124 = fStack_e4 / (fStack_e4 - fVar3);

        local_c0 = &PTR_LAB_00a0e9d8;

        local_b8 = (float)((uint)local_b8 & 0xffffff00);

        fStack_a4 = 3.4028235e+38;

        local_bc = 0x7f7fffff;

        FUN_006e8880(param_2[2]);

        uStack_90 = *param_2;

        puStack_88 = auStack_80;

        uStack_8c = param_2[1];

        iVar4 = *(int *)(param_4[3] + 0x1c);

        puStack_84 = param_2;

        do {

          iVar4 = iVar4 + -1;

          if (iVar4 < 0) break;

          iVar1 = param_2[2];

          local_b8 = (float)((uint)local_b8 & 0xffffff00);

          fStack_a4 = 3.4028235e+38;

          local_bc = 0x7f7fffff;

          fStack_30 = fStack_124 * (float)param_4[4] + *(float *)(iVar1 + 0x50);

          fStack_2c = fStack_124 * (float)param_4[5] + *(float *)(iVar1 + 0x54);

          fStack_28 = fStack_124 * (float)param_4[6] + *(float *)(iVar1 + 0x58);

          fStack_24 = fStack_124 * (float)param_4[7] + *(float *)(iVar1 + 0x5c);

          (**(code **)(*param_1 + 8))(&uStack_90,param_3,auStack_d0,&local_c0);

          fVar2 = fStack_98 * (float)param_4[6] +

                  fStack_9c * (float)param_4[5] + fStack_a0 * (float)param_4[4];

          if (g_flZero <= fVar2) {

            return;

          }

          fVar2 = -fVar2;

          if (fVar2 < fStack_124 * fVar2 + fStack_a4) {

            return;

          }

          fStack_124 = fStack_a4 / fVar2 + fStack_124;

          if ((float)param_5[1] < fStack_124) {

            return;

          }

          ppuStack_130 = ppuStack_b0;

          uStack_12c = uStack_ac;

          uStack_128 = uStack_a8;

          fStack_120 = fStack_a0;

          fStack_11c = fStack_9c;

          fStack_118 = fStack_98;

          uStack_114 = uStack_94;

        } while (fStack_a4 < *(float *)(param_4[3] + 0x18) ==

                 (fStack_a4 == *(float *)(param_4[3] + 0x18)));

        (**(code **)(*param_5 + 4))(&ppuStack_130);

        return;

      }

      if (fStack_e4 <= g_flZero) {

        fStack_124 = 0.0;

        (**(code **)(*param_5 + 4))(&ppuStack_130);

        return;

      }

      fStack_124 = fStack_e4 / (fStack_e4 - fVar3);

      if (fStack_124 <= (float)param_5[1]) {

        (**(code **)(*param_5 + 4))(&ppuStack_130);

        return;

      }

    }

  }

  return;

}
