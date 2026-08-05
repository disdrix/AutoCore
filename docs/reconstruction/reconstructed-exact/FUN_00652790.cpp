// =============================================================================
// FUN_00652790
// -----------------------------------------------------------------------------
// Stable ID: aa_00652790
// Address:   0x00652790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00652790 @ 0x00652790
// Stable ID: aa_00652790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0063fba0, FUN_006526f0, FUN_00652790, socket.
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

int * __thiscall FUN_00652790(int *param_1,int param_2)



{

  SOCKET SVar1;

  

  FUN_0063fba0();

  *param_1 = (int)&PTR_FUN_009e5b9c;

  param_1[8] = param_2;

  FUN_006526f0();

  if (param_1[8] == -1) {

    (**(code **)(*param_1 + 8))();

    SVar1 = socket(2,1,0);

    param_1[8] = SVar1;

  }

  return param_1;

}
