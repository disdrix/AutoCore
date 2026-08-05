// =============================================================================
// Named_CalleeOf_Named_VOGGraphicsBase_0096f840
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f840
// Callee of Named_VOGGraphicsBase (+1 other named callers)
// Address:   0x0096f840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGGraphicsBase: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOGGraphicsBase (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00752370, FUN_00753060, FUN_0096f840.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOGGraphicsBase (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOGGraphicsBase_0096f840(int *param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*param_1 == 0) {

    param_2 = -1;

    piVar1 = &param_2;

  }

  else {

    piVar1 = (int *)FUN_00752370(&param_2,param_2);

  }

  if (-1 < *piVar1) {

    uVar2 = FUN_00753060(*piVar1);

    return uVar2;

  }

  return 0xffffffff;

}
