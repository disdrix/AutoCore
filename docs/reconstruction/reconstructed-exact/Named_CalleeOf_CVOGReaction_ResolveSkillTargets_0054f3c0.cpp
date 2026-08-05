// =============================================================================
// Named_CalleeOf_CVOGReaction_ResolveSkillTargets_0054f3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0054f3c0
// Callee of CVOGReaction_ResolveSkillTargets
// Address:   0x0054f3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_ResolveSkillTargets: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_0054f3c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_ResolveSkillTargets
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

int __fastcall Named_CalleeOf_CVOGReaction_ResolveSkillTargets_0054f3c0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5f0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 400) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x194) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x198) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x19c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a0) = 0;

  *(uint8_t *)(param_1 + 0x1a4) = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x1a5);

  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(uint8_t *)puVar2 = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5a6);

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(uint8_t *)puVar2 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x170) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = 0;

  *(uint8_t *)(param_1 + 0x61c) = 0;

  return param_1;

}
