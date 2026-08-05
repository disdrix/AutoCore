// =============================================================================
// FUN_00950300
// -----------------------------------------------------------------------------
// Stable ID: aa_00950300
// Address:   0x00950300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00950300 @ 0x00950300
// Stable ID: aa_00950300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_005075f0, FUN_00950300.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ __fastcall FUN_00950300(int param_1)



{

  int iVar1;

  void *pvVar2;

  CVOGHBBase *pAction;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abd3a;

  local_c = ExceptionList;

  pAction = (CVOGHBBase *)0x0;

  if ((*(int *)(param_1 + 0xe98) != 0) && (*(int *)(*(int *)(param_1 + 0xe98) + 0x250) != 0)) {

    ExceptionList = &local_c;

    pvVar2 = operator_new(0x2c);

    local_4 = 0;

    if (pvVar2 != (void *)0x0) {

      pAction = (CVOGHBBase *)FUN_005075f0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe98) + 0x250),5000);

    }

    local_4 = 0xffffffff;

    iVar1 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);

    CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1) +

                                 0xe4ec),pAction);

    CVOGHBBase_Start(pAction);

  }

  ExceptionList = local_c;

  return 1;

}
