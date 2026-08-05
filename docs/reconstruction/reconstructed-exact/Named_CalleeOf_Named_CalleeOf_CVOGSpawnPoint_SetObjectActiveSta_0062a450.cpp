// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0062a450
// -----------------------------------------------------------------------------
// Stable ID: aa_0062a450
// Callee of Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState
// Address:   0x0062a450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_005fff20, FUN_0062a450.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState
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

void Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0062a450(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = *(int *)(param_1 + 0x4c);

  while (iVar1 = iVar1 + -1, -1 < iVar1) {

    piVar2 = *(int **)(*(int *)(param_1 + 0x48) + iVar1 * 4);

    if (piVar2 != (int *)0x0) {

      (**(code **)(*piVar2 + 0xc))(param_2);

    }

  }

  FUN_005fff20();

  return;

}
