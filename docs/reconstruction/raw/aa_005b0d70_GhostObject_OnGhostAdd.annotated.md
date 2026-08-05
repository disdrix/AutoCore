# Annotated low-level: GhostObject_OnGhostAdd

| Field | Value |
|---|---|
| Stable ID | `aa_005b0d70` |
| VA | `0x005b0d70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005b0d70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall GhostObject_OnGhostAdd(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    (**(code **)(**(int **)(param_1 + 0x50) + 0x2b8))(param_1);
    return 1;
  }
  FUN_005a0b30(param_1,param_1 + 0x40);
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
