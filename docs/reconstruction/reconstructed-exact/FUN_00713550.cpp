// =============================================================================
// FUN_00713550
// -----------------------------------------------------------------------------
// Stable ID: aa_00713550
// Address:   0x00713550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00713550 @ 0x00713550
// Stable ID: aa_00713550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00713550, FUN_00713620, FUN_00713700, FUN_00714e90, FUN_00714f30.
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

void FUN_00713550(uint32_t /* width from decompiler */ *param_1,float *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,int param_6)



{

  float10 fVar1;

  float local_420;

  uint32_t /* width from decompiler */ local_41c;

  uint32_t /* width from decompiler */ local_418;

  uint8_t local_414 [1044];

  

  fVar1 = (float10)FUN_00714e90(param_1[0xd],param_2[2],param_1[0xc],param_2[3]);

  local_420 = (float)fVar1;

  if (param_6 == 1) {

    local_420 = local_420 + local_420;

  }

  FUN_00713700(local_420,*param_1,local_414,&local_41c,param_3);

  fVar1 = (float10)FUN_00714f30(local_414,local_41c,local_420,&local_418,0x3dcccccd);

  *param_2 = (float)fVar1;

  if (param_6 == 1) {

    *param_2 = (float)(fVar1 * (float10)DAT_00a0f298);

  }

  fVar1 = (float10)FUN_00713620(param_1[0xc],param_2[3],param_5,local_418,param_1 + 7);

  param_2[1] = (float)fVar1;

  return;

}
