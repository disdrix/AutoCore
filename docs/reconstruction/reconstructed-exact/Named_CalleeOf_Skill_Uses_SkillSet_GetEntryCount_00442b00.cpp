// =============================================================================
// Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_00442b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00442b00
// Callee of Skill_Uses_SkillSet_GetEntryCount
// Address:   0x00442b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Uses_SkillSet_GetEntryCount: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_00442b00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Uses_SkillSet_GetEntryCount
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

void __fastcall Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_00442b00(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  for (; param_1 != param_2; param_1 = param_1 + 6) {

    if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

      *in_EAX = *param_1;

      in_EAX[1] = param_1[1];

      in_EAX[2] = param_1[2];

      in_EAX[3] = param_1[3];

      in_EAX[4] = param_1[4];

      in_EAX[5] = param_1[5];

    }

    in_EAX = in_EAX + 6;

  }

  return;

}
