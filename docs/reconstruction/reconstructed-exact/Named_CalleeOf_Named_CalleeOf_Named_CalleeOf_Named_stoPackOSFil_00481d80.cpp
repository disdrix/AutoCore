// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFil_00481d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00481d80
// Callee of Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFile
// Address:   0x00481d80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFile: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00481d80.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFile
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_stoPackOSFil_00481d80(void)



{

  int unaff_ESI;

  

  if (*(void **)(unaff_ESI + 0x18) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 0x18));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = 0;

  return;

}
