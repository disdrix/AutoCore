// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×20, for×3, while×3, goto×2, return×2, do×1.
//  - Notable callees: FUN_00800af0×2, sprintf×2, CONCAT31, FUN_0093bf60.
//  - Return sites: 2.

// =============================================================================
// Inv_ValidateItemsAfterRandomization
// -----------------------------------------------------------------------------
// Purpose:  Post-randomization inventory integrity check: walks cargo and locker linked lists of item nodes and logs when a recorded coid/qty is missing from inventory after a randomize pass.
//
// Address:  0x0093bf60  (autoassault.exe, image base 0x400000)
// Stable:   aa_0093bf60
// System:   inventory-transfer
//
// Evidence strings (from raw decompile):
//   - "Item that was in cargo with coid: %I64d \nwith quantity: %d \nnot found in inventory after randomization"
//   - "Item that was in locker with coid: %I64d \nwith quantity: %d \nnot found in inventory after randomization"
//
// Notable callees:
//   - sprintf
//   - FUN_00800af0 (log/assert path)
//   - operator_delete
//
// Notes:    Multiple list-head pointer params (cargo/locker snapshots).
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

void Inv_ValidateItemsAfterRandomization(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4,

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
