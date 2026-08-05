// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_Load_00793d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00793d20
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile
// Address:   0x00793d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00793d20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile
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

uint __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_Load_00793d20(char *param_1,char *param_2)



{

  char cVar1;

  

  cVar1 = *param_1;

  if (cVar1 == *param_2) {

    do {

      if (cVar1 == '\0') break;

      cVar1 = param_1[1];

      param_1 = param_1 + 1;

      param_2 = param_2 + 1;

    } while (cVar1 == *param_2);

  }

  if (*param_1 < *param_2) {

    return 0xffffffff;

  }

  return (uint)(*param_2 < *param_1);

}
