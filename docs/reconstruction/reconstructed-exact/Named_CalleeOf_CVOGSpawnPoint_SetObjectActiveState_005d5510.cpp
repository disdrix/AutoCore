// =============================================================================
// Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState_005d5510
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5510
// Callee of CVOGSpawnPoint_SetObjectActiveState
// Address:   0x005d5510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSpawnPoint_SetObjectActiveState: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005d5510.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGSpawnPoint_SetObjectActiveState
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

void __thiscall Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState_005d5510(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  int iVar1;

  

  if (*(char *)(param_1 + 0x50) == '\x02') {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0xffffffff;

    *(uint8_t *)(param_1 + 0x50) = 3;

    iVar1 = 0;

    *(uint8_t *)(param_1 + 0x51) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    if (param_3 != 0) {

      iVar1 = g_dwClientTickMs + param_3;

    }

    *(int *)(param_1 + 0x54) = iVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *param_2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = param_2[1];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = param_2[2];

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = param_2[3];

  }

  return;

}
