// =============================================================================
// FUN_007166a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007166a0
// Address:   0x007166a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007166a0 @ 0x007166a0
// Stable ID: aa_007166a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_007166a0.
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

uint32_t /* width from decompiler */ FUN_007166a0(int *param_1)



{

  int iVar1;

  

  if (param_1 == (int *)0x0) {

    return 1;

  }

  *param_1 = 0;

  iVar1 = (*(code *)PTR_calloc_00af8a48)(1,0xc);

  if (iVar1 == 0) {

    return 1;

  }

  *param_1 = iVar1;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = 0x40a00000;

  return 0;

}
