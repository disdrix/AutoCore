// =============================================================================
// FUN_0069a580
// -----------------------------------------------------------------------------
// Stable ID: aa_0069a580
// Address:   0x0069a580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069a580 @ 0x0069a580
// Stable ID: aa_0069a580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: ABS×2, _CIpow×2, FUN_0069a580.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 __thiscall FUN_0069a580(float *param_1,float param_2,float param_3)



{

  float fVar1;

  float10 fVar2;

  float10 extraout_ST1;

  

  fVar2 = (float10)g_flZero;

  fVar1 = *param_1;

  if (_DAT_009eb45c < ABS(param_2 - fVar1)) {

    if (fVar1 <= param_2) {

      fVar1 = DAT_00af55b4 + fVar1;

    }

    else {

      param_2 = param_2 + DAT_00af55b4;

    }

  }

  if ((ABS(param_2 - fVar1) < param_1[1]) && (g_flZero < param_1[3] - param_3)) {

    _CIpow();

    fVar2 = (float10)_CIpow();

    fVar2 = fVar2 * extraout_ST1 * (float10)param_1[5];

  }

  return fVar2;

}
