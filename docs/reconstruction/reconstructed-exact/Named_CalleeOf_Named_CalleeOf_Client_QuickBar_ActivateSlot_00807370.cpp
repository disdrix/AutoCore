// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_QuickBar_ActivateSlot_00807370
// -----------------------------------------------------------------------------
// Stable ID: aa_00807370
// Callee of Named_CalleeOf_Client_QuickBar_ActivateSlot
// Address:   0x00807370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_QuickBar_ActivateSlot: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00807370.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_QuickBar_ActivateSlot
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

uint Named_CalleeOf_Named_CalleeOf_Client_QuickBar_ActivateSlot_00807370(void)



{

  uint in_EAX;

  uint uVar1;

  

  if (*(int *)(in_EAX + 0xc7c) != 0) {

                    /* WARNING: Could not recover jumptable at 0x00807381. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar1 = (**(code **)(**(int **)(in_EAX + 0xc7c) + 8))();

    return uVar1;

  }

  return in_EAX & 0xffffff00;

}
