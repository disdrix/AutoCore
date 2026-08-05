// =============================================================================
// FUN_006fb6d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006fb6d0
// Address:   0x006fb6d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fb6d0 @ 0x006fb6d0
// Stable ID: aa_006fb6d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_006fb6d0.
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

void __thiscall FUN_006fb6d0(int *param_1,uint32_t /* width from decompiler */ param_2,float *param_3,float *param_4)



{

  float fVar1;

  

  param_4[8] = param_3[3];

  *param_4 = -*param_3;

  param_4[1] = -param_3[1];

  param_4[2] = -param_3[2];

  param_4[3] = -param_3[3];

  if (*param_1 == 1) {

    param_4[4] = (float)param_1[8];

    param_4[5] = (float)param_1[9];

    param_4[6] = (float)param_1[10];

    param_4[7] = (float)param_1[0xb];

    param_4[9] = 1.0;

    return;

  }

  if (param_1[1] == 1) {

    fVar1 = param_3[3];

    param_4[4] = (float)param_1[0x28];

    param_4[5] = (float)param_1[0x29];

    param_4[6] = (float)param_1[0x2a];

    param_4[7] = (float)param_1[0x2b];

    param_4[4] = fVar1 * *param_4 + param_4[4];

    param_4[5] = fVar1 * param_4[1] + param_4[5];

    param_4[6] = fVar1 * param_4[2] + param_4[6];

    param_4[7] = fVar1 * param_4[3] + param_4[7];

    param_4[9] = 0.0;

    return;

  }

  param_4[4] = (float)param_1[0x4c];

  param_4[5] = (float)param_1[0x4d];

  param_4[6] = (float)param_1[0x4e];

  param_4[7] = (float)param_1[0x4f];

  param_4[9] = 0.5;

  return;

}
