// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00793830
// -----------------------------------------------------------------------------
// Stable ID: aa_00793830
// Callee of Named_CalleeOf_CVOGSectorMap_LoadMapFile (+1 other named callers)
// Address:   0x00793830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGSectorMap_LoadMapFile (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: while×2, if×2, return×1.
//  - Notable callees: FUN_00793830.
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

int Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00793830(char *param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  bool bVar4;

  

  iVar3 = 0;

  cVar1 = *param_1;

  while (pcVar2 = param_1 + 1, cVar1 == ' ') {

    param_1 = pcVar2;

    cVar1 = *pcVar2;

  }

  bVar4 = cVar1 == '-';

  if (bVar4) {

    cVar1 = *pcVar2;

    pcVar2 = param_1 + 2;

  }

  while (('/' < cVar1 && (cVar1 < ':'))) {

    iVar3 = cVar1 + -0x30 + iVar3 * 10;

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  }

  if (bVar4) {

    iVar3 = -iVar3;

  }

  return iVar3;

}
