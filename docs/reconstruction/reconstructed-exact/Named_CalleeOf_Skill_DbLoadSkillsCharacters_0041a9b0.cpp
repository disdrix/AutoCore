// =============================================================================
// Named_CalleeOf_Skill_DbLoadSkillsCharacters_0041a9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a9b0
// Callee of Skill_DbLoadSkillsCharacters (+1 other named callers)
// Address:   0x0041a9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_DbLoadSkillsCharacters: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Skill_DbLoadSkillsCharacters (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0041a9b0, FUN_0041c000.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_DbLoadSkillsCharacters (+1 other named callers)
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

void Named_CalleeOf_Skill_DbLoadSkillsCharacters_0041a9b0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  if (unaff_EDI[3] != 0) {

    (**(code **)(*(int *)*unaff_EDI + 0x18))((int *)*unaff_EDI,1,unaff_EDI + 3,0,0,0);

    unaff_EDI[3] = 0;

  }

  iVar1 = (**(code **)(*(int *)*unaff_EDI + 0x1c))((int *)*unaff_EDI,0);

  if (-1 < iVar1) {

    FUN_0041c000(0,1);

  }

  return;

}
