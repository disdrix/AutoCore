# Annotated low-level: CVOGHBAIBase_ctor

| Field | Value |
|---|---|
| Stable ID | `aa_005d3b30` |
| VA | `0x005d3b30` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d3b30`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall
CVOGHBAIBase_ctor(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  float fVar1;
  
  fVar1 = g_flOne;
  param_1[2] = 0;
  *param_1 = &PTR_LAB_009daad0;
  param_1[0x13] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  param_1[0x14] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[3] = fVar1;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[0x18] = *param_2;
  param_1[0x19] = param_2[1];
  param_1[0x1a] = param_2[2];
  param_1[0x1b] = param_2[3];
  param_1[0x1b] = 0;
  param_1[0x1c] = *param_2;
  param_1[0x1d] = param_2[1];
  param_1[0x1e] = param_2[2];
  param_1[0x1f] = param_2[3];
  param_1[0x2c] = *param_2;
  param_1[0x2d] = param_2[1];
  param_1[0x2e] = param_2[2];
  param_1[0x2f] = param_2[3];
  param_1[0xc] = *param_3;
  param_1[0xd] = param_3[1];
  param_1[0xe] = param_3[2];
  param_1[0xf] = param_3[3];
  FUN_005eadb0(param_3);
  param_1[0x1f] = 0;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
