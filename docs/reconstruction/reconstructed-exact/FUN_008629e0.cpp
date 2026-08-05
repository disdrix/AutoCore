// =============================================================================
// FUN_008629e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008629e0
// Address:   0x008629e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008629e0 @ 0x008629e0
// Stable ID: aa_008629e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_008629e0.
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



void __fastcall FUN_008629e0(int *param_1)



{

  int iVar1;

  

  iVar1 = (**(code **)(*param_1 + 0x3ac))();

  if (iVar1 != 0) {

    iVar1 = (**(code **)(*param_1 + 0x3ac))();

    if (*(int *)(*(int *)(iVar1 + 0xa8) + 0x38) == 0xe) {

      param_1[0x12a] = (int)((float)DAT_00d1e818 * (float)_DAT_00d1e50c * DAT_00aaa67c);

      param_1[299] = (int)((float)DAT_00d1e81c * (float)_DAT_00d1e510 * DAT_00aaa678);

      return;

    }

  }

  param_1[0x12a] = (int)((float)DAT_00d1e818 * (float)_DAT_00d1e50c * DAT_00aaa67c) * param_1[0x128]

  ;

  param_1[299] = (int)((float)DAT_00d1e81c * (float)_DAT_00d1e510 * DAT_00aaa678) * param_1[0x129];

  return;

}
