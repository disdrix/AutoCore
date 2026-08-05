// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0095aaa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0095aaa0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI
// Address:   0x0095aaa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0095aaa0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0095aaa0(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_00a152ec;

  if ((void *)param_1[1] != (void *)0x0) {

    operator_delete__((void *)param_1[1]);

  }

  param_1[1] = 0;

  if ((void *)param_1[2] != (void *)0x0) {

    operator_delete__((void *)param_1[2]);

  }

  param_1[2] = 0;

  return;

}
