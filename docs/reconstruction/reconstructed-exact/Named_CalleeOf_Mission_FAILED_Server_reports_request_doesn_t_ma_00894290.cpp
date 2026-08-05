// =============================================================================
// Named_CalleeOf_Mission_FAILED_Server_reports_request_doesn_t_ma_00894290
// -----------------------------------------------------------------------------
// Stable ID: aa_00894290
// Callee of Mission_FAILED_Server_reports_request_doesn_t_match
// Address:   0x00894290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_FAILED_Server_reports_request_doesn_t_ma: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00894290.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_FAILED_Server_reports_request_doesn_t_match
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

void Named_CalleeOf_Mission_FAILED_Server_reports_request_doesn_t_ma_00894290(void)



{

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x550) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x550) + 0x34c))();

  }

  if (*(int *)(unaff_ESI + 0x554) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x554) + 0x34c))();

  }

  if (*(int *)(unaff_ESI + 0x558) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x558) + 0x34c))();

  }

  if (*(int *)(unaff_ESI + 0x55c) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x55c) + 0x34c))();

  }

  if (*(int *)(unaff_ESI + 0x560) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x560) + 0x34c))();

  }

  if (*(int *)(unaff_ESI + 0x568) != 0) {

                    /* WARNING: Could not recover jumptable at 0x00894314. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x568) + 0x34c))();

    return;

  }

  return;

}
