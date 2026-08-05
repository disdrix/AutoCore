// =============================================================================
// FUN_007a2580
// -----------------------------------------------------------------------------
// Stable ID: aa_007a2580
// Address:   0x007a2580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a2580 @ 0x007a2580
// Stable ID: aa_007a2580
// Embedded strings (evidence for future rename):
//   - "DistortTexture"
//   - "NormalMapTexture"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00752370×2, FUN_00970060×2, FUN_007a2580.
//  - Strings: "DistortTexture"; "NormalMapTexture".
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

void __thiscall FUN_007a2580(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int local_4;

  

  piVar1 = &local_4;

  if (**(int **)(param_1 + 0x1e0) == 0) {

    local_4 = -1;

  }

  else {

    local_4 = param_1;

    piVar1 = (int *)FUN_00752370(piVar1,"DistortTexture");

  }

  if (-1 < *piVar1) {

    FUN_00970060(*piVar1,param_2);

  }

  if (**(int **)(param_1 + 0x1e0) == 0) {

    param_2 = -1;

    piVar1 = &param_2;

  }

  else {

    piVar1 = (int *)FUN_00752370(&param_2,"NormalMapTexture");

  }

  if (-1 < *piVar1) {

    FUN_00970060(*piVar1,param_3);

  }

  return;

}
