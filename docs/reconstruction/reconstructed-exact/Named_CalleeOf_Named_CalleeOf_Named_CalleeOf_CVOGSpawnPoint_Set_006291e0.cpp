// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set_006291e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006291e0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta
// Address:   0x006291e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_006291e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set_006291e0(int *param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  *(int **)(param_2 + 0x44) = param_1;

  if (param_1[0x10] == (param_1[0x11] & 0x7fffffffU)) {

    FUN_005b3370(param_1 + 0xf,4);

  }

  *(int *)(param_1[0xf] + param_1[0x10] * 4) = param_2;

  param_1[0x10] = param_1[0x10] + 1;

  *(int *)(param_2 + 0x58) = param_1[0x10] + -1;

  iVar1 = *param_1;

  uVar2 = (**(code **)(**(int **)(param_2 + 0x3c) + 0x14))();

  (**(code **)(iVar1 + 0x10))(uVar2);

  return;

}
