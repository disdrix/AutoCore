// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_005d3ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d3ef0
// Callee of Named_CalleeOf_Named_SkyBoxParticles (+1 other named callers)
// Address:   0x005d3ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_SkyBoxParticles (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00507260, FUN_005d3ef0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SkyBoxParticles (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_005d3ef0(int param_1,int param_2)



{

  float fVar1;

  int iVar2;

  uint8_t uVar3;

  float fVar4;

  

  FUN_00507260(param_2);

  iVar2 = *(int *)(param_1 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb0);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb8);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xbc);

  iVar2 = *(int *)(param_1 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x30) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x30);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x34) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x38) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x38);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x3c);

  iVar2 = *(int *)(param_1 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x40) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x40);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x48) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x48);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x4c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x4c);

  iVar2 = *(int *)(param_1 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x50) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x50);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x54) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x54);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x58) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x58);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x5c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x5c);

  uVar3 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x18))();

  *(uint8_t *)(param_2 + 0xb4) = uVar3;

  (**(code **)(**(int **)(param_1 + 0x3c) + 0x24))(param_2 + 0x60);

  fVar1 = *(float *)(*(int *)(param_1 + 0x3c) + 0x2c);

  fVar4 = 0.0;

  if (fVar1 != 0.0) {

    fVar4 = g_flOne / fVar1;

  }

  *(float *)(param_2 + 0xa0) = fVar4;

  iVar2 = *(int *)(param_1 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x90) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x20);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x94) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x98) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x28);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x9c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x2c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xac) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xa4) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + 0x14);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xa8) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + 0x18);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xb0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x50);

  if (*(int **)(param_1 + 0x54) != (int *)0x0) {

    uVar3 = (**(code **)(**(int **)(param_1 + 0x54) + 0x1c))();

    *(uint8_t *)(param_2 + 0xb5) = uVar3;

    return;

  }

  *(uint8_t *)(param_2 + 0xb5) = 1;

  return;

}
