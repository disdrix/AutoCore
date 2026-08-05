# Raw capture: QuickBar_ClearActiveSlot_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_008274c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008274c0` |
| **Canonical name** | `QuickBar_ClearActiveSlot_INFERRED` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* QuickBar_ClearActiveSlot_INFERRED
   
   Clears the currently selected QuickBar UI slot locally:
     - item COID via CVOGCharacter_SetQuickBarItem(slot, -1)
     - skill id via CVOGCharacter_SetQuickBarSkill(slot, -1)
     - zeros QuickBarSlotPayload_INFERRED at this+0x548 (kind=0, value=-1)
   Callers then often send Client_SendQuickBarUpdateFromUi with that payload
   (IsItem=1, Value=-1) so the server persists the clear.
   
   Only partially RE'd for QuickBarUpdate clear semantics; full UI refresh side effects
   not fully documented. Name marked _INFERRED.
   Session: AutoCore QuickBarUpdate (2026-07). */

void QuickBar_ClearActiveSlot_INFERRED(void)

{
  char cVar1;
  int iVar2;
  int *unaff_ESI;
  
  unaff_ESI[0x152] = 0;
  unaff_ESI[0x154] = -1;
  unaff_ESI[0x155] = -1;
  unaff_ESI[0x156] = 0;
  unaff_ESI[0x157] = unaff_ESI[0x140] + unaff_ESI[0x141] * 10;
  CVOGCharacter_SetQuickBarItem
            (DAT_00d1b6d8,(char)unaff_ESI[0x141] * '\n' + (char)unaff_ESI[0x140],0xffffffff,
             0xffffffff);
  CVOGCharacter_SetQuickBarSkill
            (DAT_00d1b6d8,(char)unaff_ESI[0x141] * '\n' + (char)unaff_ESI[0x140],-1);
  if (DAT_00d1b984 != (int *)0x0) {
    cVar1 = (**(code **)(*DAT_00d1b984 + 0xd0))();
    if (cVar1 != '\0') {
      iVar2 = (**(code **)(*DAT_00d1b984 + 0xe8))();
      if (iVar2 != -1) {
        (**(code **)(*DAT_00d1b984 + 0xfc))();
      }
    }
  }
  (**(code **)(*unaff_ESI + 0x444))();
  if ((char)unaff_ESI[0x13f] != '\0') {
    FUN_00826780();
  }
  *(undefined1 *)((int)unaff_ESI + 0x4fe) = 0;
  if ((int *)unaff_ESI[0x15f] != (int *)0x0) {
    (**(code **)(*(int *)unaff_ESI[0x15f] + 4))();
  }
  if ((int *)unaff_ESI[0x159] != (int *)0x0) {
    iVar2 = (**(code **)(*(int *)unaff_ESI[0x159] + 0xe8))();
    if (iVar2 != 0) {
      (**(code **)(*(int *)unaff_ESI[0x159] + 0xe4))();
    }
    (**(code **)(*(int *)unaff_ESI[0x159] + 0x1d8))(&DAT_00a1419b);
    (**(code **)(*(int *)unaff_ESI[0x159] + 0x58))();
    (**(code **)(*(int *)unaff_ESI[0x159] + 0x15c))(0,&stack0xfffffff0);
    (**(code **)(*(int *)unaff_ESI[0x159] + 0x34c))();
  }
  if ((int *)unaff_ESI[0x15d] != (int *)0x0) {
    (**(code **)(*(int *)unaff_ESI[0x15d] + 0x1d8))(0);
    (**(code **)(*(int *)unaff_ESI[0x15d] + 0x34c))();
  }
  if ((int *)unaff_ESI[0x15e] != (int *)0x0) {
    (**(code **)(*(int *)unaff_ESI[0x15e] + 0x1d8))(0);
    (**(code **)(*(int *)unaff_ESI[0x15e] + 0x34c))();
  }
  return;
}
```
