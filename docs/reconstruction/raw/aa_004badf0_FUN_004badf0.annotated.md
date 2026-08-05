# Annotated low-level: FUN_004badf0

| Field | Value |
|---|---|
| Stable ID | `aa_004badf0` |
| VA | `0x004badf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004badf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004badf0(int param_1)

{
  *(undefined1 *)(param_1 + 0xe) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
