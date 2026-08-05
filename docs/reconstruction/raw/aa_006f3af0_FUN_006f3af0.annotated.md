# Annotated low-level: FUN_006f3af0

| Field | Value |
|---|---|
| Stable ID | `aa_006f3af0` |
| VA | `0x006f3af0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006f3af0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006f3af0(int param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  
  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =
       (char)param_3;
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 8) <= iVar1) {
    FUN_006f3900();
  }
  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =
       (char)((uint)param_3 >> 8);
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 8) <= iVar1) {
    FUN_006f3900();
  }
  *(char *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10)) =
       (char)((uint)param_3 >> 0x10);
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (*(int *)(param_1 + 8) <= iVar1) {
    FUN_006f3900();
  }
  *(undefined1 *)((*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc)) + -1 + *(int *)(param_1 + 0x10))
       = param_2;
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
