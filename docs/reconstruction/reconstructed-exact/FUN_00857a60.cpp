// =============================================================================
// FUN_00857a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00857a60
// Address:   0x00857a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00857a60 @ 0x00857a60
// Stable ID: aa_00857a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00857a60.
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

void __fastcall FUN_00857a60(int *param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar1 = g_flOne;

  fVar2 = (float)param_1[0x141] - g_flOne;

  param_1[0x141] = (int)fVar2;

  if (fVar2 < fVar1) {

    param_1[0x141] = (int)fVar1;

  }

  fVar2 = DAT_00af931c;

  param_1[0x143] = (int)((float)param_1[0x142] * (fVar1 / (float)param_1[0x141]));

  fVar3 = DAT_00af9320;

  if (fVar2 < DAT_00af9320) {

    fVar3 = fVar2;

  }

  fVar2 = fVar3 * DAT_00a0f298 * (fVar1 / (float)param_1[0x141]);

  param_1[0x13f] = (int)fVar2;

  if (fVar2 < fVar1) {

    param_1[0x13f] = (int)fVar1;

  }

                    /* WARNING: Could not recover jumptable at 0x00857ae3. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x34c))();

  return;

}
