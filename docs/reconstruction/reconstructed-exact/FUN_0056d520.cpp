// =============================================================================
// FUN_0056d520
// -----------------------------------------------------------------------------
// Stable ID: aa_0056d520
// Address:   0x0056d520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056d520 @ 0x0056d520
// Stable ID: aa_0056d520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_00514ff0, FUN_0056d160, FUN_0056d520, FUN_005fe6a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall FUN_0056d520(int param_1)



{

  void *pvVar1;

  CVOGHBBase *pAction;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4dbb;

  local_c = ExceptionList;

  if (*(char *)(param_1 + 0xcb) != '\0') {

    return 0;

  }

  pAction = (CVOGHBBase *)0x0;

  ExceptionList = &local_c;

  if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) != 0) {

    ExceptionList = &local_c;

    FUN_00514ff0(0);

  }

  *(uint8_t *)(param_1 + 199) = 1;

  if (*(char *)(param_1 + 200) != '\x01') {

    *(uint8_t *)(param_1 + 200) = 1;

  }

  *(uint8_t *)(param_1 + 0xc9) = 1;

  FUN_0056d160(&DAT_00b047c0,0);

  pvVar1 = operator_new(0x24);

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    pAction = (CVOGHBBase *)FUN_005fe6a0(param_1,1000);

  }

  local_4 = 0xffffffff;

  CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +

                               0xe4ec),pAction);

  CVOGHBBase_Start(pAction);

  ExceptionList = local_c;

  return 1;

}
