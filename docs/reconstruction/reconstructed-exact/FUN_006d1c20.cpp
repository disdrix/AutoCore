// =============================================================================
// FUN_006d1c20
// -----------------------------------------------------------------------------
// Stable ID: aa_006d1c20
// Address:   0x006d1c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d1c20 @ 0x006d1c20
// Stable ID: aa_006d1c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×16, return×1.
//  - Notable callees: FUN_005d68f0×3, FUN_006d1c20.
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

void __thiscall FUN_006d1c20(int param_1,uint32_t /* width from decompiler */ param_2,float param_3,float *param_4)



{

  float fVar1;

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

  

  param_3 = param_3 + *(float *)(param_1 + 0xc);

  FUN_005d68f0(param_2,param_1 + 0x10);

  FUN_005d68f0(param_2,param_1 + 0x20);

  FUN_005d68f0(param_2,param_1 + 0x30);

  fVar1 = local_30;

  if (local_40 < local_30) {

    fVar1 = local_40;

  }

  *param_4 = fVar1;

  fVar1 = local_2c;

  if (local_3c < local_2c) {

    fVar1 = local_3c;

  }

  param_4[1] = fVar1;

  fVar1 = local_28;

  if (local_38 < local_28) {

    fVar1 = local_38;

  }

  param_4[2] = fVar1;

  fVar1 = local_24;

  if (local_34 < local_24) {

    fVar1 = local_34;

  }

  param_4[3] = fVar1;

  if (local_30 < local_40) {

    local_30 = local_40;

  }

  param_4[4] = local_30;

  if (local_2c < local_3c) {

    local_2c = local_3c;

  }

  param_4[5] = local_2c;

  if (local_28 < local_38) {

    local_28 = local_38;

  }

  param_4[6] = local_28;

  if (local_24 < local_34) {

    local_24 = local_34;

  }

  param_4[7] = local_24;

  fVar1 = local_20;

  if (*param_4 < local_20) {

    fVar1 = *param_4;

  }

  *param_4 = fVar1;

  fVar1 = local_1c;

  if (param_4[1] < local_1c) {

    fVar1 = param_4[1];

  }

  param_4[1] = fVar1;

  fVar1 = local_18;

  if (param_4[2] < local_18) {

    fVar1 = param_4[2];

  }

  param_4[2] = fVar1;

  fVar1 = local_14;

  if (param_4[3] < local_14) {

    fVar1 = param_4[3];

  }

  param_4[3] = fVar1;

  if (local_20 < param_4[4]) {

    local_20 = param_4[4];

  }

  param_4[4] = local_20;

  if (local_1c < param_4[5]) {

    local_1c = param_4[5];

  }

  param_4[5] = local_1c;

  if (local_18 < param_4[6]) {

    local_18 = param_4[6];

  }

  param_4[6] = local_18;

  if (local_14 < param_4[7]) {

    local_14 = param_4[7];

  }

  param_4[7] = local_14;

  *param_4 = *param_4 - param_3;

  param_4[1] = param_4[1] - param_3;

  param_4[2] = param_4[2] - param_3;

  param_4[3] = param_4[3] - param_3;

  param_4[4] = param_3 + param_4[4];

  param_4[5] = param_3 + param_4[5];

  param_4[6] = param_3 + param_4[6];

  param_4[7] = param_3 + param_4[7];

  return;

}
