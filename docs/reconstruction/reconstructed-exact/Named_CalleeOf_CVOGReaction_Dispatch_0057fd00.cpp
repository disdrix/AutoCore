// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_0057fd00
// -----------------------------------------------------------------------------
// Stable ID: aa_0057fd00
// Callee of CVOGReaction_Dispatch
// Address:   0x0057fd00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0057fd00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_Dispatch
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

uint64_t __thiscall Named_CalleeOf_CVOGReaction_Dispatch_0057fd00(int param_1,int param_2)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x4c) == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c) >> 3;

  }

  if (param_2 < iVar1) {

    return *(uint64_t *)(*(int *)(param_1 + 0x4c) + param_2 * 8);

  }

  return 0xffffffffffffffff;

}
