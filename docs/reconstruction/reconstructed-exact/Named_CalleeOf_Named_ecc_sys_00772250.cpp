// =============================================================================
// Named_CalleeOf_Named_ecc_sys_00772250
// -----------------------------------------------------------------------------
// Stable ID: aa_00772250
// Callee of Named_ecc_sys (+1 other named callers)
// Address:   0x00772250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_ecc_sys (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_007707d0, FUN_00772250.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys (+1 other named callers)
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

void Named_CalleeOf_Named_ecc_sys_00772250(int param_1)



{

  uint8_t *puVar1;

  

  puVar1 = (uint8_t *)register0x00000010;

  while (param_1 != 0) {

    FUN_007707d0();

    param_1 = *(int *)(puVar1 + 8);

    puVar1 = puVar1 + 4;

  }

  return;

}
