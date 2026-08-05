# Annotated low-level: FUN_0062aff0

| Field | Value |
|---|---|
| Stable ID | `aa_0062aff0` |
| VA | `0x0062aff0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0062aff0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0062aff0(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 local_14 [2];
  int local_10;
  int local_c;
  int local_8;
  
  uVar4 = param_2;
  iVar2 = *(int *)(param_1 + 0x20);
  iVar3 = *(int *)(param_1 + 0x1c);
  local_14[0] = (undefined2)param_2;
  local_10 = param_1;
  local_c = iVar3;
  local_8 = iVar2;
  FUN_0062a610(*(undefined4 *)(param_1 + 8),local_14);
  if (*(int *)(iVar3 + 100) != 0) {
    FUN_006000c0(iVar3,local_14);
  }
  if (*(int *)(iVar2 + 100) != 0) {
    FUN_006000c0(iVar2,local_14);
  }
  FUN_006515a0(uVar4);
  if (*(int *)(param_1 + 0xa4) == 0) {
    uVar1 = *(undefined1 *)(*(int *)(param_1 + 8) + 300);
    *(undefined1 *)(*(int *)(param_1 + 8) + 300) = 0;
    FUN_0055e860(&param_2,param_1 + 0x10);
    *(undefined1 *)(*(int *)(param_1 + 8) + 300) = uVar1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
