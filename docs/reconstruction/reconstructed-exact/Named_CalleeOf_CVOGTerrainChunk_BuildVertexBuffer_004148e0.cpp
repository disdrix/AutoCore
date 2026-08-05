// =============================================================================
// Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer_004148e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004148e0
// Callee of CVOGTerrainChunk_BuildVertexBuffer
// Address:   0x004148e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTerrainChunk_BuildVertexBuffer: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004148e0.
//  - Return sites: 1.

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

int * __thiscall Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffer_004148e0(int *param_1,int *param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  

  piVar2 = (int *)*param_2;

  if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

    (**(code **)(*piVar2 + 4))();

  }

  piVar3 = (int *)*param_1;

  if (piVar3 != (int *)0x0) {

    piVar1 = piVar3 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

  }

  *param_1 = (int)piVar2;

  *(char *)(param_1 + 1) = (char)param_2[1];

  *(uint8_t *)((int)param_1 + 5) = *(uint8_t *)((int)param_2 + 5);

  *(uint8_t *)((int)param_1 + 6) = *(uint8_t *)((int)param_2 + 6);

  return param_1;

}
