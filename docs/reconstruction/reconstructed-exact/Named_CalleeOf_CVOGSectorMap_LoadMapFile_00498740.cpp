// =============================================================================
// Named_CalleeOf_CVOGSectorMap_LoadMapFile_00498740
// -----------------------------------------------------------------------------
// Stable ID: aa_00498740
// Callee of CVOGSectorMap_LoadMapFile (+1 other named callers)
// Address:   0x00498740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGSectorMap_LoadMapFile (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_00498740, FUN_00793710, FUN_00793830, FUN_0079cd10, FUN_0079cd30.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of CVOGSectorMap_LoadMapFile (+1 other named callers)
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

bool __thiscall Named_CalleeOf_CVOGSectorMap_LoadMapFile_00498740(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint8_t local_c [12];

  

  if (*(char *)((int)param_1 + 5) != '\0') {

    if ((char)param_1[2] == '\0') {

      (**(code **)(*param_1 + 4))(param_3,4);

      return true;

    }

    FUN_0079cd10(param_2,local_c,0xc);

    uVar1 = FUN_00793830(local_c);

    *param_3 = uVar1;

    return true;

  }

  if (*(char *)((int)param_1 + 6) == '\0') {

    return false;

  }

  if ((char)param_1[2] == '\0') {

    (**(code **)(*param_1 + 8))(param_3,4);

    return true;

  }

  FUN_00793710(local_c,*param_3,0xc);

  iVar2 = FUN_0079cd30(param_2,local_c);

  return iVar2 != 0;

}
