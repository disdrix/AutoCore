# Annotated low-level: FUN_005be7d0

| Field | Value |
|---|---|
| Stable ID | `aa_005be7d0` |
| VA | `0x005be7d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005be7d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005be7d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_009d9c1c;
  param_1[1] = &PTR_LAB_009d9c0c;
  FUN_005be6a0();
  FUN_00748600();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
