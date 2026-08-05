// =============================================================================
// Named_CalleeOf_Mission_bActiveObjectiveOverride_00419ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00419ca0
// Callee of Mission_bActiveObjectiveOverride (+7 other named callers)
// Address:   0x00419ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_bActiveObjectiveOverride (+7 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: _com_issue_error×2, FUN_00419ca0, SysAllocString.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_bActiveObjectiveOverride (+7 other named callers)
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Mission_bActiveObjectiveOverride_00419ca0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  BSTR pOVar2;

  OLECHAR *unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc02b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar1 = operator_new(0xc);

  local_4 = 0;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar1[1] = 0;

    puVar1[2] = 1;

    pOVar2 = SysAllocString(unaff_EDI);

    *puVar1 = pOVar2;

    if ((pOVar2 == (BSTR)0x0) && (unaff_EDI != (OLECHAR *)0x0)) {

      _com_issue_error(-0x7ff8fff2);

    }

  }

  local_4 = 0xffffffff;

  *param_1 = puVar1;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    _com_issue_error(-0x7ff8fff2);

  }

  ExceptionList = local_c;

  return param_1;

}
