// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunk_B_005bf530
// -----------------------------------------------------------------------------
// Stable ID: aa_005bf530
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffe (+1 other named callers)
// Address:   0x005bf530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffe: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffe (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CONCAT22, FUN_005bf530.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunk_BuildVertexBuffe (+1 other named callers)
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTerrainChunk_B_005bf530(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  param_2 = *(int *)(param_1 + 0xcc) * DAT_00b03650 + param_2;

  param_3 = *(int *)(param_1 + 0xd0) * DAT_00b03650 + param_3;

  iVar2 = *(int *)(DAT_00bc5524 + 0x10) + -1;

  iVar1 = param_2;

  if (iVar2 <= param_2) {

    iVar1 = iVar2;

  }

  if (iVar1 < 1) {

    param_2 = 0;

  }

  else if (iVar2 <= param_2) {

    param_2 = iVar2;

  }

  iVar1 = *(int *)(DAT_00bc5524 + 0x14) + -1;

  iVar2 = param_3;

  if (iVar1 <= param_3) {

    iVar2 = iVar1;

  }

  if (iVar2 < 1) {

    param_3 = 0;

  }

  else if (iVar1 <= param_3) {

    param_3 = iVar1;

  }

  return CONCAT22((short)((uint)*(int *)(DAT_00bc5524 + 0x3e0) >> 0x10),

                  *(uint16_t *)

                   (*(int *)(DAT_00bc5524 + 0x3e0) +

                   (*(int *)(DAT_00bc5524 + 0x10) * param_3 + param_2) * 2));

}
