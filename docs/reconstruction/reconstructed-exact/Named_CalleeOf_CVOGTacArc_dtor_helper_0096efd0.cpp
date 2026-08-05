// =============================================================================
// Named_CalleeOf_CVOGTacArc_dtor_helper_0096efd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096efd0
// Callee of CVOGTacArc_dtor_helper
// Address:   0x0096efd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTacArc_dtor_helper: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0096efd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGTacArc_dtor_helper
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

void __fastcall Named_CalleeOf_CVOGTacArc_dtor_helper_0096efd0(int *param_1)



{

  int *piVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac21a;

  pvStack_c = ExceptionList;

  local_4 = 0;

  iVar2 = *param_1;

  ExceptionList = &pvStack_c;

  if (iVar2 != 0) {

    piVar1 = (int *)(iVar2 + 8);

    ExceptionList = &pvStack_c;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(iVar2 + 4) + 8))();

    }

    *param_1 = 0;

  }

  local_4 = 0xffffffff;

  iVar2 = *param_1;

  if (iVar2 != 0) {

    piVar1 = (int *)(iVar2 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(iVar2 + 4) + 8))();

    }

  }

  ExceptionList = pvStack_c;

  return;

}
