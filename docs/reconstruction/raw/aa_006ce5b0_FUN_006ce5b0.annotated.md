# Annotated low-level: FUN_006ce5b0

| Field | Value |
|---|---|
| Stable ID | `aa_006ce5b0` |
| VA | `0x006ce5b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ce5b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006ce5b0(int param_1)

{
  if (-1 < *(int *)(param_1 + 0x1c)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 0x14),*(int *)(param_1 + 0x1c) << 4,0x12);
  }
  if (-1 < *(int *)(param_1 + 0x10)) {
    (**(code **)(*DAT_00b05060 + 0x14))
              (*(undefined4 *)(param_1 + 8),*(int *)(param_1 + 0x10) << 4,0x12);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
