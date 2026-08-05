# Annotated low-level: FUN_0069aac0

| Field | Value |
|---|---|
| Stable ID | `aa_0069aac0` |
| VA | `0x0069aac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0069aac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0069aac0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (*(float *)(*param_1 + 0x2c) < *(float *)(*param_2 + 0x2c)) {
    iVar1 = *param_2;
    *param_2 = *param_1;
    *param_1 = iVar1;
  }
  if (*(float *)(*param_2 + 0x2c) < *(float *)(*param_3 + 0x2c)) {
    iVar1 = *param_3;
    *param_3 = *param_2;
    *param_2 = iVar1;
  }
  if (*(float *)(*param_1 + 0x2c) < *(float *)(*param_2 + 0x2c)) {
    iVar1 = *param_2;
    *param_2 = *param_1;
    *param_1 = iVar1;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
