# Annotated low-level: FUN_0040acb0

| Field | Value |
|---|---|
| Stable ID | `aa_0040acb0` |
| VA | `0x0040acb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0040acb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0040acb0(int param_1,float param_2)

{
  int iVar1;
  
  iVar1 = _isnan((double)param_2);
  if (iVar1 == 0) {
    *(float *)(param_1 + 0x138) = param_2;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
