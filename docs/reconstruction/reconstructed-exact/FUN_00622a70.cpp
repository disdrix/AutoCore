// =============================================================================
// FUN_00622a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00622a70
// Address:   0x00622a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00622a70 @ 0x00622a70
// Stable ID: aa_00622a70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005787a0, FUN_006228f0, FUN_00622a70.
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

uint32_t /* width from decompiler */ __thiscall FUN_00622a70(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  float fVar2;

  

  fVar2 = (float)param_1[0x1b0] - ((float)param_1[0x1b0] - (float)param_1[0x62]);

  if (fVar2 < g_flOne) {

    fVar2 = g_flOne;

  }

  piVar1 = param_1 + 0x1b0;

  *piVar1 = *piVar1 - (int)fVar2;

  if (*piVar1 < 0) {

    param_1[0x1b0] = 0;

  }

  FUN_006228f0();

  (**(code **)(*param_1 + 0x50))();

  FUN_005787a0(param_2);

  return param_2;

}
