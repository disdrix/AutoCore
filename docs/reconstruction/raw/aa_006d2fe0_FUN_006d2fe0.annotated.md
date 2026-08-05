# Annotated low-level: FUN_006d2fe0

| Field | Value |
|---|---|
| Stable ID | `aa_006d2fe0` |
| VA | `0x006d2fe0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006d2fe0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006d2fe0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined **local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  local_14 = param_4;
  local_8 = param_1[2];
  local_4 = param_1;
  local_18 = 0x7f7fffff;
  local_1c = &PTR_LAB_00a0e324;
  local_10 = *(undefined4 *)(*param_1 + 0xc);
  local_c = param_1[1];
  FUN_006ebad0(param_2,&local_10,param_3,&local_1c);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
