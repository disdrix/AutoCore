// =============================================================================
// FUN_004cfca0
// -----------------------------------------------------------------------------
// Stable ID: aa_004cfca0
// Address:   0x004cfca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cfca0 @ 0x004cfca0
// Stable ID: aa_004cfca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_0048e9e0, FUN_004cfca0, FUN_00558b20.
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

void __fastcall FUN_004cfca0(int param_1)



{

  int *piVar1;

  void *pvVar2;

  CVOGHBBase *pAction;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a1f4b;

  pvStack_c = ExceptionList;

  piVar1 = *(int **)(param_1 + 0x78);

  ExceptionList = &pvStack_c;

  if (piVar1 != (int *)0x0) {

    if (*(int *)(param_1 + 0xe4ec) == 0) {

      ExceptionList = &pvStack_c;

      (**(code **)*piVar1)(1);

    }

    else {

      ExceptionList = &pvStack_c;

      (**(code **)(*piVar1 + 0x18))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  }

  if (*(int *)(param_1 + 0xe894) != 0) {

    FUN_0048e9e0();

  }

  pvVar2 = operator_new(0x1d8);

  uStack_4 = 0;

  if (pvVar2 == (void *)0x0) {

    pAction = (CVOGHBBase *)0x0;

  }

  else {

    pAction = (CVOGHBBase *)FUN_00558b20(param_1);

  }

  uStack_4 = 0xffffffff;

  *(CVOGHBBase **)(param_1 + 0x78) = pAction;

  if (*(void **)(param_1 + 0xe4ec) != (void *)0x0) {

    CVOGHBList_Enqueue(*(void **)(param_1 + 0xe4ec),pAction);

    CVOGHBBase_Start(*(CVOGHBBase **)(param_1 + 0x78));

  }

  ExceptionList = pvStack_c;

  return;

}
