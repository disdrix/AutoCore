# Function record: Client_SendInventoryDrop_Hardpoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00863430` |
| **Canonical name** | `Client_SendInventoryDrop_Hardpoint` |
| **Address** | `0x00863430` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

C2S drop/unequip-from-cursor for hardpoint items. Blocks paint/customize-only-in-town cases and certain locked items with toast 'This item can only be changed in town.'

## Signature (refined)

```c
uint8_t Client_SendInventoryDrop_Hardpoint(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00863430_Client_SendInventoryDrop_Hardpoint.md`
- Annotated: `docs/reconstruction/raw/aa_00863430_Client_SendInventoryDrop_Hardpoint.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SendInventoryDrop_Hardpoint.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
