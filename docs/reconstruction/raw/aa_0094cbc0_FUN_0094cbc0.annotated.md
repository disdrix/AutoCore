# Annotated low-level: FUN_0094cbc0

| Field | Value |
|---|---|
| Stable ID | `aa_0094cbc0` |
| VA | `0x0094cbc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0094cbc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0094cbc0(char param_1)

{
  if (param_1 != '\0') {
    _param_1 = 0x8012;
    FUN_008073b0(4,&param_1);
    return;
  }
  _param_1 = 0x8014;
  FUN_008073b0(4,&param_1);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
