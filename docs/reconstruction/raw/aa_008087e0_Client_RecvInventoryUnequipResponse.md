# Raw capture: Client_RecvInventoryUnequipResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_008087e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008087e0` |
| **Canonical name** | `Client_RecvInventoryUnequipResponse` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* S2C InventoryUnequipResponse 0x203F. Packet in EAX: if success byte@+0x10==0, OutputDebugString
   unsync fail with coid@+0x08. No state mutation. */

void Client_RecvInventoryUnequipResponse(void)

{
  int in_EAX;
  char local_80 [128];
  
  if (*(char *)(in_EAX + 0x10) == '\0') {
    sprintf(local_80,
            "Your Inventory is unsynchronized. VOGClient::InventoryUnequip_Response Failed on coid: %i\n"
            ,*(undefined4 *)(in_EAX + 8));
    OutputDebugStringA(local_80);
  }
  return;
}
```
