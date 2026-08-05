// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Could_not_ge_00587440
// -----------------------------------------------------------------------------
// Stable ID: aa_00587440
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk
// Address:   0x00587440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00587440, FUN_00587520, FUN_006759b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Could_not_ge_00587440(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int iVar2;

  

  *param_1 = &PTR_LAB_009d49b8;

  param_1[1] = param_2;

  if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

    iVar1 = *(int *)((int)param_2 + 8);

    param_2 = param_1;

    iVar2 = FUN_006759b0(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&param_2);

    FUN_00587520(1);

    *(int *)(iVar1 + 4) = iVar2;

    **(int **)(iVar2 + 4) = iVar2;

  }

  return param_1;

}
