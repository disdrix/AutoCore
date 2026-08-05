// =============================================================================
// FUN_005ef780
// -----------------------------------------------------------------------------
// Stable ID: aa_005ef780
// Address:   0x005ef780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ef780 @ 0x005ef780
// Stable ID: aa_005ef780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~137 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: ABS×6, FUN_005eee10, FUN_005ef780, SQRT.
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



void FUN_005ef780(int *param_1)



{

  int iVar1;

  uint uVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  float *unaff_EDI;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  int local_64;

  int local_58;

  float local_50 [4];

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  local_58 = param_1[4];

  DAT_00d027ac = 0.0;

  DAT_00d027a8 = 0.0;

  DAT_00d027a4 = 0.0;

  DAT_00d027e0 = 0.0;

  DAT_00d027dc = 0.0;

  DAT_00d027d8 = 0.0;

  DAT_00d02808 = 0.0;

  DAT_00d02804 = 0.0;

  DAT_00d02800 = 0.0;

  DAT_00d027b0 = 0.0;

  fVar7 = 0.0;

  fVar8 = 0.0;

  fVar9 = 0.0;

  fVar10 = 0.0;

  fVar11 = 0.0;

  fVar12 = 0.0;

  fVar13 = 0.0;

  if (0 < local_58) {

    local_64 = 0;

    do {

      piVar3 = (int *)(param_1[3] + local_64);

      iVar1 = *param_1;

      iVar4 = *piVar3 * 0x10;

      local_3c = *(float *)(iVar4 + 4 + iVar1) + unaff_EDI[1];

      local_40 = *(float *)(iVar4 + iVar1) + *unaff_EDI;

      local_38 = *(float *)(iVar4 + iVar1 + 8) + unaff_EDI[2];

      local_34 = *(float *)(iVar4 + iVar1 + 0xc) + unaff_EDI[3];

      iVar4 = piVar3[1] * 0x10;

      local_24 = *(float *)(iVar4 + 0xc + iVar1) + unaff_EDI[3];

      local_2c = *(float *)(iVar4 + 4 + iVar1) + unaff_EDI[1];

      local_28 = *(float *)(iVar4 + 8 + iVar1) + unaff_EDI[2];

      iVar5 = piVar3[2] * 0x10;

      local_14 = *(float *)(iVar5 + 0xc + iVar1) + unaff_EDI[3];

      local_18 = *(float *)(iVar5 + 8 + iVar1) + unaff_EDI[2];

      local_1c = *(float *)(iVar5 + 4 + iVar1) + unaff_EDI[1];

      local_30 = *unaff_EDI + *(float *)(iVar4 + iVar1);

      local_20 = *(float *)(iVar5 + iVar1) + *unaff_EDI;

      local_50[2] = (local_1c - local_3c) * (local_30 - local_40) -

                    (local_2c - local_3c) * (local_20 - local_40);

      local_50[1] = (local_28 - local_38) * (local_20 - local_40) -

                    (local_18 - local_38) * (local_30 - local_40);

      local_50[0] = (local_18 - local_38) * (local_2c - local_3c) -

                    (local_1c - local_3c) * (local_28 - local_38);

      local_50[3] = SQRT(local_50[0] * local_50[0] +

                         local_50[1] * local_50[1] + local_50[2] * local_50[2]);

      if (g_flZero < local_50[3]) {

        local_50[3] = g_flOne / local_50[3];

        local_50[0] = local_50[0] * local_50[3];

        local_50[1] = local_50[1] * local_50[3];

        local_50[2] = local_50[2] * local_50[3];

        local_50[3] = local_50[3] * 0.0;

        if ((ABS(local_50[0]) <= ABS(local_50[1])) || (ABS(local_50[0]) <= ABS(local_50[2]))) {

          DAT_00d027fc = 1;

          if (ABS(local_50[1]) <= ABS(local_50[2])) {

            DAT_00d027fc = 2;

          }

        }

        else {

          DAT_00d027fc = 0;

        }

        uVar6 = (DAT_00d027fc + 1U) % 3;

        DAT_00d027f0 = (uVar6 + 1) % 3;

        DAT_00d027d4 = uVar6;

        FUN_005eee10();

        uVar2 = DAT_00d027f0;

        fVar7 = DAT_00d02790;

        if ((uVar6 != 0) && (fVar7 = DAT_00d027cc, DAT_00d027f0 != 0)) {

          fVar7 = DAT_00d02798;

        }

        DAT_00d027b0 = fVar7 * local_50[0] + DAT_00d027b0;

        (&DAT_00d02800)[uVar6] = local_50[uVar6] * _DAT_00d027b8 + (&DAT_00d02800)[uVar6];

        (&DAT_00d02800)[uVar2] = local_50[uVar2] * _DAT_00d027ec + (&DAT_00d02800)[uVar2];

        iVar1 = DAT_00d027fc;

        (&DAT_00d02800)[DAT_00d027fc] =

             DAT_00d0279c * local_50[DAT_00d027fc] + (&DAT_00d02800)[DAT_00d027fc];

        (&DAT_00d027d8)[uVar6] = local_50[uVar6] * _DAT_00d027c0 + (&DAT_00d027d8)[uVar6];

        (&DAT_00d027d8)[uVar2] = local_50[uVar2] * _DAT_00d02814 + (&DAT_00d027d8)[uVar2];

        (&DAT_00d027d8)[iVar1] = DAT_00d027b4 * local_50[iVar1] + (&DAT_00d027d8)[iVar1];

        (&DAT_00d027a4)[uVar6] = local_50[uVar6] * _DAT_00d027c8 + (&DAT_00d027a4)[uVar6];

        (&DAT_00d027a4)[uVar2] = local_50[uVar2] * _DAT_00d0280c + (&DAT_00d027a4)[uVar2];

        (&DAT_00d027a4)[iVar1] = DAT_00d027e8 * local_50[iVar1] + (&DAT_00d027a4)[iVar1];

      }

      local_64 = local_64 + 0xc;

      local_58 = local_58 + -1;

      fVar7 = DAT_00d02800;

      fVar8 = DAT_00d02804;

      fVar9 = DAT_00d02808;

      fVar10 = DAT_00d027d8;

      fVar11 = DAT_00d027dc;

      fVar12 = DAT_00d027e0;

      fVar13 = DAT_00d027a4;

    } while (local_58 != 0);

  }

  DAT_00d02800 = fVar7 * DAT_00a0f298;

  DAT_00d027a8 = DAT_00d027a8 * DAT_00a0f298;

  DAT_00d02804 = fVar8 * DAT_00a0f298;

  DAT_00d02808 = fVar9 * DAT_00a0f298;

  DAT_00d027d8 = fVar10 * g_flDisplayRateScaleOneThird;

  DAT_00d027dc = fVar11 * g_flDisplayRateScaleOneThird;

  DAT_00d027e0 = fVar12 * g_flDisplayRateScaleOneThird;

  DAT_00d027a4 = fVar13 * DAT_00a0f298;

  DAT_00d027ac = DAT_00d027ac * DAT_00a0f298;

  return;

}
