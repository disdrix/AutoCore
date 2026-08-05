// =============================================================================
// Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer_0096fdf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096fdf0
// Callee of CVOGTerrainChunk_BuildVertexBuffer
// Address:   0x0096fdf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTerrainChunk_BuildVertexBuffer: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0043ed00, FUN_0043ee30, FUN_0073df30, FUN_0096fdf0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of CVOGTerrainChunk_BuildVertexBuffer
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer_0096fdf0(int *param_1)



{

  int iVar1;

  

  iVar1 = *param_1;

  if ((iVar1 != 0) && (1 < *(int *)(iVar1 + 4))) {

    iVar1 = FUN_0073df30(DAT_00d1f61c,iVar1);

    if (iVar1 == 0) {

      return 0;

    }

    FUN_0043ed00();

    FUN_0043ee30();

    return 1;

  }

  return 0;

}
