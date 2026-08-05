# Annotated low-level: FUN_005fea30

| Field | Value |
|---|---|
| Stable ID | `aa_005fea30` |
| VA | `0x005fea30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fea30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005fea30(int param_1)

{
  *(undefined2 *)(param_1 + -0x12) = *(undefined2 *)(param_1 + -0x14);
  FUN_00512130();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
