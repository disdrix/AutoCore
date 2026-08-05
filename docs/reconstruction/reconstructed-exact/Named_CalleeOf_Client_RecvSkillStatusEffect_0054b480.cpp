// =============================================================================
// Named_CalleeOf_Client_RecvSkillStatusEffect_0054b480
// -----------------------------------------------------------------------------
// Stable ID: aa_0054b480
// Callee of Client_RecvSkillStatusEffect
// Address:   0x0054b480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvSkillStatusEffect: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0054b2c0, FUN_0054b480.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RecvSkillStatusEffect
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

undefined * Named_CalleeOf_Client_RecvSkillStatusEffect_0054b480(void)



{

  if (DAT_00b04724 == '\0') {

    FUN_0054b2c0();

  }

  return &DAT_00b04734;

}
