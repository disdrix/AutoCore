// =============================================================================
// Named_CalleeOf_CVOGReaction_FailMissionNotify_0040dbf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040dbf0
// Callee of CVOGReaction_FailMissionNotify
// Address:   0x0040dbf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_FailMissionNotify: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004073a0, FUN_0040dbf0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_FailMissionNotify
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

void __thiscall Named_CalleeOf_CVOGReaction_FailMissionNotify_0040dbf0(int param_1,int *param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 == 0) || (*(int *)(param_1 + 8) - iVar1 >> 2 == 0)) {

    iVar1 = 0;

  }

  else {

    iVar1 = param_3 - iVar1 >> 2;

  }

  FUN_004073a0(param_3,1,param_4);

  *param_2 = *(int *)(param_1 + 4) + iVar1 * 4;

  return;

}
