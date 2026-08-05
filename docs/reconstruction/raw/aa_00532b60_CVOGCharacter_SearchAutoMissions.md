# Raw capture: CVOGCharacter_SearchAutoMissions

| Field | Value |
|---|---|
| **Stable ID** | `aa_00532b60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00532b60` |
| **Canonical name** | `CVOGCharacter_SearchAutoMissions` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGCharacter::SearchAutoMissions
   
   Iterates the character's auto-eligible missions hash table, skipping already-active
   and completed missions. For each candidate mission, calls CheckMissionRequirements
   (FUN_005462b0) to validate level, race, faction, XP, and prerequisite missions.
   If all requirements pass (returns 0), invokes CVOGReaction_GiveMission. */

void __fastcall CVOGCharacter_SearchAutoMissions(int *this)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint *this_00;
  int *unaff_ESI;
  int iVar4;
  void *l_prevException;
  undefined1 *puStack_8;
  undefined4 l_excGuard;
  
  l_excGuard = 0xffffffff;
  puStack_8 = &LAB_009a3ca1;
  l_prevException = ExceptionList;
  ExceptionList = &l_prevException;
  FUN_00786a00("CVOGCharacter::SearchAutoMissions");
  l_excGuard = 0;
  iVar4 = 0;
  iVar2 = FUN_0053fff0();
  if (iVar2 == 0) {
                    /* // No auto missions available */
    l_excGuard = 0xffffffff;
    FUN_00786990();
    ExceptionList = l_prevException;
    return;
  }
  piVar3 = (int *)FUN_0053fff0();
  iVar2 = *piVar3;
  if (*(char *)(iVar2 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
                    /* // Lock hash for safe traversal */
  *(undefined1 *)(iVar2 + 0x1d) = 1;
LAB_00532c00:
  do {
    piVar3 = (int *)FUN_0053fff0();
    iVar2 = *piVar3;
    if (*(char *)(iVar2 + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    if (iVar4 == 0) {
      iVar4 = *(int *)(iVar2 + 0x14);
      if (iVar4 == 0) goto LAB_00532c4a;
      this_00 = *(uint **)(iVar4 + 8);
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x14);
      if (iVar4 == 0) {
LAB_00532c4a:
        this_00 = (uint *)0x0;
      }
      else {
        this_00 = *(uint **)(iVar4 + 8);
      }
    }
    if (this_00 == (uint *)0x0) {
      piVar3 = (int *)FUN_0053fff0();
      *(undefined1 *)(*piVar3 + 0x1d) = 0;
      l_excGuard = 0xffffffff;
      FUN_00786990();
      ExceptionList = l_prevException;
      return;
    }
    if ((short)this_00[0x3e] != 0) {
                    /* // Skip if mission already active (hash at this+0x540) */
      uVar1 = *this_00;
      for (iVar2 = *(int *)(*(int *)(*(int *)(this[0x150] + 0x10) +
                                    (*(uint *)(this[0x150] + 8) & uVar1) * 4) + 4); iVar2 != 0;
          iVar2 = *(int *)(iVar2 + 0xc)) {
        if (uVar1 == *(uint *)(iVar2 + 0x10)) {
          if ((iVar2 != 0) && (*(int *)(iVar2 + 8) != 0)) goto LAB_00532c00;
          break;
        }
      }
                    /* // Skip if mission already completed (hash at this+0x538) */
      for (iVar2 = *(int *)(*(int *)(*(int *)(this[0x14e] + 0x10) +
                                    (*(uint *)(this[0x14e] + 8) & uVar1) * 4) + 4); iVar2 != 0;
          iVar2 = *(int *)(iVar2 + 0xc)) {
        if (uVar1 == *(uint *)(iVar2 + 0x10)) {
          if ((iVar2 != 0) && (*(int *)(iVar2 + 8) != 0)) goto LAB_00532c00;
          break;
        }
      }
                    /* // Check level/race/faction/XP/prereq requirements */
      iVar2 = CVOGCharacter_CheckMissionRequirements(this_00,this,unaff_ESI);
      if (iVar2 == 0) {
                    /* // Award mission - all requirements satisfied */
        CVOGReaction_GiveMission(*this_00);
      }
    }
  } while( true );
}
```
