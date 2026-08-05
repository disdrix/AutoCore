// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_DebugListMi_004040f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004040f0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_DebugListMissionsStatus
// Address:   0x004040f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_DebugListMissionsStatus: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004040f0, FUN_00404840, FUN_00418700.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_DebugListMissionsStatus
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_DebugListMi_004040f0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  

  iVar1 = FUN_00418700(param_1,*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2);

  FUN_00404840(1);

  *(int *)(param_1 + 4) = iVar1;

  **(int **)(iVar1 + 4) = iVar1;

  return;

}
