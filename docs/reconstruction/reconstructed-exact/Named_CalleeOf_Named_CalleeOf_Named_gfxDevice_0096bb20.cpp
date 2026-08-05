// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_0096bb20
// -----------------------------------------------------------------------------
// Stable ID: aa_0096bb20
// Callee of Named_CalleeOf_Named_gfxDevice
// Address:   0x0096bb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0043b800, FUN_0096bb20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDevice
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

int Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_0096bb20(void)



{

  uint uVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x18) != 0) {

    uVar1 = FUN_0043b800();

    return (uVar1 >> 3) * *(int *)(unaff_ESI + 0x20) * *(int *)(unaff_ESI + 0x1c);

  }

  return 0;

}
