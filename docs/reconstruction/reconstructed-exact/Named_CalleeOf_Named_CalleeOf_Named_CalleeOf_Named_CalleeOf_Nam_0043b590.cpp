// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043b590
// -----------------------------------------------------------------------------
// Stable ID: aa_0043b590
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLODHandle
// Address:   0x0043b590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLODHandle: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0043a090×2, FUN_0043b590.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLODHandle
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0043b590(int param_1)



{

  int in_EAX;

  int unaff_EDI;

  

  for (; in_EAX != param_1; in_EAX = in_EAX + 0x28) {

    FUN_0043a090();

    FUN_0043a090();

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20);

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x24) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x24);

  }

  return;

}
