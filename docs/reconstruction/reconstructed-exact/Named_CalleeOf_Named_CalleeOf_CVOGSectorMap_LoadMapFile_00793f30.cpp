// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00793f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00793f30
// Callee of Named_CalleeOf_CVOGSectorMap_LoadMapFile
// Address:   0x00793f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: for×2, return×2, if×1, while×1.
//  - Notable callees: CONCAT31, FUN_00793db0, FUN_00793f30.
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

uint32_t /* width from decompiler */

Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_00793f30(uint8_t *param_1,char *param_2,uint8_t *param_3,char *param_4,int param_5)



{

  char cVar1;

  int iVar2;

  uint8_t *puVar3;

  char *pcVar4;

  

  iVar2 = FUN_00793db0(param_3);

  if (iVar2 != -1) {

    puVar3 = param_3 + iVar2;

    for (iVar2 = param_5; (param_3 < puVar3 && (1 < iVar2)); iVar2 = iVar2 + -1) {

      *param_1 = *param_3;

      param_3 = param_3 + 1;

      param_1 = param_1 + 1;

    }

    *param_1 = 0;

    cVar1 = *param_4;

    pcVar4 = param_4;

    while (cVar1 != '\0') {

      pcVar4 = pcVar4 + 1;

      cVar1 = *pcVar4;

    }

    pcVar4 = puVar3 + ((int)pcVar4 - (int)param_4);

    cVar1 = *pcVar4;

    for (; (cVar1 != '\0' && (1 < param_5)); param_5 = param_5 + -1) {

      pcVar4 = pcVar4 + 1;

      *param_2 = cVar1;

      cVar1 = *pcVar4;

      param_2 = param_2 + 1;

    }

    *param_2 = '\0';

    return CONCAT31((int3)((uint)pcVar4 >> 8),1);

  }

  return 0xffffff00;

}
