# Annotated low-level: FUN_004bdd40

| Field | Value |
|---|---|
| Stable ID | `aa_004bdd40` |
| VA | `0x004bdd40` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004bdd40`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
uint __thiscall FUN_004bdd40(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint in_EAX;
  int iVar2;
  byte bVar3;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    return in_EAX & 0xffffff00;
  }
  iVar2 = *(int *)(param_1 + 0x14);
  bVar3 = 0;
  do {
    *(int *)(param_1 + 0x18) = iVar2;
    if ((int *)**(int **)(iVar2 + 0xc) != (int *)0x0) {
      bVar1 = (**(code **)(*(int *)**(int **)(iVar2 + 0xc) + 0x78))(param_2,param_3);
      bVar3 = bVar3 | bVar1;
    }
  } while ((*(int *)(param_1 + 0x18) != 0) &&
          (iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 4), iVar2 != 0));
  return (uint)bVar3;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
