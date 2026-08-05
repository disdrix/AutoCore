# Annotated low-level: FUN_004f7ec0

| Field | Value |
|---|---|
| Stable ID | `aa_004f7ec0` |
| VA | `0x004f7ec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f7ec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004f7ec0(int param_1,char param_2)

{
  void *pvVar1;
  CVOGHBBase *pAction;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2ccf;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 0x100) != '\0') {
    if (param_2 == '\0') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x24);
      pAction = (CVOGHBBase *)0x0;
      local_4 = 0;
      if (pvVar1 != (void *)0x0) {
        pAction = (CVOGHBBase *)FUN_005fc1f0(param_1,DAT_00af0c70);
      }
      local_4 = 0xffffffff;
      CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +
                                   0xe4ec),pAction);
      CVOGHBBase_Start(pAction);
    }
    *(char *)(param_1 + 0x100) = param_2;
    ExceptionList = local_c;
    return;
  }
  *(char *)(param_1 + 0x100) = param_2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
