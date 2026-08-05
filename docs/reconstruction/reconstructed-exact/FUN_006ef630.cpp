// =============================================================================
// FUN_006ef630
// -----------------------------------------------------------------------------
// Stable ID: aa_006ef630
// Address:   0x006ef630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ef630 @ 0x006ef630
// Stable ID: aa_006ef630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~133 non-empty decompiler lines.
//  - Control keywords: if×11, do×3, while×3, return×1.
//  - Notable callees: FUN_006ef630.
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

void __thiscall FUN_006ef630(int param_1,float *param_2,float param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  uint uVar4;

  float *pfVar5;

  float *pfVar6;

  float *pfVar7;

  float *pfVar8;

  int iVar9;

  float local_f0;

  float local_ec;

  float local_e8;

  float local_e4;

  int local_d4;

  float local_b0;

  float local_ac;

  float local_a8;

  float local_90 [35];

  

  uVar4 = *(uint *)(param_1 + 0xc);

  local_d4 = uVar4 - 1;

  pfVar7 = local_90;

  pfVar5 = (float *)(param_1 + 0x10);

  if (3 < (int)uVar4) {

    uVar4 = uVar4 >> 2;

    local_d4 = local_d4 + uVar4 * -4;

    pfVar6 = pfVar5;

    pfVar8 = local_90 + 6;

    do {

      fVar1 = *pfVar6;

      fVar2 = pfVar6[1];

      fVar3 = pfVar6[2];

      *pfVar7 = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];

      pfVar8[-5] = fVar2 * param_2[5] + fVar3 * param_2[9] + fVar1 * param_2[1] + param_2[0xd];

      pfVar8[-4] = fVar2 * param_2[6] + fVar3 * param_2[10] + fVar1 * param_2[2] + param_2[0xe];

      pfVar8[-3] = 0.0;

      fVar1 = pfVar6[4];

      fVar2 = pfVar6[5];

      fVar3 = pfVar6[6];

      pfVar8[-2] = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];

      pfVar8[-1] = fVar2 * param_2[5] + fVar3 * param_2[9] + fVar1 * param_2[1] + param_2[0xd];

      *pfVar8 = fVar2 * param_2[6] + fVar3 * param_2[10] + fVar1 * param_2[2] + param_2[0xe];

      pfVar8[1] = 0.0;

      fVar1 = pfVar6[8];

      fVar2 = pfVar6[9];

      fVar3 = pfVar6[10];

      pfVar8[2] = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];

      pfVar7 = pfVar7 + 0x10;

      pfVar5 = pfVar6 + 0x10;

      uVar4 = uVar4 - 1;

      pfVar8[3] = fVar2 * param_2[5] + fVar3 * param_2[9] + fVar1 * param_2[1] + param_2[0xd];

      pfVar8[4] = fVar2 * param_2[6] + fVar3 * param_2[10] + fVar1 * param_2[2] + param_2[0xe];

      pfVar8[5] = 0.0;

      fVar1 = pfVar6[0xc];

      fVar2 = pfVar6[0xd];

      fVar3 = pfVar6[0xe];

      pfVar8[6] = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];

      pfVar8[7] = fVar2 * param_2[5] + fVar3 * param_2[9] + fVar1 * param_2[1] + param_2[0xd];

      pfVar8[8] = fVar2 * param_2[6] + fVar3 * param_2[10] + fVar1 * param_2[2] + param_2[0xe];

      pfVar8[9] = 0.0;

      pfVar6 = pfVar5;

      pfVar8 = pfVar8 + 0x10;

    } while (uVar4 != 0);

  }

  if (-1 < local_d4) {

    local_d4 = local_d4 + 1;

    do {

      fVar1 = *pfVar5;

      fVar2 = pfVar5[1];

      local_d4 = local_d4 + -1;

      fVar3 = pfVar5[2];

      *pfVar7 = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];

      pfVar7[1] = fVar2 * param_2[5] + fVar3 * param_2[9] + fVar1 * param_2[1] + param_2[0xd];

      pfVar7[2] = fVar2 * param_2[6] + fVar3 * param_2[10] + fVar1 * param_2[2] + param_2[0xe];

      pfVar7[3] = 0.0;

      pfVar5 = pfVar5 + 4;

      pfVar7 = pfVar7 + 4;

    } while (local_d4 != 0);

  }

  iVar9 = *(int *)(param_1 + 0xc);

  local_f0 = 3.4028235e+38;

  local_ec = 3.4028235e+38;

  local_e8 = 3.4028235e+38;

  local_e4 = 3.4028235e+38;

  local_b0 = -3.4028235e+38;

  local_ac = -3.4028235e+38;

  local_a8 = -3.4028235e+38;

  fVar1 = DAT_00aaa63c;

  if (0 < iVar9) {

    pfVar5 = (float *)(param_1 + 0x1c);

    pfVar7 = local_90 + 2;

    do {

      fVar2 = *pfVar5;

      if (pfVar7[-2] - fVar2 <= local_f0) {

        local_f0 = pfVar7[-2] - fVar2;

      }

      if (pfVar7[-1] - fVar2 <= local_ec) {

        local_ec = pfVar7[-1] - fVar2;

      }

      if (*pfVar7 - fVar2 <= local_e8) {

        local_e8 = *pfVar7 - fVar2;

      }

      if (pfVar7[1] - fVar2 <= local_e4) {

        local_e4 = pfVar7[1] - fVar2;

      }

      if (local_b0 <= fVar2 + pfVar7[-2]) {

        local_b0 = fVar2 + pfVar7[-2];

      }

      if (local_ac <= fVar2 + pfVar7[-1]) {

        local_ac = fVar2 + pfVar7[-1];

      }

      if (local_a8 <= fVar2 + *pfVar7) {

        local_a8 = fVar2 + *pfVar7;

      }

      if (fVar1 <= fVar2 + pfVar7[1]) {

        fVar1 = fVar2 + pfVar7[1];

      }

      pfVar5 = pfVar5 + 4;

      pfVar7 = pfVar7 + 4;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  *param_4 = local_f0 - param_3;

  param_4[1] = local_ec - param_3;

  param_4[2] = local_e8 - param_3;

  param_4[3] = local_e4 - param_3;

  param_4[4] = local_b0 + param_3;

  param_4[5] = local_ac + param_3;

  param_4[6] = local_a8 + param_3;

  param_4[7] = fVar1 + param_3;

  return;

}
