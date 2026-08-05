# Review B (skeptical / adversarial): `aa_0085e590` Client_UI_InventoryItemWidget_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085e590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/A_aa_0085e590_Client_UI_InventoryItemWidget_ctor.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on ctor role + strings + CF; **reject** overclaims that this places, binds, or prices items |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This places the widget on the grid | No pitch/origin math; place is `FUN_0085f150` | **Falsified** |
| 2 | This binds an item COID / object | No `+0x160` / item ptr; bind is parent `vtbl+0x3b0` | **Falsified** |
| 3 | This is the full inventory window | Loads **item** template XML, not window root | **Falsified** |
| 4 | Overlay load failure is soft | Fail path deletes + nulls; `FUN_0096efd0` may noreturn on assert path | **Partial** — soft null if delete path returns; decompiler marks noreturn |
| 5 | Only one caller (AddItemWidget) | Four callers from `get_function_callers` | **Falsified** sole-caller claim |
| 6 | Product symbol sealed | Role name from strings only | **Fail** complete |
| 7 | Ready for runtime parity | No live UI | **Open** |

---

## 2. Decisive dataflow (SEALED)

```text
InventoryItemWidget* __thiscall Client_UI_InventoryItemWidget_ctor(void* mem)
{
    // SEH…
    NDUI_BaseInit(mem, 0);                 // FUN_007b5dd0
    *(void**)mem = &PTR_FUN_00a65354;
    FUN_0085cd40(/*this*/);
    // zero inventory-specific fields (see A)
    NDUIWindow_LoadInterfaceFile("i_g_2d_wnd_inventory_item_template.xml");
    FUN_0085dc30();
    LoadOverlaySlot(mem+0x50C, "i_g_2d_overlay_broken.dds");
    LoadOverlaySlot(mem+0x510, "i_g_2d_highlight.dds");
    return mem;
}
```

Live decompile 2026-07-29 ≡ 2026-07-23 raw.

**Cross-seals:**

| Peer | Relation |
|------|----------|
| `Client_UI_InventorySheet_AddItemWidget` | `new(0x514)` → this ctor → hash insert → place |
| `Client_UI_InventoryItemWidget_PlaceFromCell` | uses cell slots parent stamps after this returns |
| Template string | **Confirmed** inventory item chrome |

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor for sheet item widget | **High** | Wrong UI class |
| Broken/highlight DDS roles | **High** | Wrong overlay mapping |
| Does not bind item | **High** | Invented inventory mutation |
| Field dictionary beyond known | **Low–Med** | Doc noise |
| Product name | **Open** | Rename residual |

---

## 4. Surviving contract for AutoCore

```text
// UI-only placement-new for inventory sheet icon:
widget = Client_UI_InventoryItemWidget_ctor(operator_new(0x514));
// then parent stamps type/cell, binds item, places pixels
```

Do **not** use this unit for grid logic, packets, or vendor math.

**Verdict:** **accept-with-gaps**
