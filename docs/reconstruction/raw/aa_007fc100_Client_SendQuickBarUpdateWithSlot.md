# Raw capture: Client_SendQuickBarUpdateWithSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc100` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fc100` |
| **Canonical name** | `Client_SendQuickBarUpdateWithSlot` |
| **System** | skills-abilities |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
