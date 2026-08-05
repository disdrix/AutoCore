// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00
// -----------------------------------------------------------------------------
// Stable ID: aa_004bae00
// Callee of Named_CalleeOf_CVOGSectorMap_LoadMapFile (+1 other named callers)
// Address:   0x004bae00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGSectorMap_LoadMapFile (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00402c40×2, FUN_004bc530×2, FUN_004bae00.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00(int param_1,char param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (param_2 == '\0') {

    if ((*(char *)(param_1 + 0xd) != '\0') && (*(int *)(param_1 + 8) != 0)) {

      FUN_00402c40();

      uVar1 = FUN_004bc530(param_3);

      *(uint8_t *)(*(int *)(param_1 + 8) + 0x1d) = 0;

      return uVar1;

    }

  }

  else if ((*(char *)(param_1 + 0xc) != '\0') && (*(int *)(param_1 + 4) != 0)) {

    FUN_00402c40();

    uVar1 = FUN_004bc530(param_3);

    *(uint8_t *)(*(int *)(param_1 + 4) + 0x1d) = 0;

    return uVar1;

  }

  return 0;

}
