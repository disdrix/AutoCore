# Annotated low-level: FUN_005ffdb0

| Field | Value |
|---|---|
| Stable ID | `aa_005ffdb0` |
| VA | `0x005ffdb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ffdb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005ffdb0(int param_1,int param_2)

{
  FUN_005ffcf0(param_1,param_2);
  if (param_2 != 0) {
    *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) | 0x80;
    return;
  }
  *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) & 0x7f;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
