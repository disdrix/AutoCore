# Annotated low-level: FUN_004f4ce0

| Field | Value |
|---|---|
| Stable ID | `aa_004f4ce0` |
| VA | `0x004f4ce0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004f4ce0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_004f4ce0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0);
  if ((iVar1 != 0) || (uVar2 = 0xc, *(char *)(param_1 + 0x103) != '\0')) {
    uVar2 = 10;
  }
  return uVar2;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
