// =============================================================================
// FUN_006324a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006324a0
// Address:   0x006324a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006324a0 @ 0x006324a0
// Stable ID: aa_006324a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_006324a0.
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

int __thiscall FUN_006324a0(int param_1,int param_2)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0xc) == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))();

  }

  if (param_2 < iVar1) {

                    /* WARNING: Could not recover jumptable at 0x006324c9. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))();

    return iVar1;

  }

  return (param_2 - iVar1) * 0x10 + *(int *)(param_1 + 0x20);

}
