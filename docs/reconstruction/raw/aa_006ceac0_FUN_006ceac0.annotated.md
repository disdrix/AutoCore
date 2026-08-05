# Annotated low-level: FUN_006ceac0

| Field | Value |
|---|---|
| Stable ID | `aa_006ceac0` |
| VA | `0x006ceac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ceac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006ceac0(int param_1)

{
  if (param_1 != 0) {
    FUN_006ceae0();
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
