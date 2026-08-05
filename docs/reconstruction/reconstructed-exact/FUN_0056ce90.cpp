// =============================================================================
// FUN_0056ce90
// -----------------------------------------------------------------------------
// Stable ID: aa_0056ce90
// Address:   0x0056ce90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056ce90 @ 0x0056ce90
// Stable ID: aa_0056ce90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004c4cf0, FUN_0056b280, FUN_0056ce90.
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

float10 __thiscall FUN_0056ce90(int param_1,int *param_2)



{

  int iVar1;

  float10 extraout_ST0;

  

  if ((param_2 != (int *)0x0) && (iVar1 = (**(code **)(*param_2 + 0x214))(), iVar1 != 0)) {

    param_1 = param_1 + 0x130;

    (**(code **)(*param_2 + 0x214))(param_1);

    FUN_004c4cf0(param_1);

  }

  iVar1 = FUN_0056b280();

  return extraout_ST0 + (float10)iVar1;

}
