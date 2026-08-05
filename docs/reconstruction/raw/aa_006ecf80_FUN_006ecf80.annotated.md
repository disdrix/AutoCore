# Annotated low-level: FUN_006ecf80

| Field | Value |
|---|---|
| Stable ID | `aa_006ecf80` |
| VA | `0x006ecf80` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006ecf80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006ecf80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined **local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = param_4;
  local_8 = 0x7f7fffff;
  local_c = &PTR_LAB_00a0e324;
  FUN_006ec7f0(param_2,param_1,param_3,&local_c);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
