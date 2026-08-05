// =============================================================================
// FUN_00714db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00714db0
// Address:   0x00714db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714db0 @ 0x00714db0
// Stable ID: aa_00714db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_00714db0.
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



float10 FUN_00714db0(float param_1,float param_2,float param_3,float param_4,float param_5)



{

  float10 fVar1;

  float10 fVar2;

  

  if (param_1 <= DAT_00a0f718) {

    param_2 = g_flZero;

  }

  fVar1 = (float10)param_2;

  if (DAT_00a0f74c <= param_1) {

    fVar2 = (float10)param_1 - (float10)DAT_00a0f74c;

    if ((float10)param_4 * (float10)DAT_00a0f298 * fVar2 < (float10)g_flOne) {

      fVar2 = fVar2 + (float10)_DAT_00a110e8;

    }

    param_1 = (float)fVar2;

    if (fVar1 < fVar2) {

      fVar1 = (float10)param_1;

    }

  }

  if ((fVar1 < (float10)param_3) && (_DAT_00a110e8 <= param_3)) {

    if ((param_4 < param_5 * _DAT_00a0f69c) && (param_5 * DAT_00a0f698 < param_4)) {

      fVar1 = (float10)param_3 * (float10)g_flOverheatCoolFrac + fVar1 * (float10)DAT_00a0f710;

    }

    if (fVar1 < (float10)_DAT_00a110e8) {

      fVar1 = fVar1 + (float10)_DAT_00a110e8;

    }

  }

  return fVar1;

}
