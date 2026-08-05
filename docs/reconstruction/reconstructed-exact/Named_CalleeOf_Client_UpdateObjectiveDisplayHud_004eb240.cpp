// =============================================================================
// Named_CalleeOf_Client_UpdateObjectiveDisplayHud_004eb240
// -----------------------------------------------------------------------------
// Stable ID: aa_004eb240
// Callee of Client_UpdateObjectiveDisplayHud
// Address:   0x004eb240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_UpdateObjectiveDisplayHud: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004eb240.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_UpdateObjectiveDisplayHud
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

undefined * __fastcall Named_CalleeOf_Client_UpdateObjectiveDisplayHud_004eb240(int param_1)



{

  undefined *puVar1;

  

  puVar1 = *(undefined **)(param_1 + 0x84);

  if ((puVar1 == (undefined *)0x0) &&

     (puVar1 = (undefined *)(*(int *)(param_1 + 0x3c) + 0x92), *(int *)(param_1 + 0x3c) == 0)) {

    puVar1 = &DAT_00a860bc;

  }

  return puVar1;

}
