// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_004526f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004526f0
// Callee of Named_CalleeOf_Named_gfxShadowVolume
// Address:   0x004526f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_004526f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxShadowVolume
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_004526f0(void)



{

  char cVar1;

  int *piVar2;

  int *in_EAX;

  

  piVar2 = (int *)*in_EAX;

  cVar1 = *(char *)((int)piVar2 + 0x39);

  while (cVar1 == '\0') {

    piVar2 = (int *)*piVar2;

    cVar1 = *(char *)((int)piVar2 + 0x39);

  }

  return;

}
