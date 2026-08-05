// =============================================================================
// Named_CalleeOf_Skill_ApplyStatusEffectLocal_0051b720
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b720
// Callee of Skill_ApplyStatusEffectLocal
// Address:   0x0051b720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_ApplyStatusEffectLocal: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_0051b720.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_ApplyStatusEffectLocal
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

void __thiscall Named_CalleeOf_Skill_ApplyStatusEffectLocal_0051b720(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (0xfffff < *(int *)(param_1 + 0xc) + param_2) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc) * 2);

  for (uVar1 = (uint)(param_2 * 2) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

    *param_3 = *puVar2;

    puVar2 = puVar2 + 1;

    param_3 = param_3 + 1;

  }

  for (uVar1 = param_2 * 2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

    *(uint8_t *)param_3 = *(uint8_t *)puVar2;

    puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

    param_3 = (uint32_t /* width from decompiler */ *)((int)param_3 + 1);

  }

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

  return;

}
