// =============================================================================
// Named_CalleeOf_Named_gfxLightImplPoint_004653e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004653e0
// Callee of Named_gfxLightImplPoint
// Address:   0x004653e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxLightImplPoint: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00465260, FUN_004653e0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_gfxLightImplPoint
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

void Named_CalleeOf_Named_gfxLightImplPoint_004653e0(void)



{

  int unaff_ESI;

  

  FUN_00465260();

  if (DAT_00aaa620 < *(float *)(unaff_ESI + 0x210) * *(float *)(unaff_ESI + 0x1cc)) {

    return;

  }

  if (DAT_00aaa620 < *(float *)(unaff_ESI + 0x20c) * *(float *)(unaff_ESI + 0x1cc)) {

    return;

  }

  return;

}
