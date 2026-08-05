# Annotated low-level: FUN_004cd7d0

| Field | Value |
|---|---|
| Stable ID | `aa_004cd7d0` |
| VA | `0x004cd7d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004cd7d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_004cd7d0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xe4e8) = param_2;
  if (*(int *)(param_1 + 0xe894) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xe894) + 0xbc) = param_2;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
