// =============================================================================
// FUN_007aec10
// -----------------------------------------------------------------------------
// Stable ID: aa_007aec10
// Address:   0x007aec10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007aec10 @ 0x007aec10
// Stable ID: aa_007aec10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007ae2a0, FUN_007aec10.
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

void __fastcall FUN_007aec10(int *param_1)



{

  char cVar1;

  int iVar2;

  

  cVar1 = (**(code **)(*param_1 + 0x328))();

  if (cVar1 == '\0') {

    param_1[0xa7] = 0;

  }

  else {

    iVar2 = (**(code **)(*param_1 + 0x5c))(param_1[0xa5]);

    param_1[0xa7] = iVar2;

  }

  if (param_1[0xa7] != 0) {

    iVar2 = FUN_007ae2a0(param_1[0xa7]);

    param_1[0xa8] = iVar2;

    return;

  }

  param_1[0xa8] = 0;

  return;

}
