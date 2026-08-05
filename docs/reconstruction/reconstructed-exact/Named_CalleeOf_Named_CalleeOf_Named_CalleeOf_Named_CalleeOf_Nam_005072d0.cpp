// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005072d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005072d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic
// Address:   0x005072d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005072d0, FUN_005b3370.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005072d0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  if (*(uint *)(param_1 + 0x8c) == (*(uint *)(param_1 + 0x90) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x88),4);

  }

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x88) + *(int *)(param_1 + 0x8c) * 4) = param_2;

  *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;

  return;

}
