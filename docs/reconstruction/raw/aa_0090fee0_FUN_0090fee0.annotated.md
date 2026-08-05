# Annotated low-level: FUN_0090fee0

| Field | Value |
|---|---|
| Stable ID | `aa_0090fee0` |
| VA | `0x0090fee0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0090fee0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_0090fee0(int *param_1)

{
  int iVar1;
  int in_EAX;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_0090fe50();
  piVar2 = (int *)CVOGReaction_GiveItemByCbid(in_EAX);
  param_1[0x28a] = (int)piVar2;
  if (piVar2 == (int *)0x0) {
    FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer");
    return;
  }
  (**(code **)(*piVar2 + 8))();
  puVar3 = (undefined4 *)(**(code **)(*(int *)param_1[0x28a] + 0x1cc))();
  (**(code **)*puVar3)(1,0,0,0,0,0,0,g_flOne,0);
  DAT_00d09a68 = 0;
  iVar1 = puVar3[2];
  if (iVar1 != 0) {
    DAT_00d09a68 = iVar1;
    iVar4 = (**(code **)(*param_1 + 0x1a8))();
    if (iVar1 != 0) {
      *(undefined1 *)(iVar4 + 0x48) = 1;
      *(undefined4 *)(iVar4 + 0x44) = *(undefined4 *)(iVar4 + 0x40);
      FUN_0076c4d0();
      (**(code **)(**(int **)(iVar4 + 8) + 4))(iVar1);
      FUN_00755f10(iVar1);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
