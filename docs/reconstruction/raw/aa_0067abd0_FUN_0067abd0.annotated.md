# Annotated low-level: FUN_0067abd0

| Field | Value |
|---|---|
| Stable ID | `aa_0067abd0` |
| VA | `0x0067abd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0067abd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0067abd0(int param_1,int param_2)

{
  if ((param_2 != 0) && (3 < *(uint *)(param_1 + 0xc))) {
    FUN_00680c80(param_2,4);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
