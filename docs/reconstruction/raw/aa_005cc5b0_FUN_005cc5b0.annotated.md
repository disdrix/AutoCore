# Annotated low-level: FUN_005cc5b0

| Field | Value |
|---|---|
| Stable ID | `aa_005cc5b0` |
| VA | `0x005cc5b0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005cc5b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005cc5b0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((((*(int *)(param_1 + 0x18) != 0) &&
       (iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 0xa4), iVar1 != 0)) &&
      (iVar2 = *(int *)(param_1 + 100), iVar2 != 0)) &&
     (*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) + 0x38) != 0x14)) {
    if ((*(uint *)(iVar2 + 0x210) & *(uint *)(iVar2 + 0x214)) == 0xffffffff) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
      if (*(char *)(param_1 + 0x21) == '\0') {
        *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -1;
      }
      if (*(char *)(param_1 + 0x6d) != '\0') {
        *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + -1;
      }
    }
    else {
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + -1;
      if (*(char *)(param_1 + 0x21) == '\0') {
        *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + -1;
      }
      if (*(char *)(param_1 + 0x6d) != '\0') {
        *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + -1;
        FUN_005083f0();
        return;
      }
    }
  }
  FUN_005083f0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
