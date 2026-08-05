// =============================================================================
// FUN_00700a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00700a30
// Address:   0x00700a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00700a30 @ 0x00700a30
// Stable ID: aa_00700a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00700940×2, FUN_00700a30.
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

void FUN_00700a30(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

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

  

  local_70 = -*param_1;

  local_6c = -param_1[1];

  local_68 = -param_1[2];

  local_64 = -param_1[3];

  FUN_00700940(param_1,&local_40);

  FUN_00700940(&local_70,param_3);

  fVar1 = ((local_40 - local_20) - *param_2) * *param_1 +

          ((local_3c - local_1c) - param_2[1]) * param_1[1] +

          ((local_38 - local_18) - param_2[2]) * param_1[2];

  fVar2 = ((*param_3 - param_3[8]) - *param_2) * local_70 +

          ((param_3[1] - param_3[9]) - param_2[1]) * local_6c +

          ((param_3[2] - param_3[10]) - param_2[2]) * local_68;

  if (fVar2 <= fVar1) {

    *param_3 = local_40;

    param_3[1] = local_3c;

    param_3[2] = local_38;

    param_3[3] = local_34;

    param_3[4] = local_30;

    param_3[5] = local_2c;

    param_3[6] = local_28;

    param_3[7] = local_24;

    param_3[8] = local_20;

    param_3[9] = local_1c;

    param_3[10] = local_18;

    param_3[0xb] = local_14;

    param_3[0xc] = fVar1;

    return;

  }

  param_3[0xc] = fVar2;

  return;

}
