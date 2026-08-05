// =============================================================================
// Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_0094bfa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094bfa0
// Callee of Mission_Attempting_to_open_null_dialog_i
// Address:   0x0094bfa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Attempting_to_open_null_dialog_i: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0094bfa0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Attempting_to_open_null_dialog_i
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

void __fastcall Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_0094bfa0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 0x10a0);

  if ((iVar1 != 0) && (DAT_00d1775e = (uint8_t)param_1, *(int *)(iVar1 + 0x5b4) != 0)) {

    (**(code **)(**(int **)(iVar1 + 0x5b4) + 0x3c8))(param_1,1);

  }

  return;

}
