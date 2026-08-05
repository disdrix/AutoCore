// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_INITIALIZE_NO_MAXPARTICLES_005b8170
// -----------------------------------------------------------------------------
// Stable ID: aa_005b8170
// Callee of Named_CalleeOf_Named_INITIALIZE_NO_MAXPARTICLES_ON_MASTER_FLUID
// Address:   0x005b8170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_INITIALIZE_NO_MAXPARTICLES_ON_MASTER_FLUID: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b8170.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_INITIALIZE_NO_MAXPARTICLES_ON_MASTER_FLUID
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_INITIALIZE_NO_MAXPARTICLES_005b8170(int param_1)



{

  if (*(void **)(param_1 + 0x24) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x24));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  return;

}
