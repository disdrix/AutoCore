// =============================================================================
// FUN_006a26c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a26c0
// Address:   0x006a26c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a26c0 @ 0x006a26c0
// Stable ID: aa_006a26c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: SQRT×2, FUN_0069aa50, FUN_006a2580, FUN_006a26c0, block, fcos.
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

/* WARNING: Removing unreachable block (ram,0x006a27ac) */



void __thiscall FUN_006a26c0(int param_1,float *param_2,float *param_3,float param_4)



{

  float fVar1;

  unkbyte10 Var2;

  float10 fVar3;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_c = *(float *)(param_1 + 4) - *param_2;

  local_8 = *(float *)(param_1 + 8) - param_2[1];

  local_4 = *(float *)(param_1 + 0xc) - param_2[2];

  fVar1 = g_flOne / SQRT(local_c * local_c + local_8 * local_8 + local_4 * local_4);

  local_c = local_c * fVar1;

  local_8 = local_8 * fVar1;

  local_4 = local_4 * fVar1;

  local_18 = *param_3 - *param_2;

  local_14 = param_3[1] - param_2[1];

  local_10 = param_3[2] - param_2[2];

  fVar1 = g_flOne / SQRT(local_18 * local_18 + local_14 * local_14 + local_10 * local_10);

  local_18 = local_18 * fVar1;

  local_14 = local_14 * fVar1;

  local_10 = local_10 * fVar1;

  Var2 = FUN_0069aa50(&local_18);

  fVar3 = (float10)fcos(Var2);

  fVar3 = ((float10)g_flOne - (float10)param_4) * (fVar3 + (float10)g_flOne) * (float10)DAT_00a0f298

          + (float10)param_4;

  local_10 = (float)*(byte *)(param_1 + 0x16) * DAT_00aaa7a8;

  local_c = (float)((float10)(*(uint *)(param_1 + 0x14) & 0xff) * (float10)DAT_00aaa7a8 * fVar3);

  local_8 = (float)((float10)*(byte *)(param_1 + 0x15) * (float10)DAT_00aaa7a8 * fVar3);

  local_4 = (float)((float10)local_10 * fVar3);

  FUN_006a2580(&local_c,1);

  return;

}
