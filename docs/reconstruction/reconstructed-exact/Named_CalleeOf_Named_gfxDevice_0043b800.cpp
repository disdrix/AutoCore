// =============================================================================
// Named_CalleeOf_Named_gfxDevice_0043b800
// -----------------------------------------------------------------------------
// Stable ID: aa_0043b800
// Callee of Named_gfxDevice (+2 other named callers)
// Address:   0x0043b800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxDevice (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×5, switch×1.
//  - Notable callees: FUN_0043b800.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice (+2 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxDevice_0043b800(void)



{

  uint32_t /* width from decompiler */ in_EAX;

  

  switch(in_EAX) {

  case 0x47:

    return 0x20;

  default:

    return 0;

  case 0x49:

    return 0xf;

  case 0x4b:

  case 0x4d:

  case 0x4f:

    return 0x18;

  case 0x50:

    return 0x10;

  }

}
