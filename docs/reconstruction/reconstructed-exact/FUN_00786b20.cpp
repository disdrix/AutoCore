// =============================================================================
// FUN_00786b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00786b20
// Address:   0x00786b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00786b20 @ 0x00786b20
// Stable ID: aa_00786b20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00786b20.
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

uint __thiscall FUN_00786b20(int param_1,int param_2,uint param_3)



{

  int iVar1;

  

  if ((((*(char *)(param_1 + 5) != '\0') && (*(char *)(param_1 + 6) == '\0')) && (param_2 != 0)) &&

     (param_3 != 0)) {

    iVar1 = (**(code **)(**(int **)(param_1 + 0x694) + 0x14))(param_2,param_3);

    return (iVar1 < 0) - 1 & param_3;

  }

  return 0;

}
