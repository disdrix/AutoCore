// =============================================================================
// FUN_00752a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00752a30
// Address:   0x00752a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752a30 @ 0x00752a30
// Stable ID: aa_00752a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00752a30.
//  - Return sites: 3.

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

int FUN_00752a30(int param_1,int param_2)



{

  int iVar1;

  

  if (param_2 < 0) {

    return -1;

  }

  iVar1 = *(int *)(param_1 + 8);

  if (*(int *)(iVar1 + 0xc) != 0) {

    iVar1 = (**(code **)(**(int **)(iVar1 + 0xc) + 0x10))

                      (*(int **)(iVar1 + 0xc),*(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x10) + param_2 * 8))

    ;

    return (-1 < iVar1) - 1;

  }

  return -1;

}
