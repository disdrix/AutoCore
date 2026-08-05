// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffe_0043ee30
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ee30
// Callee of Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer
// Address:   0x0043ee30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0043ee30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer
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

void Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffe_0043ee30(void)



{

  int *piVar1;

  int *piVar2;

  int *unaff_ESI;

  int *unaff_EDI;

  

  if ((unaff_ESI != (int *)0x0) && (unaff_ESI[1] = unaff_ESI[1] + 1, unaff_ESI[1] == 1)) {

    (**(code **)(*unaff_ESI + 4))();

  }

  piVar2 = (int *)*unaff_EDI;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *unaff_EDI = (int)unaff_ESI;

  return;

}
