// =============================================================================
// Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00508b10
// Callee of Skill_GetModifierSkillID_passed_an_invalid_IDPrefix_i
// Address:   0x00508b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_GetModifierSkillID_passed_an_invalid_IDPre: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00508b10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Skill_GetModifierSkillID_passed_an_invalid_IDPrefix_i
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

int __thiscall Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508b10(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  if ((param_2 != -1) && (0 < DAT_00d02978)) {

    piVar2 = *(int **)(param_1 + 0x48);

    do {

      if (*(int *)(*piVar2 + 0x6c) == param_2) {

        return (*(int **)(param_1 + 0x48))[iVar1];

      }

      iVar1 = iVar1 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar1 < DAT_00d02978);

  }

  return 0;

}
