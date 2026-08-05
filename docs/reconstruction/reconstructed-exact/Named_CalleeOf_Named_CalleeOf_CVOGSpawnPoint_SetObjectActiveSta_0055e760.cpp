// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0055e760
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e760
// Callee of Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState
// Address:   0x0055e760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveState: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_006291e0×3, FUN_005b3370×2, FUN_006295f0×2, FUN_0055e760.
//  - Return sites: 3.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta_0055e760(int param_1,int param_2)



{

  int iVar1;

  

  *(int *)(param_2 + 8) = param_1;

  if (*(char *)(param_2 + 0x40) != '\0') {

    FUN_006291e0(param_2);

    return;

  }

  if (*(char *)(param_1 + 0x23c) != '\0') {

    iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xa8,0x2d);

    *(uint16_t *)(iVar1 + 4) = 0xa8;

    iVar1 = FUN_006295f0(param_1);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

    FUN_006291e0(param_2);

    if (*(uint *)(param_1 + 0xc) == (*(uint *)(param_1 + 0x10) & 0x7fffffff)) {

      FUN_005b3370((int *)(param_1 + 8),4);

    }

    *(int *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 4) = iVar1;

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

    return;

  }

  if (*(int *)(param_1 + 0xc) == 0) {

    iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xa8,0x2d);

    *(uint16_t *)(iVar1 + 4) = 0xa8;

    iVar1 = FUN_006295f0(param_1);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

    if (*(uint *)(param_1 + 0xc) == (*(uint *)(param_1 + 0x10) & 0x7fffffff)) {

      FUN_005b3370((int *)(param_1 + 8),4);

    }

    *(int *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 4) = iVar1;

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

  }

  FUN_006291e0(param_2);

  return;

}
