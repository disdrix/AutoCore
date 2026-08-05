# Annotated low-level: FUN_0064fac0

| Field | Value |
|---|---|
| Stable ID | `aa_0064fac0` |
| VA | `0x0064fac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064fac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall hkDefaultSteering_ctor(undefined4 *param_1,undefined4 param_2)

{
  FUN_0065e5f0(param_2);
  *param_1 = &PTR_FUN_009e4ee4;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0x80000000;
  FUN_0064f920(param_2);
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
