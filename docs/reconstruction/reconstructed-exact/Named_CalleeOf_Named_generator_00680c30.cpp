// =============================================================================
// Named_CalleeOf_Named_generator_00680c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00680c30
// Callee of Named_generator (+5 other named callers)
// Address:   0x00680c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_generator: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_generator (+5 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00680c30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_generator (+5 other named callers)
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

void __fastcall Named_CalleeOf_Named_generator_00680c30(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009e9688;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  *(uint8_t *)(param_1 + 6) = 1;

  return;

}
