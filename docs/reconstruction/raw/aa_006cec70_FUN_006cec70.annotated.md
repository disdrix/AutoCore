# Annotated low-level: FUN_006cec70

| Field | Value |
|---|---|
| Stable ID | `aa_006cec70` |
| VA | `0x006cec70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006cec70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006cec70(int param_1,int param_2)

{
  FUN_006cde50(param_2);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0xc);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
