// =============================================================================
// FUN_004cff70
// -----------------------------------------------------------------------------
// Stable ID: aa_004cff70
// Address:   0x004cff70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cff70 @ 0x004cff70
// Stable ID: aa_004cff70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×2, while×2, goto×1.
//  - Notable callees: ABS×3, FUN_005a58c0×3, FUN_004cff70.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall

FUN_004cff70(int param_1,float *param_2,float *param_3,float *param_4,int param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  int iVar6;

  float10 extraout_ST0;

  float10 extraout_ST0_00;

  float10 extraout_ST0_01;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  

  if (*(int *)(param_1 + 0xe4e0) != 0) {

    *param_4 = *param_2;

    param_4[1] = param_2[1];

    param_4[2] = param_2[2];

    param_4[3] = param_2[3];

    fVar1 = param_3[1];

    fVar2 = param_3[2];

    fVar3 = param_3[3];

    local_34 = 0.0;

    local_30 = *param_2;

    local_2c = param_2[1];

    local_28 = param_2[2];

    local_24 = param_2[3];

    fVar4 = *param_3;

    iVar6 = 0;

    FUN_005a58c0(*param_2,param_2[2]);

    if (extraout_ST0 <= (float10)param_2[1]) {

LAB_004d00db:

      if (iVar6 < param_5) {

        do {

          local_28 = fVar2 + local_28;

          local_30 = fVar4 + local_30;

          local_2c = fVar1 + local_2c;

          local_24 = fVar3 + local_24;

          *param_4 = local_30;

          param_4[1] = local_2c;

          param_4[2] = local_28;

          param_4[3] = local_24;

          FUN_005a58c0(local_30,local_28);

          fVar5 = (float)extraout_ST0_01;

          if (local_2c <= fVar5) {

            fVar1 = ABS(param_4[1] - local_34) /

                    (ABS(fVar5 - local_2c) + ABS(param_4[1] - local_34));

            *param_4 = (local_30 - *param_4) * fVar1 + *param_4;

            param_4[2] = (local_28 - param_4[2]) * fVar1 + param_4[2];

            return 1;

          }

          iVar6 = iVar6 + 1;

          local_34 = fVar5;

        } while (iVar6 < param_5);

        return 0;

      }

    }

    else if (0 < param_5) {

      do {

        local_28 = fVar2 + local_28;

        local_30 = fVar4 + local_30;

        local_2c = fVar1 + local_2c;

        local_24 = fVar3 + local_24;

        *param_4 = local_30;

        param_4[1] = local_2c;

        param_4[2] = local_28;

        param_4[3] = local_24;

        FUN_005a58c0(local_30,local_28);

        if ((float)extraout_ST0_00 < local_2c) goto LAB_004d00db;

        iVar6 = iVar6 + 1;

      } while (iVar6 < param_5);

    }

  }

  return 0;

}
