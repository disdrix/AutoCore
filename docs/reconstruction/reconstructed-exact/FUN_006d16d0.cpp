// =============================================================================
// FUN_006d16d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006d16d0
// Address:   0x006d16d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006d16d0 @ 0x006d16d0
// Stable ID: aa_006d16d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_006d16d0.
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

int __fastcall FUN_006d16d0(int *param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  for (iVar1 = (**(code **)(*param_1 + 0x2c))(); iVar1 != -1;

      iVar1 = (**(code **)(*param_1 + 0x30))(iVar1)) {

    iVar2 = iVar2 + 1;

  }

  return iVar2;

}
