# Annotated low-level: CVOGHBAIBot_ctor

| Field | Value |
|---|---|
| Stable ID | `aa_005d3cf0` |
| VA | `0x005d3cf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d3cf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall CVOGHBAIBot_ctor(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  CVOGHBAICreatureBase_ctor(param_2,param_3);
  *param_1 = &PTR_LAB_009dabd0;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
