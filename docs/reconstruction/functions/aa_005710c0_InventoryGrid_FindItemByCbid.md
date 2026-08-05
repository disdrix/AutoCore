# Function record: InventoryGrid_FindItemByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_005710c0` |
| **Canonical name** | `InventoryGrid_FindItemByCbid` |
| **Prior names** | `FUN_005710c0`, `Named_CalleeOf_Client_QuickBar_ActivateSlot_005710c0` |
| **Address** | `0x005710c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Calling convention** | MSVC `__thiscall` — `this` = inventory grid; `ret 0x0C` |
| **Completion status** | **Human-refined** — dual A/B + residual sealed 2026-07-29 (CBID key, max-stack mask, list+0x2C) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

First-fit walk of grid-held items matching **clonebase CBID** (`clonebase+0x34`). Optional stack-capacity gate for merge-into-existing paths. Does **not** look up by instance COID/TFID (that is `FUN_00571010`).

## Signature (sealed)

```c
// this = InventoryGrid*
Item* __thiscall InventoryGrid_FindItemByCbid(
    void* this,
    int itemCbid,           // match *(item[+0xA8]+0x34)
    char skipStackGate,     // !=0 → return first CBID match (Broken ignored)
    unsigned short addQty); // when gate on: need qty+addQty ≤ (maxStack & 0xFFFF)
```

## Behavioral summary (SEALED)

1. `List_TraversalLock` (`FUN_004294f0`) on list subobject **grid+0x2C**.
2. `List_IterateNext` (`FUN_004022a0`) until done.
3. Match CBID at `item[+0xA8]+0x34`.
4. If `skipStackGate`: unlock, return item.
5. Else if Broken bit19 (`item+0x17C` / mask `0x80000`): skip.
6. Else compute max stack:
   - `clonebase+0x38 == 4` → load **999999**, then capacity uses **low 16 bits** → **16959**.
   - else `*(u16*)(*(clonebase+0x3C)+0x4BA)`; if 0 → **200**.
7. `qty = vtbl[+0x25C]()`; accept if `qty + addQty <= (max & 0xFFFF)`.
8. Done with no hit → unlock (`+0x54` clear, LeaveCS `+0x30`) → NULL.

## Naming note

Older QuickBar / task text said “find-by-**COID**”. **Incorrect.** Key is CBID. Server `FindByCoid` is a different API.

## Callers (xref complete @ dual time)

| Address | Name / role | Typical args |
|---------|-------------|--------------|
| `0x005714e0` | free/merge slot helper | `(cbid, 0, qty)` |
| `0x0052aae0` | batch place pending | `(cbid, 0, 0)` |
| `0x005879e0` | credit/item consume | `(0x21A3, 0, 0)` |
| `0x00587c00` | buy/add merge | `(cbid, 0, qty)` |
| `0x0060d460` | mission req CBID gate | `(req+0x2c, 0, 0)` |
| `0x00810670` | vendor UI path | varies |
| `0x008134d0` | TradeRemove response re-add | `(cbid, 0, 0)` |
| `0x00827ab0` | QuickBar_UpdateSlotCooldownOverlay | item resolve |
| `0x008a8770` | mission compass UI | `(obj field, 0, 0)` |
| `0x008e40f0` | recipe grid presence → COID out | `(cbid, 0, 0)` |
| `0x009436c0` | Client_QuickBar_ActivateSlot | item slot |
| `0x008a9400` site | same mission UI family | — |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | **High** |
| Signature | **High** |
| Control flow | **High** (live ≡ raw 2026-07-29) |
| CBID vs COID | **High / Sealed** |
| Max-stack formula + u16 mask | **High / Sealed** |
| Broken filter | **High** |
| List embed `+0x2C` | **High / Sealed** |
| Naming | **Probable** |
| Runtime / diff | **Open** |
| Overall | **accept-with-gaps** |

## Dual reviews

| Kind | Path | Verdict |
|---|---|---|
| A (fidelity) | `reviews/A_aa_005710c0_InventoryGrid_FindItemByCbid.md` | accept-with-gaps |
| B (skeptical) | `reviews/B_aa_005710c0_InventoryGrid_FindItemByCbid.md` | accept-with-gaps |
| Residual | `reviews/a_005710c0.md` | formulas sealed |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_005710c0_FUN_005710c0.md` |
| Annotated | `raw/aa_005710c0_FUN_005710c0.annotated.md` |
| Clean | `reconstructed-exact/InventoryGrid_FindItemByCbid.cpp` |
| Scaffold clean (legacy) | `reconstructed-exact/FUN_005710c0.cpp` |
| Sibling Count | `aa_005711c0` / `InventoryGrid_CountItemsByCbid` |
| Sibling COID walk | `FUN_00571010` @ `0x00571010` |
