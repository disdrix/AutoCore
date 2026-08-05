# Raw capture: CVOGCharacter_HasCompletedMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052aa20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052aa20` |
| **Canonical name** | `CVOGCharacter_HasCompletedMission` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGCharacter_HasCompletedMission  (thiscall)
   
   True if missionId is in completed-mission hash (char+0x538) or instance-completed (+0x53c)
   with continent match. Used to gate re-offers and interact icon states. */

bool __thiscall CVOGCharacter_HasCompletedMission(void *this,uint missionId)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  
  if (*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this) == 0) {
    pvVar3 = CNDHash_LookupByKey(*(void **)((int)this + 0x538),missionId);
    return pvVar3 != (void *)0x0;
  }
  puVar2 = (undefined4 *)FUN_0053fff0();
  if ((((((void *)*puVar2 == (void *)0x0) ||
        (pvVar3 = CNDHash_LookupByKey((void *)*puVar2,missionId), pvVar3 == (void *)0x0)) ||
       (*(int *)((int)pvVar3 + 0xfc) !=
        *(int *)(*(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xa8 + (int)this) + 0xfc))) ||
      (cVar1 = CVOGCharacter_WeaponAllowsKillXpBonus(), cVar1 == '\0')) &&
     (pvVar3 = CNDHash_LookupByKey(*(void **)((int)this + 0x538),missionId), pvVar3 != (void *)0x0))
  {
    return true;
  }
  cVar1 = CVOGCharacter_WeaponAllowsKillXpBonus();
  if ((cVar1 != '\0') &&
     (pvVar3 = CNDHash_LookupByKey(*(void **)((int)this + 0x53c),missionId), pvVar3 != (void *)0x0))
  {
    return true;
  }
  return false;
}
```
