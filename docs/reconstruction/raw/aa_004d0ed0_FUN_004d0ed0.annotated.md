# Annotated low-level: FUN_004d0ed0

| Field | Value |
|---|---|
| Stable ID | `aa_004d0ed0` |
| VA | `0x004d0ed0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004d0ed0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004d0ed0(int param_1,int param_2,float *param_3,float param_4,char param_5)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  void *pvVar4;
  CVOGHBBase *pAction;
  float10 fVar5;
  float fVar6;
  float local_30;
  float local_28;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a1fb6;
  local_1c = ExceptionList;
  if (param_2 == 0) {
    ExceptionList = &local_1c;
    FUN_007a4480(0,"trying to drop <NULL> ptr object on the ground");
    ExceptionList = local_1c;
    return;
  }
  local_30 = *param_3;
  local_28 = param_3[2];
  fVar1 = param_3[3];
  ExceptionList = &local_1c;
  if (g_flZero < param_4) {
    ExceptionList = &local_1c;
    iVar3 = CVOGReaction_RandomUnitScalar();
    if (0xfffff < *(int *)(iVar3 + 0xc)) {
      *(undefined4 *)(iVar3 + 0xc) = 0;
    }
    uVar2 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;
    local_30 = ((float)uVar2 * param_4 * _DAT_009cc4a8 - param_4) + local_30;
    iVar3 = CVOGReaction_RandomUnitScalar();
    if (0xfffff < *(int *)(iVar3 + 0xc)) {
      *(undefined4 *)(iVar3 + 0xc) = 0;
    }
    uVar2 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;
    local_28 = ((float)uVar2 * param_4 * _DAT_009cc4a8 - param_4) + local_28;
  }
  if (*(int *)(param_1 + 0xe4e0) == 0) {
    fVar6 = 0.0;
  }
  else {
    fVar5 = (float10)FUN_005a58c0(local_30,local_28);
    fVar6 = (float)fVar5;
  }
  *(float *)(param_2 + 0x84) = fVar6 + DAT_00a0f298;
  *(float *)(param_2 + 0x88) = local_28;
  *(float *)(param_2 + 0x80) = local_30;
  *(float *)(param_2 + 0x8c) = fVar1;
  FUN_004024d0(param_2);
  if (param_5 != '\0') {
    pvVar4 = operator_new(0x24);
    local_14 = 0;
    if (pvVar4 == (void *)0x0) {
      pAction = (CVOGHBBase *)0x0;
    }
    else {
      pAction = (CVOGHBBase *)
                FUN_005d8360(param_2,(-(uint)(*(int *)(*(int *)(param_2 + 0xa8) + 0x38) != 4) &
                                     0xff938290) + 7200000);
    }
    local_14 = 0xffffffff;
    CVOGHBList_Enqueue(*(void **)(param_1 + 0xe4ec),pAction);
    CVOGHBBase_Start(pAction);
  }
  ExceptionList = local_1c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
