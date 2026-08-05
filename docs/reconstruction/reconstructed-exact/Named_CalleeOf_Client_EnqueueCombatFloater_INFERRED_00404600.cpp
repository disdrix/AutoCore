// =============================================================================
// Named_CalleeOf_Client_EnqueueCombatFloater_INFERRED_00404600
// -----------------------------------------------------------------------------
// Stable ID: aa_00404600
// Callee of Client_EnqueueCombatFloater_INFERRED
// Address:   0x00404600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_EnqueueCombatFloater_INFERRED: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00404600, FUN_004046f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_EnqueueCombatFloater_INFERRED
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

void Named_CalleeOf_Client_EnqueueCombatFloater_INFERRED_00404600(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009bc760;

  local_10 = ExceptionList;

  local_8 = 0;

  ExceptionList = &local_10;

  for (; param_2 != 0; param_2 = param_2 + -1) {

    FUN_004046f0(param_1,param_3);

    param_1 = param_1 + 0x38;

  }

  ExceptionList = local_10;

  return;

}
