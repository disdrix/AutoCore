// =============================================================================
// FUN_006f63e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f63e0
// Address:   0x006f63e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f63e0 @ 0x006f63e0
// Stable ID: aa_006f63e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~145 non-empty decompiler lines.
//  - Control keywords: if×11, return×8, do×1, while×1.
//  - Notable callees: FUN_006d3a50, FUN_006e8880, FUN_006f63e0.
//  - Return sites: 8.

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

void FUN_006f63e0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int *param_4,int *param_5)



{

  code *pcVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uStack_130;

  uint32_t /* width from decompiler */ uStack_12c;

  uint32_t /* width from decompiler */ uStack_128;

  float fStack_124;

  float fStack_120;

  float fStack_11c;

  float fStack_118;

  uint32_t /* width from decompiler */ uStack_114;

  uint32_t /* width from decompiler */ *puStack_110;

  uint32_t /* width from decompiler */ *puStack_10c;

  undefined **local_100;

  uint32_t /* width from decompiler */ local_fc;

  char local_f8;

  uint32_t /* width from decompiler */ uStack_f0;

  uint32_t /* width from decompiler */ uStack_ec;

  uint32_t /* width from decompiler */ uStack_e8;

  float local_e4;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  uint32_t /* width from decompiler */ uStack_d4;

  int local_c4;

  int local_c0;

  float local_bc;

  int local_b8;

  float fStack_b4;

  undefined **ppuStack_b0;

  uint32_t /* width from decompiler */ uStack_ac;

  char cStack_a8;

  uint8_t auStack_a0 [12];

  float fStack_94;

  float fStack_90;

  float fStack_8c;

  float fStack_88;

  uint32_t /* width from decompiler */ uStack_84;

  uint32_t /* width from decompiler */ uStack_80;

  uint32_t /* width from decompiler */ uStack_7c;

  uint8_t *puStack_78;

  uint32_t /* width from decompiler */ *puStack_74;

  uint8_t auStack_70 [80];

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  local_c4 = *param_3;

  local_c0 = param_3[1];

  local_bc = (float)param_3[2] + (float)param_3[9];

  local_b8 = param_3[3];

  local_100 = &PTR_LAB_00a0e9d8;

  local_f8 = '\0';

  local_e4 = 3.4028235e+38;

  local_fc = 0x7f7fffff;

  iVar4 = (**(code **)(*(int *)*param_1 + 0x14))();

  iVar5 = (**(code **)(*(int *)*param_2 + 0x14))();

  pcVar1 = *(code **)(*param_3 + 0x218c + (iVar4 * 0x20 + iVar5) * 4);

  (*pcVar1)(param_1,param_2,&local_c4,&local_100);

  if (local_f8 != '\0') {

    fStack_11c = fStack_dc;

    uStack_130 = uStack_f0;

    puStack_10c = param_2;

    fStack_120 = fStack_e0;

    fStack_124 = local_e4;

    fStack_118 = fStack_d8;

    uStack_114 = uStack_d4;

    puStack_110 = param_1;

    uStack_12c = uStack_ec;

    uStack_128 = uStack_e8;

    if ((local_e4 < (float)param_3[2]) && (param_5 != (int *)0x0)) {

      (**(code **)(*param_5 + 4))(&uStack_130);

    }

    fVar2 = fStack_e0 * (float)param_3[4] +

            fStack_dc * (float)param_3[5] + fStack_d8 * (float)param_3[6];

    fVar3 = local_e4 + fVar2;

    if ((fVar3 <= g_flZero) && (fVar2 + (float)param_3[8] < g_flZero)) {

      if (local_e4 < *(float *)(param_3[3] + 0x18) == (local_e4 == *(float *)(param_3[3] + 0x18))) {

        fStack_124 = local_e4 / (local_e4 - fVar3);

        ppuStack_b0 = &PTR_LAB_00a0e9d8;

        cStack_a8 = '\0';

        fStack_94 = 3.4028235e+38;

        uStack_ac = 0x7f7fffff;

        FUN_006e8880(param_1[2]);

        uStack_80 = *param_1;

        puStack_78 = auStack_70;

        uStack_7c = param_1[1];

        iVar4 = *(int *)(param_3[3] + 0x1c);

        puStack_74 = param_1;

        do {

          iVar4 = iVar4 + -1;

          if (iVar4 < 0) break;

          iVar5 = param_1[2];

          cStack_a8 = '\0';

          fStack_94 = 3.4028235e+38;

          uStack_ac = 0x7f7fffff;

          fStack_20 = fStack_124 * (float)param_3[4] + *(float *)(iVar5 + 0x50);

          fStack_1c = fStack_124 * (float)param_3[5] + *(float *)(iVar5 + 0x54);

          fStack_18 = fStack_124 * (float)param_3[6] + *(float *)(iVar5 + 0x58);

          fStack_14 = fStack_124 * (float)param_3[7] + *(float *)(iVar5 + 0x5c);

          (*pcVar1)(&uStack_80,param_2,&local_c4,&ppuStack_b0);

          if (cStack_a8 == '\0') {

            return;

          }

          fVar2 = fStack_90 * (float)param_3[4] +

                  fStack_88 * (float)param_3[6] + fStack_8c * (float)param_3[5];

          if (g_flZero <= fVar2) {

            return;

          }

          fVar2 = -fVar2;

          if (fVar2 < fStack_124 * fVar2 + fStack_94) {

            return;

          }

          fStack_b4 = fStack_94 / fVar2 + fStack_124;

          if ((float)param_4[1] < fStack_b4) {

            return;

          }

          FUN_006d3a50(auStack_a0,fStack_b4);

          fStack_120 = fStack_90;

          fStack_11c = fStack_8c;

          fStack_118 = fStack_88;

          uStack_114 = uStack_84;

        } while (fStack_94 < *(float *)(param_3[3] + 0x18) ==

                 (fStack_94 == *(float *)(param_3[3] + 0x18)));

        (**(code **)(*param_4 + 4))(&uStack_130);

        return;

      }

      if (local_e4 <= g_flZero) {

        fStack_124 = 0.0;

        (**(code **)(*param_4 + 4))(&uStack_130);

        return;

      }

      fStack_124 = local_e4 / (local_e4 - fVar3);

      if (fStack_124 <= (float)param_4[1]) {

        (**(code **)(*param_4 + 4))(&uStack_130);

        return;

      }

    }

  }

  return;

}
