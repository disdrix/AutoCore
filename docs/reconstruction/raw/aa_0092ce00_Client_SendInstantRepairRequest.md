# Raw capture: Client_SendInstantRepairRequest

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092ce00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092ce00` |
| **Canonical name** | `Client_SendInstantRepairRequest` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_SendInstantRepairRequest — INC option 1.
   Sends opcode 0x20B6 (EMSG_Sector_InstantRepair_Request), body often just opcode (4 bytes).
   Not implemented in AutoCore yet. */

void Client_SendInstantRepairRequest(void)

{
  int iVar1;
  int in_EAX;
  DWORD DVar2;
  undefined4 local_4;
  
  if (DAT_00d1b6d8 != 0) {
    local_4 = 0x20b6;
    if (*(int *)(in_EAX + 0xc78) != 0) {
      (**(code **)(**(int **)(in_EAX + 0xc78) + 0x18))(0xffffffff,&local_4,4,0);
    }
    iVar1 = DAT_00d1b6d8;
    DVar2 = GetTickCount();
    *(DWORD *)(iVar1 + 0x620) = DVar2;
  }
  return;
}
```
