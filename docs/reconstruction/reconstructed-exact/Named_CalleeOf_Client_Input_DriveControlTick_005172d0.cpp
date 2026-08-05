// =============================================================================
// Named_CalleeOf_Client_Input_DriveControlTick_005172d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005172d0
// Callee of Client_Input_DriveControlTick (+2 other named callers)
// Address:   0x005172d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_DriveControlTick: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_Input_DriveControlTick (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: CVOGHBList_Enqueue×2, FUN_00604db0×2, FUN_004e2600, FUN_00512090, FUN_005172d0, FUN_00604d40, NetObject_SetMaskBits.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_Input_DriveControlTick (+2 other named callers)
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

void __thiscall Named_CalleeOf_Client_Input_DriveControlTick_005172d0(int param_1,int param_2)



{

  void *pvVar1;

  CVOGHBBase *pAction;

  CVOGHBBase *pAction_00;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3570;

  local_c = ExceptionList;

  if (param_2 != *(int *)(param_1 + 0xa0)) {

    pAction_00 = (CVOGHBBase *)0x0;

    if ((*(int *)(param_1 + 0xa4) != 0) && (*(int *)(*(int *)(param_1 + 0xa4) + 0xe4ec) != 0)) {

      ExceptionList = &local_c;

      if (*(void **)(param_1 + 0x14) != (void *)0x0) {

        ExceptionList = &local_c;

        NetObject_SetMaskBits(*(void **)(param_1 + 0x14),4,0);

      }

      if (*(int *)(param_1 + 0xa0) != 0) {

        *(int *)(param_1 + 0xa0) = param_2;

      }

      FUN_004e2600(FUN_005121d0,0,0);

      *(int *)(param_1 + 0xa0) = param_2;

      if ((param_2 != 0) && (param_2 != param_1)) {

        pvVar1 = operator_new(0x28);

        local_4 = 0;

        if (pvVar1 != (void *)0x0) {

          pAction_00 = (CVOGHBBase *)FUN_00512090(param_1);

        }

        local_4 = 0xffffffff;

        pvVar1 = operator_new(0x28);

        local_4 = 1;

        if (pvVar1 == (void *)0x0) {

          pAction = (CVOGHBBase *)0x0;

        }

        else {

          pAction = (CVOGHBBase *)FUN_00604d40(param_2);

        }

        local_4 = 0xffffffff;

        FUN_00604db0(pAction);

        FUN_00604db0(pAction_00);

        CVOGHBList_Enqueue(*(void **)(*(int *)(param_1 + 0xa4) + 0xe4ec),pAction_00);

        CVOGHBList_Enqueue(*(void **)(*(int *)(param_1 + 0xa4) + 0xe4ec),pAction);

      }

    }

  }

  ExceptionList = local_c;

  return;

}
