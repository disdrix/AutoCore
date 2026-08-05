# Raw capture: CVOGCharacter_EvaluatePendingObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_00534920` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00534920` |
| **Canonical name** | `CVOGCharacter_EvaluatePendingObjectives` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGCharacter::EvaluatePendingObjectives
   
   Iterates through the character's pending objectives hash table, evaluating each
   objective's conditions via vtable callbacks. Objectives that pass evaluation
   are collected, then completed via CVOGReaction_CompleteObjective.
   
   Algorithm:
   1. Check state flags at vtable +0xa8 (flags +0x7e and +0xf6), bail if set
   2. Get pending objectives hash from this+0x55c, lock for traversal
   3. For each objective definition in the hash:
      a. For each evaluator function in the objective's evaluator array (at +0x158):
         - Call vtable +0x4 (pre-condition check) - skip objective if fails
         - Call vtable +0x20 (action callback) - trigger UI updates
         - Send Client_SendLogicUiPacket for UI refresh
         - Call vtable +0x8 (evaluation function) - if returns true, mark as complete
      b. If evaluation threshold met (FUN_0059d880), collect objective ID
   4. Unlock hash
   5. For each collected objective ID, call CVOGReaction_CompleteObjective
   6. Cleanup via FUN_005307e0 and free collected array
   
   Parameters:
     this - Character instance (pending objectives at +0x55c)
     p1-p4 - Additional context parameters passed to evaluator callbacks */

void __thiscall
CVOGCharacter_EvaluatePendingObjectives
          (void *this,undefined4 p1,undefined4 p2,undefined4 p3,undefined4 p4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  void *pvVar6;
  uint uVar7;
  undefined4 in_stack_00000014;
  int local_15c;
  int local_158;
  void *local_150;
  int *local_14c;
  int local_148;
  undefined4 uStack_144;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009a3ccb;
  local_c = ExceptionList;
  iVar3 = *(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this);
                    /* // Check state flag +0x7e (bail if set) */
  local_158 = 0;
                    /* // Check state flag +0xf6 (bail if set) */
  if ((*(char *)(iVar3 + 0x7e) != '\0') && (*(char *)(iVar3 + 0xf6) == '\0')) {
                    /* // Get pending objectives hash from this+0x55c */
    local_150 = (void *)0x0;
    local_14c = (int *)0x0;
    local_148 = 0;
    iVar3 = *(int *)((int)this + 0x55c);
    local_4 = 0;
    ExceptionList = &local_c;
    if (*(char *)(iVar3 + 0x1d) != '\0') {
      ExceptionList = &local_c;
      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
                    /* // Lock hash for safe traversal */
    *(undefined1 *)(iVar3 + 0x1d) = 1;
    pvVar6 = (void *)0x0;
LAB_005349b0:
                    /* // Iterate through pending objectives hash */
    iVar3 = *(int *)((int)this + 0x55c);
    if (*(char *)(iVar3 + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    piVar1 = local_14c;
    if (local_158 == 0) {
      local_158 = *(int *)(iVar3 + 0x14);
      if (local_158 == 0) goto LAB_005349ff;
      piVar5 = *(int **)(local_158 + 8);
    }
    else {
      local_158 = *(int *)(local_158 + 0x14);
      if (local_158 == 0) {
LAB_005349ff:
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = *(int **)(local_158 + 8);
      }
    }
    if (piVar5 != (int *)0x0) {
                    /* // For each evaluator in objective's evaluator array (+0x158) */
      uVar7 = 0;
      cVar4 = '\x01';
      local_15c = 0;
      while( true ) {
        iVar3 = *(int *)(*piVar5 + 0x158);
        if ((iVar3 == 0) || ((uint)(*(int *)(*piVar5 + 0x15c) - iVar3 >> 2) <= uVar7)) break;
                    /* // Call vtable +0x4: pre-condition check */
        cVar2 = (**(code **)(**(int **)(iVar3 + uVar7 * 4) + 4))
                          (this,piVar5,p1,p2,p3,p4,in_stack_00000014);
        if ((cVar2 != '\0') &&
           ((iVar3 = *piVar5, *(short *)(*(int *)(iVar3 + 0x14c) + 0xf8) == 0 ||
            (*(char *)(iVar3 + 0x14) != '\0')))) {
                    /* // Call vtable +0x20: action callback */
          (**(code **)(**(int **)(*(int *)(iVar3 + 0x158) + uVar7 * 4) + 0x20))(this,piVar5);
                    /* // Send LogicUI packet for refresh */
          uStack_144 = 4;
          Client_SendLogicUiPacket(&stack0xfffffea0);
        }
                    /* // Call vtable +0x8: evaluation function */
        cVar2 = (**(code **)(**(int **)(*(int *)(*piVar5 + 0x158) + uVar7 * 4) + 8))(this,piVar5);
        if (cVar2 != '\0') {
          local_15c = local_15c + 1;
        }
        if (cVar4 != '\0') {
          cVar4 = cVar2;
        }
        uVar7 = uVar7 + 1;
      }
                    /* // Check evaluation threshold via FUN_0059d880 */
      iVar3 = FUN_0059d880();
                    /* // Collect completed objective ID (+0x10) into array */
      if ((((iVar3 != 0) && (iVar3 = FUN_0059d880(), iVar3 <= local_15c)) ||
          (pvVar6 = local_150, cVar4 != '\0')) &&
         (pvVar6 = local_150, *(int *)(*piVar5 + 0x138) == 0)) {
        local_15c = *(int *)(*piVar5 + 0x10);
        if ((local_150 == (void *)0x0) ||
           ((uint)(local_148 - (int)local_150 >> 2) <= (uint)((int)local_14c - (int)local_150 >> 2))
           ) {
          FUN_004073a0(local_14c,1,&local_15c);
          pvVar6 = local_150;
        }
        else {
          *local_14c = local_15c;
          local_14c = local_14c + 1;
        }
      }
      goto LAB_005349b0;
    }
    *(undefined1 *)(*(int *)((int)this + 0x55c) + 0x1d) = 0;
                    /* // Complete all collected objectives */
    for (uVar7 = 0; (pvVar6 != (void *)0x0 && (uVar7 < (uint)((int)piVar1 - (int)pvVar6 >> 2)));
        uVar7 = uVar7 + 1) {
                    /* // CVOGReaction_CompleteObjective for each completed objective */
      CVOGReaction_CompleteObjective
                (*(undefined4 *)((int)pvVar6 + uVar7 * 4),0xffffffff,0xffffffff,0);
    }
                    /* // Cleanup and free collected objectives array */
    FUN_005307e0();
    if (pvVar6 != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar6);
    }
  }
  ExceptionList = local_c;
  return;
}
```

---

## Version note (2026-07-29 dual tighten — append only)

Do not alter the raw body above. Dual A/B re-decompile confirms CF match. Corrections applied in annotated/clean/reviews only:

1. **FUN_0059d880** is not opaque: `return *(param_1 + 0x164)` = objective **CompleteCount** (XML dump `FUN_005468c0` emits `<CompleteCount>` via this getter). Call sites `0x00534ae2` / `0x00534aed`.
2. Collect: `(CompleteCount != 0 && CompleteCount <= successCount) || allTrue`, gated by `def+0x138 == 0`.
3. Plate algorithm text errors: "bail if flags set" (wrong polarity for `+0x7e`); "skip objective if precheck fails" (precheck only gates action/LogicUI).
4. `CompleteObjective` is `__thiscall` on character; force trailing `0`. `FUN_005307e0` is `__fastcall` on character (drains `+0x564` when non-empty).

## Version note (2026-07-29 dual residual re-pass — append only)

Additional residuals sealed (annotated/clean/reviews only; raw body untouched):

5. Pending hash `node+8` is a **slot**, not bare def*: asm `mov ecx,[esi]` / `push esi` before eval and CompleteCount; `mov esi,[esi]` before `+0x138` / `+0x10`.
6. Dual `FUN_0059d880` CALL is real (zero-test then `success >= count`); not decompiler noise. Twin of CompleteObjective force=0 algebra.
7. Exactly **7** static CODE xrefs (AddCredits/CompleteObjective/combat/35c60/35ed0/Patrol×2). Not RecvObjectiveState / CompleteMissionObjectives.
8. Kind **6** only on CompleteObjective **final** path (`pvVar7==0`). `FUN_005307e0` always zeros `+0x564` vec and `+0xd6c/+0xd68`.
