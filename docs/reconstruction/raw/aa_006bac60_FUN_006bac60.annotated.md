# Annotated low-level: FUN_006bac60

| Field | Value |
|---|---|
| Stable ID | `aa_006bac60` |
| VA | `0x006bac60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bac60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006bac60(float *param_1,float *param_2)

{
  float *in_EAX;
  
  *in_EAX = *param_2 - *param_1;
  in_EAX[1] = param_2[1] - param_1[1];
  in_EAX[2] = param_2[2] - param_1[2];
  in_EAX[3] = param_2[3] - param_1[3];
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
