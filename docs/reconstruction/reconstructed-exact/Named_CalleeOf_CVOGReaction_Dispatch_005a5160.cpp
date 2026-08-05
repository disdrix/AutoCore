// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_005a5160
// -----------------------------------------------------------------------------
// Stable ID: aa_005a5160
// Callee of CVOGReaction_Dispatch
// Address:   0x005a5160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005a5160.
//  - Return sites: 1.

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

void __fastcall Named_CalleeOf_CVOGReaction_Dispatch_005a5160(uint32_t /* width from decompiler */ *param_1)



{

  *(uint8_t *)((int)param_1 + 0x15) = 0;

  *(uint8_t *)(param_1 + 6) = 1;

  param_1[2] = 0;

  param_1[4] = 0;

  *param_1 = 0;

  param_1[1] = 0;

  *(uint8_t *)((int)param_1 + 0x19) = 1;

  *(uint8_t *)((int)param_1 + 0x1a) = 0;

  *(uint8_t *)((int)param_1 + 0x1b) = 1;

  return;

}
