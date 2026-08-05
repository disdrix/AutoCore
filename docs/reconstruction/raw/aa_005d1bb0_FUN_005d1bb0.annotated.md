# Annotated low-level: FUN_005d1bb0

| Field | Value |
|---|---|
| Stable ID | `aa_005d1bb0` |
| VA | `0x005d1bb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d1bb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 __fastcall FUN_005d1bb0(int param_1)

{
  float10 fVar1;
  float fVar2;
  
  if (g_flOne <= ABS(ABS(*(float *)(param_1 + 0xc)))) {
    fVar2 = 0.0;
    if (ABS(*(float *)(param_1 + 0xc)) <= 0.0) {
      fVar2 = DAT_009da860;
    }
    return (float10)fVar2 + (float10)fVar2;
  }
  fVar1 = (float10)_CIacos();
  return fVar1 + fVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
