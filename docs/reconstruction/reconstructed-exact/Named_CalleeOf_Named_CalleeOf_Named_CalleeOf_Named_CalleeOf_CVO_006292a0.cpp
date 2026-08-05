// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_006292a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006292a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGHBAIDriver_DoL
// Address:   0x006292a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGHBAIDriver_DoL: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_006292a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGHBAIDriver_DoL
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_006292a0(int param_1,int param_2)



{

  if (*(uint *)(param_1 + 0x50) == (*(uint *)(param_1 + 0x54) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x4c),4);

  }

  *(int *)(*(int *)(param_1 + 0x4c) + *(int *)(param_1 + 0x50) * 4) = param_2;

  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;

  *(int *)(param_2 + 0x10) = param_1;

  return;

}
