# Annotated low-level: Client_UpdateMissionJournal

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ae130` |
| **VA** | `0x008ae130` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_008ae130_Client_UpdateMissionJournal.md` |
| **Refine** | Human pass 2026-07-23 (named_hl keyword wave); residual dual 2026-07-29 |

This file is the **annotated** layer: packet/UI offsets, branch order, and decompiler corrections.

---

## 1. Purpose

Refresh mission journal UI when dialog state==3. Walks `char+0x50c` tree, partitions ids into Active vs New vectors via `char+0x540` hash, builds panels. UI only.

## 2. Corrected signature

```c
void __thiscall Client_UpdateMissionJournal(void *this, int *pContext);
// dialog context primarily EBX; gate: [0x192]==3 (+0x648)
```

## 3. Key offsets / packet fields

| Offset / symbol | Role |
|---|---|
| `ctx+0x648 / [0x192]` | dialog view state; 3 = journal |
| `char+0x50c` | mission tree header (walk source; end iterator) |
| `char+0x540` | mission instance hash (partition probe) |
| hash node `+0x8` | live payload; null → New bucket (Probable name) |
| tree node `+0x10` | mission id |
| `ctx+0x6e0` | dialog UI host (plate) |
| `ctx [0x1ca..0x1cd]` | child widget vector (New entries) |
| control id base `0x9c4f` | sequential journal entry widget ids |

## 4. Machine-level notes

- Bail unless unaff_EBX[0x192]==3 and DAT_00d1b6d8 set.
- Walk tree at char+0x50c; id @ node+0x10; hash probe +0x540.
- **Partition (assembly-sealed):** hash hit ∧ `[node+0x8]!=0` → Active vector; else New.
- **`CVOGReaction_FailMissionNotify`:** Vector_PushDword only at this site (not fail).
- **`FUN_00568200`:** tree iterator++ (`LEA ECX,[ESP+0x14]`); **not** id collection.
- Build `"Active Missions:"` / `"New Missions:"` panels; entries via `FUN_00829ec0` (`i_d_npc_2d_btn_mselect.xml`, size 0x510).
- Widget ids: Active `i+0x9c4f`; New `activeCount+0x9c4f+i`.
- Cleanup temporary id arrays on exit.

## 4.1 Residual dual (2026-07-29)

See `reviews/A_aa_008ae130_*`, `reviews/B_aa_008ae130_*`, scratch `tmp/a_008ae130.md`.

## 5. Pseudocode (authoritative raw, retained)

```c
/* Client_UpdateMissionJournal

   

   Refreshes the mission journal UI when the dialog state is 3 (mission journal view).

   Creates "Active Missions:" and "New Missions:" panels with mission entry components.

   

   Algorithm:

   1. Bail if EBX+0x648 != 3 (not in journal view) or DAT_00d1b6d8 is null

   2. Initialize client state and show mission journal header

   3. Iterate active missions list (DAT_00d1b6d8+0x50c):

      a. For each, call FailMissionNotify on the mission ID

      b. Track mission IDs in array

   4. If active missions exist: create "Active Missions:" UI panel

      a. For each active mission ID, create mission entry component

   5. If new missions exist: create "New Missions:" UI panel

      a. For each new mission ID, lookup mission hash, create entry

   6. Cleanup and free temporary arrays

   

   Parameters:

     pContext (EBX) - Context with state at +0x648, dialog UI at +0x6e0 */



void __thiscall Client_UpdateMissionJournal(void *this,int *pContext)



{

  uint uVar1;

  undefined3 uVar2;

  undefined4 *puVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int *unaff_EBX;

  int *piVar7;

  char *pcVar8;

  undefined4 uVar9;

  int local_cc;

  int *local_c8 [2];

  int *piStack_c0;

  int iStack_bc;

  void *local_b4;

  int local_b0;

  undefined4 local_ac;

  void *local_a4;

  int local_a0 [4];

  undefined1 *local_90;

  undefined1 local_8c [128];

  void *local_c;

  undefined1 *puStack_8;

  undefined4 local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb948;

  local_c = ExceptionList;

                    /* // Bail if not in journal view (state != 3) */

  if ((unaff_EBX[0x192] == 3) && (DAT_00d1b6d8 != 0)) {

    ExceptionList = &local_c;

                    /* // Initialize client state for journal */

    FUN_007a69d0();

    unaff_EBX[0x144] = 0;

    FUN_008ac110();

    iVar5 = unaff_EBX[0x191];

    if ((iVar5 == 0) ||

       ((*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) == 0 ||

        (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) +

                 0x518) == 0)))) {

      FUN_008aaf60();

    }

    else {

      puVar3 = (undefined4 *)

               FUN_00402d50(*(undefined4 *)

                             (*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) +

                                      0x3c) + 0x518));

      local_4 = 0;

      FUN_007a6de0(*puVar3,0xffffffff);

      FUN_008aaf60();

      local_4 = 0xffffffff;

      if (local_90 != local_8c) {

        free(local_90);

      }

    }

    local_cc = 0;

    if ((int *)unaff_EBX[0x1b8] != (int *)0x0) {

      (**(code **)(*(int *)unaff_EBX[0x1b8] + 0x120))(local_c8,1,0);

      (**(code **)(*(int *)unaff_EBX[0x1b8] + 0x204))(&local_cc);

      local_cc = local_cc + (int)((float)DAT_00d1e81c * DAT_00aaa9ec) + iStack_bc;

    }

    local_b4 = (void *)0x0;

    local_b0 = 0;

    local_ac = 0;

    local_a4 = (void *)0x0;

    local_a0[0] = 0;

    local_a0[1] = 0;

    local_4._1_3_ = 0;

    uVar2 = local_4._1_3_;

    local_4._0_1_ = 2;

    local_4._1_3_ = 0;

                    /* // Iterate active missions (DAT_00d1b6d8+0x50c) */

    local_c8[0] = (int *)**(int **)(DAT_00d1b6d8 + 0x50c);

    if (local_c8[0] != *(int **)(DAT_00d1b6d8 + 0x50c)) {

      do {

        for (iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 0x540) + 0x10) +

                                      (*(uint *)(*(int *)(DAT_00d1b6d8 + 0x540) + 8) &

                                      local_c8[0][4]) * 4) + 4);

            (iVar5 != 0 && (local_c8[0][4] != *(uint *)(iVar5 + 0x10)));

            iVar5 = *(int *)(iVar5 + 0xc)) {

        }

                    /* // Call FailMissionNotify for each active mission */

        CVOGReaction_FailMissionNotify(local_c8[0] + 4);

        FUN_00568200();

      } while (local_c8[0] != *(int **)(DAT_00d1b6d8 + 0x50c));

                    /* // Create "Active Missions:" UI panel */

      if ((local_b4 != (void *)0x0) &&

         (piVar7 = (int *)(local_b0 - (int)local_b4 >> 2), piStack_c0 = piVar7, piVar7 != (int *)0x0

         )) {

        local_c8[0] = operator_new(0x510);

        local_4._0_1_ = 3;

        if (local_c8[0] == (int *)0x0) {

          piVar4 = (int *)0x0;

        }

        else {

          piVar4 = (int *)FUN_00829ec0(local_c8[0]);

        }

        local_4._0_1_ = 2;

        local_c8[0] = piVar4;

        (**(code **)(*unaff_EBX + 0xa8))(piVar4);

        *(undefined1 *)(piVar4 + 0x13f) = 1;

        (**(code **)(*piVar4 + 0x43c))();

        if (piVar4[0x142] != 0) {

                    /* // Set panel title "Active Missions:" */

          iVar5 = *(int *)piVar4[0x142];

          uVar9 = 0xffffffff;

          pcVar8 = "Active Missions:";

          FUN_007a69d0("Active Missions:",0xffffffff,1,1);

          uVar9 = FUN_007a6de0(pcVar8,uVar9);

          (**(code **)(iVar5 + 0x1d8))(uVar9);

        }

        (**(code **)(*piVar4 + 0x114))(&stack0xffffff2c);

        iVar5 = (**(code **)(*piVar4 + 0x140))(local_a0,1);

        local_cc = local_cc + *(int *)(iVar5 + 4);

        FUN_00411180();

                    /* // For each active mission ID, create mission entry */

        for (iVar5 = 0; iVar5 < (int)piVar7; iVar5 = iVar5 + 1) {

          puVar3 = (undefined4 *)FUN_0053fff0();

          CNDHash_LookupByKey((void *)*puVar3,*(uint *)((int)local_b4 + iVar5 * 4));

          FUN_00547920(0);

          local_c8[0] = operator_new(0x510);

          local_4._0_1_ = 4;

          if (local_c8[0] == (int *)0x0) {

            piVar7 = (int *)0x0;

          }

          else {

            piVar7 = (int *)FUN_00829ec0(local_c8[0]);

          }

          local_4._0_1_ = 2;

          local_c8[0] = piVar7;

          (**(code **)(*piVar7 + 0x74))(iVar5 + 0x9c4f);

          (**(code **)(*unaff_EBX + 0xa8))(piVar7);

          (**(code **)(*piVar7 + 0x43c))();

          FUN_00829b20();

          (**(code **)(*piVar7 + 0x114))(&stack0xffffff28);

          iVar6 = (**(code **)(*piVar7 + 0x140))(&local_a4,1);

          local_cc = local_cc + *(int *)(iVar6 + 4);

          FUN_00411180();

          piVar7 = piStack_c0;

        }

        local_cc = local_cc + (int)((float)DAT_00d1e81c * DAT_00aaa9ec);

      }

                    /* // Create "New Missions:" UI panel */

      iVar5 = 0;

      uVar2 = local_4._1_3_;

      if ((local_a4 != (void *)0x0) &&

         (local_c8[0] = (int *)(local_a0[0] - (int)local_a4 >> 2), local_c8[0] != (int *)0x0)) {

        piStack_c0 = operator_new(0x510);

        local_4._0_1_ = 5;

        if (piStack_c0 == (int *)0x0) {

          piVar7 = (int *)0x0;

        }

        else {

          piVar7 = (int *)FUN_00829ec0(piStack_c0);

        }

        local_4._0_1_ = 2;

        piStack_c0 = piVar7;

        (**(code **)(*unaff_EBX + 0xa8))(piVar7);

        *(undefined1 *)(piVar7 + 0x13f) = 1;

        (**(code **)(*piVar7 + 0x43c))();

        if (piVar7[0x142] != 0) {

                    /* // Set panel title "New Missions:" */

          iVar6 = *(int *)piVar7[0x142];

          uVar9 = 0xffffffff;

          pcVar8 = "New Missions:";

          FUN_007a69d0("New Missions:",0xffffffff,1,1);

          uVar9 = FUN_007a6de0(pcVar8,uVar9);

          (**(code **)(iVar6 + 0x1d8))(uVar9);

        }

        (**(code **)(*piVar7 + 0x114))(&stack0xffffff2c);

        iVar6 = (**(code **)(*piVar7 + 0x140))(local_a0,1);

        local_cc = local_cc + *(int *)(iVar6 + 4);

        FUN_00411180();

                    /* // For each new mission ID, lookup hash and create entry */

        while (uVar2 = local_4._1_3_, iVar5 < (int)local_c8[0]) {

          piVar7 = (int *)FUN_0053fff0();

          uVar1 = *(uint *)((int)local_a4 + iVar5 * 4);

          for (iVar6 = *(int *)(*(int *)(*(int *)(*piVar7 + 0x10) +

                                        (*(uint *)(*piVar7 + 8) & uVar1) * 4) + 4);

              (iVar6 != 0 && (uVar1 != *(uint *)(iVar6 + 0x10))); iVar6 = *(int *)(iVar6 + 0xc)) {

          }

          FUN_00547920(0);

          piStack_c0 = operator_new(0x510);

          local_4._0_1_ = 6;

          if (piStack_c0 == (int *)0x0) {

            piVar7 = (int *)0x0;

          }

          else {

            piVar7 = (int *)FUN_00829ec0(piStack_c0);

          }

          local_4._0_1_ = 2;

          if (local_b4 == (void *)0x0) {

            iVar6 = 0;

          }

          else {

            iVar6 = local_b0 - (int)local_b4 >> 2;

          }

          piStack_c0 = piVar7;

          (**(code **)(*piVar7 + 0x74))(iVar6 + 0x9c4f + iVar5);

          (**(code **)(*unaff_EBX + 0xa8))(piVar7);

          (**(code **)(*piVar7 + 0x43c))();

          FUN_00829b20();

          (**(code **)(*piVar7 + 0x114))(&stack0xffffff28);

          iVar6 = (**(code **)(*piVar7 + 0x140))(&local_a4,1);

          local_cc = local_cc + *(int *)(iVar6 + 4);

          iVar6 = unaff_EBX[0x1cb];

          if ((iVar6 == 0) ||

             ((uint)(unaff_EBX[0x1cd] - iVar6 >> 2) <= (uint)(unaff_EBX[0x1cc] - iVar6 >> 2))) {

            FUN_00419880(unaff_EBX + 0x1ca,unaff_EBX[0x1cc],&piStack_c0);

            iVar5 = iVar5 + 1;

          }

          else {

            puVar3 = (undefined4 *)unaff_EBX[0x1cc];

            *puVar3 = piVar7;

            unaff_EBX[0x1cc] = (int)(puVar3 + 1);

            iVar5 = iVar5 + 1;

          }

        }

      }

    }

                    /* // Cleanup and free temporary arrays */

    local_4._1_3_ = uVar2;

    local_4 = CONCAT31(local_4._1_3_,1);

    if (local_a4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_a4);

    }

    local_a4 = (void *)0x0;

    local_a0[0] = 0;

    local_a0[1] = 0;

    local_4 = 0xffffffff;

    if (local_b4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_b4);

    }

  }

  ExceptionList = local_c;

  return;

}
```

## 6. Open questions

- Confirm new-missions source list offset on character.
