# Function record: Client_SendInventoryAddItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00530df0` |
| **Canonical name** | `Client_SendInventoryAddItem` |
| **Address** | `0x00530df0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean** — dual review not required this wave; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Build opcode `0x2047` (0x20) AddItem packet, call `Inventory_SerializeAddItemPacket`, place (`FUN_00571620`) or merge stack, free heap packet. Logs inventory failure on residual check miss.

## Signature

```c
void __thiscall Client_SendInventoryAddItem(int pHost, int* pItem, uint32_t param3);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00530df0_Client_SendInventoryAddItem.md`
- Annotated: `docs/reconstruction/raw/aa_00530df0_Client_SendInventoryAddItem.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SendInventoryAddItem.cpp`

## Confidence

| Claim | Level |
|---|---|
| Opcode 0x2047 + size 0x20 | High |
| Serialize callee + +0x12 branch | High |
| operator_delete noreturn warnings | Tentative (Ghidra) |
