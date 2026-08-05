// =============================================================================
// FUN_00788400
// -----------------------------------------------------------------------------
// Stable ID: aa_00788400
// Address:   0x00788400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00788400 @ 0x00788400
// Stable ID: aa_00788400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00788400, SQRT.
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

float10 FUN_00788400(float *param_1,float *param_2,float *param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float local_20;

  float local_1c;

  float local_18;

  

  local_18 = param_1[2] - param_2[2];

  local_1c = param_1[1] - param_2[1];

  fVar3 = param_3[1] - param_2[1];

  fVar4 = param_3[2] - param_2[2];

  local_20 = *param_1 - *param_2;

  fVar2 = *param_3 - *param_2;

  fVar1 = local_18 * fVar4 + local_1c * fVar3 + local_20 * fVar2;

  if (0.0 < fVar1) {

    fVar5 = fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3;

    if (fVar1 <= fVar5) {

      fVar1 = fVar1 / fVar5;

      fVar2 = fVar2 * fVar1;

      fVar3 = fVar3 * fVar1;

      fVar4 = fVar4 * fVar1;

    }

    local_20 = local_20 - fVar2;

    local_1c = local_1c - fVar3;

    local_18 = local_18 - fVar4;

  }

  return SQRT((float10)local_20 * (float10)local_20 +

              (float10)local_1c * (float10)local_1c + (float10)local_18 * (float10)local_18);

}
