# Annotated low-level: FUN_007a7eb0

| Field | Value |
|---|---|
| Stable ID | `aa_007a7eb0` |
| VA | `0x007a7eb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007a7eb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __fastcall FUN_007a7eb0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0xd8))();
  if (((char)uVar1 != '\0') && (param_1[0xac] != 0)) {
    uVar1 = (**(code **)(*(int *)param_1[0xac] + 0x338))(0x15,param_1[0x3b]);
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
