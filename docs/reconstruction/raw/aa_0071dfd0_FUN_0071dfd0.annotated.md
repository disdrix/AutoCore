# Annotated low-level: FUN_0071dfd0

| Field | Value |
|---|---|
| Stable ID | `aa_0071dfd0` |
| VA | `0x0071dfd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071dfd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0071dfd0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00aa9990;
  FUN_00718c50();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
