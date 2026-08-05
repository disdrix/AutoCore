// =============================================================================
// Named_CalleeOf_CVOGTerrainChunker_SubmitForRendering_0075c960
// -----------------------------------------------------------------------------
// Stable ID: aa_0075c960
// Callee of CVOGTerrainChunker_SubmitForRendering
// Address:   0x0075c960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTerrainChunker_SubmitForRendering: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0043f5e0, FUN_0075c500, FUN_0075c960, FUN_00972fa0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGTerrainChunker_SubmitForRendering
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

uint32_t /* width from decompiler */ Named_CalleeOf_CVOGTerrainChunker_SubmitForRendering_0075c960(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint8_t local_c [12];

  

  if (*(char *)(param_1 + 0x2c) != '\0') {

    return 0;

  }

  FUN_0075c500();

  FUN_00972fa0(param_1);

  uVar1 = FUN_0043f5e0(local_c);

  return uVar1;

}
