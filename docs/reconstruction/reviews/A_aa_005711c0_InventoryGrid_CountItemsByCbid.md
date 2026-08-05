# Review A: `aa_005711c0` InventoryGrid_CountItemsByCbid

| Field | Value |
|---|---|
| **Review date** | `2026-07-29` (residual refresh same day; UF-014 caller label fix) |
| **Verdict** | **accept-with-gaps** |

## Inspected

- Ghidra decompile `0x005711c0` (re-check residual wave)
- Helpers `0x004294f0` (TraversalLock string), `0x004022a0` (list next)
- Callers: Collect_Eval `0x00611940`, **Deliver OnInventoryEvent** `0x00611290` (req type **3** / event type **4** — **not** Collect; UF-014), SlotAction `0x006124b0`, Collect_Action `0x00611f20`, Deliver CargoReady `0x00610f20`, audit `0x00502590` (param_3=1)
- Cross-bit evidence: `Client_RecvInventoryAddItem` `"Broken: "`, UI click `"Broken: "`, `UI_overlay_broken` / `i_g_2d_overlay_broken.dds`, setter `0x00513de0`
- Clean `InventoryGrid_CountItemsByCbid.cpp`
- Residual scratch `reviews/a_005711c0.md`
- Chain correction: `CHAIN_2026-07-29_inventory_collect.md` (Deliver type 3; event `param_4==4`)

## Confirmed

| Claim | Confidence | Evidence |
|---|---|---|
| Enumerate objects via `List_IterateNext` (`FUN_004022a0`) under `List_TraversalLock` (`FUN_004294f0`) | **High** | decompile + TraversalLock string |
| Match clonebase `+0x34` to CBID arg | **High** | `local_8[0x2a]+0x34` |
| Sum vtbl `+0x25c` quantities | **High** | loop add |
| Flag filter is **Broken** bit 19 (`item+0x17c` / mask `0x80000`); exclude when `param_3==0` | **High** | `"Broken: "` + overlay + setter |
| `param_3` = includeBroken; Collect/Deliver pass `0` | **High** | call sites |
| Critical section unlock grid+0x30 / clear +0x54 | **High** | LeaveCriticalSection |
| `this` = cargo InventoryGrid (char+0x250→+0x2b0) on collect/deliver cargo paths | **High** | callers |
| `0x00611290` is Deliver OnInventoryEvent (req type 3 / event type 4), not Collect type-4 | **High** | Deliver ctor type 3 + vtable `+0x04`; chain + Deliver duals; Collect_Eval is `0x00611940` |

## Gaps (remaining)

- Runtime / bit-exact / image diff still open (policy)
- Original PDB names unknown
- Exact InventoryGrid embed of list subobject at +0x2c is **Probable** (offset delta only)
- Deliver product name remains `_Inferred` (registry); event-type enum map open on Deliver dual B

**Verdict:** **accept-with-gaps** — dual residual **flag bit19**, **enumerator roles**, and **caller label for `0x00611290`** sealed (UF-014); only verification/runtime remain.
