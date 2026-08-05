# Annotated low-level: FUN_008df7e0

| Field | Value |
|---|---|
| Stable ID | `aa_008df7e0` |
| VA | `0x008df7e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008df7e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008df7e0(int *param_1,float param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if ((cVar1 != '\0') && (DAT_00d1b6d8 != 0)) {
    param_1[0x143] = (int)((float)param_1[0x143] + param_2);
    FUN_00791f30(param_2);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
