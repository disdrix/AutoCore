// =============================================================================
// Named_CalleeOf_CVOGTerrain_LoadTintMap_007b7250
// -----------------------------------------------------------------------------
// Stable ID: aa_007b7250
// Callee of CVOGTerrain_LoadTintMap (+2 other named callers)
// Address:   0x007b7250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTerrain_LoadTintMap: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGTerrain_LoadTintMap (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00423b40, FUN_00745ea0, FUN_007b7250, FUN_00989e00, NDResourceCache_LookupOrCreate, NDResource_AcquireInnerObject.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGTerrain_LoadTintMap (+2 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_CVOGTerrain_LoadTintMap_007b7250(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int *piVar2;

  

  FUN_00989e00(&param_1,param_1);

  uVar1 = FUN_00423b40();

  piVar2 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,&param_1,uVar1,0,0);

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 4))();

    uVar1 = NDResource_AcquireInnerObject();

    FUN_00745ea0();

    return uVar1;

  }

  return 0;

}
