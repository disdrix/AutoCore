# Annotated low-level: FUN_004bdef0

| Field | Value |
|---|---|
| Stable ID | `aa_004bdef0` |
| VA | `0x004bdef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bdef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_004bdef0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);
  iVar1 = *(int *)(iVar2 + 0x38);
  if (((((*(short *)(*(int *)(iVar2 + 0x3c) + 0x3f4) != 3) && (iVar1 != 0x36)) && (iVar1 != 0x38))
      && ((iVar1 != 0x1e && (iVar1 != 0x3c)))) &&
     ((iVar2 = *(int *)(*(int *)(param_1 + 4) + 4),
      (*(byte *)(*(int *)(*(int *)(iVar2 + 0xac + param_1) + 0x3c) + 0x3f2) & 4) == 0 &&
      (*(int *)(param_1 + 0x1c) == 0)))) {
    if ((*(char *)(*(int *)(iVar2 + param_1 + 0xa8) + 0xf5) == '\0') &&
       (iVar2 = FUN_004bde80(*(undefined4 *)(param_1 + 8)), 20000 < iVar2)) {
      return 0;
    }
    return 1;
  }
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
