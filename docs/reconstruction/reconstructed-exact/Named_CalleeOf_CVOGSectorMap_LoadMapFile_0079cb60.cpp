// =============================================================================
// Named_CalleeOf_CVOGSectorMap_LoadMapFile_0079cb60
// -----------------------------------------------------------------------------
// Stable ID: aa_0079cb60
// Callee of CVOGSectorMap_LoadMapFile
// Address:   0x0079cb60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0079cb60, fclose.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGSectorMap_LoadMapFile
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_CVOGSectorMap_LoadMapFile_0079cb60(int param_1)



{

  if (*(FILE **)(param_1 + 0x694) != (FILE *)0x0) {

    if (*(char *)(param_1 + 0x698) == '\0') {

      fclose(*(FILE **)(param_1 + 0x694));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x694) = 0;

  }

  *(uint8_t *)(param_1 + 4) = 0;

  *(uint8_t *)(param_1 + 5) = 0;

  *(uint8_t *)(param_1 + 6) = 0;

  *(uint8_t *)(param_1 + 7) = 0;

  *(uint8_t *)(param_1 + 0x698) = 0;

  if (*(int **)(param_1 + 0x690) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x690) + 0x10))();

  }

  return 1;

}
