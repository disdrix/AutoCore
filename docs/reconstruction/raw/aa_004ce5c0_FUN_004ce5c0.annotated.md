# Annotated low-level: FUN_004ce5c0

| Field | Value |
|---|---|
| Stable ID | `aa_004ce5c0` |
| VA | `0x004ce5c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004ce5c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
bool __thiscall FUN_004ce5c0(int param_1,int param_2)

{
  if (param_2 == 0) {
    return false;
  }
  if (*(char *)(param_1 + 0xf5) != '\0') {
    return true;
  }
  return *(char *)(param_1 + 0x7e) != '\0';
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
