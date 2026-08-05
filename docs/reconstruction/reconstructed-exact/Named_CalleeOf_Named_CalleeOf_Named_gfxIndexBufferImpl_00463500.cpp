// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBufferImpl_00463500
// -----------------------------------------------------------------------------
// Stable ID: aa_00463500
// Callee of Named_CalleeOf_Named_gfxIndexBufferImpl
// Address:   0x00463500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxIndexBufferImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00463500, FUN_00743c50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxIndexBufferImpl
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBufferImpl_00463500(void)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  piVar1 = (int *)*unaff_EDI;

  if (piVar1 != (int *)0x0) {

    FUN_00743c50();

    piVar1[1] = 0;

    piVar1[2] = -1;

    *piVar1 = (int)DAT_00d219d4;

    DAT_00d219d4 = piVar1;

  }

  *unaff_EDI = 0;

  return;

}
