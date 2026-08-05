// =============================================================================
// Named_CalleeOf_Named_generator_00680cf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00680cf0
// Callee of Named_generator (+3 other named callers)
// Address:   0x00680cf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_generator: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_generator (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: for×4, return×3, if×2.
//  - Notable callees: FUN_00680cf0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_generator (+3 other named callers)
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

uint __thiscall Named_CalleeOf_Named_generator_00680cf0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  uVar4 = *(uint *)(param_1 + 0x10);

  uVar1 = *(uint *)(param_1 + 0xc);

  if (uVar4 == 0) {

    *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    return uVar1;

  }

  if (uVar1 < uVar4) {

    puVar5 = (uint32_t /* width from decompiler */ *)((int)*(uint32_t /* width from decompiler */ **)(param_1 + 4) + uVar4);

    puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

    for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar6 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    }

    for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

    }

    *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

    return uVar1;

  }

  puVar2 = operator_new__(uVar1);

  puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0x10));

  puVar6 = puVar2;

  for (uVar4 = uVar1 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  for (uVar4 = uVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

    puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

  }

  *param_2 = puVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  return uVar1;

}
