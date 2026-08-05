// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxPhaseAlphaTest_0043b7d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043b7d0
// Callee of Named_CalleeOf_Named_gfxPhaseAlphaTest
// Address:   0x0043b7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxPhaseAlphaTest: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0043b7d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxPhaseAlphaTest
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxPhaseAlphaTest_0043b7d0(int param_1)



{

  int *piVar1;

  

  if (DAT_00d1f614 != 0) {

    piVar1 = (int *)(DAT_00d1f614 + 0xcc + (*(int *)(DAT_00d1f614 + 0xc4) * 0x13 + param_1) * 4);

    *piVar1 = *piVar1 + 1;

  }

  return;

}
