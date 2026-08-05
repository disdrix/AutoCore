// =============================================================================
// Named_CalleeOf_Named_gfxGeometryPieceMorphed_00465090
// -----------------------------------------------------------------------------
// Stable ID: aa_00465090
// Callee of Named_gfxGeometryPieceMorphed
// Address:   0x00465090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxGeometryPieceMorphed: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00465090, FUN_004650b0.
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

void Named_CalleeOf_Named_gfxGeometryPieceMorphed_00465090(void)



{

  undefined **local_c;

  uint32_t /* width from decompiler */ local_8;

  uint8_t *local_4;

  

  local_4 = (uint8_t *)&local_c;

  local_8 = 0;

  local_c = &PTR_FUN_00a9db18;

  FUN_004650b0();

  return;

}
