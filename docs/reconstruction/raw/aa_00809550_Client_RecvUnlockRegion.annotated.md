# Annotated low-level: Client_RecvUnlockRegion

| Field | Value |
|---|---|
| Stable ID | `aa_00809550` |
| VA | `0x00809550` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00809550`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* S2C EMSG_Sector_UnlockRegion (0x205B).
   Packet: opcode, ContinentId(int), UnlockFlag(byte)+pad3, ExploredBits(uint).
   If UnlockFlag==0: relock continent.
   If no local USContinentUnlocked entry: UnlockContinentObject only (bits=0; ignores packet bits).
   If entry exists and bits differ: per-bit CVOGCharacter_SetAreaExploredBit for areas 1..32.
   AutoCore: UnlockRegionPacket; send twice after login to bootstrap then apply bits. */

void __fastcall Client_RecvUnlockRegion(void *gameState)

{
  void *this;
  void *pvVar1;
  uint uVar2;
  uint bitMask;
  int iVar3;
  int pPacket;
  int in_stack_00000004;
  
  this = *(void **)(in_stack_00000004 + 0xe98);
  if (this != (void *)0x0) {
    if (*(char *)(pPacket + 8) == '\0') {
      CVOGReaction_RelockContinentObject(*(undefined4 *)(pPacket + 4));
      return;
    }
    uVar2 = *(uint *)(pPacket + 4);
    pvVar1 = CNDHash_LookupByKey(*(void **)((int)this + 0x534),uVar2);
                    /* UnlockFlag==0 -> relock continent */
    if (pvVar1 == (void *)0x0) {
      CVOGReaction_UnlockContinentObject(this,uVar2);
    }
    else if (*(int *)((int)pvVar1 + 8) != *(int *)(pPacket + 0xc)) {
      iVar3 = 0;
      do {
                    /* No entry: create empty USContinentUnlocked (bits=0); packet ExploredBits
                       IGNORED */
        uVar2 = 1 << ((byte)iVar3 & 0x1f);
        bitMask = *(uint *)(pPacket + 0xc) & uVar2;
                    /* Bits differ: apply per-area SetAreaExploredBit for 1..32 */
        if (bitMask != (*(uint *)((int)pvVar1 + 8) & uVar2)) {
          CVOGCharacter_SetAreaExploredBit
                    (*(void **)(in_stack_00000004 + 0xe98),*(int *)(pPacket + 4),(byte)iVar3 + 1,
                     bitMask != 0);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x20);
      return;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
