# Function record: Item_CanAcceptStackQty

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040abf0` |
| **Canonical name** | `Item_CanAcceptStackQty` |
| **Prior names** | `FUN_0040abf0`, `Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_0040abf0` |
| **Address** | `0x0040abf0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Calling convention** | MSVC `__thiscall` — `this` = destination item; `ret 4` |
| **Completion status** | **Human-refined** — dual A/B sealed 2026-07-29 (stack capacity formula + callers) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Boolean stack-capacity check: whether destination item can accept `addQty` more units under its max stack. Used by inventory merge / add / loot / equip-move callers after they have already matched CBID and filtered Broken/eligibility as needed.

## Signature (sealed)

```c
// this = destination Item*
bool __thiscall Item_CanAcceptStackQty(void* this, unsigned short addQty);
```

## Behavioral summary (SEALED)

1. `clonebase = *(item + 0xA8)`.
2. If `*(clonebase + 0x38) == 4`: `max = 999999`.
3. Else: `max = *(uint16_t*)(*(clonebase + 0x3C) + 0x4BA)`; if `max == 0` then `max = 200`.
4. `qty = item->vtbl[+0x25C]()`.
5. Return `(qty + addQty) <= (max & 0xFFFF)`.
   - Type-4 path: load 999999 then **low-16 compare** → effective **16959** (`0x423F`).
6. No mutation; leaf (no named callees besides vfunc).

## Naming note

- **Not** `Item_IsStackEligible` (`aa_00513e70`) — eligibility flags only.
- **Not** the inlined gate inside `InventoryGrid_FindItemByCbid` (`aa_005710c0`) — same max formula, different function.
- Human scaffold name `Named_CalleeOf_…_0040abf0` retained on disk as legacy clean.

## Callers (xref complete @ dual time)

| Site VA | Function | Role |
|---------|----------|------|
| `0x004fae64` | `Inventory_SerializeAddItemPacket` | merge into existing on add-item serialize |
| `0x00571558` | `FUN_005714e0` | free/merge slot helper after FindByCbid |
| `0x0094564b` | `FUN_00945540` | loot pickup stack merge |
| `0x00801406` | `FUN_008012f0` | equip/move UI merge branch |
| `0x0080159c` | `FUN_008012f0` | second merge branch |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | **High** |
| Signature | **High** |
| Control flow | **High** (live ≡ raw 2026-07-29) |
| Max-stack formula + u16 mask | **High / Sealed** |
| Call-site destination/`addQty` | **High / Sealed** |
| Naming | **Probable** |
| Type-4 product identity | **Open** |
| Runtime / diff | **Open** |
| Overall | **accept-with-gaps** |

## Dual reviews

- A: `docs/reconstruction/reviews/A_aa_0040abf0_Item_CanAcceptStackQty.md`
- B: `docs/reconstruction/reviews/B_aa_0040abf0_Item_CanAcceptStackQty.md`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040abf0_FUN_0040abf0.md`
- Annotated: `docs/reconstruction/raw/aa_0040abf0_FUN_0040abf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Item_CanAcceptStackQty.cpp`
- Legacy clean: `docs/reconstruction/reconstructed-exact/FUN_0040abf0.cpp`, `…Named_CalleeOf_…_0040abf0.cpp`
- Report: `docs/agents/task-dual-ab-0040abf0-stack-capacity-report.md`
