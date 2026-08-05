// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_AudioInThrea_00711d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00711d40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_AudioInThread
// Address:   0x00711d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_AudioInThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00711d40.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_AudioInThread
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_AudioInThrea_00711d40(int param_1,float param_2)



{

  if (g_flOne < param_2) {

    *(float *)(*(int *)(param_1 + 0x48) + 0x24) = g_flOne - g_flOne;

    return;

  }

  if (param_2 < g_flZero) {

    param_2 = g_flZero;

  }

  *(float *)(*(int *)(param_1 + 0x48) + 0x24) = g_flOne - param_2;

  return;

}
