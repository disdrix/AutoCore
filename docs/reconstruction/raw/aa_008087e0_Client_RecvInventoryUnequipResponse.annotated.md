# Annotated low-level: Client_RecvInventoryUnequipResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_008087e0` |
| **VA** | `0x008087e0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | inventory-transfer |
| **Source raw** | `aa_008087e0_Client_RecvInventoryUnequipResponse.md` |
| **Refine** | Human pass 2026-07-23 (named_hl keyword wave) |

This file is the **annotated** layer: packet/UI offsets, branch order, and decompiler corrections.

---

## 1. Purpose

S2C InventoryUnequipResponse (opcode 0x203F). On failure (success byte==0) prints unsync debug line with item coid; no inventory mutation on client.

## 2. Corrected signature

```c
void Client_RecvInventoryUnequipResponse(void);  /* packet ptr in EAX */
```

## 3. Key offsets / packet fields

| Offset / symbol | Role |
|---|---|
| `pkt+0x08` | item coid (int) used in fail message |
| `pkt+0x10` | success byte; 0 = unsync fail |

## 4. Machine-level notes

- Packet base arrives in EAX (decompiler in_EAX).
- Success gate is byte at packet+0x10; zero means failure.
- Failure path only: sprintf + OutputDebugStringA; no UI toast.
- Item coid for message at packet+0x08.

## 5. Pseudocode (authoritative raw, retained)

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

## 6. Open questions

- Confirm opcode/dispatch table row and whether success path does anything elided by decompiler.
