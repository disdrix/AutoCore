# Raw capture: CVOGCharacter_CompleteMissionObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536080` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00536080` |
| **Canonical name** | `CVOGCharacter_CompleteMissionObjectives` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGCharacter::CompleteMissionObjectives (static helper)
   
   Completes all objectives for a given mission by looking up the mission definition
   in the hash table, then iterating through the objectives array.
   
   Algorithm:
   1. Get auto missions hash (FUN_0053fff0)
   2. Look up mission definition by ID (CNDHash_LookupByKey)
   3. Read objectives count from mission +0x130
   4. Read objectives array pointer from mission +0x13c
   5. For each objective, call CVOGReaction_CompleteObjective with reason 0xffffffff
   
   Parameters:
     uMissionID - Mission hash ID
     uReason    - Reason code passed to CompleteObjective
   
   Returns: 1 if mission found and objectives completed, 0 if not found */

char __cdecl CVOGCharacter_CompleteMissionObjectives(uint uMissionID,undefined4 uReason)

{
  byte bVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  
                    /* // Get auto missions hash table */
  puVar2 = (undefined4 *)FUN_0053fff0();
                    /* // Look up mission definition by ID */
  if (((void *)*puVar2 != (void *)0x0) &&
     (pvVar3 = CNDHash_LookupByKey((void *)*puVar2,uMissionID), pvVar3 != (void *)0x0)) {
                    /* // Read objectives count (mission +0x130) */
    bVar1 = *(byte *)((int)pvVar3 + 0x130);
    iVar4 = 0;
    if (bVar1 != 0) {
      do {
                    /* // Get objective ID from array (mission +0x13c) */
                    /* // Complete this objective */
        CVOGReaction_CompleteObjective
                  (*(undefined4 *)(*(int *)(*(int *)((int)pvVar3 + 0x13c) + iVar4 * 4) + 0x10),
                   0xffffffff,0xffffffff,uReason);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)bVar1);
    }
    return '\x01';
  }
  return '\0';
}
```
