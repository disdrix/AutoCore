# Annotated low-level: FUN_004b4ba0

| Field | Value |
|---|---|
| Stable ID | `aa_004b4ba0` |
| VA | `0x004b4ba0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004b4ba0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004b4ba0(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0xd8))(0);
    (**(code **)(*piVar1 + 0x24))(0);
    (**(code **)(*piVar1 + 0x1c))(0x3f000000);
    (**(code **)(*piVar1 + 0x14))(0x3f000000);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
