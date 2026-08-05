# Annotated low-level: FUN_006bdd30

| Field | Value |
|---|---|
| Stable ID | `aa_006bdd30` |
| VA | `0x006bdd30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bdd30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined1 *
FUN_006bdd30(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 local_11;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = -0x80000000;
  FUN_006bd1c0(&local_11,param_2,param_3,param_4,param_5,&local_c,local_10);
  *param_1 = local_10[0];
  if (-1 < local_4) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_c,local_4 << 5,0x12);
  }
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
