# Annotated low-level: FUN_005be7f0

| Field | Value |
|---|---|
| Stable ID | `aa_005be7f0` |
| VA | `0x005be7f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005be7f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __fastcall FUN_005be7f0(undefined4 *param_1)

{
  FUN_00748960();
  *(undefined1 *)(param_1 + 0x31) = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  *param_1 = &PTR_FUN_009d9c1c;
  param_1[1] = &PTR_LAB_009d9c0c;
  param_1[0x34] = 0xffffffff;
  param_1[0x35] = 0xffffffff;
  FUN_005be710();
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
