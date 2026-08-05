# Annotated low-level: FUN_0053cfa0

| Field | Value |
|---|---|
| Stable ID | `aa_0053cfa0` |
| VA | `0x0053cfa0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0053cfa0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __fastcall FUN_0053cfa0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00785ca0(*(undefined4 *)(param_1 + -0x48));
  if ((char)uVar1 != '\0') {
    return uVar1 & 0xffffff00;
  }
  uVar1 = FUN_00517680();
  return uVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
