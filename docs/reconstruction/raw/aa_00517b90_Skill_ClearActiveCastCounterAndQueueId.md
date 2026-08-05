# Raw capture: Skill_ClearActiveCastCounterAndQueueId

| Field | Value |
|---|---|
| **Stable ID** | `aa_00517b90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00517b90` |
| **Canonical name** | `Skill_ClearActiveCastCounterAndQueueId` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Skill_ClearActiveCastCounterAndQueueId(nSkillId)
   
   Parameters:
     nSkillId - skill id to queue after counter clear
   
   Algorithm: if active-cast counter>0 decrement; push skill id onto deferred queue.
   Returns: char (1 if counter was nonzero) INFERRED */

char Skill_ClearActiveCastCounterAndQueueId(int nSkillId)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  
  cVar3 = '\0';
  iVar1 = FUN_005169c0();
  if (*(int *)(iVar1 + 0x10) != 0) {
    iVar1 = FUN_005169c0();
    if ((*(int *)(iVar1 + 0x10) != 0) &&
       (iVar2 = *(int *)(iVar1 + 0x10) + -1, *(int *)(iVar1 + 0x10) = iVar2, iVar2 == 0)) {
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    cVar3 = '\x01';
  }
  piVar4 = &nSkillId;
  FUN_005169c0(piVar4);
  Skill_QueueDeferredCastId(piVar4);
  return cVar3;
}
```
