# Annotated low-level: FUN_005eb1a0

| Field | Value |
|---|---|
| Stable ID | `aa_005eb1a0` |
| VA | `0x005eb1a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005eb1a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005eb1a0(int param_1,undefined4 param_2)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x18))
            (param_1 + 0x80,*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0xcc) + 8),param_2);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
