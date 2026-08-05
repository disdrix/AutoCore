# Annotated low-level: hkDefaultTransmission_ctor

| Field | Value |
|---|---|
| Stable ID | `aa_0064f610` |
| VA | `0x0064f610` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064f610`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall hkDefaultTransmission_ctor(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_0065e460(param_2);
  uVar1 = DAT_00aaa668;
  *param_1 = &PTR_FUN_009e4dac;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0x80000000;
  param_1[0x15] = 0x80000000;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = 0;
  param_1[0x17] = uVar1;
  *(undefined1 *)(param_1 + 0x16) = 0;
  FUN_0064f100(param_2);
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
