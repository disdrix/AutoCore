// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00497b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00497b70
// Callee of Named_CalleeOf_CVOGSectorMap_LoadMapFile
// Address:   0x00497b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00497b70, _eh_vector_constructor_iterator_.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00497b70(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = param_1 + 8;

  _eh_vector_constructor_iterator_(puVar2,0xd0,0x28,FUN_00498730,FUN_0056f570);

  param_1[1] = DAT_00a0f698;

  param_1[2] = DAT_00a0f720;

  *(uint8_t *)(param_1 + 3) = 0;

  *param_1 = 0;

  param_1[0x828] = 0;

  param_1[0x829] = 0;

  *(uint8_t *)((int)param_1 + 0xf) = 0;

  param_1[4] = 0;

  *(uint8_t *)((int)param_1 + 0xd) = 0xff;

  *(uint8_t *)((int)param_1 + 0xe) = 0xff;

  iVar1 = 0x28;

  do {

    *puVar2 = 0;

    puVar2 = puVar2 + 0x34;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return param_1;

}
