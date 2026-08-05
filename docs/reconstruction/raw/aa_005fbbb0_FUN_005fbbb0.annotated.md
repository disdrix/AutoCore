# Annotated low-level: FUN_005fbbb0

| Field | Value |
|---|---|
| Stable ID | `aa_005fbbb0` |
| VA | `0x005fbbb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fbbb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_005fbbb0(undefined4 *param_1,undefined4 param_2)

{
  *(undefined2 *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_009dd2b8;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0x80000000;
  param_1[9] = 0x80000000;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xc] = 0x80000000;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xf] = 0x80000000;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x12] = 0x80000000;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x15] = 0x80000000;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x18] = 0x80000000;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x1c] = 0x80000000;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x20] = param_1 + 0x24;
  param_1[0x21] = 0;
  param_1[0x22] = 0x80000004;
  FUN_005fa9b0(param_2);
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
