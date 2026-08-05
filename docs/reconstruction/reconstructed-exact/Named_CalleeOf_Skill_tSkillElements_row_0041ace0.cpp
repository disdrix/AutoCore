// =============================================================================
// Named_CalleeOf_Skill_tSkillElements_row_0041ace0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041ace0
// Callee of Skill_tSkillElements_row (+1 other named callers)
// Address:   0x0041ace0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_tSkillElements_row: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Skill_tSkillElements_row (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00416ff0, FUN_0041ace0, FUN_00429310.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Skill_tSkillElements_row (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Skill_tSkillElements_row_0041ace0(int param_1,uint param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (param_3 == 0) {

    return 0x80004003;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_00416ff0();

  puVar2[2] = param_3;

  puVar2[3] = 0;

  *puVar2 = &PTR_FUN_00a86174;

  puVar2[5] = 0;

  puVar2[6] = 0;

  *(uint8_t *)(puVar2 + 1) = 0;

  puVar2[4] = param_2;

  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4);

  puVar2[3] = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

  *(uint32_t /* width from decompiler */ **)(iVar1 + 4) = puVar2;

  FUN_00429310();

  if (*(int *)(param_1 + 0x18) != 0) {

    *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x18) + 0x14) = puVar2;

    puVar2[5] = 0;

    puVar2[6] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar2;

    return 0;

  }

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar2;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x14) = puVar2;

  puVar2[6] = 0;

  puVar2[5] = 0;

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

  return 0;

}
