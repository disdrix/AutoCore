# Annotated low-level: FUN_0071aaf0

| Field | Value |
|---|---|
| Stable ID | `aa_0071aaf0` |
| VA | `0x0071aaf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071aaf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_0071aaf0(undefined4 param_1,int param_2)

{
  int local_8;
  
  switch(param_1) {
  case 0:
  case 3:
    break;
  case 1:
    local_8 = (int)(longlong)ROUND((double)param_2 * _DAT_00aaa5c8 + _DAT_00aaa5c0);
    return local_8;
  case 2:
    local_8 = (int)(longlong)ROUND((double)param_2 * _DAT_00aaa5b8 + _DAT_00aaa5b0);
    return local_8;
  default:
    param_2 = 0;
  }
  return param_2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
