// =============================================================================
// Named_CalleeOf_Named_VOGSpecGlowFilter_0073f2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073f2c0
// Callee of Named_VOGSpecGlowFilter
// Address:   0x0073f2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGSpecGlowFilter: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0073f2c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOGSpecGlowFilter
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOGSpecGlowFilter_0073f2c0(int param_1,uint param_2)



{

  if ((*(int *)(param_1 + 0x14) != 0) &&

     (param_2 < (uint)(*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2))) {

    return *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + param_2 * 4);

  }

  return 0;

}
