// =============================================================================
// FUN_004c3f10
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3f10
// Address:   0x004c3f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c3f10 @ 0x004c3f10
// Stable ID: aa_004c3f10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004c3f10.
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

int __thiscall FUN_004c3f10(int param_1,char param_2)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x1bc) == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(param_1 + 0x1c0) - *(int *)(param_1 + 0x1bc) >> 4;

  }

  if (param_2 == '\0') {

    if (*(int *)(param_1 + 0x1cc) == 0) {

      return iVar1;

    }

    iVar1 = iVar1 - (*(int *)(param_1 + 0x1d0) - *(int *)(param_1 + 0x1cc) >> 4);

  }

  return iVar1;

}
