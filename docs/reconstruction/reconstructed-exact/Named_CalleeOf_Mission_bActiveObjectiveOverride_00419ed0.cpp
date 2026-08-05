// =============================================================================
// Named_CalleeOf_Mission_bActiveObjectiveOverride_00419ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_00419ed0
// Callee of Mission_bActiveObjectiveOverride (+7 other named callers)
// Address:   0x00419ed0  (autoassault.exe, image base 0x400000)
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
//  - Notable callees: FUN_00419e20, FUN_00419ed0, _com_issue_errorex.
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Mission_bActiveObjectiveOverride_00419ed0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  IID *riid;

  HRESULT HVar3;

  IUnknown *unaff_EDI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar2 = param_2;

  puVar1 = param_1;

  puStack_8 = &LAB_009bceb8;

  pvStack_c = ExceptionList;

  local_4 = 0;

  param_1 = (void *)0x0;

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    riid = (IID *)0x0;

  }

  else {

    riid = (IID *)*param_2;

  }

  ExceptionList = &pvStack_c;

  HVar3 = (*unaff_EDI->lpVtbl[0xc].QueryInterface)(unaff_EDI,riid,&param_1);

  if (HVar3 < 0) {

    _com_issue_errorex(HVar3,unaff_EDI,(_GUID *)&DAT_00a86128);

  }

  *puVar1 = param_1;

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00419e20();

  }

  ExceptionList = pvStack_c;

  return puVar1;

}
