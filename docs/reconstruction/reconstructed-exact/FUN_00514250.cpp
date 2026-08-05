// =============================================================================
// FUN_00514250
// -----------------------------------------------------------------------------
// Stable ID: aa_00514250
// Address:   0x00514250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00514250 @ 0x00514250
// Stable ID: aa_00514250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00513580, FUN_00514250.
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

int __fastcall FUN_00514250(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 0xc4);

  if (iVar2 == -1) {

    return 0;

  }

  iVar1 = FUN_00513580();

  iVar2 = iVar2 + iVar1;

  if ((*(byte *)(param_1 + 0x17e) & 8) != 0) {

    iVar2 = (int)((float)*(int *)(param_1 + 0xc4) * DAT_00aaa8ec);

  }

  if (iVar2 < 1) {

    iVar2 = 1;

  }

  return iVar2;

}
