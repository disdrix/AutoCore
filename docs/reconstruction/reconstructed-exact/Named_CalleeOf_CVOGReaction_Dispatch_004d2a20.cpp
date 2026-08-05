// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_004d2a20
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2a20
// Callee of CVOGReaction_Dispatch
// Address:   0x004d2a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004d2a20, FUN_004e3050.
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_CVOGReaction_Dispatch_004d2a20(int param_1,uint8_t param_2)



{

  int local_4;

  

  local_4 = param_1;

  FUN_004e3050(&local_4,&param_2);

  if (local_4 != *(int *)(param_1 + 0xe514)) {

    return *(uint32_t /* width from decompiler */ *)(local_4 + 0x10);

  }

  return 0;

}
