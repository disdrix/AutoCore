# Annotated low-level: FUN_006bfed0

| Field | Value |
|---|---|
| Stable ID | `aa_006bfed0` |
| VA | `0x006bfed0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006bfed0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_006bfed0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined1 local_39;
  char local_38 [4];
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_30 = 0x37a7c5ac;
  local_28 = 0x358637bd;
  local_24 = 0x3727c5ac;
  local_20 = 0x3d4ccccd;
  local_1c = 0x358637bd;
  local_18 = 0x358637bd;
  local_14 = 0x322bcc77;
  local_10 = 0x358637bd;
  local_c = 0x38d1b717;
  local_8 = 0x3727c5ac;
  local_4 = 0x37a7c5ac;
  local_34[0] = 0;
  local_2c = 0x368637bd;
  FUN_006bfd90(local_34,param_1,param_2,param_3,param_4);
  FUN_006c0b20(local_38,local_34,param_1,param_2,param_3,param_4);
  if (local_38[0] == '\0') {
    local_34[0] = 1;
    FUN_006bfd90(local_34,param_1,param_2,param_3,param_4);
    pcVar1 = (char *)FUN_006c0b20(&local_39,local_34,param_1,param_2,param_3,param_4);
    local_38[0] = *pcVar1;
    if (local_38[0] == '\0') {
      local_2c = 0x3456bf95;
      FUN_006bfd90(local_34,param_1,param_2,param_3,param_4);
      pcVar1 = (char *)FUN_006c0b20(&local_39,local_34,param_1,param_2,param_3,param_4);
      local_38[0] = *pcVar1;
      if (local_38[0] == '\0') {
        local_4 = 0x358637bd;
        FUN_006bfd90(local_34,param_1,param_2,param_3,param_4);
        FUN_006c0b20(&local_39,local_34,param_1,param_2,param_3,param_4);
      }
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
