# Annotated low-level: FUN_0045ffb0

| Field | Value |
|---|---|
| Stable ID | `aa_0045ffb0` |
| VA | `0x0045ffb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0045ffb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0045ffb0(int param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 == param_4) {
    *param_2 = param_3;
    return;
  }
  iVar2 = FUN_00460aa0(*(undefined4 *)(param_1 + 8),param_3,param_3);
  iVar1 = *(int *)(param_1 + 8);
  for (iVar3 = iVar2; iVar3 != iVar1; iVar3 = iVar3 + 0x20) {
    FUN_0045f5d0();
  }
  *(int *)(param_1 + 8) = iVar2;
  *param_2 = param_3;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
