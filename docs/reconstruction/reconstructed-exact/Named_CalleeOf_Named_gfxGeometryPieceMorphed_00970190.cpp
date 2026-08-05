// =============================================================================
// Named_CalleeOf_Named_gfxGeometryPieceMorphed_00970190
// -----------------------------------------------------------------------------
// Stable ID: aa_00970190
// Callee of Named_gfxGeometryPieceMorphed
// Address:   0x00970190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxGeometryPieceMorphed: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00752510, FUN_0096f740, FUN_0096fdf0, FUN_00970190.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxGeometryPieceMorphed
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxGeometryPieceMorphed_00970190(void)



{

  char cVar1;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ uVar2;

  

  cVar1 = FUN_0096fdf0();

  uVar2 = 0xffffffff;

  if (*unaff_ESI != 0) {

    uVar2 = FUN_00752510();

  }

  if (cVar1 != '\0') {

    FUN_0096f740();

  }

  return uVar2;

}
