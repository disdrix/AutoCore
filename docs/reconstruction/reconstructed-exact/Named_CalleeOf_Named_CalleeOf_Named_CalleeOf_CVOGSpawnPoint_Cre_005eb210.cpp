// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_005eb210
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb210
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature
// Address:   0x005eb210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00581190, FUN_005eb040, FUN_005eb210.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Cre_005eb210(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  

  FUN_00581190(param_2[1],2);

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0x80000000;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0x80000000;

  param_1[0xb] = param_1;

  *param_1 = &PTR_FUN_009dcde0;

  param_1[0x1b] = 0;

  param_1[0x1a] = 0;

  param_1[0x19] = 0;

  param_1[0x18] = 0;

  param_1[0x1f] = 0;

  param_1[0x1e] = 0;

  param_1[0x1d] = 0;

  param_1[0x1c] = 0;

  uVar1 = DAT_009dcddc;

  param_1[0x1b] = DAT_009dcddc;

  param_1[0x1f] = uVar1;

  param_1[10] = *param_2;

  param_1[5] = param_1 + 0x18;

  uVar1 = (**(code **)(*(int *)param_1[3] + 0x14))();

  param_1[0x15] = uVar1;

  FUN_005eb040(param_2 + 8);

  return param_1;

}
