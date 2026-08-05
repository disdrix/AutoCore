# Function record: Client_SendInventoryUnequip

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862c00` |
| **Canonical name** | `Client_SendInventoryUnequip` |
| **Address** | `0x00862c00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

C2S InventoryUnequip (0x203E, size 0x30). Builds packet with item TFID and free-slot destination X/Y; rejects when inventory has no space.

## Signature (refined)

```c
uint32_t Client_SendInventoryUnequip(void);  /* item object in EAX */
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00862c00_Client_SendInventoryUnequip.md`
- Annotated: `docs/reconstruction/raw/aa_00862c00_Client_SendInventoryUnequip.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SendInventoryUnequip.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
