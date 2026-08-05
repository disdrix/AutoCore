// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00787730
// -----------------------------------------------------------------------------
// Stable ID: aa_00787730
// Callee of Named_CalleeOf_CVOGSectorMap_LoadMapFile
// Address:   0x00787730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00405000×2, FUN_00404fa0, FUN_00787530, FUN_00787730, FUN_0079cb60, fopen.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGSectorMap_LoadMapFile
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

uint8_t Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00787730(char *param_1)



{

  uint8_t uVar1;

  int local_6a8;

  uint8_t uStack_6a4;

  uint8_t uStack_6a2;

  FILE *pFStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac2d8;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00404fa0();

  local_4 = 0;

  (**(code **)(local_6a8 + 0x10))();

  pFStack_14 = fopen(param_1,"wb");

  if (pFStack_14 != (FILE *)0x0) {

    uStack_6a2 = 1;

    uStack_6a4 = 1;

    uVar1 = FUN_00787530(&local_6a8);

    FUN_0079cb60();

    local_4 = 0xffffffff;

    FUN_00405000();

    ExceptionList = pvStack_c;

    return uVar1;

  }

  local_4 = 0xffffffff;

  FUN_00405000();

  ExceptionList = pvStack_c;

  return 0;

}
