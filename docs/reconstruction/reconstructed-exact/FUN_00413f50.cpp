// =============================================================================
// FUN_00413f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00413f50
// Address:   0x00413f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00413f50 @ 0x00413f50
// Stable ID: aa_00413f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00413f50.
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

void __thiscall FUN_00413f50(int *param_1,int *param_2,int *param_3)



{

  int iVar1;

  

  iVar1 = *param_2;

  *param_1 = iVar1;

  param_1[2] = *param_3 + iVar1;

  iVar1 = param_2[1];

  param_1[1] = iVar1;

  param_1[3] = param_3[1] + iVar1;

  return;

}
