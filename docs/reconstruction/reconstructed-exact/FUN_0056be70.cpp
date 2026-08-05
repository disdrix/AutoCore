// =============================================================================
// FUN_0056be70
// -----------------------------------------------------------------------------
// Stable ID: aa_0056be70
// Address:   0x0056be70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056be70 @ 0x0056be70
// Stable ID: aa_0056be70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_0056ab40, FUN_0056be70, FUN_005fe6a0.
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

void __fastcall FUN_0056be70(int param_1)



{

  int iVar1;

  void *pvVar2;

  CVOGHBBase *pAction;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a4d5a;

  local_c = ExceptionList;

  if (*(char *)(param_1 + 0xc5) == '\0') {

    ExceptionList = &local_c;

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x104))(1);

    *(uint8_t *)(param_1 + 0xc5) = 1;

    *(uint8_t *)(param_1 + 0xcb) = 1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8) = 0;

    FUN_0056ab40();

    iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0xe4ec) != 0)) {

      pvVar2 = operator_new(0x24);

      uStack_4 = 0;

      if (pvVar2 == (void *)0x0) {

        pAction = (CVOGHBBase *)0x0;

      }

      else {

        pAction = (CVOGHBBase *)FUN_005fe6a0(param_1,1000);

      }

      uStack_4 = 0xffffffff;

      CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +

                                   0xe4ec),pAction);

      CVOGHBBase_Start(pAction);

      if (*(int *)(param_1 + 0x30) != 0) {

        (**(code **)(**(int **)(param_1 + 0x24) + 0x18))(*(int *)(param_1 + 0x30),0x3e4ccccd,0);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0xffffffff;

    }

  }

  ExceptionList = local_c;

  return;

}
