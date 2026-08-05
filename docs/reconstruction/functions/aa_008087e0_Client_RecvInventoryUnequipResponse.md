# Function record: Client_RecvInventoryUnequipResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_008087e0` |
| **Canonical name** | `Client_RecvInventoryUnequipResponse` |
| **Address** | `0x008087e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

S2C InventoryUnequipResponse (opcode 0x203F). On failure (success byte==0) prints unsync debug line with item coid; no inventory mutation on client.

## Signature (refined)

```c
void Client_RecvInventoryUnequipResponse(void);  /* packet ptr in EAX */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008087e0_Client_RecvInventoryUnequipResponse.md`
- Annotated: `docs/reconstruction/raw/aa_008087e0_Client_RecvInventoryUnequipResponse.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_RecvInventoryUnequipResponse.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
