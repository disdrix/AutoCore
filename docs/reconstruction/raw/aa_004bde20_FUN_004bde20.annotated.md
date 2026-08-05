# Annotated low-level: FUN_004bde20

| Field | Value |
|---|---|
| Stable ID | `aa_004bde20` |
| VA | `0x004bde20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bde20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_004bde20(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 8);
  for (piVar3 = *(int **)(*(int *)(param_1 + 0xc) + 4); piVar3 != piVar1; piVar3 = piVar3 + 1) {
    iVar2 = *piVar3;
    if (((*(int *)(iVar2 + 8) == 0) && (*(char *)(iVar2 + 0xf) == '\0')) &&
       ((*(uint *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x180 + iVar2) >> 9 & 1) != 0)) {
      FUN_00496210(iVar2);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
