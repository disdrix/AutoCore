# Function record: Client_UI_CraftHost_BindObjectByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5ce0` |
| **Canonical name** | `Client_UI_CraftHost_BindObjectByTfid_Inferred` |
| **Ghidra name** | `FUN_008e5ce0` |
| **Address** | `0x008e5ce0`–`0x008e5df3` |
| **Module** | `autoassault.exe` |
| **System** | `inventory-transfer` |
| **Dual** | WQ8R-H 2026-08-04 — **accept-with-gaps** |

## Evidence for name

1. Sole meaningful side effect is `FUN_008e5990(host, obj|null)` which stores `host+0x7cc`, rebuilds name chrome, recipe/material slots — craft/RE panel bind.
2. Resolution uses sealed `InventoryGrid_FindItemByCoid` + equip TFID table @ `char+0x5a0`.
3. Callers pass TFID from list widget vtbl+0x44c after selection change.

`_Inferred`: host class product name not RTTI-sealed in this unit.

## Cross-links

- Bind body (unowned): `FUN_008e5990` @ `0x008e5990`
- Parent refresh: `FUN_008e5e00` @ `0x008e5e00`
- Grid lookup: `InventoryGrid_FindItemByCoid` (`0x00571010`)
