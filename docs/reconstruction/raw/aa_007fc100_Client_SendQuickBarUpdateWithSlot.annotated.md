# Annotated low-level: Client_SendQuickBarUpdateWithSlot

| Field | Value |
|---|---|
| Stable ID | `aa_007fc100` |
| VA | `0x007fc100` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fc100`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_SendQuickBarUpdateWithSlot
   
   Same EMSG_Sector_QuickBarUpdate (0x2062) wire layout as Client_SendQuickBarUpdateFromUi,
   but slot is supplied in CL and payload pointer in EAX (custom register convention).
   
     EAX = QuickBarSlotPayload_INFERRED*
     CL  = absolute slot index (0..99)
   
   Packet stack buffer: Sector_QuickBarUpdatePacket (16 bytes).
   isItem = (payload->kind != 1). value = payload int64 at +8.
   
   INFERRED calling convention: registers, not standard stdcall.
   Verified: AutoCore QuickBarUpdate session RE (2026-07). */

void Client_SendQuickBarUpdateWithSlot(void)

{
  int *in_EAX;
  uint dwOpcode;
  byte bIsItem;
  uint dwValueLo;
  uint dwValueHi;
  
  if (in_EAX != (int *)0x0) {
    bIsItem = *in_EAX != 1;
                    /* slot from CL (absolute 0..99) */
    dwValueLo = in_EAX[2];
    dwValueHi = in_EAX[3];
                    /* opcode 0x2062 QuickBarUpdate */
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
