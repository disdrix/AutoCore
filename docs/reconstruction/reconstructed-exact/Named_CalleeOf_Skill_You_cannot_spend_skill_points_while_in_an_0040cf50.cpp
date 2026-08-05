// =============================================================================
// Named_CalleeOf_Skill_You_cannot_spend_skill_points_while_in_an_0040cf50
// -----------------------------------------------------------------------------
// Stable ID: aa_0040cf50
// Callee of Skill_You_cannot_spend_skill_points_while_in_an_arena
// Address:   0x0040cf50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_You_cannot_spend_skill_points_while_in_an: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0040cf50.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Skill_You_cannot_spend_skill_points_while_in_an_arena
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

uint32_t /* width from decompiler */ Named_CalleeOf_Skill_You_cannot_spend_skill_points_while_in_an_0040cf50(void)



{

  int in_EAX;

  

  if (((*(char *)(in_EAX + 4) == '\0') && (*(char *)(in_EAX + 6) == '\0')) &&

     (*(char *)(in_EAX + 5) == '\0')) {

    return 0;

  }

  return 1;

}
