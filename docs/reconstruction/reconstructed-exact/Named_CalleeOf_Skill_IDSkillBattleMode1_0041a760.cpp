// =============================================================================
// Named_CalleeOf_Skill_IDSkillBattleMode1_0041a760
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a760
// Callee of Skill_IDSkillBattleMode1
// Address:   0x0041a760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_IDSkillBattleMode1: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0041a760, FUN_0041bef0, FUN_00422040.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Skill_IDSkillBattleMode1
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

void __fastcall Named_CalleeOf_Skill_IDSkillBattleMode1_0041a760(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ in_EAX;

  int local_4;

  

  iVar1 = *(int *)(param_1 + 4);

  local_4 = param_1;

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x38) <

      (uint)((*(int *)(param_1 + 0xc) - iVar1) / 0x38))) {

    iVar1 = *(int *)(param_1 + 8);

    FUN_00422040(param_1);

    *(int *)(param_1 + 8) = iVar1 + 0x38;

    return;

  }

  FUN_0041bef0(&local_4,*(uint32_t /* width from decompiler */ *)(param_1 + 8),in_EAX);

  return;

}
