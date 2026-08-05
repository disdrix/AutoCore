// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00930360
// -----------------------------------------------------------------------------
// Stable ID: aa_00930360
// Callee of Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x00930360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~140 non-empty decompiler lines.
//  - Control keywords: if×7, while×2, return×2, do×1, goto×1.
//  - Notable callees: FUN_00408640, FUN_00409bd0, FUN_00409e20, FUN_004e8a40, FUN_004e8ad0, FUN_00930360, Object_ResolveFromTFID, SQRT.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_PollBoundActions
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

void Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00930360(int param_1,TFID_16 *param_2,uint *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  float *pfVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  uint uVar6;

  int iVar7;

  void *pvVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  uint uStack_8c;

  TFID_16 *pTStack_88;

  uint8_t auStack_80 [4];

  void *pvStack_7c;

  int iStack_78;

  int iStack_74;

  int *piStack_70;

  float fStack_6c;

  float fStack_68;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  float fStack_50;

  float fStack_4c;

  float fStack_48;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009ac665;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  pfVar3 = (float *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4

                                         + *(int *)(param_1 + 0xe98)) + 0x1a0))();

  fStack_50 = *pfVar3;

  fStack_4c = pfVar3[1];

  fStack_48 = pfVar3[2];

  puVar4 = (uint32_t /* width from decompiler */ *)

           (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                *(int *)(param_1 + 0xe98)) + 0x1a4))();

  uStack_60 = *puVar4;

  uStack_5c = puVar4[1];

  uStack_58 = puVar4[2];

  uStack_54 = puVar4[3];

  FUN_004e8a40(&uStack_60,&fStack_40);

  FUN_004e8ad0(&uStack_60,&fStack_30);

  iVar7 = 0;

  pvVar8 = (void *)0x0;

  pvStack_7c = (void *)0x0;

  iStack_78 = 0;

  iStack_74 = 0;

  uStack_14 = 0;

  uStack_8c = 0;

  if (*param_3 != 0) {

    pTStack_88 = param_2;

    do {

      piVar5 = Object_ResolveFromTFID(pTStack_88);

      piStack_70 = piVar5;

      if (piVar5 != (int *)0x0) {

        (**(code **)(*piVar5 + 0x144))();

        fVar12 = (float)piVar5[0x21] - fStack_4c;

        fVar13 = (float)piVar5[0x22] - fStack_48;

        fVar14 = (float)piVar5[0x20] - fStack_50;

        fVar9 = fVar13 * fVar13 + fVar12 * fVar12 + fVar14 * fVar14;

        fStack_68 = SQRT(fVar9);

        fStack_6c = g_flLevelUpUiBase_Inferred;

        if (g_flZero < fStack_68) {

          fVar10 = g_flOne / fStack_68;

          fVar11 = fStack_38 * fVar13 * fVar10 + fStack_3c * fVar12 * fVar10 +

                   fStack_40 * fVar10 * fVar14;

          if (fStack_28 * fVar13 * fVar10 + fStack_2c * fVar12 * fVar10 +

              fStack_30 * fVar10 * fVar14 <= g_flZero) {

            fStack_6c = fVar11 + g_flOne;

          }

          else {

            fStack_6c = fVar11 * DAT_00aaa668 - g_flOne;

          }

        }

        if ((pvVar8 == (void *)0x0) ||

           ((uint)(iStack_74 - (int)pvVar8 >> 4) <= (uint)(iVar7 - (int)pvVar8 >> 4))) {

          FUN_00408640(iVar7,&piStack_70);

          iVar7 = iStack_78;

          pvVar8 = pvStack_7c;

        }

        else {

          FUN_00409e20(iVar7,1,auStack_80,fVar9);

          iStack_78 = iVar7 + 0x10;

          iVar7 = iStack_78;

        }

      }

      pTStack_88 = pTStack_88 + 1;

      uStack_8c = uStack_8c + 1;

    } while (uStack_8c < *param_3);

  }

  uVar6 = iVar7 - (int)pvVar8 >> 4;

  FUN_00409bd0(pvVar8,iVar7,uVar6,&LAB_0092cdd0);

  iVar7 = (int)pvVar8 - (int)param_2;

  uStack_8c = 0;

  while (pvVar8 != (void *)0x0) {

    if (uVar6 <= uStack_8c) goto LAB_00930652;

    iVar1 = *(int *)(iVar7 + (int)param_2);

    uStack_8c = uStack_8c + 1;

    param_2->dwCoidLo = *(uint *)(iVar1 + 0x160);

    param_2->dwCoidHi = *(uint *)(iVar1 + 0x164);

    uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168);

    param_2->bGlobal = (char)uVar2;

    param_2->bPad0 = (char)((uint)uVar2 >> 8);

    param_2->bPad1 = (char)((uint)uVar2 >> 0x10);

    param_2->bPad2 = (char)((uint)uVar2 >> 0x18);

    uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x16c);

    param_2->bPad3 = (char)uVar2;

    param_2->bPad4 = (char)((uint)uVar2 >> 8);

    param_2->bPad5 = (char)((uint)uVar2 >> 0x10);

    param_2->bPad6 = (char)((uint)uVar2 >> 0x18);

    param_2 = param_2 + 1;

  }

  uVar6 = 0;

LAB_00930652:

  *param_3 = uVar6;

  uStack_14 = 0xffffffff;

  if (pvVar8 == (void *)0x0) {

    ExceptionList = pvStack_1c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar8);

}
