// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005b6320
// -----------------------------------------------------------------------------
// Stable ID: aa_005b6320
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x005b6320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "NDTree.fx". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "NDTree.fx"
//   - "DiffuseTexture"
//   - "DarkTexture"
//   - "WindMatrices"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~208 non-empty decompiler lines.
//  - Control keywords: if×21, return×3, do×2, while×2, for×2, goto×1.
//  - Notable callees: FUN_0068a4d0×3, FUN_00970140×2, CONCAT31, FUN_004148e0, FUN_00414bc0, FUN_00414c20, FUN_0044b9c0, FUN_005b4bc0.
//  - Strings: "NDTree.fx"; "DiffuseTexture"; "DarkTexture"; "WindMatrices".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005b6320(int param_1,uint param_2)



{

  int *piVar1;

  uint *puVar2;

  ushort uVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint uVar9;

  void *pvVar10;

  int iVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint uVar13;

  int iVar14;

  uint32_t /* width from decompiler */ *puVar15;

  void *local_34;

  int local_30;

  uint8_t auStack_2c [12];

  void *pvStack_20;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pvVar10 = ExceptionList;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a69b1;

  local_c = ExceptionList;

  iVar11 = *(int *)(param_1 + 0x50);

  uVar3 = *(ushort *)(iVar11 + 0x4c);

  iVar14 = iVar11 + 0x3c;

  ExceptionList = &local_c;

  *(uint *)(param_1 + 0x68) = (uint)uVar3;

  if (uVar3 < 2) {

    ExceptionList = pvVar10;

    return;

  }

  local_30 = iVar14;

  local_34 = operator_new(0xdc);

  local_4 = 0;

  if (local_34 == (void *)0x0) {

    uVar8 = 0;

  }

  else {

    uVar8 = FUN_005b4bc0();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = uVar8;

  local_4 = 0xffffffff;

  uVar8 = (**(code **)(**(int **)(param_1 + 8) + 0xc))();

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 100) = uVar8;

  iVar4 = **(int **)(param_1 + 0x10);

  uVar8 = (**(code **)(**(int **)(param_1 + 8) + 100))();

  (**(code **)(iVar4 + 0x34))(uVar8);

  FUN_0096f530();

  local_4 = 1;

  FUN_00989e00(&local_34,"NDTree.fx");

  FUN_009701d0(&local_34);

  FUN_00970140("DiffuseTexture",**(uint32_t /* width from decompiler */ **)(param_1 + 0x24));

  if (DAT_00b05348 != (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00970140("DarkTexture",*DAT_00b05348);

  }

  FUN_004148e0(auStack_2c);

  iVar4 = *(int *)(param_1 + 0x10);

  *(uint *)(iVar4 + 0xbc) = *(uint *)(iVar4 + 0xbc) | 1;

  iVar5 = *(int *)(param_1 + 0x10);

  uVar9 = FUN_00685c90();

  local_34 = (void *)(uVar9 & 0xffff);

  if ((char)param_2 == '\0') {

    pvVar10 = operator_new__((int)local_34 * 2);

    uVar9 = 0;

    *(void **)(param_1 + 0x70) = pvVar10;

    if (local_34 != (void *)0x0) {

      pvVar10 = (void *)0x0;

      do {

        FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),2,0xffffffff,uVar9,0xffffffff);

        if (*(short *)(iVar11 + 0x40) == 0) {

          *(uint16_t *)(*(int *)(param_1 + 0x70) + (int)pvVar10 * 2) = 0;

        }

        else {

          *(uint16_t *)(*(int *)(param_1 + 0x70) + (int)pvVar10 * 2) =

               **(uint16_t **)(iVar11 + 0x44);

        }

        uVar9 = uVar9 + 1;

        pvVar10 = (void *)(uVar9 & 0xffff);

      } while (pvVar10 < local_34);

    }

  }

  if (*(int *)(*(int *)(param_1 + 0x174) + 0x128) == 0) {

    uVar8 = FUN_00414bc0(DAT_00af3ef4);

    local_4._0_1_ = 2;

    FUN_00414c20(*(uint32_t /* width from decompiler */ *)(param_1 + 0x68),uVar8,0x22,0);

    local_4 = CONCAT31(local_4._1_3_,1);

    uStack_14 = 0;

    uStack_10 = 0;

    if (pvStack_20 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvStack_20);

    }

    iVar11 = *(int *)(iVar4 + 0x14);

    if (*(int *)(iVar11 + 0x10) == 0) {

      iVar11 = 0;

    }

    else {

      iVar11 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar11 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar11 + 0x18),0);

    }

    uVar9 = 0;

    if ((iVar11 != 0) && (param_2 = 0, *(int *)(param_1 + 0x68) != 0)) {

      puVar12 = (uint32_t /* width from decompiler */ *)(iVar11 + 0x18);

      do {

        puVar15 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar14 + 0x24) + uVar9 * 0xc);

        puVar12[-6] = *puVar15;

        puVar12[-5] = puVar15[1];

        puVar12[-4] = puVar15[2];

        puVar15 = (uint32_t /* width from decompiler */ *)(*(int *)(local_30 + 0x18) + uVar9 * 0xc);

        puVar12[-3] = *puVar15;

        puVar12[-2] = puVar15[1];

        puVar12[-1] = puVar15[2];

        *puVar12 = *(uint32_t /* width from decompiler */ *)(*(int *)(local_30 + 0x28) + uVar9 * 8);

        puVar12[1] = *(uint32_t /* width from decompiler */ *)(*(int *)(local_30 + 0x28) + 4 + uVar9 * 8);

        puVar12[2] = (float)*(byte *)(*(int *)(local_30 + 0x34) + uVar9);

        puVar12[3] = *(uint32_t /* width from decompiler */ *)(*(int *)(local_30 + 0x30) + uVar9 * 4);

        param_2 = param_2 + 1;

        uVar9 = param_2 & 0xffff;

        puVar12 = puVar12 + 10;

        iVar14 = local_30;

      } while (uVar9 < *(uint *)(param_1 + 0x68));

    }

    if (*(int *)(*(int *)(iVar4 + 0x14) + 0x10) != 0) {

      FUN_007464e0();

    }

    FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),2,0xffffffff,0,0xffffffff);

    iVar11 = FUN_0044b9c0(**(uint16_t **)(param_1 + 0x70),0x22,0,0);

    if (iVar11 < 0) goto LAB_005b6778;

    iVar11 = *(int *)(iVar5 + 0xc);

    if ((*(int *)(iVar11 + 0x10) != 0) &&

       (puVar12 = (uint32_t /* width from decompiler */ *)

                  FUN_00743be0(*(uint32_t /* width from decompiler */ *)(iVar11 + 0x18),*(uint32_t /* width from decompiler */ *)(iVar11 + 0x1c),0x800),

       puVar12 != (uint32_t /* width from decompiler */ *)0x0)) {

      uVar9 = (uint)**(ushort **)(iVar14 + 8) * 2;

      puVar15 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(iVar14 + 0xc);

      for (uVar13 = uVar9 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {

        *puVar12 = *puVar15;

        puVar15 = puVar15 + 1;

        puVar12 = puVar12 + 1;

      }

      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

        *(uint8_t *)puVar12 = *(uint8_t *)puVar15;

        puVar15 = (uint32_t /* width from decompiler */ *)((int)puVar15 + 1);

        puVar12 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);

      }

    }

    if (*(int *)(*(int *)(iVar5 + 0xc) + 0x10) != 0) {

      FUN_00743ba0();

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x174) + 0x10c) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x14);

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x174) + 0x110) = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc);

  }

  else {

    piVar6 = *(int **)(*(int *)(param_1 + 0x174) + 0x10c);

    if ((piVar6 != (int *)0x0) && (piVar6[1] = piVar6[1] + 1, piVar6[1] == 1)) {

      (**(code **)(*piVar6 + 4))();

    }

    piVar7 = *(int **)(iVar4 + 0x14);

    if (piVar7 != (int *)0x0) {

      piVar1 = piVar7 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar7 + 8))();

      }

    }

    *(int **)(iVar4 + 0x14) = piVar6;

    piVar6 = *(int **)(*(int *)(param_1 + 0x174) + 0x110);

    if ((piVar6 != (int *)0x0) && (piVar6[1] = piVar6[1] + 1, piVar6[1] == 1)) {

      (**(code **)(*piVar6 + 4))();

    }

    piVar7 = *(int **)(iVar5 + 0xc);

    if (piVar7 != (int *)0x0) {

      piVar1 = piVar7 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar7 + 8))();

      }

    }

    *(int **)(iVar5 + 0xc) = piVar6;

    FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),2,0xffffffff,0,0xffffffff);

  }

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 0xac) = 5;

  *(uint *)(*(int *)(param_1 + 0x10) + 0xa8) = **(ushort **)(iVar14 + 8) - 2;

  FUN_0096f740();

  puVar2 = (uint *)(*(int *)(param_1 + 0x10) + 0xbc);

  *puVar2 = *puVar2 & 0xfffffffe;

  FUN_007647c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

  if (*(int *)(*(int *)(param_1 + 0x10) + 0x20) == 0) {

    param_2 = 0xffffffff;

    puVar12 = &param_2;

  }

  else {

    puVar12 = (uint32_t /* width from decompiler */ *)FUN_00752370(&param_2,"WindMatrices");

  }

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 0xd0) = *puVar12;

LAB_005b6778:

  local_4 = 0xffffffff;

  FUN_0096f510();

  ExceptionList = local_c;

  return;

}
