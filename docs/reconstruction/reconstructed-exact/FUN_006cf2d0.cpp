// =============================================================================
// FUN_006cf2d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006cf2d0
// Address:   0x006cf2d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006cf2d0 @ 0x006cf2d0
// Stable ID: aa_006cf2d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: ROUND×5, FUN_006cec90, FUN_006cf2d0.
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

void __thiscall FUN_006cf2d0(uint32_t /* width from decompiler */ *param_1,float *param_2,float *param_3,uint32_t /* width from decompiler */ param_4)



{

  float fVar1;

  float fVar2;

  int local_28;

  int local_24;

  int local_20;

  int local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  *param_1 = param_4;

  param_1[4] = (int)ROUND((*param_3 - *param_2) * param_2[3]) + -1;

  param_1[5] = (int)ROUND((param_3[1] - param_2[1]) * param_2[3]) + -1;

  param_1[6] = (int)ROUND((param_3[2] - param_2[2]) * param_2[3]) + -1;

  fVar1 = param_3[3];

  fVar2 = param_2[3];

  local_28 = (int)*(short *)((int)param_1 + 0x12);

  param_1[7] = (int)ROUND(fVar1 * fVar2);

  local_24 = (int)*(short *)((int)param_1 + 0x16);

  local_1c = ((int)ROUND(fVar1 * fVar2) >> 0x10) + 1;

  local_20 = (int)*(short *)((int)param_1 + 0x1a);

  local_18 = 0;

  local_14 = 0;

  local_10 = 0;

  local_c = 0;

  local_4 = 0;

  local_8 = 0x10;

  FUN_006cec90(&local_28,param_2 + 0xc);

  return;

}
