# Raw capture: FUN_006a0ac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a0ac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006a0ac0` |
| **Canonical name** | `FUN_006a0ac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_006a0ac0(void *param_1,int param_2,uint param_3,undefined4 *param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  uint extraout_ECX;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009ab098;
  local_10 = ExceptionList;
  local_34 = *param_4;
  local_30 = param_4[1];
  local_2c = param_4[2];
  local_28 = param_4[3];
  local_24 = param_4[4];
  local_20 = param_4[5];
  local_14 = &stack0xffffffc0;
  iVar3 = *(int *)((int)param_1 + 4);
  uVar6 = 0;
  local_8 = 0;
  if (iVar3 != 0) {
    uVar6 = (*(int *)((int)param_1 + 0xc) - iVar3) / 0x18;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  puVar1 = &stack0xffffffc0;
  if (param_3 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)((int)param_1 + 8) - iVar3) / 0x18;
    }
    ExceptionList = &local_10;
    puVar1 = &stack0xffffffc0;
    if (0xaaaaaaaU - iVar2 < param_3) {
      ExceptionList = &local_10;
      FUN_00690330();
      uVar6 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)((int)param_1 + 8) - iVar3) / 0x18;
    }
    if (uVar6 < iVar2 + param_3) {
      if (0xaaaaaaa - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)((int)param_1 + 8) - iVar3) / 0x18;
      }
      if (uVar6 < iVar3 + param_3) {
        iVar3 = SkillSet_GetEntryCount(param_1);
        uVar6 = iVar3 + param_3;
      }
      pvVar4 = operator_new(uVar6 * 0x18);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar4;
      iVar3 = FUN_00422580(*(undefined4 *)((int)param_1 + 4),param_2,pvVar4,param_1,param_2);
      FUN_0069ac30(iVar3,param_3,&local_34,param_1,param_2);
      FUN_00422580(param_2,*(undefined4 *)((int)param_1 + 8),iVar3 + param_3 * 0x18,param_1,param_2)
      ;
      local_8 = 0;
      iVar3 = 0;
      if (*(int *)((int)param_1 + 4) != 0) {
        iVar3 = (*(int *)((int)param_1 + 8) - *(int *)((int)param_1 + 4)) / 0x18;
      }
      if (*(int *)((int)param_1 + 4) != 0) {
        FUN_00691590(*(int *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
                    /* WARNING: Subroutine does not return */
        operator_delete(*(void **)((int)param_1 + 4));
      }
      *(void **)((int)param_1 + 0xc) = (void *)(uVar6 * 0x18 + (int)pvVar4);
      *(void **)((int)param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar3) * 0x18);
      *(void **)((int)param_1 + 4) = pvVar4;
      puVar1 = local_14;
    }
    else {
      iVar3 = *(int *)((int)param_1 + 8);
      if ((uint)((iVar3 - param_2) / 0x18) < param_3) {
        FUN_00422580(param_2,iVar3,param_3 * 0x18 + param_2,param_1,param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0069b340(*(int *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x18,&local_34);
        iVar3 = *(int *)((int)param_1 + 8) + param_3 * 0x18;
        *(int *)((int)param_1 + 8) = iVar3;
        FUN_0069a6a0(param_2,iVar3 + param_3 * -0x18,&local_34);
        puVar1 = local_14;
      }
      else {
        iVar2 = iVar3 + param_3 * -0x18;
        uVar5 = FUN_00422580(iVar2,iVar3,iVar3,param_1,iVar2);
        *(undefined4 *)((int)param_1 + 8) = uVar5;
        FUN_00422160(param_2,iVar2,iVar3,iVar2);
        FUN_0069a6a0(param_2,param_3 * 0x18 + param_2,&local_34);
        puVar1 = local_14;
      }
    }
  }
  local_14 = puVar1;
  local_8 = 0xffffffff;
  FUN_0056f570();
  ExceptionList = local_10;
  return;
}
```
