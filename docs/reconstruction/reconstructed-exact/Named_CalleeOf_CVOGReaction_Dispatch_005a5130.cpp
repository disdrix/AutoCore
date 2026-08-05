// =============================================================================
// Named_CalleeOf_CVOGReaction_Dispatch_005a5130
// -----------------------------------------------------------------------------
// Stable ID: aa_005a5130
// Callee of CVOGReaction_Dispatch
// Address:   0x005a5130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005a5130.
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

void __thiscall Named_CalleeOf_CVOGReaction_Dispatch_005a5130(int param_1,char param_2)



{

  if (param_2 == '\0') {

    *(uint8_t *)(param_1 + 0x19) = 1;

    *(bool *)(param_1 + 0x15) = *(char *)(param_1 + 0x15) == '\0';

    return;

  }

  *(uint8_t *)(param_1 + 0x19) = 1;

  *(uint8_t *)(param_1 + 0x15) = 1;

  return;

}
