// =============================================================================
// Inventory_LogMissingItemAfterRandomize
// -----------------------------------------------------------------------------
// Purpose:  Debug error when cargo/locker item missing after inventory randomization.
//
// Address:  0x0093bf60  (autoassault.exe, image base 0x400000)
// Stable:   aa_0093bf60
// System:   inventory-transfer
//
// String evidence: "not found in inventory after randomization" (cargo/locker)
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_0093bf60.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_0093bf60 using string evidence: "not found in inventory after randomization" (cargo/locker)
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void Inventory_LogMissingItemAfterRandomize(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ *param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

                 uint32_t /* width from decompiler */ *param_9,uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ *param_12)

{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  bool bVar5;

  uint uVar6;

  void **ppvVar7;

  int iVar8;

  int iVar9;

  uint32_t /* width from decompiler */ uVar10;

  char acStack_10c [256];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bad33;

  local_4 = 3;

  ppvVar7 = &pvStack_c;

  pvStack_c = ExceptionList;

  for (puVar1 = (uint32_t /* width from decompiler */ *)*param_3; ExceptionList = ppvVar7, puVar1 != param_3;

      puVar1 = (uint32_t /* width from decompiler */ *)*puVar1) {

    piVar2 = (int *)puVar1[2];

    if (piVar2 != (int *)0x0) {

      puVar3 = (uint32_t /* width from decompiler */ *)*param_9;

      bVar5 = false;

      while ((puVar3 != param_9 && (!bVar5))) {

        piVar4 = (int *)puVar3[2];

        if (piVar4 != (int *)0x0) {

          if ((piVar4[0x58] == piVar2[0x58]) && (piVar4[0x59] == piVar2[0x59])) {

            iVar8 = (**(code **)(*piVar4 + 0x25c))();

            iVar9 = (**(code **)(*piVar2 + 0x25c))();

            if (iVar8 == iVar9) {

              bVar5 = true;

            }

          }

        }

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

      }

      for (puVar3 = (uint32_t /* width from decompiler */ *)*param_12; puVar3 != param_12; puVar3 = (uint32_t /* width from decompiler */ *)*puVar3) {

        if (bVar5) goto LAB_0093c0cf;

        piVar4 = (int *)puVar3[2];

        if (piVar4 != (int *)0x0) {

          if ((piVar4[0x58] == piVar2[0x58]) && (piVar4[0x59] == piVar2[0x59])) {

            iVar8 = (**(code **)(*piVar4 + 0x25c))();

            iVar9 = (**(code **)(*piVar2 + 0x25c))();

            if (iVar8 == iVar9) {

              bVar5 = true;

            }

          }

        }

      }

      if (!bVar5) {

        iVar8 = piVar2[0x58];

        iVar9 = piVar2[0x59];

        uVar10 = (**(code **)(*piVar2 + 0x25c))();

        sprintf(acStack_10c,

                "Item that was in cargo with coid: %I64d \nwith quantity: %d \nnot found in inventory after randomization"

                ,iVar8,iVar9,uVar10);

        FUN_00800af0(param_1,0x223d,0,acStack_10c,&DAT_00afdf0c);

      }

    }

LAB_0093c0cf:

    ppvVar7 = ExceptionList;

  }

  puVar1 = (uint32_t /* width from decompiler */ *)*param_6;

  do {

    if (puVar1 == param_6) {

      uVar6 = (uint)local_4 >> 8;

      local_4 = CONCAT31((int3)uVar6,2);

      puVar1 = (uint32_t /* width from decompiler */ *)*param_3;

      *param_3 = param_3;

      param_3[1] = param_3;

      if (puVar1 == param_3) {

                    /* WARNING: Subroutine does not return */

        operator_delete(param_3);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(puVar1);

    }

    piVar2 = (int *)puVar1[2];

    if (piVar2 != (int *)0x0) {

      puVar3 = (uint32_t /* width from decompiler */ *)*param_9;

      bVar5 = false;

      while ((puVar3 != param_9 && (!bVar5))) {

        piVar4 = (int *)puVar3[2];

        if (piVar4 != (int *)0x0) {

          if ((piVar4[0x58] == piVar2[0x58]) && (piVar4[0x59] == piVar2[0x59])) {

            iVar8 = (**(code **)(*piVar4 + 0x25c))();

            iVar9 = (**(code **)(*piVar2 + 0x25c))();

            if (iVar8 == iVar9) {

              bVar5 = true;

            }

          }

        }

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

      }

      for (puVar3 = (uint32_t /* width from decompiler */ *)*param_12; puVar3 != param_12; puVar3 = (uint32_t /* width from decompiler */ *)*puVar3) {

        if (bVar5) goto LAB_0093c234;

        piVar4 = (int *)puVar3[2];

        if (piVar4 != (int *)0x0) {

          if ((piVar4[0x58] == piVar2[0x58]) && (piVar4[0x59] == piVar2[0x59])) {

            iVar8 = (**(code **)(*piVar4 + 0x25c))();

            iVar9 = (**(code **)(*piVar2 + 0x25c))();

            if (iVar8 == iVar9) {

              bVar5 = true;

            }

          }

        }

      }

      if (!bVar5) {

        uVar10 = (**(code **)(*piVar2 + 0x25c))();

        sprintf(acStack_10c,

                "Item that was in locker with coid: %I64d \nwith quantity: %d \nnot found in inventory after randomization"

                ,&LAB_00401c20,uVar10);

        FUN_00800af0(param_1,0x223d,0,acStack_10c,&DAT_00afdf0c);

      }

    }

LAB_0093c234:

    puVar1 = (uint32_t /* width from decompiler */ *)*puVar1;

  } while( true );

}
