// =============================================================================
// Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_004ca910
// -----------------------------------------------------------------------------
// Stable ID: aa_004ca910
// Callee of Skill_Skill_d_had_invalid_creature_d (+1 other named callers)
// Address:   0x004ca910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_d_had_invalid_creature_d: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Skill_Skill_d_had_invalid_creature_d (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004bb070, FUN_004ca730, FUN_004ca910, FUN_00512460, Object_GetRootRaceId.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_d_had_invalid_creature_d (+1 other named callers)
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

void __thiscall Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_004ca910(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int iVar2;

  RACE_ID_INFERRED RVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x228) = *param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x22c) = param_2[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x230) = param_2[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x234) = param_2[3];

  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if ((iVar2 != 0) && (*(int *)(iVar2 + 0xe4e8) != 0)) {

    iVar2 = FUN_004bb070(param_2);

    if (iVar2 != 0) {

      RVar3 = Object_GetRootRaceId((void *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2));

      FUN_00512460(RVar3);

      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);

      uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x290))(0);

      (**(code **)(iVar1 + 0x288))(uVar4);

      FUN_004ca730(*(int *)(*(int *)(param_1 + 4) + 4) + 0x164 + param_1,unaff_retaddr);

      *(bool *)(param_1 + 0x205) = (char)unaff_retaddr == '\0';

    }

  }

  return;

}
