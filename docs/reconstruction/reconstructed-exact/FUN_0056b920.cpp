// =============================================================================
// FUN_0056b920
// -----------------------------------------------------------------------------
// Stable ID: aa_0056b920
// Address:   0x0056b920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056b920 @ 0x0056b920
// Stable ID: aa_0056b920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_0056b920, FUN_005fe6a0.
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

void __fastcall FUN_0056b920(int *param_1)



{

  char cVar1;

  int iVar2;

  void *pvVar3;

  CVOGHBBase *pAction;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a4d45;

  local_c = ExceptionList;

  iVar2 = *(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1);

  if (iVar2 == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(iVar2 + 0x3c);

  }

  if (*(int *)(iVar2 + 0x528) == -1) {

    ExceptionList = &local_c;

    cVar1 = (**(code **)(*param_1 + 0x4c))(0);

    if (cVar1 != '\0') {

      *(uint8_t *)((int)param_1 + 199) = 1;

      if ((char)param_1[0x32] != '\x01') {

        *(uint8_t *)(param_1 + 0x32) = 1;

      }

      pvVar3 = operator_new(0x24);

      uStack_4 = 0;

      if (pvVar3 == (void *)0x0) {

        pAction = (CVOGHBBase *)0x0;

      }

      else {

        pAction = (CVOGHBBase *)FUN_005fe6a0(param_1,1000);

      }

      uStack_4 = 0xffffffff;

      CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1) +

                                   0xe4ec),pAction);

      CVOGHBBase_Start(pAction);

    }

  }

  ExceptionList = local_c;

  return;

}
