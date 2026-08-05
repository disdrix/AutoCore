// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_DbLoadSkillsCharacters_00423620
// -----------------------------------------------------------------------------
// Stable ID: aa_00423620
// Callee of Named_CalleeOf_Skill_DbLoadSkillsCharacters (+1 other named callers)
// Address:   0x00423620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_DbLoadSkillsCharacters: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Skill_DbLoadSkillsCharacters (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004048e0, FUN_00423620, SysAllocString, SysFreeString, VarBstrCmp.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Skill_DbLoadSkillsCharacters (+1 other named callers)
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

bool Named_CalleeOf_Named_CalleeOf_Skill_DbLoadSkillsCharacters_00423620(uint32_t /* width from decompiler */ *param_1)



{

  OLECHAR *in_EAX;

  HRESULT HVar1;

  BSTR bstrRight;

  

  if (in_EAX == (OLECHAR *)0x0) {

    bstrRight = (BSTR)0x0;

  }

  else {

    bstrRight = SysAllocString(in_EAX);

    if (bstrRight == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0(0x8007000e);

    }

  }

  HVar1 = VarBstrCmp((BSTR)*param_1,bstrRight,0x400,0);

  SysFreeString(bstrRight);

  return HVar1 == 1;

}
