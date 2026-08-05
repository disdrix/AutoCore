// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_008e5990
// -----------------------------------------------------------------------------
// Stable ID: aa_008e5990
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
// Address:   0x008e5990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~154 non-empty decompiler lines.
//  - Control keywords: if×18, do×5, while×5, return×2.
//  - Notable callees: FUN_00403450, FUN_004ce940, FUN_00599dd0, FUN_00764030, FUN_007afe80, FUN_008e2d60, FUN_008e47d0, FUN_008e4ea0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_008e5990(int param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  char *pcVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ *puVar9;

  void *pvStack_198;

  char *pcStack_194;

  char acStack_190 [127];

  uint32_t /* width from decompiler */ uStack_111;

  uint8_t auStack_10c [256];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b2bfa;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *(int **)(param_1 + 0x7cc) = param_2;

  if ((*(uint32_t /* width from decompiler */ **)(param_1 + 2000) != (uint32_t /* width from decompiler */ *)0x0) && (*(int *)(param_1 + 0x520) == 0)) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 2000))(1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 2000) = 0;

  }

  FUN_008e2d60(param_1);

  puVar7 = (uint32_t /* width from decompiler */ *)(param_1 + 0x590);

  piVar8 = (int *)(param_1 + 0x568);

  iVar6 = 5;

  do {

    if ((int *)*piVar8 != (int *)0x0) {

      iVar2 = (**(code **)(*(int *)*piVar8 + 700))();

      if (iVar2 != 0) {

        (**(code **)(*(int *)*piVar8 + 0x58))();

      }

      (**(code **)(*(int *)*piVar8 + 4))(0);

    }

    if ((uint32_t /* width from decompiler */ *)piVar8[5] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)piVar8[5])(1);

    }

    piVar8[5] = 0;

    *puVar7 = 0xffffffff;

    puVar7[1] = 0xffffffff;

    piVar8 = piVar8 + 1;

    puVar7 = puVar7 + 2;

    iVar6 = iVar6 + -1;

  } while (iVar6 != 0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7da) = 0;

  *(uint16_t *)(param_1 + 0x7de) = 0;

  *(uint8_t *)(param_1 + 0x7e0) = 0;

  piVar8 = *(int **)(param_1 + 0x530);

  if (param_2 == (int *)0x0) {

    if (piVar8 != (int *)0x0) {

      (**(code **)(*piVar8 + 4))(0);

    }

    if (*(int **)(param_1 + 0x54c) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x54c) + 4))(0);

    }

    if (*(int **)(param_1 + 0x520) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x520) + 0x44))();

    }

    if (*(int **)(param_1 + 0x754) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x754) + 0x448))(0xffffffff,0xffffffff);

    }

  }

  else {

    if (piVar8 != (int *)0x0) {

      (**(code **)(*piVar8 + 4))(1);

    }

    if (*(int **)(param_1 + 0x54c) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x54c) + 4))(1);

    }

    if (*(int **)(param_1 + 0x754) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x754) + 0x448))

                (*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x7cc) + 0x160),

                 *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x7cc) + 0x164));

    }

    pvStack_198 = operator_new(0x14c);

    uStack_4 = 0;

    if (pvStack_198 == (void *)0x0) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_00764030();

    }

    uStack_4 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 2000) = uVar3;

    if (*(int *)(param_2[0x2a] + 0x38) == 0xc) {

      pcVar4 = (char *)(**(code **)(*param_2 + 0x1c0))();

      pcVar5 = (char *)((int)&uStack_111 + 1);

      do {

        cVar1 = *pcVar4;

        *pcVar5 = cVar1;

        pcVar4 = pcVar4 + 1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

    }

    else {

      iVar6 = *(int *)(param_2[0x2a] + 0x3c);

      pcStack_194 = acStack_190;

      uVar3 = (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450(iVar6 + 0x10,uVar3);

      pcVar5 = pcStack_194;

      do {

        cVar1 = *pcVar5;

        pcVar5[(int)&uStack_111 + (1 - (int)pcStack_194)] = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      uStack_4 = 0xffffffff;

      if (pcStack_194 != acStack_190) {

        free(pcStack_194);

      }

    }

    puVar7 = &uStack_111;

    do {

      puVar9 = puVar7;

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

    } while (*(char *)((int)puVar9 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar9 + 1) = DAT_00a28904;

    *(uint8_t *)((int)puVar9 + 5) = DAT_00a28908;

    FUN_00989e00(&pvStack_198,(int)&uStack_111 + 1);

    (**(code **)(**(int **)(param_1 + 2000) + 0x5c))(&pvStack_198);

    if (*(int **)(param_1 + 0x520) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x520) + 0x40))(*(uint32_t /* width from decompiler */ *)(param_1 + 2000),1);

    }

    FUN_007afe80(*(uint32_t /* width from decompiler */ *)(param_1 + 2000),1);

    iVar6 = FUN_00599dd0();

    if (iVar6 == 0) {

      ExceptionList = pvStack_c;

      return;

    }

    FUN_008e5120(iVar6);

    *(uint8_t *)(param_1 + 0x7da) = 1;

    iVar6 = FUN_004ce940();

    iVar2 = (**(code **)(**(int **)(param_1 + 0x7cc) + 0x60))();

    if ((iVar6 != 0) && (0 < iVar2)) {

      iVar6 = 0;

      param_1 = param_1 + 0x61c;

      do {

        FUN_008e5220(param_1);

        iVar6 = iVar6 + 1;

        param_1 = param_1 + 0x14;

      } while (iVar6 < 5);

    }

    FUN_008e4ea0();

  }

  FUN_008e55e0();

  FUN_008e47d0();

  ExceptionList = pvStack_c;

  return;

}
