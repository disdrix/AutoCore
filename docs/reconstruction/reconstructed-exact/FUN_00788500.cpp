// =============================================================================
// FUN_00788500
// -----------------------------------------------------------------------------
// Stable ID: aa_00788500
// Address:   0x00788500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00788500 @ 0x00788500
// Stable ID: aa_00788500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00788500, SQRT.
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



uint32_t /* width from decompiler */ __fastcall

FUN_00788500(int param_1,int param_2,float param_3,float param_4,float param_5,float param_6,

            float param_7,float param_8)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  

  fVar1 = *(float *)(param_1 + 0x18) - *(float *)(param_1 + 0x14);

  fVar5 = *(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x20);

  fVar9 = *(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x10);

  fVar10 = *(float *)(param_1 + 0x20) - *(float *)(param_1 + 0x1c);

  fVar3 = *(float *)(param_1 + 0xc) - *(float *)(param_1 + 8);

  fVar7 = *(float *)(param_1 + 8) - *(float *)(param_1 + 4);

  fVar2 = fVar5 * fVar9 - fVar1 * fVar10;

  fVar9 = fVar1 * fVar7 - fVar3 * fVar9;

  fVar3 = fVar3 * fVar10 - fVar5 * fVar7;

  fVar1 = SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar9 * fVar9);

  if (fVar1 != g_flZero) {

    fVar1 = g_flOne / fVar1;

    fVar2 = fVar1 * fVar2;

    fVar3 = fVar1 * fVar3;

    fVar9 = fVar1 * fVar9;

  }

  param_4 = param_4 - *(float *)(param_1 + 0x10);

  param_3 = param_3 - *(float *)(param_1 + 4);

  param_5 = param_5 - *(float *)(param_1 + 0x1c);

  fVar1 = fVar2 * param_3 + fVar3 * param_4 + fVar9 * param_5;

  if (((float)_DAT_00aaa608 <= fVar1) &&

     ((param_5 + param_8) * fVar9 + (param_4 + param_7) * fVar3 + (param_3 + param_6) * fVar2 <=

      (float)_DAT_00aaa608)) {

    fVar5 = (DAT_00aaa668 / (fVar2 * param_6 + fVar3 * param_7 + fVar9 * param_8)) * fVar1;

    fVar4 = fVar5 * param_7 + param_4 + *(float *)(param_1 + 0x10);

    fVar7 = fVar5 * param_8 + param_5 + *(float *)(param_1 + 0x1c);

    fVar10 = *(float *)(param_1 + 0x14) - *(float *)(param_1 + 0x18);

    fVar6 = *(float *)(param_1 + 0x20) - *(float *)(param_1 + 0x24);

    fVar8 = fVar5 * param_6 + param_3 + *(float *)(param_1 + 4);

    fVar5 = *(float *)(param_1 + 8) - *(float *)(param_1 + 0xc);

    if (0.0 <= (fVar10 * fVar9 - fVar6 * fVar3) *

               (fVar8 - (*(float *)(param_1 + 0xc) + *(float *)(param_1 + 8)) * DAT_00a0f298) +

               (fVar6 * fVar2 - fVar5 * fVar9) *

               (fVar4 - (*(float *)(param_1 + 0x14) + *(float *)(param_1 + 0x18)) * DAT_00a0f298) +

               (fVar5 * fVar3 - fVar10 * fVar2) *

               (fVar7 - (*(float *)(param_1 + 0x20) + *(float *)(param_1 + 0x24)) * DAT_00a0f298)) {

      fVar6 = *(float *)(param_1 + 0x18) - *(float *)(param_1 + 0x10);

      fVar10 = *(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x1c);

      fVar5 = *(float *)(param_1 + 0xc) - *(float *)(param_1 + 4);

      if (0.0 <= (fVar6 * fVar9 - fVar10 * fVar3) *

                 (fVar8 - (*(float *)(param_1 + 0xc) + *(float *)(param_1 + 4)) * DAT_00a0f298) +

                 (fVar10 * fVar2 - fVar5 * fVar9) *

                 (fVar4 - (*(float *)(param_1 + 0x18) + *(float *)(param_1 + 0x10)) * DAT_00a0f298)

                 + (fVar5 * fVar3 - fVar6 * fVar2) *

                   (fVar7 - (*(float *)(param_1 + 0x1c) + *(float *)(param_1 + 0x24)) * DAT_00a0f298

                   )) {

        fVar6 = *(float *)(param_1 + 0x10) - *(float *)(param_1 + 0x14);

        fVar10 = *(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x20);

        fVar5 = *(float *)(param_1 + 4) - *(float *)(param_1 + 8);

        if (0.0 <= (fVar6 * fVar9 - fVar10 * fVar3) *

                   (fVar8 - (*(float *)(param_1 + 4) + *(float *)(param_1 + 8)) * DAT_00a0f298) +

                   (fVar10 * fVar2 - fVar5 * fVar9) *

                   (fVar4 - (*(float *)(param_1 + 0x14) + *(float *)(param_1 + 0x10)) * DAT_00a0f298

                   ) + (fVar5 * fVar3 - fVar6 * fVar2) *

                       (fVar7 - (*(float *)(param_1 + 0x1c) + *(float *)(param_1 + 0x20)) *

                                DAT_00a0f298)) {

          fVar2 = fVar2 * DAT_00a0f298;

          *(float *)(param_2 + 0x10) = fVar2 + fVar8;

          *(float *)(param_2 + 0x14) = fVar2 + fVar4;

          *(float *)(param_2 + 0x18) = fVar2 + fVar7;

          *(float *)(param_2 + 0x20) = fVar1;

          return 1;

        }

      }

    }

  }

  return 0;

}
