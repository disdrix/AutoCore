# Annotated low-level: FUN_006ceae0

| Field | Value |
|---|---|
| Stable ID | `aa_006ceae0` |
| VA | `0x006ceae0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ceae0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __fastcall FUN_006ceae0(int param_1)

{
  FUN_0066dcf0();
  *(undefined4 *)(param_1 + 4) = 0;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
