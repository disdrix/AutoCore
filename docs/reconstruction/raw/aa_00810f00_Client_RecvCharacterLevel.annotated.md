# Annotated low-level: Client_RecvCharacterLevel

| Field | Value |
|---|---|
| Stable ID | `aa_00810f00` |
| VA | `0x00810f00` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00810f00`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_RecvCharacterLevel — S2C 0x2017 (Packet_CharacterLevel absolute snapshot).
   
   Algorithm:
     pObj = Client_LookupObjectByTfid_Inferred(bGlobal, coidLo, coidHi)
     if pObj: vfunc+0xcc → CVOGCharacter_ApplyCharacterLevelPacket(pObj, packet)
     if TFID matches local player: Client_RefreshLocalCharacterLevelUi + HUD
   
   Parameters: pGameClient (this/ECX), packet often in EAX from dispatch
   Returns: void.
   
   AutoCore: login restore, /credits, mission money UI sync (absolute Currency). */

void __fastcall Client_RecvCharacterLevel(void *pGameClient,Packet_CharacterLevel *pPacket)

{
  char bUiVisible;
  int pPacketInEax;
  int *pObject;
  int nLocalPlayerOff;
  int nLocalTfidBase;
  int pLocalPlayerCtx;
  
                    /* S2C CharacterLevel 0x2017 — absolute money/XP/level */
                    /* Lookup object by TFID (packet coid/global) */
  pObject = Client_LookupObjectByTfid_Inferred
                      (*(byte *)(pPacketInEax + 0x10),*(uint *)(pPacketInEax + 8),
                       *(uint *)(pPacketInEax + 0xc));
  if (pObject != (int *)0x0) {
                    /* vfunc +0xcc → CVOGCharacter_ApplyCharacterLevelPacket */
    (**(code **)(*pObject + 0xcc))();
  }
  if (*(int *)((int)pGameClient + 0xe98) != 0) {
    pLocalPlayerCtx = *(int *)((int)pGameClient + 0xe98);
    nLocalPlayerOff = *(int *)(*(int *)(pLocalPlayerCtx + 4) + 4);
    nLocalTfidBase = nLocalPlayerOff + 0x164 + pLocalPlayerCtx;
    if (((*(int *)(pPacketInEax + 8) == *(int *)(nLocalPlayerOff + 0x164 + pLocalPlayerCtx)) &&
        (*(int *)(pPacketInEax + 0xc) == *(int *)(nLocalTfidBase + 4))) &&
       (*(char *)(pPacketInEax + 0x10) == *(char *)(nLocalTfidBase + 8))) {
                    /* Local player TFID match → refresh level UI */
      Client_RefreshLocalCharacterLevelUi();
      if (*(int *)((int)pGameClient + 0x1034) != 0) {
        bUiVisible = (**(code **)(**(int **)((int)pGameClient + 0x1034) + 0x3d8))();
        if (bUiVisible != '\0') {
          pObject = *(int **)((int)pGameClient + 0x1034);
          (**(code **)(*pObject + 0x448))();
          (**(code **)(*pObject + 0x34c))();
        }
      }
    }
  }
  Client_RefreshOpenMissionUiWindows(pGameClient);
  if (*(int *)((int)pGameClient + 0x10b0) != 0) {
    bUiVisible = (**(code **)(**(int **)((int)pGameClient + 0x10b0) + 0x3d8))();
    if (bUiVisible != '\0') {
      FUN_008a05a0();
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
