# Function record: InventoryGrid_CountItemsByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_005711c0` |
| **Canonical name** | `InventoryGrid_CountItemsByCbid` |
| **Prior name** | `FUN_005711c0` |
| **Address** | `0x005711c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer (+ missions collect bridge) |
| **Calling convention** | MSVC `__thiscall` — `this` = inventory grid |
| **Completion status** | **Human-refined** — inventory↔collect bridge sealed (static); dual residual bit19/helpers sealed 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Walk all items in an inventory grid and sum stack quantities for items whose clonebase CBID matches `itemCbid`. When `includeBroken == 0`, skips items with **Broken** flag bit 19 at `item+0x17c` (`object[0x5f] >> 0x13 & 1`, mask `0x80000`).

## Signature

```c
// this = InventoryGrid*
int __thiscall InventoryGrid_CountItemsByCbid(
    void* this, int itemCbid, char includeBroken /* param_3 */);
```

## Behavioral summary

1. `List_TraversalLock` (`FUN_004294f0`) then iterate via `List_IterateNext` (`FUN_004022a0`).
2. For each object: match `*(object[0x2a]+0x34) == itemCbid`.
3. If `includeBroken==0`, exclude when Broken bit 19 set on `object[0x5f]` / `+0x17c`.
4. Add vtable `+0x25c` quantity (stack size).
5. Unlock critical section at grid `+0x30` if grid `+0x54` flag set (paired TraversalUnlock; **Probable** list subobject at grid+0x2c).
6. Return total count.

## Flag bit 19 = Broken (sealed)

| Cross-ref | Note |
|-----------|------|
| Loot log / UI | Prefix `"Broken: "` when bit set |
| `UI_overlay_broken` | Texture `i_g_2d_overlay_broken.dds` |
| `FUN_00513de0` | Setter xor `0x80000` |
| Stack merge `0x004fadb0` | Both sides must have bit clear |
| Equip `0x004fabc0` | Returns code 9 if set |

Collect/Deliver mission paths pass **`includeBroken = 0`** so broken stacks do not advance cargo-count progress.

## Callers (collect / deliver bridge)

| Caller | Role | includeBroken |
|--------|------|---------------|
| `FUN_00611940` / Collect_Eval | progress = count / NumToCollect | `0` |
| `FUN_00611290` / `CVOGObjectiveRequirement_Deliver_OnInventoryEvent_Inferred` | Deliver **req type 3**; OnInventoryEvent when **event type 4** (`param_4==4`); count vs deliver qty — **not** Collect type-4 | `0` |
| `FUN_006124b0` / Collect_SlotAction | Collect UI string `"%s: %d / %d"` | `0` |
| `FUN_00611f20` / Collect_Action inv arm | progress signal | `0` |
| `FUN_00610f20` / `CVOGObjectiveRequirement_Deliver_CargoReady_Inferred` | Deliver cargo readiness | `0` |
| `FUN_00502590` inventory audit | include broken stacks | `1` |
| Other inventory/vendor paths | quantity queries | varies |

**Label note (UF-014 sealed):** do not call `0x00611290` “Collect type-4”. That address is Deliver OnInventoryEvent (req type 3 / event type 4). Collect Eval remains `0x00611940`.

Collect/Deliver cargo paths pass **cargo grid** at `character+0x250 → +0x2b0` (same type-1 grid as DropResponse).

## Confidence

| Dimension | Level |
|---|---|
| CBID match at clonebase `+0x34` | **High** |
| Quantity via vtbl `+0x25c` | **High** |
| Flag filter bit 19 = Broken | **High** |
| TraversalLock / IterateNext roles | **High** |
| Name | **High** (behavior); original symbol unknown |

## Related

- Dual residual: `reviews/a_005711c0.md`
- Chain: `reviews/CHAIN_2026-07-29_inventory_collect.md`
- Collect eval: `aa_00611940`
- Clean: `reconstructed-exact/InventoryGrid_CountItemsByCbid.cpp`
- Duals: `A_aa_005711c0_*`, `B_aa_005711c0_*`
