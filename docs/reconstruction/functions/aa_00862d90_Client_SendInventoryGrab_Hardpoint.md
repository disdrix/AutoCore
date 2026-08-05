# Function record: Client_SendInventoryGrab_Hardpoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862d90` |
| **Canonical name** | `Client_SendInventoryGrab_Hardpoint` |
| **Address** | `0x00862d90` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

C2S InventoryGrab (0x2034, size 0x20) for equipped/hardpoint items. inventoryType=2 at +0x18; TFID from item +0x160/+0x164/+0x168. Used from item-click dispatch when store cursor empty.

## Signature (refined)

```c
int Client_SendInventoryGrab_Hardpoint(void);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00862d90_Client_SendInventoryGrab_Hardpoint.md`
- Annotated: `docs/reconstruction/raw/aa_00862d90_Client_SendInventoryGrab_Hardpoint.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SendInventoryGrab_Hardpoint.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
