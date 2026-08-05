# Annotated low-level: Client_SendQuickBarUpdateFromUi

| Field | Value |
|---|---|
| Stable ID | `aa_00826720` |
| VA | `0x00826720` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00826720`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_SendQuickBarUpdateFromUi
   
   Builds and sends EMSG_Sector_QuickBarUpdate (0x2062) for the active QuickBar UI slot.
   
   Registers (custom / not pure __fastcall):
     ECX = QuickBarSlotPayload_INFERRED*  (kind@0, value@+8 as int64)
     ESI = QuickBar UI object (this from caller)
       ESI+0x500 = column index (byte)
       ESI+0x504 = page index (byte)
       absolute slot = page*10 + column
   
   Wire packet (16 bytes total, Client_SendSectorPacket size 0x10):
     +0x00 uint32 opcode = 0x2062
     +0x04 uint8  slot
     +0x05 uint8  isItem  (0 if kind==1 skill, 1 otherwise)
     +0x06 uint16 pad     (uninitialized on stack)
     +0x08 int64  value   (skillId sign-extended OR item COID)
   
   Transport: g_pSectorNetConnection_INFERRED (DAT_00d1b4b8) vtable +0x18.
   No server ack expected; UI is optimistic. Login restore via CreateCharacterExtended.
   Verified: AutoCore QuickBarUpdate session RE (2026-07). */

void __fastcall Client_SendQuickBarUpdateFromUi(QuickBarSlotPayload_INFERRED *pSlot)

{
  int unaff_ESI;
  uint dwOpcode;
  byte bSlot;
  byte bIsItem;
  uint dwValueLo;
  uint dwValueHi;
  
  if (pSlot != (QuickBarSlotPayload_INFERRED *)0x0) {
                    /* slot = page(ESI+0x504)*10 + column(ESI+0x500) */
    bSlot = *(char *)(unaff_ESI + 0x504) * '\n' + *(char *)(unaff_ESI + 0x500);
                    /* isItem = (kind != QuickBarSlotKind_Skill / 1) */
    bIsItem = pSlot->nKind != QuickBarSlotKind_Skill;
    dwValueLo = pSlot->dwValueLo;
    dwValueHi = pSlot->dwValueHi;
                    /* opcode EMSG_Sector_QuickBarUpdate = 0x2062 */
    dwOpcode = 0x2062;
    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {
      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,&dwOpcode,0x10,0);
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
