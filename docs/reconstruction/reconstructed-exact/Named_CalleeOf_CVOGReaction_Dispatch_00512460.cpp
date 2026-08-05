// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_00512460
// -----------------------------------------------------------------------------
// Stable ID: aa_00512460
// Callee of CVOGReaction_Dispatch (+2 other named callers)
// Address:   0x00512460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGReaction_Dispatch (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00512460.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_Dispatch (+2 other named callers)
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

void __thiscall Named_CalleeOf_CVOGReaction_Dispatch_00512460(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = *(int *)(param_1 + 0xac);

  piVar2 = (int *)(param_1 + 0xac);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = param_2;

  while (iVar1 != 0) {

    iVar1 = *piVar2;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10) = param_2;

    piVar2 = (int *)(iVar1 + 0xac);

    iVar1 = *piVar2;

  }

  return;

}
