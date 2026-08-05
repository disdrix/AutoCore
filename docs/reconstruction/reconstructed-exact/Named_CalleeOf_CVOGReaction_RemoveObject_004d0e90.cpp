// =============================================================================
// Named_CalleeOf_CVOGReaction_RemoveObject_004d0e90
// -----------------------------------------------------------------------------
// Stable ID: aa_004d0e90
// Callee of CVOGReaction_RemoveObject
// Address:   0x004d0e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_RemoveObject: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004024d0, FUN_004d0e90, FUN_004e15a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_RemoveObject
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

void Named_CalleeOf_CVOGReaction_RemoveObject_004d0e90(int param_1)



{

  char cVar1;

  

  if ((*(byte *)(param_1 + 0x17c) & 1) == 0) {

    cVar1 = FUN_004e15a0(param_1);

    if (cVar1 == '\0') {

      FUN_004024d0(param_1);

      *(uint *)(param_1 + 0x17c) = *(uint *)(param_1 + 0x17c) | 1;

    }

  }

  return;

}
