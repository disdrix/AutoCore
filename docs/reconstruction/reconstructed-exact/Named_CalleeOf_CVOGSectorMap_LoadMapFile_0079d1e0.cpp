// =============================================================================
// Named_CalleeOf_CVOGSectorMap_LoadMapFile_0079d1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079d1e0
// Callee of CVOGSectorMap_LoadMapFile (+1 other named callers)
// Address:   0x0079d1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSectorMap_LoadMapFile: config/load helper. Evidence string: "} end : ". Supports parent flow (not a free-standing entry point). CVOGSectorMap_LoadMapFile (+1 other named callers).
// Embedded strings (evidence):
//   - "} end : "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_00793a10×2, FUN_0079d1e0.
//  - Strings: "} end : ".
//  - Return sites: 2.

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

int __fastcall Named_CalleeOf_CVOGSectorMap_LoadMapFile_0079d1e0(int *param_1)



{

  int *piVar1;

  char *pcVar2;

  char local_64;

  char local_63 [99];

  

  if ((char)param_1[2] != '\0') {

    FUN_00793a10(&local_64,"} end : ",param_1 + param_1[0x1a3] * 0x19 + -6,100);

    FUN_00793a10(&local_64,&local_64,&DAT_00a97b84,100);

    if (1 < (uint)param_1[0x1a3]) {

      (**(code **)(*param_1 + 8))(PTR_s__00afa264,param_1[0x1a3] * 4 + -4);

    }

    pcVar2 = &local_64;

    while (local_64 != '\0') {

      pcVar2 = pcVar2 + 1;

      local_64 = *pcVar2;

    }

    (**(code **)(*param_1 + 8))(&local_64,(int)pcVar2 - (int)&local_64);

  }

  piVar1 = param_1 + 0x1a3;

  *piVar1 = *piVar1 + -1;

  if (*piVar1 != 0) {

    return param_1[param_1[0x1a3] + 2];

  }

  return 0;

}
