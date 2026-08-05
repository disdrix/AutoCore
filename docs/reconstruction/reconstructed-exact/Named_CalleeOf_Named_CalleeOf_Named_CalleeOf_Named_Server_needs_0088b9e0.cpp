// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs_0088b9e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0088b9e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update
// Address:   0x0088b9e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004122f0, FUN_0088ad60, FUN_0088b9e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Server_needs_0088b9e0(void)



{

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x528) != 0) {

    FUN_004122f0(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x524) + 4));

    *(int *)(*(int *)(unaff_EDI + 0x524) + 4) = *(int *)(unaff_EDI + 0x524);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x528) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x524) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x524);

    *(int *)(*(int *)(unaff_EDI + 0x524) + 8) = *(int *)(unaff_EDI + 0x524);

    FUN_0088ad60(unaff_EDI,1,0);

  }

  return;

}
