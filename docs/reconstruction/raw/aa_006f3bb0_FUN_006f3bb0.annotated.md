# Annotated low-level: FUN_006f3bb0

| Field | Value |
|---|---|
| Stable ID | `aa_006f3bb0` |
| VA | `0x006f3bb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006f3bb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006f3bb0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =
       (char)param_2;
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 8) <= iVar1) {
    FUN_006f3900();
  }
  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =
       (char)((uint)param_2 >> 8);
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 8) <= iVar1) {
    FUN_006f3900();
  }
  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =
       (char)((uint)param_2 >> 0x10);
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 8) <= iVar1) {
    FUN_006f3900();
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
