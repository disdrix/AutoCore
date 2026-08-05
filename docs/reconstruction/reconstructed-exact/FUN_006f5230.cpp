// =============================================================================
// FUN_006f5230
// -----------------------------------------------------------------------------
// Stable ID: aa_006f5230
// Address:   0x006f5230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f5230 @ 0x006f5230
// Stable ID: aa_006f5230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_006f5230.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __thiscall FUN_006f5230(int param_1,int *param_2)



{

  float10 fVar1;

  float10 fVar2;

  

  if (*param_2 < param_2[1]) {

    fVar1 = (float10)(float)param_2[3] - (float10)(float)param_2[2];

    fVar2 = (float10)*(float *)(param_1 + 0x1c);

    if (fVar1 <= (float10)*(float *)(param_1 + 0x1c)) {

      fVar2 = fVar1;

    }

    fVar2 = (float10)g_flOne / (fVar2 + fVar1);

  }

  else {

    fVar2 = (float10)(float)param_2[4];

  }

  fVar2 = fVar2 * ((float10)(float)param_2[8] -

                  ((float10)(float)param_2[3] + (float10)(float)param_2[2]) * (float10)DAT_00a0f298)

  ;

  if (fVar2 < (float10)g_flZero) {

    return (float10)g_flZero;

  }

  fVar2 = fVar2 * fVar2;

  fVar1 = fVar2 * fVar2;

  return (fVar2 * (float10)_DAT_00a0eec8 +

         fVar1 * (float10)g_flVehicleHpTechCoeff + fVar1 * fVar1 * (float10)_DAT_00a0eecc) *

         (float10)*(float *)(param_1 + 0x14);

}
