# Annotated low-level: FUN_005dcb60

| Field | Value |
|---|---|
| Stable ID | `aa_005dcb60` |
| VA | `0x005dcb60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dcb60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005dcb60(int param_1)

{
  int iVar1;
  void *pvVar2;
  CVOGHBBase *this;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a730f;
  local_c = ExceptionList;
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);
  if (((iVar1 != 0) && (*(int *)(param_1 + 0x15c) != 0)) && (*(char *)(iVar1 + 0x7e) != '\0')) {
    if (*(float *)(param_1 + 0x154) == g_flZero) {
      ExceptionList = &local_c;
      FUN_005dc5f0(1);
      ExceptionList = local_c;
      return;
    }
    ExceptionList = &local_c;
    pvVar2 = operator_new(0x28);
    local_4 = 0;
    if (pvVar2 == (void *)0x0) {
      this = (CVOGHBBase *)0x0;
    }
    else {
      this = (CVOGHBBase *)FUN_00642a90(param_1,*(undefined4 *)(param_1 + 0x154));
    }
    local_4 = 0xffffffff;
    CVOGHBBase_Start(this);
    CVOGHBList_Enqueue(*(void **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) +
                                 0xe4ec),this);
  }
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
