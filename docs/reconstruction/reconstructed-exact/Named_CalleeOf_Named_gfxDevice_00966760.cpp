// =============================================================================
// Named_CalleeOf_Named_gfxDevice_00966760
// -----------------------------------------------------------------------------
// Stable ID: aa_00966760
// Callee of Named_gfxDevice
// Address:   0x00966760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00966760.
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxDevice_00966760(void)



{

  int iVar1;

  int unaff_EDI;

  

  iVar1 = (**(code **)(*(int *)*DAT_00d1f044 + 0x1d8))

                    ((int *)*DAT_00d1f044,5,(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3d4));

  *(uint8_t *)(unaff_EDI + 0x3d8) = 0;

  if (iVar1 < 0) {

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3d4) = 0;

  }

  return 0;

}
