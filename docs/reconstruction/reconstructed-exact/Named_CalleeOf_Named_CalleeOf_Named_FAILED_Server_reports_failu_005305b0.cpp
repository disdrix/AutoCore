// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_FAILED_Server_reports_failu_005305b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005305b0
// Callee of Named_CalleeOf_Named_FAILED_Server_reports_failure
// Address:   0x005305b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_FAILED_Server_reports_failure: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00418b80, FUN_005305b0, FUN_0053af20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_FAILED_Server_reports_failure
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_FAILED_Server_reports_failu_005305b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int local_4;

  

  local_4 = param_1;

  FUN_00418b80(&local_4,&param_2);

  uVar1 = param_3;

  if (local_4 == *(int *)(param_1 + 0x588)) {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_0053af20(&param_2);

    *puVar2 = 0;

    puVar2[1] = uVar1;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(local_4 + 0x14) = param_3;

  return;

}
