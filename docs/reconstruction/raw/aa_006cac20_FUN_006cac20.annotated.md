# Annotated low-level: FUN_006cac20

| Field | Value |
|---|---|
| Stable ID | `aa_006cac20` |
| VA | `0x006cac20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006cac20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_006cac20(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(param_1 + 0x100);
  *puVar1 = &PTR_LAB_00a0d828;
  piVar2 = (int *)(param_1 + 8);
  iVar3 = 8;
  do {
    piVar2[-2] = (int)puVar1;
    piVar2[-1] = (int)puVar1;
    *piVar2 = (int)puVar1;
    piVar2[1] = (int)puVar1;
    piVar2[2] = (int)puVar1;
    piVar2[3] = (int)puVar1;
    piVar2[4] = (int)puVar1;
    piVar2[5] = (int)puVar1;
    piVar2 = piVar2 + 8;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
