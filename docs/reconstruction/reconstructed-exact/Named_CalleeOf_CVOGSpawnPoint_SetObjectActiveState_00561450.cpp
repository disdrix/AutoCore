// =============================================================================
// Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState_00561450
// -----------------------------------------------------------------------------
// Stable ID: aa_00561450
// Callee of CVOGSpawnPoint_SetObjectActiveState
// Address:   0x00561450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSpawnPoint_SetObjectActiveState: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0055fbf0, FUN_0055fd80, FUN_00561320, FUN_00561450, FUN_005b3370, FUN_005ffff0, FUN_0062a490.
//  - Return sites: 2.

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

void __thiscall Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState_00561450(int param_1,uint8_t *param_2,uint32_t /* width from decompiler */ *param_3)



{

  if (*(char *)(param_1 + 300) == '\x01') {

    if (*(uint *)(param_1 + 0xf4) == (*(uint *)(param_1 + 0xf8) & 0x7fffffff)) {

      FUN_005b3370((int *)(param_1 + 0xf0),4);

    }

    *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xf0) + *(int *)(param_1 + 0xf4) * 4) = param_3;

    *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + 1;

    *(short *)((int)param_3 + 6) = *(short *)((int)param_3 + 6) + 1;

    *param_2 = 0;

    return;

  }

  if (0 < *(int *)(param_1 + 0x24)) {

    FUN_00561320();

  }

  FUN_0055fbf0(param_3);

  FUN_0062a490(param_1,param_3);

  FUN_005ffff0(param_3);

  FUN_0055fd80(param_3);

  *(short *)((int)param_3 + 6) = *(short *)((int)param_3 + 6) + -1;

  if (*(short *)((int)param_3 + 6) == 0) {

    (**(code **)*param_3)(1);

  }

  *param_2 = 1;

  return;

}
