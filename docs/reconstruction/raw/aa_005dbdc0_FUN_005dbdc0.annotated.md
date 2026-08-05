# Annotated low-level: FUN_005dbdc0

| Field | Value |
|---|---|
| Stable ID | `aa_005dbdc0` |
| VA | `0x005dbdc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005dbdc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_005dbdc0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  char cVar6;
  undefined4 *puVar7;
  
  uVar2 = param_6;
  if ((*(char *)(param_1 + -0x36) == '\0') &&
     (((cVar6 = (char)param_6, cVar6 != '\0' || ((char)param_3 == '\0')) ||
      (cVar3 = (**(code **)(*(int *)(param_1 + -0x1c0) + 100))(param_2), cVar3 != '\0')))) {
    *(undefined1 *)(param_1 + -0x36) = 1;
    if (param_1 == 0x1c0) {
      param_6 = 0;
    }
    else {
      param_6 = *(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x1bc + param_1;
    }
    iVar1 = *(int *)(param_4 + 4);
    iVar4 = FUN_00418700(iVar1,*(undefined4 *)(iVar1 + 4),&param_6);
    FUN_00404840(1);
    *(int *)(iVar1 + 4) = iVar4;
    **(int **)(iVar4 + 4) = iVar4;
    puVar7 = *(undefined4 **)(param_1 + -0x78);
    if (puVar7 != *(undefined4 **)(param_1 + -0x74)) {
      do {
        piVar5 = (int *)CVOGReaction_ResolveObjectTarget(uVar2,*puVar7,puVar7[1]);
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0x130))(param_2,param_3,param_4,param_5,uVar2);
        }
        puVar7 = puVar7 + 2;
      } while (puVar7 != *(undefined4 **)(param_1 + -0x74));
    }
    if ((cVar6 != '\0') &&
       (puVar7 = *(undefined4 **)(param_1 + -0x98), puVar7 != *(undefined4 **)(param_1 + -0x94))) {
      do {
        piVar5 = (int *)CVOGReaction_ResolveObjectTarget(uVar2,*puVar7,puVar7[1]);
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0x130))(param_2,param_3,param_4,param_5,uVar2);
        }
        puVar7 = puVar7 + 4;
      } while (puVar7 != *(undefined4 **)(param_1 + -0x94));
    }
    *(undefined1 *)(param_1 + -0x36) = 0;
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
