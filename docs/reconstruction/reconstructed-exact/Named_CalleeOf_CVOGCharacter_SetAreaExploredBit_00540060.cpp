// =============================================================================
// Named_CalleeOf_CVOGCharacter_SetAreaExploredBit_00540060
// -----------------------------------------------------------------------------
// Stable ID: aa_00540060
// Callee of CVOGCharacter_SetAreaExploredBit
// Address:   0x00540060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCharacter_SetAreaExploredBit: character create/apply helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00540060, FUN_007dd5e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGCharacter_SetAreaExploredBit
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

int __fastcall Named_CalleeOf_CVOGCharacter_SetAreaExploredBit_00540060(int param_1)



{

  if (*(int *)(param_1 + 0xefc) == 0) {

    FUN_007dd5e0(param_1 + 0xef4);

  }

  return param_1 + 0xef4;

}
