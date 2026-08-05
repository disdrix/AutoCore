// =============================================================================
// Named_CalleeOf_CVOGSectorMap_LoadMapFile_0079d290
// -----------------------------------------------------------------------------
// Stable ID: aa_0079d290
// Callee of CVOGSectorMap_LoadMapFile (+1 other named callers)
// Address:   0x0079d290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSectorMap_LoadMapFile: config/load helper. Evidence string: "{ begin : ". Supports parent flow (not a free-standing entry point). CVOGSectorMap_LoadMapFile (+1 other named callers).
// Embedded strings (evidence):
//   - "(unlabeled)"
//   - "{ begin : "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00426c70, FUN_00793a10, FUN_00793aa0, FUN_0079d290.
//  - Strings: "(unlabeled)"; "{ begin : ".
//  - Return sites: 1.

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

int __thiscall Named_CalleeOf_CVOGSectorMap_LoadMapFile_0079d290(int *param_1,int param_2,char *param_3)



{

  char *pcVar1;

  uint8_t local_64 [100];

  

  if ((char)param_1[2] == '\0') {

    if (*(char *)((int)param_1 + 5) == '\0') {

      (**(code **)(*param_1 + 8))(&param_2,4);

    }

    else {

      (**(code **)(*param_1 + 4))();

    }

  }

  else {

    pcVar1 = param_3;

    if (param_3 == (char *)0x0) {

      pcVar1 = "(unlabeled)";

    }

    FUN_00793aa0(param_1 + param_1[0x1a3] * 0x19 + 0x13,pcVar1,100);

    FUN_00793a10(local_64,"{ begin : ",pcVar1,100);

    FUN_00426c70(local_64,&param_2);

  }

  param_1[param_1[0x1a3] + 3] = param_2;

  param_1[0x1a3] = param_1[0x1a3] + 1;

  return param_2;

}
