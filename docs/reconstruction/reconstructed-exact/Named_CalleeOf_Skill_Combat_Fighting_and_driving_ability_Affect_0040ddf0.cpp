// =============================================================================
// Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_0040ddf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ddf0
// Callee of Skill_Combat_Fighting_and_driving_ability_Affects_Weap
// Address:   0x0040ddf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Combat_Fighting_and_driving_ability_Affect: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0040ddf0.
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

int __fastcall Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_0040ddf0(int param_1)



{

  int iVar1;

  

  iVar1 = (int)*(short *)(param_1 + 0x140);

  if (199 < *(short *)(param_1 + 0x140)) {

    iVar1 = 200;

  }

  return iVar1;

}
