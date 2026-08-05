// =============================================================================
// Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_0051f880
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f880
// Callee of Skill_Skill_d_has_invalid_frequency_d
// Address:   0x0051f880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_d_has_invalid_frequency_d: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~5 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0051f880.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_d_has_invalid_frequency_d
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

void __thiscall Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_0051f880(int param_1,uint8_t param_2)



{

  *(uint8_t *)(param_1 + 0x6b8) = param_2;

  return;

}
