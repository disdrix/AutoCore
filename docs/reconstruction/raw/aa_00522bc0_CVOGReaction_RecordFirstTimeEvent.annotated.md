# Annotated low-level: CVOGReaction_RecordFirstTimeEvent

| Field | Value |
|---|---|
| Stable ID | `aa_00522bc0` |
| VA | `0x00522bc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00522bc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __thiscall CVOGReaction_RecordFirstTimeEvent(int param_1,int param_2)

{
  uint uVar1;
  void *pvVar2;
  CVOGHBBase *pAction;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_009a380c;
  local_c = ExceptionList;
  uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);
  if ((*(char *)(uVar1 + 0x7e) != '\0') && (*(char *)(param_1 + 0xc7c) == '\0')) {
    ExceptionList = &local_c;
    if (*(int *)(param_1 + 0xca0) != 0) {
      ExceptionList = &local_c;
      FUN_0060b410(1);
      *(undefined4 *)(param_1 + 0xca0) = 0;
    }
    *(bool *)(param_1 + 0xc7d) = *(float *)(param_2 + 0x260) != g_flZero;
    pvVar2 = operator_new(0x2c);
    local_4 = 0;
    if (pvVar2 == (void *)0x0) {
      pAction = (CVOGHBBase *)0x0;
    }
    else {
      pAction = (CVOGHBBase *)FUN_0060b380(param_2,param_1,*(undefined4 *)(param_2 + 0x25c));
    }
    *(CVOGHBBase **)(param_1 + 0xca0) = pAction;
    local_4 = 0xffffffff;
    CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +
                                 0xe4ec),pAction);
    CVOGHBBase_Start(*(CVOGHBBase **)(param_1 + 0xca0));
    *(undefined4 *)(param_1 + 0xc98) = *(undefined4 *)(param_1 + 0x6c0);
    *(int *)(param_1 + 0xc9c) = param_2;
    *(undefined1 *)(param_1 + 0xc7c) = 1;
    ExceptionList = local_c;
    return CONCAT31((int3)((uint)*(undefined4 *)(param_1 + 0x6c0) >> 8),1);
  }
  return uVar1 & 0xffffff00;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
