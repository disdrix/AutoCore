// =============================================================================
// Named_CalleeOf_Named_gfxDevice_0073e980
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e980
// Callee of Named_gfxDevice
// Address:   0x0073e980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_004425f0, FUN_0073e780, FUN_0073e980.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice
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

void Named_CalleeOf_Named_gfxDevice_0073e980(void)



{

  int *piVar1;

  int *piVar2;

  

  piVar2 = DAT_00d1ee68;

  piVar1 = (int *)*DAT_00d1ee68;

  while (piVar1 != piVar2) {

    FUN_0073e780(piVar1[3]);

    FUN_004425f0();

  }

  return;

}
