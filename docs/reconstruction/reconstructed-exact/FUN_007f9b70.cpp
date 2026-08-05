// =============================================================================
// FUN_007f9b70
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9b70
// Address:   0x007f9b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f9b70 @ 0x007f9b70
// Stable ID: aa_007f9b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007f9b70.
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

void __thiscall FUN_007f9b70(int *param_1,int *param_2)



{

  int iVar1;

  int local_8;

  int local_4;

  

  if (DAT_00d1b213 == '\0') {

    iVar1 = param_1[0x13c] * 2 + 0x129;

  }

  else {

    iVar1 = param_1[0x13c] * 2 + 0x150;

  }

  local_8 = *param_2 + param_1[iVar1];

  local_4 = param_2[1] + (param_1 + iVar1)[1];

  (**(code **)(*param_1 + 0x110))(&local_8);

  return;

}
