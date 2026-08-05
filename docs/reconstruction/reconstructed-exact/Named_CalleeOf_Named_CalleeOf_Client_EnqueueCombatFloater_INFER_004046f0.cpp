// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_EnqueueCombatFloater_INFER_004046f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004046f0
// Callee of Named_CalleeOf_Client_EnqueueCombatFloater_INFERRED
// Address:   0x004046f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_EnqueueCombatFloater_INFERRED: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_004046f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_EnqueueCombatFloater_INFERRED
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

void Named_CalleeOf_Named_CalleeOf_Client_EnqueueCombatFloater_INFER_004046f0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  

  if (param_1 != (uint32_t /* width from decompiler */ *)0x0) {

    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {

      *param_1 = *param_2;

      param_2 = param_2 + 1;

      param_1 = param_1 + 1;

    }

  }

  return;

}
