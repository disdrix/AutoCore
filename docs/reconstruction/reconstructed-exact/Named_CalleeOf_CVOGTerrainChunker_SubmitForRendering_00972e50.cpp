// =============================================================================
// Named_CalleeOf_CVOGTerrainChunker_SubmitForRendering_00972e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00972e50
// Callee of CVOGTerrainChunker_SubmitForRendering
// Address:   0x00972e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTerrainChunker_SubmitForRendering: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076f970, FUN_00972e50.
//  - Return sites: 1.

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

int __fastcall Named_CalleeOf_CVOGTerrainChunker_SubmitForRendering_00972e50(int param_1)



{

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  float local_4;

  

  local_10 = 0;

  local_c = 0;

  local_8 = 0;

  local_4 = g_flOne;

  FUN_0076f970(param_1,&local_10,param_1 + 0x9c,param_1 + 0x80,param_1 + 0x90);

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffe;

  return param_1;

}
