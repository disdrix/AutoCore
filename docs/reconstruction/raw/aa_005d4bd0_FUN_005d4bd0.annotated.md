# Annotated low-level: FUN_005d4bd0

| Field | Value |
|---|---|
| Stable ID | `aa_005d4bd0` |
| VA | `0x005d4bd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005d4bd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_005d4bd0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + -0xd8);
  if ((iVar1 != 0) && (*(char *)(iVar1 + 0x40) != '\0')) {
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x34 + param_1) + 0x3c);
  if (((*(byte *)(iVar1 + 0x3f2) >> 1 & 1) == 0) && (*(float *)(iVar1 + 0x3e4) != g_flZero)) {
    return 0;
  }
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
