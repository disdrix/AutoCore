// =============================================================================
// FUN_00418e10
// -----------------------------------------------------------------------------
// Stable ID: aa_00418e10
// Address:   0x00418e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00418e10 @ 0x00418e10
// Stable ID: aa_00418e10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00418e10, FUN_00418e60.
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

void __thiscall FUN_00418e10(int param_1,int *param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 == 0) || (*(int *)(param_1 + 8) - iVar1 >> 3 == 0)) {

    iVar1 = 0;

  }

  else {

    iVar1 = param_3 - iVar1 >> 3;

  }

  FUN_00418e60(param_3,1,param_4);

  *param_2 = *(int *)(param_1 + 4) + iVar1 * 8;

  return;

}
