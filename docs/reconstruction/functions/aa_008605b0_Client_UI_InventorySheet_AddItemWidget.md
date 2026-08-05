# Function record: Client_UI_InventorySheet_AddItemWidget

| Field | Value |
|---|---|
| **Stable ID** | `aa_008605b0` |
| **Canonical name** | `Client_UI_InventorySheet_AddItemWidget` |
| **Address** | `0x008605b0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined** — dual A/B 2026-07-29 **accept-with-gaps**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_008605b0`
- `Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryEquip_008605b0`

## Purpose

UI-only helper: allocate an inventory-item template widget (`0x514`, ctor `FUN_0085e590` / `i_g_2d_wnd_inventory_item_template.xml`), hash-insert by item COID into the inventory window sheet, attach, stamp inventory type + page-local cell coords, pixel-place, refresh.

Does **not** send C2S packets and does **not** stamp grid footprints.

## Signature (register convention)

```c
// EDI = InventoryUiWindow*, EBX = ItemObject*
void Client_UI_InventorySheet_AddItemWidget(void);
```

Gate: `*(EDI+0x56c) != 0 && EBX != 0`.

## Behavioral summary

1. `widget = new(0x514); FUN_0085e590(widget)`.
2. `FUN_00413920(*(window+0x570), item+0x160, item+0x164, widget, 0)`.
3. On `hr >= 0`: type from `*(typeHost+4)` → `widget+0x494`; attach `window.vtbl+0xa8`; `*(window+0x500)++`; cell X/Y from item vtbl `+0x250/+0x254` with **Y′ = Y − pageH×pageIdx**; bind `widget.vtbl+0x3b0(item)`; `FUN_0085f150`; `widget.vtbl+0x34c`.
4. On fail: `widget->dtor(1)` if non-null.

### Page-local Y (asm-sealed)

```text
pageH   = typeHost ? *(typeHost+0x1c) : 0
pageIdx = *(u8*)(window+0x564)
cellY   = (item.vY() & 0xff) - pageH * pageIdx
```

Inverse of DropToGrid wire Y (`pageH×pageIdx + cellY`).

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller | `0x00860700` | Bulk sheet rebuild (iterate resolved items) |
| Caller | `0x008c3120` | Thin single-add; used by `Client_RecvInventoryEquip` |
| Callee | `0x0085e590` | Inventory item widget ctor (template XML) |
| Callee | `0x00413920` | COID hash insert |
| Callee | `0x0085f150` | Cell → pixel place |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature (EDI/EBX) | High |
| Control flow | High |
| Widget identity (template) | **Confirmed** |
| COID / typeHost / page math | High |
| Naming | High |
| Item vfunc English | Probable |
| Side effects (UI only) | High |
| Overall | Probable — dual sealed; runtime open |

## Open questions

- Window product class English (offset host shared with DropToGrid)
- Item vfunc `+0x250/+0x254` names
- Runtime multi-page icon placement check

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_008605b0_FUN_008605b0.md` |
| Annotated | `raw/aa_008605b0_FUN_008605b0.annotated.md` |
| Clean | `reconstructed-exact/Client_UI_InventorySheet_AddItemWidget.cpp` |
| Dual A | `reviews/A_aa_008605b0_Client_UI_InventorySheet_AddItemWidget.md` |
| Dual B | `reviews/B_aa_008605b0_Client_UI_InventorySheet_AddItemWidget.md` |
| Ctor | `functions/aa_0085e590_FUN_0085e590.md` |
| Drop sibling | `functions/aa_00860a50_Client_UI_InventoryDropToGrid.md` |
