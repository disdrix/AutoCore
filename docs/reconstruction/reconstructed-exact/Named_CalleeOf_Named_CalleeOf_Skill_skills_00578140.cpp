// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_skills_00578140
// -----------------------------------------------------------------------------
// Stable ID: aa_00578140
// Callee of Named_CalleeOf_Skill_skills
// Address:   0x00578140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_skills: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00578140.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Skill_skills
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

float10 Named_CalleeOf_Named_CalleeOf_Skill_skills_00578140(float param_1)



{

  param_1 = param_1 * DAT_00aaa7ac;

  if (param_1 < 0.0) {

    return (float10)(int)(param_1 - g_flMissionXpRoundBias) * (float10)DAT_00a0f718;

  }

  return (float10)(int)(param_1 + g_flMissionXpRoundBias) * (float10)DAT_00a0f718;

}
