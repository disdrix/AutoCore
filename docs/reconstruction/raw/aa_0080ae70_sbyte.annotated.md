# Annotated low-level: sbyte

| Field | Value |
|---|---|
| Stable ID | `aa_0080ae70` |
| VA | `0x0080ae70` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0080ae70`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_AwardKillExperience — S2C GiveXP 0x205F handler (docs/XP.md)
   
   NOTE: Historical name; handles all GiveXP packets, not kills only.
   
   Parameters:
     pGiveXp - GiveXpPacketBody* (amount + levelHint)
     Register state (INFERRED custom dispatch):
       EDI+0xe98 = local Character*
       ESI       = packet framing pointer (amount often at ESI+4)
   
   Algorithm:
     1) Bail if no local character (VOG_DEBUG_STOP)
     2) CVOGReaction_AddExperience(char, amount, PacketOrNonKill)
     3) if levelHint != -1: char+0x738 = hint; char+0x734 = GetTickCount()
     4) if vehicle present: queue combat floater type XP (3)
   
   Returns: void
   Wire: Amount int32, LevelHint sbyte (-1 = none) */

void __cdecl Client_AwardKillExperience(GiveXpPacketBody *pGiveXp)

{
  DWORD DVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_10;
  undefined4 uStack_8;
  
                    /* // Get client state from EDI+0xe98, bail if null */
  if (*(void **)(unaff_EDI + 0xe98) == (void *)0x0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
    return;
  }
                    /* // Award XP via CVOGReaction_AddExperience */
  CVOGReaction_AddExperience(*(void **)(unaff_EDI + 0xe98),*(int *)(unaff_ESI + 4),PacketOrNonKill);
                    /* // Update character level (client_state+0x738) if level changed */
  if (*(char *)(unaff_ESI + 8) != -1) {
    *(char *)(*(int *)(unaff_EDI + 0xe98) + 0x738) = *(char *)(unaff_ESI + 8);
                    /* // Record timestamp for level change */
    DVar1 = GetTickCount();
    *(DWORD *)(*(int *)(unaff_EDI + 0xe98) + 0x734) = DVar1;
  }
                    /* // Build and send XP award packet (type 0x3) */
  iVar2 = *(int *)(*(int *)(unaff_EDI + 0xe98) + 0x250);
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1c8))();
    uStack_38 = DAT_00a1e840;
    uStack_30 = DAT_00a1e848;
    uStack_34 = DAT_00a1e844;
    uStack_2c = DAT_00a1e84c;
    iVar2 = iVar2 + *(int *)(*(int *)(iVar2 + 4) + 4);
    uStack_28 = *(undefined4 *)(iVar2 + 0x164);
    uStack_24 = *(undefined4 *)(iVar2 + 0x168);
    uStack_20 = *(undefined4 *)(iVar2 + 0x16c);
    uStack_1c = *(undefined4 *)(iVar2 + 0x170);
    uStack_18 = *(undefined4 *)(unaff_ESI + 4);
    uStack_8 = 3;
    uStack_10 = 0;
    Client_EnqueueCombatFloater_INFERRED(&uStack_38);
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
