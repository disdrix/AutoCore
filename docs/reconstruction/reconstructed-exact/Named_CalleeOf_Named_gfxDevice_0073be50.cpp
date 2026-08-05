// =============================================================================
// Named_CalleeOf_Named_gfxDevice_0073be50
// -----------------------------------------------------------------------------
// Stable ID: aa_0073be50
// Callee of Named_gfxDevice
// Address:   0x0073be50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0073be50, FUN_00755820.
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxDevice_0073be50(void)



{

  int unaff_EBX;

  int *piVar1;

  

  piVar1 = (int *)**(int **)(unaff_EBX + 8);

  if (piVar1 != *(int **)(unaff_EBX + 8)) {

    do {

      FUN_00755820();

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(unaff_EBX + 8));

  }

  return 0;

}
