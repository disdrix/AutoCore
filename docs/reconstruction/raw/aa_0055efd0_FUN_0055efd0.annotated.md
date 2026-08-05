# Annotated low-level: FUN_0055efd0

| Field | Value |
|---|---|
| Stable ID | `aa_0055efd0` |
| VA | `0x0055efd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0055efd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0055efd0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = (int *)(param_1 + 0x20);
  iVar4 = *(int *)(param_1 + 0x24) + 1;
  uVar2 = *(uint *)(param_1 + 0x28) & 0x7fffffff;
  if ((int)uVar2 < iVar4) {
    iVar3 = uVar2 * 2;
    if (iVar3 <= iVar4) {
      iVar3 = iVar4;
    }
    FUN_005b3300(piVar1,iVar3,8);
  }
  *(int *)(param_1 + 0x24) = iVar4;
  *(undefined4 *)(*piVar1 + -8 + *(int *)(param_1 + 0x24) * 8) = param_2;
  *(undefined4 *)(*piVar1 + -4 + *(int *)(param_1 + 0x24) * 8) = param_3;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
