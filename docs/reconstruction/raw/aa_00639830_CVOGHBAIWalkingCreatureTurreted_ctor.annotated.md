# Annotated low-level: CVOGHBAIWalkingCreatureTurreted_ctor

| Field | Value |
|---|---|
| Stable ID | `aa_00639830` |
| VA | `0x00639830` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00639830`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall
CVOGHBAIWalkingCreatureTurreted_ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  CVOGHBAIBase_ctor(param_2,param_3);
  *param_1 = &PTR_LAB_009e3cc0;
  param_1[0x30] = 0;
  param_1[4] = 0;
  FUN_0063a700(0);
  param_1[0x1f] = g_flOne;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
