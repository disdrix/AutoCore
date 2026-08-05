# Raw capture: Vehicle_applyCreatePacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00505270` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00505270` |
| **Canonical name** | `Vehicle_applyCreatePacket` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
Vehicle_applyCreatePacket
          (int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  undefined1 uVar2;
  DWORD DVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  TypeDescriptor *pTVar9;
  TypeDescriptor *pTVar10;
  undefined4 uVar11;
  int local_94;
  undefined1 *local_90;
  undefined1 local_8c [128];
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &DAT_009a303d;
  local_c = ExceptionList;
  if (param_2 != (int *)0x0) {
    uVar1 = (uint)ExceptionList >> 8;
    ExceptionList = &local_c;
    *(undefined1 *)(param_1 + -0x3c4) = *(undefined1 *)((int)param_2 + 0x151);
    *(undefined1 *)(param_1 + -0x55c) = *(undefined1 *)((int)param_2 + 0x152);
    if ((*(char *)((int)param_2 + 0x151) == '\0') && (*(char *)((int)param_2 + 0xa2) == '\0')) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    FUN_005c9120(param_2,param_3,param_4,param_5,0,CONCAT31((int3)uVar1,uVar2),param_8);
    DVar3 = GetTickCount();
    *(DWORD *)(param_1 + -0x65c) = DVar3;
    iVar6 = *(int *)(*(int *)(param_1 + -0x66c) + 4);
    *(undefined4 *)(iVar6 + param_1 + -0x5ac) =
         *(undefined4 *)(*(int *)(*(int *)(iVar6 + -0x5c4 + param_1) + 0x3c) + 0x3e4);
    if (*(int *)(param_1 + -0x524) != -1) {
      local_94 = *(int *)(param_1 + -0x524);
      piVar4 = (int *)FUN_0040b330(&local_94);
      if (*piVar4 == *(int *)(param_1 + -0x524)) {
        local_90 = local_8c;
        uVar5 = (*(code *)PTR_FUN_00af8c9c)();
        FUN_00403450((int)piVar4 + 0xf6,uVar5);
        uStack_4 = 0;
        FUN_00516720(local_90);
        uStack_4 = 0xffffffff;
        if (local_90 != local_8c) {
          free(local_90);
        }
      }
      else {
        *(undefined4 *)(param_1 + -0x524) = 0xffffffff;
      }
    }
    iVar7 = param_2[0x19];
    iVar6 = param_2[0x1a];
    piVar4 = (int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5ec + param_1);
    piVar4[2] = param_2[0x1b];
    *piVar4 = iVar7;
    piVar4[1] = iVar6;
    piVar4[3] = 0;
    FUN_00797170(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5dc + param_1);
    Vehicle_EquipFromCreate(param_2,param_3,param_5,param_6,param_7);
    iVar6 = param_2[0x38];
    if (iVar6 != -1) {
      iVar6 = FUN_004bb340(0,iVar6,iVar6 >> 0x1f);
      *(int *)(param_1 + -0x3f0) = iVar6;
      if (iVar6 == 0) {
        uVar11 = 0;
        pTVar10 = &CVOGSpawnPoint::RTTI_Type_Descriptor;
        pTVar9 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;
        uVar8 = 0;
        uVar5 = FUN_004e3260(param_2[0x38],param_2[0x38] >> 0x1f);
        uVar5 = __RTDynamicCast(uVar5,uVar8,pTVar9,pTVar10,uVar11);
        *(undefined4 *)(param_1 + -0x3f0) = uVar5;
      }
      if (*(int *)(param_1 + -0x3f0) != 0) {
        FUN_00563a30(param_1 + -0x670);
        if (param_1 == 0x670) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x66c + param_1;
        }
        iVar7 = *(int *)(param_1 + -0x3f0);
        if (iVar7 != 0) {
          iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;
        }
        FUN_005138e0(iVar7,iVar6);
      }
    }
    iVar6 = *(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1);
    if (iVar6 != 0) {
      if (*(int *)(iVar6 + 0xe4e8) != 0) {
        local_94 = CONCAT31(local_94._1_3_,
                            *(undefined1 *)
                             (*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x504 + param_1));
        iVar7 = FUN_004bb040(local_94,param_2[0x36],param_2[0x37]);
        iVar6 = iVar7;
        if (iVar7 != 0) {
          iVar6 = *(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7;
        }
        FUN_005131b0(iVar6);
        if (iVar7 != 0) {
          FUN_004c49d0(param_1 + -0x670);
          *(bool *)(param_1 + -0x56f) = *(char *)(iVar7 + 0x30c) == '\0';
        }
      }
      piVar4 = *(int **)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c0 + param_1);
      if (piVar4 != (int *)0x0) {
        iVar6 = (**(code **)(*piVar4 + 0x1dc))();
        if ((((iVar6 != 0) &&
             (*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6 ==
              *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) +
                      0xe8a0))) && (*(int *)(iVar6 + 0x250) != 0)) &&
           (*(int *)(iVar6 + 0x250) == param_1 + -0x670)) {
          *(undefined1 *)(param_1 + -0x56d) = 1;
          FUN_004f39c0();
          *(undefined4 *)(*(int *)(param_1 + -0x3ec) + 0x5c) = DAT_00a0f704;
        }
      }
    }
    if ((*(char *)((int)param_2 + 0x151) == '\0') && (*(char *)((int)param_2 + 0xa2) == '\0')) {
      if ((*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) == 0) ||
         (((char)param_7 == '\0' && ((char)param_6 == '\0')))) {
        FUN_004fedc0(param_2,param_3,param_5,param_6,param_7,0);
      }
      else {
        uVar8 = 0;
        piVar4 = param_2;
        uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + param_1 + -0x66c) +
                            0x1cc))(param_2,param_3,param_5,param_6,param_7,0,param_8);
        FUN_004c0140(uVar5,piVar4,param_3,param_5,param_6,param_7,uVar8,param_8);
      }
    }
    if (*param_2 == 0x201e) {
      Vehicle_CreateCargoInventoryFromPageCount((void *)(param_1 + -0x670),(short)param_2[0x35e]);
      if ((*(int *)(param_1 + -0x3c0) != 0) &&
         (*(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1) != 0)) {
        FUN_00570f50();
        iVar6 = 0;
        if (*(short *)((int)param_2 + 0xd7a) != 0) {
          piVar4 = param_2 + 0x360;
          do {
            local_94 = CONCAT31(local_94._1_3_,
                                *(undefined1 *)
                                 (*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x504 + param_1));
            iVar7 = CVOGReaction_ResolveObjectTarget(local_94,*piVar4,piVar4[1]);
            if (iVar7 == 0) {
              FUN_007a4480(0,"VOG_DEBUG_STOP");
            }
            else {
              FUN_00571d30(iVar7);
            }
            iVar6 = iVar6 + 1;
            piVar4 = piVar4 + 2;
          } while (iVar6 < (int)(uint)*(ushort *)((int)param_2 + 0xd7a));
        }
      }
    }
    *(int *)(param_1 + -0x53c) = param_2[0x53];
  }
  ExceptionList = local_c;
  return;
}
```
