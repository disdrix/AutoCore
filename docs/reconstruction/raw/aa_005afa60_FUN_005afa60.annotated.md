# Annotated low-level: FUN_005afa60

| Field | Value |
|---|---|
| Stable ID | `aa_005afa60` |
| VA | `0x005afa60` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005afa60`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005afa60(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = param_2;
  FUN_0079d290(1,"CVOGVariableManager");
  param_2 = *(undefined4 *)(param_1 + 0xc);
  FUN_00498740("lNumberVars",&param_2);
  iVar3 = 0;
  if (*(char *)(param_1 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  *(undefined1 *)(param_1 + 0x1d) = 1;
  while( true ) {
    if (*(char *)(param_1 + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x14);
    }
    else {
      iVar3 = *(int *)(iVar3 + 0x14);
    }
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar3 + 8);
    }
    if (iVar2 == 0) break;
    FUN_005af890(uVar1,iVar2);
  }
  *(undefined1 *)(param_1 + 0x1d) = 0;
  FUN_0079d1e0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
