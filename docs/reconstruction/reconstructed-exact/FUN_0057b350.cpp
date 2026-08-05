// =============================================================================
// FUN_0057b350
// -----------------------------------------------------------------------------
// Stable ID: aa_0057b350
// Address:   0x0057b350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057b350 @ 0x0057b350
// Stable ID: aa_0057b350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×12, do×4, while×4, for×2, return×1.
//  - Notable callees: FUN_0057fd40×3, FUN_00580610×3, FUN_005801e0×2, FUN_0057b350, FUN_007a6880, FUN_007a69d0, FUN_007a6de0.
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

void __thiscall FUN_0057b350(int param_1,int *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  void *pvVar4;

  int iVar5;

  char *pcVar6;

  char *pcVar7;

  char *pcVar8;

  void *pvVar9;

  uint uVar10;

  int iVar11;

  void **ppvStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  int iStack_54;

  void *pvStack_50;

  int iStack_4c;

  void *pvStack_48;

  int iVar12;

  void *pvStack_34;

  int iStack_20;

  int iStack_18;

  int iStack_14;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a52e8;

  pvStack_c = ExceptionList;

  pvStack_48 = (void *)0x1;

  pvStack_50 = (void *)0x57b37d;

  ExceptionList = &pvStack_c;

  iStack_4c = param_1;

  (**(code **)(*param_2 + 0x14))();

  pvStack_50 = (void *)0x1;

  iStack_54 = param_1 + 1;

  uStack_58 = 0x57b38b;

  (**(code **)(*param_2 + 0x14))();

  uStack_58 = 4;

  ppvStack_5c = &pvStack_c;

  pvStack_c = (void *)0x0;

  (**(code **)(*param_2 + 0x14))();

  if (iStack_14 < 1) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  }

  else {

    FUN_007a69d0();

    pvVar4 = operator_new__(iStack_14 + 1);

    *(void **)(param_1 + 4) = pvVar4;

    (**(code **)(*param_2 + 0x14))(pvVar4);

    *(uint8_t *)(iStack_14 + *(int *)(param_1 + 4)) = 0;

    iVar5 = FUN_007a6880();

    if (iVar5 != 0) {

      pcVar6 = (char *)FUN_007a6de0(*(uint32_t /* width from decompiler */ *)(param_1 + 4));

      operator_delete__(*(void **)(param_1 + 4));

      pcVar7 = pcVar6;

      do {

        cVar1 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar1 != '\0');

      pcVar7 = pcVar7 + (1 - (int)(pcVar6 + 1));

      pcVar8 = operator_new__((uint)pcVar7);

      *(char **)(param_1 + 4) = pcVar8;

      for (uVar10 = (uint)pcVar7 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar6;

        pcVar6 = pcVar6 + 4;

        pcVar8 = pcVar8 + 4;

      }

      for (uVar10 = (uint)pcVar7 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {

        *pcVar8 = *pcVar6;

        pcVar6 = pcVar6 + 1;

        pcVar8 = pcVar8 + 1;

      }

    }

  }

  (**(code **)(*param_2 + 0x14))(&stack0xffffffbc);

  FUN_005801e0(0,0);

  FUN_00580610(iStack_4c);

  iVar5 = 0;

  if (0 < iStack_4c) {

    do {

      pvVar4 = operator_new(0xc);

      pvStack_48 = pvVar4;

      if (iStack_18 < 0xe) {

        (**(code **)(*param_2 + 0x14))(pvVar4,8);

        *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 8) = 0;

      }

      else {

        (**(code **)(*param_2 + 0x14))(pvVar4,0xc);

      }

      iVar11 = *(int *)(param_1 + 0xc);

      if ((iVar11 == 0) ||

         ((uint)(*(int *)(param_1 + 0x14) - iVar11 >> 2) <=

          (uint)(*(int *)(param_1 + 0x10) - iVar11 >> 2))) {

        FUN_0057fd40(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),1,&pvStack_48);

      }

      else {

        puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10);

        *puVar2 = pvVar4;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x10) = puVar2 + 1;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < iStack_4c);

  }

  iVar11 = 4;

  (**(code **)(*param_2 + 0x14))(&stack0xffffffc0);

  FUN_005801e0(0,0);

  FUN_00580610(pvStack_48);

  iVar5 = 0;

  if (0 < (int)pvStack_48) {

    do {

      pvVar4 = operator_new(0x20);

      if (pvVar4 == (void *)0x0) {

        pvVar4 = (void *)0x0;

      }

      else {

        *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x10) = 0;

        *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x14) = 0;

        *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x18) = 0;

      }

      (**(code **)(*param_2 + 0x14))(pvVar4,8);

      (**(code **)(*param_2 + 0x14))(&stack0xffffffa0,4);

      if (iVar11 < 1) {

        *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 8) = 0;

      }

      else {

        pvVar9 = operator_new__(iVar11 + 1);

        *(void **)((int)pvVar4 + 8) = pvVar9;

        (**(code **)(*param_2 + 0x14))(pvVar9,iVar11);

        *(uint8_t *)(iVar11 + *(int *)((int)pvVar4 + 8)) = 0;

      }

      (**(code **)(*param_2 + 0x14))(&ppvStack_5c,4);

      FUN_00580610(iStack_4c);

      iVar12 = 0;

      if (0 < iStack_4c) {

        do {

          pvVar9 = operator_new(0xc);

          pvStack_50 = pvVar9;

          if (iStack_20 < 0xe) {

            (**(code **)(*param_2 + 0x14))(pvVar9,8);

            *(uint32_t /* width from decompiler */ *)((int)pvVar9 + 8) = 0;

          }

          else {

            (**(code **)(*param_2 + 0x14))(pvVar9,0xc);

          }

          iVar3 = *(int *)((int)pvVar4 + 0x10);

          if ((iVar3 == 0) ||

             ((uint)(*(int *)((int)pvVar4 + 0x18) - iVar3 >> 2) <=

              (uint)(*(int *)((int)pvVar4 + 0x14) - iVar3 >> 2))) {

            FUN_0057fd40(*(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x14),1,&pvStack_50);

          }

          else {

            puVar2 = *(uint32_t /* width from decompiler */ **)((int)pvVar4 + 0x14);

            *puVar2 = pvVar9;

            *(uint32_t /* width from decompiler */ **)((int)pvVar4 + 0x14) = puVar2 + 1;

          }

          iVar12 = iVar12 + 1;

        } while (iVar12 < iStack_4c);

      }

      iVar12 = *(int *)(param_1 + 0x1c);

      if ((iVar12 == 0) ||

         ((uint)(*(int *)(param_1 + 0x24) - iVar12 >> 2) <=

          (uint)(*(int *)(param_1 + 0x20) - iVar12 >> 2))) {

        FUN_0057fd40(*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),1,&stack0xffffffc8);

      }

      else {

        puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x20);

        *puVar2 = pvVar4;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = puVar2 + 1;

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < (int)pvStack_48);

  }

  ExceptionList = pvStack_34;

  return;

}
