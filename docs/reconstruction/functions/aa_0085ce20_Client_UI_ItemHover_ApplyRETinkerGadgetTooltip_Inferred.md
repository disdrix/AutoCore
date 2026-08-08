# Function record: Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085ce20` |
| **Canonical name** | `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` |
| **Ghidra name** | `FUN_0085ce20` |
| **Address** | `0x0085ce20`–`0x0085d571` |
| **Module** | `autoassault.exe` |
| **System** | `inventory-transfer` |
| **Dual** | WQ8R-H 2026-08-04 — **accept-with-gaps** |

## Evidence for name

1. Product strings for Reverse Engineer, Gadget, and Tinkering Kit failure paths.
2. RTTI `CVOGGadget` / `CVOGTinkeringKit` / `CVOGClonedObjectBase`.
3. Mode field `DAT_00d1d900` already sealed as `client+0x30c0` multi-mode for RE/tinker/gadget UI (`systems/skills-abilities.md`).
4. Callers are inventory item UI widgets + `FUN_0085d900` refresh with `strictMode` 0/1.

`_Inferred` retained: no PDB; helper English (SetText vtbl names) structural.

## Cross-links

- Sibling RE action: `Inv_Client_ReverseEngineerItem` (`0x0093d110`)
- Sibling RE failure toasts: `Client_OnReverseEngineerFailure` (`0x0080df40`)
- Grid lookup: `InventoryGrid_FindItemByCoid` (`0x00571010`)
