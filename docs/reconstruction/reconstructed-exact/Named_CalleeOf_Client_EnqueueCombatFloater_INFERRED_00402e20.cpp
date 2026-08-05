// =============================================================================
// Named_CalleeOf_Client_EnqueueCombatFloater_INFERRED_00402e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00402e20
// Callee of Client_EnqueueCombatFloater_INFERRED
// Address:   0x00402e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_EnqueueCombatFloater_INFERRED: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, goto×1, return×1.
//  - Notable callees: FUN_00402e20, FUN_00403680.
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

void __thiscall Named_CalleeOf_Client_EnqueueCombatFloater_INFERRED_00402e20(int param_1,int *param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 4);

  if (iVar1 != 0) {

    if ((*(int *)(param_1 + 8) - iVar1) / 0x38 != 0) {

      iVar1 = (param_3 - iVar1) / 0x38;

      goto LAB_00402e69;

    }

  }

  iVar1 = 0;

LAB_00402e69:

  FUN_00403680(param_3,1,param_4);

  *param_2 = *(int *)(param_1 + 4) + iVar1 * 0x38;

  return;

}
