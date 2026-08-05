// =============================================================================
// FUN_005244e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005244e0
// Address:   0x005244e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005244e0 @ 0x005244e0
// Stable ID: aa_005244e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_00522710, FUN_005244e0.
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

int FUN_005244e0(uint *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = 0;

  iVar3 = 0;

  do {

    if ((*param_1 & param_1[1]) != 0xffffffff) {

      iVar1 = FUN_00522710(iVar3,param_1);

      iVar2 = iVar2 + iVar1;

    }

    iVar3 = iVar3 + 1;

    param_1 = param_1 + 10;

  } while (iVar3 < 5);

  return iVar2;

}
