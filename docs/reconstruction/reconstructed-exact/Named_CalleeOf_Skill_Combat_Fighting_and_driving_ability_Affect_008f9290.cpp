// =============================================================================
// Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_008f9290
// -----------------------------------------------------------------------------
// Stable ID: aa_008f9290
// Callee of Skill_Combat_Fighting_and_driving_ability_Affects_Weap
// Address:   0x008f9290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Combat_Fighting_and_driving_ability_Affect: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_008f9290.
//  - Return sites: 4.

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

void __fastcall Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect_008f9290(int param_1,int param_2)



{

  uint8_t *in_EAX;

  

  if ((0xf9 < param_2 + param_1) || ((param_2 == 200 && (param_1 == 0)))) {

    in_EAX[2] = 0xeb;

    in_EAX[1] = 0xdc;

    *in_EAX = 0x8c;

    in_EAX[3] = 0xff;

    return;

  }

  in_EAX[3] = 0xff;

  if (0 < param_1) {

    in_EAX[2] = 0;

    in_EAX[1] = 0xff;

    *in_EAX = 0;

    return;

  }

  in_EAX[2] = 0xff;

  if (param_1 < 0) {

    in_EAX[1] = 0;

    *in_EAX = 0;

    return;

  }

  in_EAX[1] = 0xff;

  *in_EAX = 0xff;

  return;

}
