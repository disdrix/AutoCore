// =============================================================================
// Named_CalleeOf_Skill_Skills_005122c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005122c0
// Callee of Skill_Skills (+1 other named callers)
// Address:   0x005122c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skills: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Skill_Skills (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005122c0, ROUND, SQRT.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Skill_Skills (+1 other named callers)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int __fastcall Named_CalleeOf_Skill_Skills_005122c0(int param_1)



{

  int iVar1;

  

  if ((0 < *(int *)(param_1 + 0xc4)) &&

     (iVar1 = (int)ROUND(SQRT((float)*(int *)(param_1 + 0xc4)) * _DAT_009cdff4), 0 < iVar1)) {

    return iVar1;

  }

  return 0;

}
