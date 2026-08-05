// =============================================================================
// FUN_006eefc0
// -----------------------------------------------------------------------------
// Stable ID: aa_006eefc0
// Address:   0x006eefc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006eefc0 @ 0x006eefc0
// Stable ID: aa_006eefc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_006eefc0.
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

void FUN_006eefc0(float *param_1,int param_2,int param_3,float *param_4)



{

  float fVar1;

  

  *param_4 = *param_1;

  param_4[1] = param_1[1];

  param_1 = param_1 + 2;

  param_4[2] = *param_1;

  param_4[3] = 0.0;

  param_4[4] = *param_4;

  param_4[5] = param_4[1];

  param_4[6] = param_4[2];

  param_4[7] = param_4[3];

  if (0 < param_2) {

    do {

      fVar1 = param_1[-2];

      if (param_1[-2] < param_4[4]) {

        fVar1 = param_4[4];

      }

      param_4[4] = fVar1;

      fVar1 = param_1[-1];

      if (param_1[-1] < param_4[5]) {

        fVar1 = param_4[5];

      }

      param_4[5] = fVar1;

      fVar1 = *param_1;

      if (*param_1 < param_4[6]) {

        fVar1 = param_4[6];

      }

      param_4[6] = fVar1;

      fVar1 = param_1[-2];

      if (*param_4 < param_1[-2]) {

        fVar1 = *param_4;

      }

      *param_4 = fVar1;

      fVar1 = param_1[-1];

      if (param_4[1] < param_1[-1]) {

        fVar1 = param_4[1];

      }

      param_4[1] = fVar1;

      fVar1 = *param_1;

      if (param_4[2] < *param_1) {

        fVar1 = param_4[2];

      }

      param_1 = (float *)((int)param_1 + param_3);

      param_4[2] = fVar1;

      param_2 = param_2 + -1;

    } while (param_2 != 0);

  }

  return;

}
