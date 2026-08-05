# Annotated low-level: FUN_006efd90

| Field | Value |
|---|---|
| Stable ID | `aa_006efd90` |
| VA | `0x006efd90` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006efd90`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_006efd90(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  iVar1 = param_2;
  FUN_006cde50(param_2);
  if (0 < *(int *)(param_1 + 0x14)) {
    piVar4 = (int *)(param_2 + 4);
    iVar3 = 0;
    param_2 = *(int *)(param_1 + 0x14);
    do {
      puVar5 = (undefined4 *)(*(int *)(param_1 + 0x10) + iVar3);
      if (*(uint *)(iVar1 + 8) == (*(uint *)(iVar1 + 0xc) & 0x7fffffff)) {
        FUN_005b3370(piVar4,0x10);
      }
      puVar2 = (undefined4 *)(*(int *)(iVar1 + 8) * 0x10 + *piVar4);
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
      *puVar2 = *puVar5;
      puVar2[1] = puVar5[1];
      puVar2[2] = puVar5[2];
      puVar2[3] = puVar5[3];
      puVar5 = (undefined4 *)(iVar3 + 0x10 + *(int *)(param_1 + 0x10));
      if (*(uint *)(iVar1 + 8) == (*(uint *)(iVar1 + 0xc) & 0x7fffffff)) {
        FUN_005b3370(piVar4,0x10);
      }
      puVar2 = (undefined4 *)(*(int *)(iVar1 + 8) * 0x10 + *piVar4);
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
      *puVar2 = *puVar5;
      puVar2[1] = puVar5[1];
      puVar2[2] = puVar5[2];
      puVar2[3] = puVar5[3];
      iVar3 = iVar3 + 0x20;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
