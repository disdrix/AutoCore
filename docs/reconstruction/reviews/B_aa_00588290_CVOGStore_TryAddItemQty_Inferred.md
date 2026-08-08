# Review B (skeptical / adversarial): `aa_00588290` CVOGStore_TryAddItemQty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00588290` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ8R-A dual) |
| **Counterpart** | `reviews/A_aa_00588290_CVOGStore_TryAddItemQty_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + host grid + merge/place; **reject** capacity-safe stack claims and Terminal/runtime Confirmed |
| **Terminal** | **false** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always places a new footprint | **Falsified** — list stack-merge returns early without Place |
| 2 | Merge respects max stack / CanAcceptStackQty | **Falsified** — merge path has no `0040abf0`; pure add |
| 3 | `this` is InventoryGrid | **Falsified** — grid is `*(this+0x35c)`; this is host |
| 4 | `unaff_EBX` / `unaff_retaddr` are real registers as Place args | **Falsified as names** — decompiler noise for outX/outY locals from FindFree |
| 5 | InvSize 0,0 fails place | **Falsified** — forces **2×2** FindFreeSlot success path attempt |
| 6 | FindFreeForItem page is restricted | **Falsified for this site** — page `0xffffffff` (whole grid); allowStack `1` |
| 7 | Multiple code callers | **Falsified** — sole xref CALL from `FUN_00588450` |
| 8 | Product name CVOGStore_* proven by string in body | **Fail** — no strings; name from **caller RTTI** + role → `_Inferred` |
| 9 | Returns bool 0/1 only | **Falsified** — returns **qty** (or 0) |
| 10 | Terminal / runtime Confirmed | **Fail** — no Launcher |

---

## 2. Decisive dataflow (SEALED)

```
if !item || !*(host+0x35c): return 0
grid = *(host+0x35c)
BeginTraversal(grid+0x2c)
for existing in list:
  if existing && cbid(existing)==cbid(item) && IsStackEligible(existing):
    SetQty(existing, GetQty(existing)+qty)   // NO capacity check
    Unlock; return qty
Unlock
SetQty(item, qty)                            // absolute
*(item+0x17c) |= 0x10
MarkDirty(item)
if InvSizeX==0 && InvSizeY==0:
  found = FindFreeSlot(grid, 2, 2, &x, &y, -1)
else:
  found = FindFreeForItem(grid, item, &x, &y, 1, -1)
if found:
  PlaceItemFootprint(grid, item, x, y, GetQty(item)); return qty
return 0
// RET 8
```

Cross-seals: `Item_IsStackEligible` (`0x00513e70`), FindFree family duals, Place dual, residual `a_005714e0` ECX=grid.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Merge-or-place CF | **High** | Wrong store deposit |
| No merge capacity clamp | **High** | Over-stack if port adds clamp silently |
| host+0x35c | **High** | Wrong grid pointer |
| Return qty vs bool | **High** | Caller misuse |
| CVOGStore type name | **Probable** | Other hosts with same offset |
| Flag 0x10 meaning | **Tentative** | Dirty/sync side effects |
| Runtime golden | **Open** | Residual parity |

---

## 4. Surviving contract for AutoCore

```
Store.TryAddItemQty(item, qty):
  if no item/grid: fail
  if stackable peer same CBID in grid list:
    peer.qty += qty          // retail: no max clamp here
    return qty
  item.qty = qty
  item.flags |= 0x10
  mark dirty
  if both InvSize 0: find 2x2 else find free for item (stack prefer, whole grid)
  if found: place footprint; return qty
  return 0
```

**Port hazard:** servers that clamp merge to max stack diverge from this client path unless another layer clamps first.

---

## 5. Residual gaps

- `FUN_00588450` / reaction-resolve caller chain not dualed here.
- Field English for `+0x35c` and flag `0x10`.
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
