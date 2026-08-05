# Annotated low-level: FUN_007fb4a0

| Field | Value |
|---|---|
| Stable ID | `aa_007fb4a0` |
| VA | `0x007fb4a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fb4a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_007fb4a0(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (*(code **)(in_EAX + 0xdd4) == (code *)0x0) {
    return 0;
  }
  uVar1 = (**(code **)(in_EAX + 0xdd4))(0x3f800000,0x3f600000,0x40000000);
  return uVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
