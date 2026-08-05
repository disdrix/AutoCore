# Annotated low-level: FUN_005b3ad0

| Field | Value |
|---|---|
| Stable ID | `aa_005b3ad0` |
| VA | `0x005b3ad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005b3ad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 __thiscall FUN_005b3ad0(int param_1,int param_2)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x24) - *(float *)(param_2 + 4);
  if (fVar1 <= 0.0) {
    return (float10)g_flZero;
  }
  if (DAT_00aaa7a4 < fVar1) {
    return (float10)g_flOne;
  }
  return (float10)fVar1 * (float10)DAT_00aaac18;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
