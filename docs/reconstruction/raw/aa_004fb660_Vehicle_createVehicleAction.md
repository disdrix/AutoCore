# Raw capture: Vehicle_createVehicleAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb660` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fb660` |
| **Canonical name** | `Vehicle_createVehicleAction` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Vehicle_createVehicleAction: entity+0x1a0 = new 0xC { [0]=VehicleAction*,
   [4]=hkVehicleFramework*, [8]=driverInput from FUN_005fe020 }. Framework built with input;
   VehicleAction_ctor(entity, rb, framework, mode2). */

void __fastcall Vehicle_createVehicleAction(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a2cfa;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x1a0) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
    iVar3 = iVar1 + param_1;
    ExceptionList = &local_c;
    FUN_007a4480(0xffffffff,"Would have duplicate vehicle actions for %d, %I64d",
                 *(undefined4 *)(*(int *)(iVar3 + 0xac) + 0x34),*(undefined4 *)(iVar3 + 0x164),
                 *(undefined4 *)(iVar1 + 0x168 + param_1));
    FUN_004f7d60();
  }
  if (*(int *)(param_1 + 8) != 0) {
    pvVar2 = operator_new(0xc);
    *(void **)(param_1 + 0x1a0) = pvVar2;
    FUN_005fe5c0();
    local_1c = DAT_00a0f710;
    local_18 = DAT_009cd0d8;
    local_14 = 0;
    local_10 = 1;
    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x40,10);
    *(undefined2 *)(iVar3 + 4) = 0x40;
    uStack_4 = 0;
    uVar4 = hkDefaultAnalogDriverInput_ctor(&local_1c);
    *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 8) = uVar4;
    uStack_4 = 0xffffffff;
    uVar4 = Vehicle_buildHavokVehicleFramework
                      (param_1,*(undefined4 *)
                                (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +
                                0xe4a4),0,*(undefined4 *)(*(int *)(param_1 + 0x1a0) + 8),
                       *(undefined4 *)(param_1 + 8),0);
    *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 4) = uVar4;
    iVar3 = *(int *)(param_1 + 600);
    if (iVar3 != 0) {
      bVar5 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xac + iVar3) + 0x3c)
                       + 0x4ce) == '\x02';
      if (bVar5) {
        iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x48,0x24);
        *(undefined2 *)(iVar3 + 4) = 0x48;
        uStack_4 = 1;
      }
      else {
        iVar3 = (**(code **)(*DAT_00b05060 + 0x10))();
        *(undefined2 *)(iVar3 + 4) = 0x48;
        uStack_4 = 2;
      }
      uVar4 = VehicleAction_ctor(param_1,*(undefined4 *)(param_1 + 8),
                                 *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 4),bVar5);
      uStack_4 = 0xffffffff;
      **(undefined4 **)(param_1 + 0x1a0) = uVar4;
    }
    FUN_0055fe50(**(undefined4 **)(param_1 + 0x1a0));
    FUN_005d4050(1);
  }
  ExceptionList = local_c;
  return;
}
```
