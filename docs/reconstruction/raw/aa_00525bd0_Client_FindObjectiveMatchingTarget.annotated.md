# Annotated low-level: Client_FindObjectiveMatchingTarget

| Field | Value |
|---|---|
| Stable ID | `aa_00525bd0` |
| VA | `0x00525bd0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00525bd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Traverse character mission hash (param+0x548) looking for an objective that matches target object
   (param_2 = target clonebase field). Returns mission/objective node with field at +0x10 used as
   IDObjective in Client_SendUseObject (+0x18 of 0x2072 packet). Returns 0 if none. */

int __thiscall Client_FindObjectiveMatchingTarget(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = 0;
  if (*(int *)(*(int *)(param_1 + 0x55c) + 0xc) < 1) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0x548);
  if (*(char *)(iVar4 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  *(undefined1 *)(iVar4 + 0x1d) = 1;
  while( true ) {
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
    if (iVar4 == 0) break;
    for (uVar5 = 0;
        (iVar1 = *(int *)(iVar4 + 0x158), iVar1 != 0 &&
        (uVar5 < (uint)(*(int *)(iVar4 + 0x15c) - iVar1 >> 2))); uVar5 = uVar5 + 1) {
      cVar2 = (**(code **)(**(int **)(iVar1 + uVar5 * 4) + 0x38))(param_2,param_1);
      if (cVar2 != '\0') {
        *(undefined1 *)(*(int *)(param_1 + 0x548) + 0x1d) = 0;
        return iVar4;
      }
    }
  }
  *(undefined1 *)(*(int *)(param_1 + 0x548) + 0x1d) = 0;
  return 0;
}
```

## Open questions

- Character ECX provenance at `Client_SendUseObject` call site (thiscall residual).
- Full catalog of evaluator `vtable+0x38` implementers under **(key, character)** ABI.
- UseItem `FUN_0060d460` is object-ABI (char, worldObj) via `FUN_0060df70` — not sealed as key MatchTarget for this walker.
- Pending-count staleness vs active hash; runtime `0x2072` IDObjective capture.

## Dual residual (2026-07-29)

- Live decompile ≡ raw body. Sole caller SendUseObject. Contrast sealed vs `00524520` (+0x40 / id / no pending gate).
- See `reviews/A|B_aa_00525bd0_*` and scratch `reviews/a_00525bd0.md`.
