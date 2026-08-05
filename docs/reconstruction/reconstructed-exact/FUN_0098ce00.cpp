// =============================================================================
// FUN_0098ce00
// -----------------------------------------------------------------------------
// Stable ID: aa_0098ce00
// Address:   0x0098ce00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098ce00 @ 0x0098ce00
// Stable ID: aa_0098ce00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_0040ce80, FUN_0098ce00.
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

uint32_t /* width from decompiler */ __fastcall

FUN_0098ce00(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,

            float *param_6)



{

  float *unaff_EBX;

  float *unaff_ESI;

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_14 = param_1[1] - param_4[1];

  local_10 = param_1[2] - param_4[2];

  local_18 = *param_1 - *param_4;

  local_c = *param_2 - *param_4;

  local_4 = param_2[2] - param_4[2];

  local_8 = param_2[1] - param_4[1];

  fVar3 = unaff_ESI[1] * local_10 - unaff_ESI[2] * local_14;

  fVar2 = *unaff_ESI * local_14 - unaff_ESI[1] * local_18;

  fVar4 = unaff_ESI[2] * local_18 - *unaff_ESI * local_10;

  fVar1 = fVar2 * local_4 + local_c * fVar3 + fVar4 * local_8;

  if (0.0 < fVar1) {

    local_30 = *param_3 - *param_4;

    local_2c = param_3[1] - param_4[1];

    local_28 = param_3[2] - param_4[2];

    if (DAT_00aaa664 <= fVar1) {

      fVar2 = local_28 * fVar2 + local_2c * fVar4 + local_30 * fVar3;

      if ((0.0 <= fVar2) && (fVar2 <= fVar1)) {

        local_24 = local_30;

        local_20 = local_2c;

        local_1c = local_28;

        FUN_0040ce80(&local_30,&local_c);

        fVar3 = unaff_ESI[1] * local_20 + *unaff_ESI * local_24 + unaff_ESI[2] * local_1c;

        if (0.0 <= fVar3) {

          if (fVar3 + fVar2 <= fVar1) {

            fVar1 = g_flOne / fVar1;

            if (unaff_EBX != (float *)0x0) {

              *unaff_EBX = (local_1c * local_10 + local_20 * local_14 + local_24 * local_18) * fVar1

              ;

            }

            if ((param_5 != (float *)0x0) && (param_6 != (float *)0x0)) {

              *param_5 = fVar1 * fVar2;

              *param_6 = fVar1 * fVar3;

            }

            return 1;

          }

        }

      }

    }

  }

  return 0;

}
