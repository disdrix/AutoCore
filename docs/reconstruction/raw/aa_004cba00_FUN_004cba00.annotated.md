# Annotated low-level: FUN_004cba00

| Field | Value |
|---|---|
| Stable ID | `aa_004cba00` |
| VA | `0x004cba00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cba00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004cba00(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = FUN_004cb4b0(param_3);
  if (iVar1 != *(int *)(param_1 + 4)) {
    if ((*(int *)(iVar1 + 0x14) <= (int)param_3[1]) &&
       ((*(int *)(iVar1 + 0x14) < (int)param_3[1] || (*(uint *)(iVar1 + 0x10) <= *param_3)))) {
      *param_2 = iVar1;
      return;
    }
  }
  *param_2 = *(int *)(param_1 + 4);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
