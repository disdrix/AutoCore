# Function record: Client_UI_InventoryItemClickDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_008635b0` |
| **Canonical name** | `Client_UI_InventoryItemClickDispatch` |
| **Address** | `0x008635b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined** — annotated + clean upgraded; dual review still open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

UI click dispatcher for inventory/equip items. Routes to Grab_Hardpoint when store empty, Drop_Hardpoint when cursor held; handles permanent-customize confirm dialog.

## Signature (refined)

```c
uint32_t __fastcall Client_UI_InventoryItemClickDispatch(int *pWidget);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008635b0_Client_UI_InventoryItemClickDispatch.md`
- Annotated: `docs/reconstruction/raw/aa_008635b0_Client_UI_InventoryItemClickDispatch.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_UI_InventoryItemClickDispatch.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Packet / UI offsets in notes | Probable–High |
| Types / names | Probable |
