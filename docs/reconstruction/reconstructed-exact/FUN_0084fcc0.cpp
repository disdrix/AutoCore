// =============================================================================
// FUN_0084fcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0084fcc0
// Address:   0x0084fcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084fcc0 @ 0x0084fcc0
// Stable ID: aa_0084fcc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0084fcc0.
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



void __fastcall FUN_0084fcc0(int *param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar2 = DAT_00aaa8dc;

  fVar1 = g_flOne;

  fVar3 = (float)param_1[0x141] + g_flOne;

  param_1[0x141] = (int)fVar3;

  if (fVar2 < fVar3) {

    param_1[0x141] = (int)fVar2;

  }

  fVar2 = DAT_00af9328;

  param_1[0x143] = (int)((float)param_1[0x142] * (fVar1 / (float)param_1[0x141]));

  fVar3 = DAT_00af932c;

  if (fVar2 < DAT_00af932c) {

    fVar3 = fVar2;

  }

  _DAT_00af9330 = fVar3 * DAT_00a0f298 * (fVar1 / (float)param_1[0x141]);

  if (_DAT_00af9330 < fVar1) {

    _DAT_00af9330 = fVar1;

  }

                    /* WARNING: Could not recover jumptable at 0x0084fd4b. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x34c))();

  return;

}
