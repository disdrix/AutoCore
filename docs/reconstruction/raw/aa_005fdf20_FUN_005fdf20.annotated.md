# Annotated low-level: FUN_005fdf20

| Field | Value |
|---|---|
| Stable ID | `aa_005fdf20` |
| VA | `0x005fdf20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fdf20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 __fastcall FUN_005fdf20(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = ABS(*(float *)(param_1 + 0x1c));
  if (fVar1 < *(float *)(param_1 + 0x38)) {
    return (float10)g_flZero;
  }
  fVar2 = g_flOne;
  if (*(float *)(param_1 + 0x1c) <= g_flZero) {
    fVar2 = DAT_00aaa668;
  }
  if (fVar1 < *(float *)(param_1 + 0x28)) {
    return ((float10)fVar1 - (float10)*(float *)(param_1 + 0x38)) *
           (float10)*(float *)(param_1 + 0x2c) * (float10)fVar2;
  }
  return (((float10)fVar1 - (float10)*(float *)(param_1 + 0x28)) *
          (float10)*(float *)(param_1 + 0x30) + (float10)*(float *)(param_1 + 0x34)) *
         (float10)fVar2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
