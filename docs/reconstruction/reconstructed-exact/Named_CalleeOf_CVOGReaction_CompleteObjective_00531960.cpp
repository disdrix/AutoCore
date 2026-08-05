// =============================================================================
// Named_CalleeOf_CVOGReaction_CompleteObjective_00531960
// -----------------------------------------------------------------------------
// Stable ID: aa_00531960
// Callee of CVOGReaction_CompleteObjective
// Address:   0x00531960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_CompleteObjective: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: Client_SendLogicUiPacket, FUN_00531960.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_CompleteObjective
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

void __thiscall Named_CalleeOf_CVOGReaction_CompleteObjective_00531960(int param_1,short param_2)



{

  int iVar1;

  uint8_t local_138 [28];

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  

  if (0 < param_2) {

    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

    local_118 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_1);

    local_114 = *(uint32_t /* width from decompiler */ *)(iVar1 + param_1 + 0x168);

    local_11c = 0x22;

    Client_SendLogicUiPacket(local_138);

  }

  *(short *)(param_1 + 0x580) = *(short *)(param_1 + 0x580) + param_2;

  *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 1;

  return;

}
