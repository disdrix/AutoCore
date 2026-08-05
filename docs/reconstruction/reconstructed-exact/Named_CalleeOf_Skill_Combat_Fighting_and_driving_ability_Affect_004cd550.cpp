// =============================================================================
// Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_004cd550
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd550
// Callee of Skill_Combat_Fighting_and_driving_ability_Affects_Weap
// Address:   0x004cd550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Combat_Fighting_and_driving_ability_Affect: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004cd550.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Combat_Fighting_and_driving_ability_Affects_Weap
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_004cd550(float param_1)



{

  return (float10)param_1 * (float10)_DAT_009cc1c8 + (float10)_DAT_009cc1c0;

}
