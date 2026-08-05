// =============================================================================
// FUN_0073f7b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073f7b0
// Address:   0x0073f7b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073f7b0 @ 0x0073f7b0
// Stable ID: aa_0073f7b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_0073f7b0.
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

int FUN_0073f7b0(int *param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int unaff_EDI;

  

  uVar3 = 0;

  iVar2 = 0;

  while( true ) {

    if ((*(int *)(unaff_EDI + 0x28) == 0) ||

       ((uint)((*(int *)(unaff_EDI + 0x2c) - *(int *)(unaff_EDI + 0x28)) / 0x1c) <= uVar3)) {

      return -1;

    }

    iVar1 = *(int *)(unaff_EDI + 0x28) + iVar2;

    if ((*param_1 == *(int *)(iVar1 + 4)) && (*param_2 == *(int *)(iVar1 + 8))) break;

    uVar3 = uVar3 + 1;

    iVar2 = iVar2 + 0x1c;

  }

  return uVar3 + 1;

}
