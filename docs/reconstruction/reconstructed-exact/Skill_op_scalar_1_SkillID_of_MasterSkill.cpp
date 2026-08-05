// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005781b0, FUN_0061a370, FUN_00625f00.
//  - Strings: "op_scalar_1] (SkillID of MasterSkill)\n".
//  - Return sites: 1.

// =============================================================================
// Skill_op_scalar_1_SkillID_of_MasterSkill
// -----------------------------------------------------------------------------
// Stable ID: aa_00625f00
// Address:   0x00625f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "op_scalar_1] (SkillID of MasterSkill)
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Skill_op_scalar_1_SkillID_of_MasterSkill(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  if (*(float *)(param_1 + 0x160) != g_flZero) {

    FUN_005781b0(param_3,param_2,"op_scalar_1] (SkillID of MasterSkill)\n",1);

  }

  FUN_0061a370(param_1,param_2,param_3);

  return;

}
