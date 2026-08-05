# Annotated low-level: FUN_005fea50

| Field | Value |
|---|---|
| Stable ID | `aa_005fea50` |
| VA | `0x005fea50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fea50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005fea50(int param_1)

{
  *(undefined2 *)(param_1 + -0x14) = *(undefined2 *)(param_1 + -0x12);
  FUN_00512140();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
