# Annotated low-level: FUN_006d3ac0

| Field | Value |
|---|---|
| Stable ID | `aa_006d3ac0` |
| VA | `0x006d3ac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006d3ac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006d3ac0(undefined1 *param_1,float *param_2,float *param_3,int param_4)

{
  float fVar1;
  
  if (DAT_00aaa6d4 <= param_3[3]) {
    if ((param_3[4] * param_2[4] + param_3[5] * param_2[5] + param_3[6] * param_2[6] <
         *(float *)(param_4 + 0x10)) &&
       (fVar1 = (*param_3 - *param_2) * param_2[4] +
                (param_3[1] - param_2[1]) * param_2[5] + (param_3[2] - param_2[2]) * param_2[6],
       fVar1 < *(float *)(param_4 + 0xc) != (fVar1 == *(float *)(param_4 + 0xc)))) {
      *param_1 = 0;
      return;
    }
  }
  *param_1 = 1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
