// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0058ab60
// -----------------------------------------------------------------------------
// Stable ID: aa_0058ab60
// Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
// Address:   0x0058ab60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, FUN_0058ab60.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_VOG_DEBUG_STOP_0058ab60(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar1 = operator_new__(0x4b0);

  iVar2 = CVOGReaction_RandomUnitScalar();

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = param_1;

  iVar2 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar2 + 0xc) + 600) {

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc) = 0;

  }

  puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 8) + *(int *)(iVar2 + 0xc) * 2);

  puVar5 = puVar1;

  for (iVar3 = 300; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;

  return puVar1;

}
