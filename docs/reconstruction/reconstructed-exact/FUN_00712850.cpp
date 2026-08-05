// =============================================================================
// FUN_00712850
// -----------------------------------------------------------------------------
// Stable ID: aa_00712850
// Address:   0x00712850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00712850 @ 0x00712850
// Stable ID: aa_00712850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_00712850.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ FUN_00712850(int *param_1)



{

  int *piVar1;

  int iVar2;

  

  if (param_1 == (int *)0x0) {

    return 1;

  }

  *param_1 = 0;

  piVar1 = (int *)(*(code *)PTR_calloc_00af8a48)(1,0xc);

  if (piVar1 == (int *)0x0) {

    return 1;

  }

  *param_1 = (int)piVar1;

  iVar2 = (*(code *)PTR_calloc_00af8a48)(0x21,4);

  *piVar1 = iVar2;

  if (iVar2 == 0) {

    return 1;

  }

  piVar1[1] = 0;

  *(uint16_t *)(piVar1 + 2) = 0;

  return 0;

}
