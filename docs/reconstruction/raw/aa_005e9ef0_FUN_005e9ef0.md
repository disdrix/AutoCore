# Raw capture: FUN_005e9ef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e9ef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005e9ef0` |
| **Canonical name** | `FUN_005e9ef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005e9ef0(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  float10 fVar4;
  undefined4 uStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  int local_20;
  float local_1c;
  int local_18;
  int local_14;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  if (((uint)param_1[0x5f] >> 5 & 1) == 0) {
LAB_005ea036:
    if (((uint)param_1[0x5f] >> 6 & 1) != 0) {
      iVar1 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                              &CVOGGraphicsBase::RTTI_Type_Descriptor,0);
      if (*(int **)(iVar1 + 8) != (int *)0x0) {
        iVar2 = (**(code **)(**(int **)(iVar1 + 8) + 0xc))();
        uStack_2c = *(undefined4 *)(iVar2 + 0x90);
        fStack_28 = *(float *)(iVar2 + 0x94);
        uStack_24 = *(undefined4 *)(iVar2 + 0x98);
        fVar4 = (float10)FUN_004cd220(uStack_2c,uStack_24);
        fStack_28 = (float)(fVar4 + (float10)(float)param_1[0x2f]);
        (**(code **)(**(int **)(iVar1 + 8) + 0x18))(&uStack_2c);
        (**(code **)(*param_1 + 0x144))();
        return;
      }
    }
    local_20 = param_1[0x20];
    local_1c = (float)param_1[0x21];
    local_18 = param_1[0x22];
    local_14 = param_1[0x23];
    fVar4 = (float10)FUN_004cd220(local_20,local_18);
    param_1[0x21] = (int)(float)fVar4;
    param_1[0x20] = local_20;
    param_1[0x22] = local_18;
    param_1[0x23] = local_14;
    return;
  }
  iVar1 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                          &CVOGPhysicsBase::RTTI_Type_Descriptor,0);
  if (*(int *)(iVar1 + 8) == 0) goto LAB_005ea036;
  iVar2 = *(int *)(*(int *)(iVar1 + 8) + 0x3c);
  local_20 = *(int *)(iVar2 + 0xb0);
  local_1c = *(float *)(iVar2 + 0xb4);
  local_18 = *(undefined4 *)(iVar2 + 0xb8);
  local_14 = *(undefined4 *)(iVar2 + 0xbc);
  if ((*(int *)(iVar1 + 8) == 0) ||
     (iVar2 = (**(code **)(**(int **)(*(int *)(iVar1 + 8) + 0x3c) + 0x18))(), iVar2 != 6)) {
    if (*(char *)(*(int *)(iVar1 + 8) + 0x40) != '\0') goto LAB_005e9ff8;
    fVar4 = (float10)FUN_004cd220(local_20,local_18);
    local_1c = (local_1c + (float)fVar4) - *(float *)(param_3 + 4);
  }
  else {
    fVar4 = (float10)FUN_004cd220(local_20,local_18);
    local_1c = (float)(fVar4 + (float10)(float)param_1[0x2f]);
  }
  FUN_0040d2a0(&local_20);
LAB_005e9ff8:
  if (((uint)param_1[0x5f] >> 6 & 1) != 0) {
    piVar3 = (int *)__RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                    &CVOGGraphicsPhysicsBase::RTTI_Type_Descriptor,0);
    (**(code **)(*piVar3 + 0x44))();
  }
  (**(code **)(*param_1 + 0x144))();
  return;
}
```
