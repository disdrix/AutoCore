// =============================================================================
// Named_CalleeOf_Named_gfxDevice_0040ead0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ead0
// Callee of Named_gfxDevice (+6 other named callers)
// Address:   0x0040ead0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxDevice (+6 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×7, switch×1.
//  - Notable callees: FUN_0040ead0.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice (+6 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxDevice_0040ead0(uint32_t /* width from decompiler */ param_1)



{

  switch(param_1) {

  case 0x14:

    return 0x18;

  case 0x15:

  case 0x16:

  case 0x23:

  case 0x70:

  case 0x72:

    return 0x20;

  case 0x17:

  case 0x19:

  case 0x1a:

  case 0x33:

  case 0x6f:

    return 0x10;

  default:

    return 0;

  case 0x1c:

  case 0x32:

    return 8;

  case 0x24:

  case 0x71:

  case 0x73:

    return 0x40;

  case 0x74:

    return 0x80;

  }

}
