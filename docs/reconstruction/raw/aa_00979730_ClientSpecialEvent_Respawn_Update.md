# Raw capture: ClientSpecialEvent_Respawn_Update

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979730` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00979730` |
| **Canonical name** | `ClientSpecialEvent_Respawn_Update` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* ClientSpecialEvent_Respawn_Update — per-frame INC airlift animation state machine.
   
   Source: ClientSpecialEvent_Respawn.cpp
   State byte at this+0x6d (phases 0..7):
     0 -> spawn airlift ship (cptest.geo), attach to vehicle
     mid phases: lift vehicle, CVOGReaction_TeleportTarget to dest at this+0x40
     later: lower ship, cleanup camera (FUN_0090dd50), destroy ship
   
   Dest pose stored on event object from SpecialEvent packet (pos/quat).
   TFID of controlled entity at this+0x28.. from vehicle/character clone offsets 0x164. */

undefined4 __thiscall ClientSpecialEvent_Respawn_Update(int param_1,float param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  int local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined1 auStack_30 [20];
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  iVar2 = DAT_00d09874;
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009b296a;
  local_1c = ExceptionList;
  local_40 = param_1;
  if (*(char *)(param_1 + 8) == '\0') {
    ExceptionList = &local_1c;
    *(float *)(param_1 + 0x60) = param_2 + *(float *)(param_1 + 0x60);
    (**(code **)(**(int **)(param_1 + 0x10) + 0x28))(*(undefined4 *)(iVar2 + 0x238));
    (**(code **)(**(int **)(*(int *)(param_1 + 0x10) + 8) + 0x34))();
    pvVar1 = (void *)FUN_004bb010(param_1 + 0x28);
    if (*(char *)(param_1 + 0x6c) != '\0') {
      iVar2 = (**(code **)(**(int **)(param_1 + 0x14) + 0xc))();
      fStack_3c = *(float *)(iVar2 + 0x90) - *(float *)(param_1 + 0x18);
      fStack_38 = *(float *)(iVar2 + 0x94) - *(float *)(param_1 + 0x1c);
      fStack_34 = *(float *)(iVar2 + 0x98) - *(float *)(param_1 + 0x20);
      if (pvVar1 != (void *)0x0) {
        puVar3 = (undefined4 *)FUN_004e9530(auStack_30,&fStack_3c);
        CVOGReaction_TeleportTarget(pvVar1,puVar3);
      }
    }
    fVar9 = *(float *)(param_1 + 100) + DAT_00aaa690;
    if ((fVar9 <= *(float *)(param_1 + 0x60)) && (*(char *)(param_1 + 0x6d) == '\x06')) {
      *(float *)(param_1 + 100) = fVar9;
      *(undefined1 *)(param_1 + 0x6d) = 7;
      ExceptionList = local_1c;
      return 1;
    }
    fVar8 = *(float *)(param_1 + 100) + g_flLevelUpUiBase_Inferred;
    if ((*(float *)(param_1 + 0x60) < fVar8) || (*(char *)(param_1 + 0x6d) != '\x05')) {
      fVar8 = *(float *)(param_1 + 100) + g_flOne;
      if ((*(float *)(param_1 + 0x60) < fVar8) || (*(char *)(param_1 + 0x6d) != '\x04')) {
        fVar8 = *(float *)(param_1 + 100) + DAT_00aaa8b0;
        if ((*(float *)(param_1 + 0x60) < fVar8) || (*(char *)(param_1 + 0x6d) != '\x03')) {
          if ((*(float *)(param_1 + 0x60) < fVar9) || (*(char *)(param_1 + 0x6d) != '\x02')) {
            fVar9 = *(float *)(param_1 + 100) + _DAT_00aaab48;
            if ((*(float *)(param_1 + 0x60) < fVar9) || (*(char *)(param_1 + 0x6d) != '\x01')) {
              if ((DAT_00aaa8b0 <= *(float *)(param_1 + 0x60)) &&
                 (*(char *)(param_1 + 0x6d) == '\0')) {
                *(undefined1 *)(param_1 + 0x6d) = 1;
                *(float *)(param_1 + 100) = fVar8;
                FUN_005816a0(3,0x3dcccccd);
                *(undefined1 *)(param_1 + 0x6c) = 1;
                pvVar1 = operator_new(0x14c);
                uStack_14 = 0;
                if (pvVar1 == (void *)0x0) {
                  piVar5 = (int *)0x0;
                }
                else {
                  piVar5 = (int *)FUN_00764030();
                }
                uStack_14 = 0xffffffff;
                *(int **)(param_1 + 0x14) = piVar5;
                iVar2 = *piVar5;
                uVar4 = FUN_00404ba0("cptest.geo");
                (**(code **)(iVar2 + 0x5c))(uVar4);
                piVar5 = *(int **)(*(int *)(param_1 + 0x10) + 8);
                iVar2 = FUN_0040d4b0(0x23);
                if ((iVar2 == 0) || (iVar2 = FUN_0040d4b0(0), iVar2 == 0)) {
                  uVar4 = FUN_0076cec0(&local_40,"No 35 from INC provided");
                  vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\appClient\\ClientSpecialEvent_Respawn.cpp"
                                 ,0xb4,3,uVar4);
                  FUN_007a4480(0,"VOG_DEBUG_STOP");
                  if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
                    (**(code **)**(undefined4 **)(param_1 + 0x14))(1);
                  }
                  *(undefined4 *)(param_1 + 0x14) = 0;
                }
                else {
                  puVar3 = operator_new(0x10);
                  if (puVar3 != (undefined4 *)0x0) {
                    *puVar3 = 0;
                    puVar3[1] = 0;
                    puVar3[2] = 0;
                    puVar3[3] = 0;
                  }
                  uStack_14 = 0xffffffff;
                  FUN_004406e0();
                  pvVar1 = *(void **)(piVar5[0x1c] + -4);
                  iVar2 = FUN_0044af00();
                  iVar6 = FUN_0044af00();
                  if ((iVar2 != 0) || (iVar6 != 0)) {
                    *(undefined4 *)((int)pvVar1 + 8) = 0;
                    FUN_0044adc0(pvVar1);
                    /* WARNING: Subroutine does not return */
                    operator_delete(pvVar1);
                  }
                  uVar10 = 3;
                  (**(code **)(*piVar5 + 0x30))(3);
                  (**(code **)(*piVar5 + 0x34))();
                  FUN_00439a80();
                  uVar4 = (**(code **)(*piVar5 + 0xc))();
                  uVar7 = (**(code **)(*piVar5 + 0x48))();
                  uVar7 = (**(code **)(*piVar5 + 0xc))(uVar7,uVar4);
                  FUN_0074c9c0(uVar7,uVar4,uVar10);
                }
              }
            }
            else {
              *(undefined1 *)(param_1 + 0x6d) = 2;
              *(float *)(param_1 + 100) = fVar9;
              FUN_005816a0(2,0x3dcccccd);
            }
          }
          else {
            *(undefined1 *)(param_1 + 0x6d) = 3;
            *(float *)(param_1 + 100) = fVar9;
            if (*(char *)(param_1 + 0x38) == '\0') {
              ExceptionList = local_1c;
              return 1;
            }
            iVar2 = **(int **)(*(int *)(param_1 + 0x10) + 8);
            uVar4 = FUN_004e88e0(&fStack_3c,param_1 + 0x40);
            (**(code **)(iVar2 + 0x18))(uVar4);
            if ((pvVar1 != (void *)0x0) &&
               (iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar1 + 4) + 4) + 4 +
                                             (int)pvVar1) + 0x210))(0), iVar2 == DAT_00d1b6d8)) {
              piVar5 = *(int **)(*(int *)(param_1 + 0x10) + 8);
              (**(code **)(*piVar5 + 0xc))();
              (**(code **)(*piVar5 + 0xc))();
              FUN_00417e40(DAT_00d1b778);
            }
            FUN_005816a0(1,0x3dcccccd);
            if (pvVar1 != (void *)0x0) {
              CVOGReaction_TeleportTarget(pvVar1,(undefined4 *)(param_1 + 0x40));
              FUN_00404dc0(param_1 + 0x50);
            }
          }
        }
        else {
          *(float *)(param_1 + 100) = fVar8;
          *(undefined1 *)(param_1 + 0x6d) = 4;
          FUN_005816a0(0,0x3dcccccd);
        }
      }
      else {
        *(float *)(param_1 + 100) = fVar8;
        *(undefined1 *)(param_1 + 0x6d) = 5;
        *(undefined1 *)(param_1 + 0x6c) = 0;
        FUN_00979290();
        if ((pvVar1 != (void *)0x0) &&
           (iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar1 + 4) + 4) + 4 + (int)pvVar1)
                                + 0x210))(0), iVar2 == DAT_00d1b6d8)) {
          *(undefined4 *)(DAT_00d1b778 + 0x60c) = *(undefined4 *)(param_1 + 0xc);
          FUN_0090dd50();
        }
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x6d) = 6;
      *(float *)(param_1 + 100) = fVar8;
      FUN_005816a0(2,0x3dcccccd);
    }
  }
  else {
    ExceptionList = &local_1c;
    FUN_00979310();
  }
  ExceptionList = local_1c;
  return 0;
}
```
