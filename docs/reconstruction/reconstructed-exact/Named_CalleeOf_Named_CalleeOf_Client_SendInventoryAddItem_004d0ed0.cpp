// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_SendInventoryAddItem_004d0ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d0ed0
// Callee of Named_CalleeOf_Client_SendInventoryAddItem (+1 other named callers)
// Address:   0x004d0ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_SendInventoryAddItem: inventory/item helper. Evidence string: "trying to drop <NULL> ptr object on the ground". Supports parent flow (not a free-standing entry point). Named_CalleeOf_Client_SendInventoryAddItem (+1 other named callers).
// Embedded strings (evidence):
//   - "trying to drop <NULL> ptr object on the ground"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_004024d0, FUN_004d0ed0, FUN_005a58c0, FUN_005d8360, FUN_007a4480.
//  - Strings: "trying to drop <NULL> ptr object on the ground".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_SendInventoryAddItem (+1 other named callers)
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_CalleeOf_Named_CalleeOf_Client_SendInventoryAddItem_004d0ed0(int param_1,int param_2,float *param_3,float param_4,char param_5)



{

  float fVar1;

  ushort uVar2;

  int iVar3;

  void *pvVar4;

  CVOGHBBase *pAction;

  float10 fVar5;

  float fVar6;

  float local_30;

  float local_28;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a1fb6;

  local_1c = ExceptionList;

  if (param_2 == 0) {

    ExceptionList = &local_1c;

    FUN_007a4480(0,"trying to drop <NULL> ptr object on the ground");

    ExceptionList = local_1c;

    return;

  }

  local_30 = *param_3;

  local_28 = param_3[2];

  fVar1 = param_3[3];

  ExceptionList = &local_1c;

  if (g_flZero < param_4) {

    ExceptionList = &local_1c;

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar2 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    local_30 = ((float)uVar2 * param_4 * _DAT_009cc4a8 - param_4) + local_30;

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar2 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    local_28 = ((float)uVar2 * param_4 * _DAT_009cc4a8 - param_4) + local_28;

  }

  if (*(int *)(param_1 + 0xe4e0) == 0) {

    fVar6 = 0.0;

  }

  else {

    fVar5 = (float10)FUN_005a58c0(local_30,local_28);

    fVar6 = (float)fVar5;

  }

  *(float *)(param_2 + 0x84) = fVar6 + DAT_00a0f298;

  *(float *)(param_2 + 0x88) = local_28;

  *(float *)(param_2 + 0x80) = local_30;

  *(float *)(param_2 + 0x8c) = fVar1;

  FUN_004024d0(param_2);

  if (param_5 != '\0') {

    pvVar4 = operator_new(0x24);

    local_14 = 0;

    if (pvVar4 == (void *)0x0) {

      pAction = (CVOGHBBase *)0x0;

    }

    else {

      pAction = (CVOGHBBase *)

                FUN_005d8360(param_2,(-(uint)(*(int *)(*(int *)(param_2 + 0xa8) + 0x38) != 4) &

                                     0xff938290) + 7200000);

    }

    local_14 = 0xffffffff;

    CVOGHBList_Enqueue(*(void **)(param_1 + 0xe4ec),pAction);

    CVOGHBBase_Start(pAction);

  }

  ExceptionList = local_1c;

  return;

}
