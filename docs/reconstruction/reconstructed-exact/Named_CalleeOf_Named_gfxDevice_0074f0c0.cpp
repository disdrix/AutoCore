// =============================================================================
// Named_CalleeOf_Named_gfxDevice_0074f0c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074f0c0
// Callee of Named_gfxDevice
// Address:   0x0074f0c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0074f0c0.
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

void Named_CalleeOf_Named_gfxDevice_0074f0c0(void)



{

  int unaff_ESI;

  

  if ((DAT_00afe034 != 0) && (*(int *)(DAT_00afe034 + 0xc) != 0)) {

    (**(code **)(**(int **)(DAT_00afe034 + 0xc) + 0x10c))(*(int **)(DAT_00afe034 + 0xc));

  }

  if ((DAT_00afe01c != 0) && (*(int *)(DAT_00afe01c + 0xc) != 0)) {

    (**(code **)(**(int **)(DAT_00afe01c + 0xc) + 0x10c))(*(int **)(DAT_00afe01c + 0xc));

  }

  if ((DAT_00afe010 != 0) && (*(int *)(DAT_00afe010 + 0xc) != 0)) {

    (**(code **)(**(int **)(DAT_00afe010 + 0xc) + 0x10c))(*(int **)(DAT_00afe010 + 0xc));

  }

  if (*(int *)(unaff_ESI + 0xc) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x114))(*(int **)(unaff_ESI + 0xc));

  }

  return;

}
