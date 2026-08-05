# Annotated low-level: FUN_0065aec0

| Field | Value |
|---|---|
| Stable ID | `aa_0065aec0` |
| VA | `0x0065aec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0065aec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __fastcall FUN_0065aec0(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xc0,0x12);
  *param_1 = uVar1;
  FUN_006380d0(uVar1,0xff,0x40);
  param_1[1] = 0;
  param_1[2] = 0xf;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
