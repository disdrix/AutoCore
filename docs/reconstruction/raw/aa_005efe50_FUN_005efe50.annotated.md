# Annotated low-level: FUN_005efe50

| Field | Value |
|---|---|
| Stable ID | `aa_005efe50` |
| VA | `0x005efe50` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005efe50`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_005efe50(undefined4 param_1,float param_2,float *param_3)

{
  int extraout_EDX;
  float fVar1;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (param_2 <= 0.0) {
    return 1;
  }
  FUN_005efcc0();
  FUN_005ef780(param_1);
  fVar1 = param_2 / DAT_00d027b0;
  *param_3 = DAT_00d027b0;
  FUN_005ef1d0(param_2,fVar1);
  *(float *)(extraout_EDX + 0x10) = local_50 - local_60;
  *(float *)(extraout_EDX + 0x14) = local_4c - local_5c;
  *(float *)(extraout_EDX + 0x18) = local_48 - local_58;
  *(undefined4 *)(extraout_EDX + 0x1c) = local_44;
  *(undefined4 *)(extraout_EDX + 0x20) = local_40;
  *(undefined4 *)(extraout_EDX + 0x24) = local_3c;
  *(undefined4 *)(extraout_EDX + 0x28) = local_38;
  *(undefined4 *)(extraout_EDX + 0x2c) = local_34;
  *(undefined4 *)(extraout_EDX + 0x30) = local_30;
  *(undefined4 *)(extraout_EDX + 0x34) = local_2c;
  *(undefined4 *)(extraout_EDX + 0x38) = local_28;
  *(undefined4 *)(extraout_EDX + 0x3c) = local_24;
  *(undefined4 *)(extraout_EDX + 0x40) = local_20;
  *(undefined4 *)(extraout_EDX + 0x44) = local_1c;
  *(undefined4 *)(extraout_EDX + 0x48) = local_18;
  *(undefined4 *)(extraout_EDX + 0x4c) = local_14;
  *(float *)(extraout_EDX + 4) = param_2;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
