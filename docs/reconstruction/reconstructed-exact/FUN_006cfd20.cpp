// =============================================================================
// FUN_006cfd20
// -----------------------------------------------------------------------------
// Stable ID: aa_006cfd20
// Address:   0x006cfd20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006cfd20 @ 0x006cfd20
// Stable ID: aa_006cfd20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: ROUND×6, FUN_006cf3b0, FUN_006cfd20.
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

void __thiscall FUN_006cfd20(uint32_t /* width from decompiler */ *param_1,float *param_2,float *param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int local_50;

  int local_4c;

  int local_48;

  int local_40;

  int local_3c;

  int local_38;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  

  *param_1 = param_4;

  param_1[0xc] = param_2;

  param_1[8] = (int)ROUND((*param_3 - *param_2) * param_2[3]) + -1;

  param_1[4] = (int)ROUND((param_3[4] - *(float *)param_1[0xc]) * ((float *)param_1[0xc])[3]) + -1;

  param_1[9] = (int)ROUND((param_3[1] - *(float *)(param_1[0xc] + 4)) *

                          *(float *)(param_1[0xc] + 0xc)) + -1;

  param_1[5] = (int)ROUND((param_3[5] - *(float *)(param_1[0xc] + 4)) *

                          *(float *)(param_1[0xc] + 0xc)) + -1;

  param_1[10] = (int)ROUND((param_3[2] - *(float *)(param_1[0xc] + 8)) *

                           *(float *)(param_1[0xc] + 0xc)) + -1;

  local_40 = (int)*(short *)((int)param_1 + 0x22);

  iVar1 = (int)ROUND((param_3[6] - *(float *)(param_1[0xc] + 8)) * *(float *)(param_1[0xc] + 0xc)) +

          -1;

  local_50 = *(short *)((int)param_1 + 0x12) + 1;

  local_3c = (int)*(short *)((int)param_1 + 0x26);

  local_4c = *(short *)((int)param_1 + 0x16) + 1;

  param_1[6] = iVar1;

  local_38 = (int)*(short *)((int)param_1 + 0x2a);

  local_48 = (iVar1 >> 0x10) + 1;

  local_30 = 0;

  local_2c = 0;

  local_28 = 0;

  local_24 = 0;

  local_20 = 0;

  local_1c = 0;

  FUN_006cf3b0(&local_50,param_2 + 0xc);

  return;

}
