# Raw capture: CVOGObject_EvalOfferableMissionInteractState

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d5aa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004d5aa0` |
| **Canonical name** | `CVOGObject_EvalOfferableMissionInteractState` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGObject_EvalOfferableMissionInteractState
   
   Walk global mission table for missions whose NPC CBID / continent match this object.
   Skip completed (CVOGCharacter_HasCompletedMission) and already-active missions.
   If CVOGCharacter_CheckMissionRequirements returns 0 (eligible):
     return 6 if CoreMission==0, else 7  ( *(mission+0x169) )
   Else return 0.
   
   Returns: interact state byte used by Client_UpdateNpcInteractIcons. */

char CVOGObject_EvalOfferableMissionInteractState(int param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint *this;
  int *unaff_EDI;
  int iVar5;
  
  cVar4 = '\0';
  iVar5 = 0;
  piVar2 = (int *)FUN_0053fff0();
  iVar3 = *piVar2;
  if (*(char *)(iVar3 + 0x1d) != '\0') {
    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  *(undefined1 *)(iVar3 + 0x1d) = 1;
LAB_004d5ae1:
  do {
    piVar2 = (int *)FUN_0053fff0();
    iVar3 = *piVar2;
    if (*(char *)(iVar3 + 0x1d) == '\0') {
      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0,"VOG_DEBUG_STOP");
    }
    if (iVar5 == 0) {
      iVar5 = *(int *)(iVar3 + 0x14);
    }
    else {
      iVar5 = *(int *)(iVar5 + 0x14);
    }
    if (iVar5 == 0) {
      this = (uint *)0x0;
    }
    else {
      this = *(uint **)(iVar5 + 8);
    }
    if (this == (uint *)0x0) goto LAB_004d5bed;
    if (((short)this[0x2b] == -1) ||
       (bVar1 = CVOGCharacter_HasCompletedMission(param_2,*this), !bVar1)) {
      if ((this[0x22] == *(uint *)(*(int *)(param_1 + 0xa8) + 0x34)) &&
         (this[0x3f] == *(uint *)(*(int *)(param_1 + 0xa4) + 0xfc))) {
        for (iVar3 = *(int *)(*(int *)(*(int *)(param_2[0x150] + 0x10) +
                                      (*(uint *)(param_2[0x150] + 8) & *this) * 4) + 4); iVar3 != 0;
            iVar3 = *(int *)(iVar3 + 0xc)) {
          if (*this == *(uint *)(iVar3 + 0x10)) {
            if ((iVar3 != 0) && (*(int *)(iVar3 + 8) != 0)) {
              cVar4 = CVOGMission_EvalActiveObjectiveInteractState(this,param_1,param_2);
              goto LAB_004d5ae1;
            }
            break;
          }
        }
        iVar3 = CVOGCharacter_CheckMissionRequirements(this,param_2,unaff_EDI);
        if (iVar3 == 0) {
          FUN_00547920(0);
          cVar4 = (*(char *)((int)this + 0x169) != '\0') + '\x06';
          *param_3 = this;
LAB_004d5bed:
          piVar2 = (int *)FUN_0053fff0();
          *(undefined1 *)(*piVar2 + 0x1d) = 0;
          return cVar4;
        }
        cVar4 = '\0';
      }
      goto LAB_004d5ae1;
    }
    cVar4 = '\0';
  } while( true );
}
```
