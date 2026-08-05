// =============================================================================
// Named_CalleeOf_Named_VOGSpecGlowFilter_00752a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00752a00
// Callee of Named_VOGSpecGlowFilter (+1 other named callers)
// Address:   0x00752a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGSpecGlowFilter: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOGSpecGlowFilter (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00752800, FUN_00752a00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOGSpecGlowFilter (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_VOGSpecGlowFilter_00752a00(int param_1)



{

  if (-1 < param_1) {

    FUN_00752800(param_1);

    return 0;

  }

  return 0xffffffff;

}
