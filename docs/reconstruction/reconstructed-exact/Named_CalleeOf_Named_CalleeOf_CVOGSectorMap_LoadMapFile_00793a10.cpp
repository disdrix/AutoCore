// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00793a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00793a10
// Callee of Named_CalleeOf_CVOGSectorMap_LoadMapFile (+1 other named callers)
// Address:   0x00793a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGSectorMap_LoadMapFile (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_00793a10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGSectorMap_LoadMapFile (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00793a10(char *param_1,char *param_2,char *param_3,int param_4)



{

  char *pcVar1;

  char cVar2;

  

  pcVar1 = param_1 + param_4 + -1;

  cVar2 = *param_2;

  for (; (cVar2 != '\0' && (param_1 < pcVar1)); param_1 = param_1 + 1) {

    param_2 = param_2 + 1;

    *param_1 = cVar2;

    cVar2 = *param_2;

  }

  cVar2 = *param_3;

  for (; (cVar2 != '\0' && (param_1 < pcVar1)); param_1 = param_1 + 1) {

    param_3 = param_3 + 1;

    *param_1 = cVar2;

    cVar2 = *param_3;

  }

  *param_1 = '\0';

  return;

}
