// =============================================================================
// VehicleNet_PostCorrectionEvent
// -----------------------------------------------------------------------------
// Stable ID: aa_005f7360
// Address:   0x005f7360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void __thiscall
VehicleNet_PostCorrectionEvent
          (int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  void *pvVar4;
  uint32_t /* width from decompiler */ uVar5;
  int iVar6;
  uint32_t /* width from decompiler */ *puVar7;
  void *pvVar8;
  uint32_t /* width from decompiler */ *puVar9;
  int iVar10;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a7b81;
  pvStack_c = ExceptionList;
  iVar10 = 0;
  ExceptionList = &pvStack_c;
  if (*(int *)(param_1 + 0x50) != 0) {
    ExceptionList = &pvStack_c;
    iVar6 = (**(code **)(**(int **)(param_1 + 0x50) + 0x1d4))();
    pvVar4 = param_2;
    fVar3 = g_flOne;
    if (*(char *)(iVar6 + 0x103) == '\0') {
      if (param_2 != (void *)0x0) {
        *(uint32_t /* width from decompiler */ *)((int)param_2 + 0xd0) = 0xffffffff;
        *(uint32_t /* width from decompiler */ *)((int)param_2 + 0x84) = 1;
        *(uint8_t *)((int)param_2 + 0xa0) = 1;
        *(float *)((int)param_2 + 0x80) = fVar3;
        *(uint32_t /* width from decompiler */ *)((int)param_2 + 8) = 0xffffffff;
        *(uint32_t /* width from decompiler */ *)((int)param_2 + 0xc) = 0xffffffff;
        *(uint32_t /* width from decompiler */ *)((int)param_2 + 0x28) = 0xffffffff;
        *(uint32_t /* width from decompiler */ *)((int)param_2 + 0x2c) = 0xffffffff;
        *(uint32_t /* width from decompiler */ *)((int)param_2 + 0x30) = 0xffffffff;
        *(uint32_t /* width from decompiler */ *)((int)param_2 + 0x34) = 0xffffffff;
        *(uint32_t /* width from decompiler */ *)((int)param_2 + 0x38) = 0xffffffff;
        puVar7 = operator_new(0x18);
        if (puVar7 == (uint32_t /* width from decompiler */ *)0x0) {
          puVar7 = (uint32_t /* width from decompiler */ *)0x0;
        }
        else {
          puVar7[2] = 0;
        }
        *puVar7 = 0xffffffff;
        puVar7[1] = 0;
        param_2 = puVar7;
        pvVar8 = operator_new(0x18);
        uStack_4 = 0;
        if (pvVar8 != (void *)0x0) {
          iVar10 = FUN_00424ce0(0,0);
        }
        piVar2 = (int *)puVar7[2];
        uStack_4 = 0xffffffff;
        if (piVar2 != (int *)0x0) {
          piVar1 = piVar2 + 2;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar2 + 8))();
          }
        }
        uVar5 = param_4;
        puVar7[2] = iVar10;
        if (iVar10 != 0) {
          *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;
        }
        FUN_005a2120(pvVar4,param_4,1);
        puVar7[3] = *(uint32_t /* width from decompiler */ *)(puVar7[2] + 0xc);
        puVar7[4] = uVar5;
        FUN_005b2d70(&param_2);
        puVar7 = malloc(0x40);
        *puVar7 = 0x203c;
        puVar7[2] = *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x90);
        puVar7[3] = *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x94);
        puVar7[4] = *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x98);
        puVar7[5] = *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x9c);
        iVar10 = *(int *)(param_1 + 0x50);
        puVar7[6] = *(uint32_t /* width from decompiler */ *)(iVar10 + 0x160);
        puVar7[7] = *(uint32_t /* width from decompiler */ *)(iVar10 + 0x164);
        puVar7[8] = *(uint32_t /* width from decompiler */ *)(iVar10 + 0x168);
        puVar7[9] = *(uint32_t /* width from decompiler */ *)(iVar10 + 0x16c);
        puVar7[10] = *param_3;
        puVar7[0xb] = param_3[1];
        *(uint8_t *)(puVar7 + 0xc) = *(uint8_t *)(param_3 + 2);
        *(uint8_t *)(puVar7 + 0xe) = 1;
        puVar9 = operator_new(0x18);
        iVar10 = 0;
        if (puVar9 == (uint32_t /* width from decompiler */ *)0x0) {
          puVar9 = (uint32_t /* width from decompiler */ *)0x0;
        }
        else {
          puVar9[2] = 0;
        }
        *puVar9 = 0xffffffff;
        puVar9[1] = 0;
        param_2 = puVar9;
        param_3 = operator_new(0x18);
        uStack_4 = 1;
        if (param_3 != (void *)0x0) {
          iVar10 = FUN_00424ce0(0,0);
        }
        piVar2 = (int *)puVar9[2];
        uStack_4 = 0xffffffff;
        if (piVar2 != (int *)0x0) {
          piVar1 = piVar2 + 2;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar2 + 8))();
          }
        }
        puVar9[2] = iVar10;
        if (iVar10 != 0) {
          *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;
        }
        iVar10 = puVar9[2];
        if (*(char *)(iVar10 + 0x14) != '\0') {
          *(uint8_t *)(iVar10 + 0x14) = 0;
          free(*(void **)(iVar10 + 0xc));
        }
        *(uint32_t /* width from decompiler */ **)(iVar10 + 0xc) = puVar7;
        *(uint32_t /* width from decompiler */ *)(iVar10 + 0x10) = 0x40;
        *(uint8_t *)(iVar10 + 0x14) = 1;
        puVar9[3] = *(uint32_t /* width from decompiler */ *)(puVar9[2] + 0xc);
        puVar9[4] = 0x40;
        FUN_005b2d70(&param_2);
        FUN_005a0b30(param_1,param_1 + 0x40);
        ExceptionList = pvStack_c;
        return;
      }
      puVar7 = malloc(0x30);
      *puVar7 = 0x203e;
      puVar7[2] = *param_3;
      puVar7[3] = param_3[1];
      puVar7[4] = param_3[2];
      puVar7[5] = param_3[3];
      iVar6 = *(int *)(param_1 + 0x50);
      puVar7[6] = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x160);
      puVar7[7] = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x164);
      puVar7[8] = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x168);
      puVar7[9] = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x16c);
      *(uint8_t *)((int)puVar7 + 0x2a) = 2;
      *(uint8_t *)(puVar7 + 10) = 0;
      *(uint8_t *)((int)puVar7 + 0x29) = 0;
      puVar9 = operator_new(0x18);
      if (puVar9 == (uint32_t /* width from decompiler */ *)0x0) {
        puVar9 = (uint32_t /* width from decompiler */ *)0x0;
      }
      else {
        puVar9[2] = 0;
      }
      *puVar9 = 0xffffffff;
      puVar9[1] = 0;
      param_3 = puVar9;
      param_2 = operator_new(0x18);
      uStack_4 = 2;
      if (param_2 != (void *)0x0) {
        iVar10 = FUN_00424ce0(0,0);
      }
      piVar2 = (int *)puVar9[2];
      uStack_4 = 0xffffffff;
      if (piVar2 != (int *)0x0) {
        piVar1 = piVar2 + 2;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar2 + 8))();
        }
      }
      puVar9[2] = iVar10;
      if (iVar10 != 0) {
        *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;
      }
      iVar10 = puVar9[2];
      if (*(char *)(iVar10 + 0x14) != '\0') {
        *(uint8_t *)(iVar10 + 0x14) = 0;
        free(*(void **)(iVar10 + 0xc));
      }
      *(uint32_t /* width from decompiler */ **)(iVar10 + 0xc) = puVar7;
      *(uint32_t /* width from decompiler */ *)(iVar10 + 0x10) = 0x30;
      *(uint8_t *)(iVar10 + 0x14) = 1;
      puVar9[3] = *(uint32_t /* width from decompiler */ *)(puVar9[2] + 0xc);
      puVar9[4] = 0x30;
      FUN_005b2d70(&param_3);
      FUN_005a0b30(param_1,param_1 + 0x40);
      ExceptionList = pvStack_c;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(param_2);
}
