// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature_005eb130
// -----------------------------------------------------------------------------
// Stable ID: aa_005eb130
// Callee of Named_CalleeOf_CVOGSpawnPoint_CreateCreature
// Address:   0x005eb130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSpawnPoint_CreateCreature: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005eb130, FUN_00634450.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGSpawnPoint_CreateCreature
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature_005eb130(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint8_t auStack_3c [12];

  uint8_t local_30 [44];

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = *param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = param_2[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = param_2[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = param_2[3];

  (**(code **)(**(int **)(param_1 + 0xc) + 0x18))

            (param_1 + 0x80,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 8) + 0xcc) + 8),local_30);

  FUN_00634450(auStack_3c);

  return;

}
