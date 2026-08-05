// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_00581330
// -----------------------------------------------------------------------------
// Stable ID: aa_00581330
// Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x00581330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_00518940, FUN_00581330.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
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

int __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_00581330(int param_1,int param_2)



{

  uint *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (param_2 != 0) {

    *(undefined **)(param_1 + 4) = &DAT_009d45e4;

    FUN_00518940();

  }

  *(uint8_t *)(param_1 + 0xe) = 3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint8_t *)(param_1 + 0xd) = 0;

  *(uint8_t *)(param_1 + 0xf) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0xffffffff;

  puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x180 + param_1);

  *puVar1 = *puVar1 | 0x40;

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  return param_1;

}
