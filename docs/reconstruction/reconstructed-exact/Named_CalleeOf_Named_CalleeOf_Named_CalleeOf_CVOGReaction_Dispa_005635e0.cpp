// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_005635e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005635e0
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x005635e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×2, CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_005635e0, FUN_00632850.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_005635e0(int param_1,int param_2,char param_3)



{

  float fVar1;

  ushort uVar2;

  int iVar3;

  void *pvVar4;

  CVOGHBBase *pAction;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4abb;

  local_c = ExceptionList;

  if (((param_3 != '\0') ||

      ((*(int *)(param_1 + 0xd8) == 0 && (DAT_00aaa668 < *(float *)(param_1 + 0x84))))) &&

     (*(char *)(param_1 + 0xb0) == '\0')) {

    fVar1 = *(float *)(param_1 + 0x84);

    ExceptionList = &local_c;

    iVar3 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar3 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    }

    uVar2 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

    if ((int)((uint)uVar2 % 2000 + 1000 + (int)fVar1) < 0x1d4c1) {

      fVar1 = *(float *)(param_1 + 0x84);

      iVar3 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar3 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

      }

      uVar2 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

      *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

      iVar3 = (uint)uVar2 % 2000 + 1000 + (int)fVar1;

    }

    else {

      iVar3 = 120000;

    }

    pvVar4 = operator_new(0x24);

    local_4 = 0;

    if (pvVar4 == (void *)0x0) {

      pAction = (CVOGHBBase *)0x0;

    }

    else {

      if (param_2 == -1) {

        param_2 = iVar3;

      }

      pAction = (CVOGHBBase *)FUN_00632850(param_1,param_2);

    }

    local_4 = 0xffffffff;

    CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +

                                 0xe4ec),pAction);

    CVOGHBBase_Start(pAction);

  }

  ExceptionList = local_c;

  return;

}
