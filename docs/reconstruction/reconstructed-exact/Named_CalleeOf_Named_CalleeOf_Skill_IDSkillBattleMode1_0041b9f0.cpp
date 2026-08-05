// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1_0041b9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0041b9f0
// Callee of Named_CalleeOf_Skill_IDSkillBattleMode1
// Address:   0x0041b9f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_IDSkillBattleMode1: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CoTaskMemFree×2, FUN_0041b9f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Skill_IDSkillBattleMode1
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

void Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1_0041b9f0(void)



{

  int unaff_ESI;

  

  CoTaskMemFree(*(LPVOID *)(unaff_ESI + 0x14));

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  CoTaskMemFree(*(LPVOID *)(unaff_ESI + 0x18));

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

  operator_delete__(*(void **)(unaff_ESI + 8));

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  operator_delete__(*(void **)(unaff_ESI + 0x10));

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  return;

}
