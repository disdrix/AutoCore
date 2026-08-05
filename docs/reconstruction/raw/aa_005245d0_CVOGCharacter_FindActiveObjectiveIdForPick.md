# Raw capture: CVOGCharacter_FindActiveObjectiveIdForPick

| Field | Value |
|---|---|
| **Stable ID** | `aa_005245d0` |
| **VA** | `0x005245d0` |
| **Canonical name** | `CVOGCharacter_FindActiveObjectiveIdForPick` |
| **Prior** | `FUN_005245d0`; scaffold `…ForInteractAlt` |
| **System** | interaction-activation |
| **Capture** | Ghidra `decompile_function` 2026-07-29 (matches 2026-07-23 raw body) |

## Raw pseudocode

```c
undefined4 __thiscall FUN_005245d0(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0x548);
  iVar3 = 0;
  uVar2 = 0;
  if (*(char *)(iVar4 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  *(undefined1 *)(iVar4 + 0x1d) = 1;
  do {
    iVar4 = *(int *)(param_1 + 0x548);
    if (*(char *)(iVar4 + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    if (iVar3 == 0) {
      iVar3 = *(int *)(iVar4 + 0x14);
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x14);
    }
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar3 + 8);
    }
    if (iVar4 == 0) goto LAB_00524666;
    // thiscall: ECX = objective payload (iVar4); stack (character, worldObject)
    cVar1 = FUN_0059da10(param_1,param_2);
  } while (cVar1 == '\0');
  uVar2 = *(undefined4 *)(iVar4 + 0x10);
LAB_00524666:
  *(undefined1 *)(*(int *)(param_1 + 0x548) + 0x1d) = 0;
  return uVar2;
}
```

## Notes

- Authoritative scaffold raw: `aa_005245d0_FUN_005245d0.md` (do not overwrite scaffold body).
- Sole structural difference from sibling `0x00524520`: callee `FUN_0059da10` (eval **vtable+0x44**) vs `FUN_0059d9c0` (**+0x40**).
