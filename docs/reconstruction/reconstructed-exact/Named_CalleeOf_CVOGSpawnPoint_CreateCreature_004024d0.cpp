// =============================================================================
// Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004024d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004024d0
// Callee of CVOGSpawnPoint_CreateCreature (+1 other named callers)
// Address:   0x004024d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSpawnPoint_CreateCreature: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGSpawnPoint_CreateCreature (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: EnterCriticalSection×2, FUN_00402598×2, FUN_004024d0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of CVOGSpawnPoint_CreateCreature (+1 other named callers)
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

uint __thiscall Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004024d0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  void *local_10;

  uint8_t *puStack_c;

  uint local_8;

  

  puStack_c = &LAB_009bc1ab;

  local_10 = ExceptionList;

  if (param_2 == 0) {

    return (uint)ExceptionList & 0xffffff00;

  }

  local_8 = 0;

  ExceptionList = &local_10;

  puVar1 = operator_new(0xc);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar1 = &PTR_FUN_009cb340;

    puVar1[2] = 0;

    puVar1[1] = 0;

  }

  local_8 = local_8 & 0xffffff00;

  puVar1[1] = param_2;

  if (*(int *)(param_1 + 0xc) < 4) {

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));

  }

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));

  if (*(int *)(param_1 + 8) == 0) {

    *(uint32_t /* width from decompiler */ **)(param_1 + 4) = puVar1;

    *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar1;

    uVar2 = FUN_00402598();

    return uVar2;

  }

  *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 8) + 8) = puVar1;

  *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar1;

  uVar2 = FUN_00402598();

  return uVar2;

}
