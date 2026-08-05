// =============================================================================
// Named_CalleeOf_Named_generator_006839b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006839b0
// Callee of Named_generator
// Address:   0x006839b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_generator: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006839b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_generator
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

void __thiscall Named_CalleeOf_Named_generator_006839b0(int param_1,uint param_2)



{

  void *pvVar1;

  

  if (*(uint *)(param_1 + 200) < param_2) {

    *(uint *)(param_1 + 200) = param_2;

    operator_delete__(*(void **)(param_1 + 0xc4));

    pvVar1 = operator_new__(param_2);

    *(void **)(param_1 + 0xc4) = pvVar1;

  }

  return;

}
