# Review A (reconstruction fidelity): `aa_00588290` CVOGStore_TryAddItemQty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00588290` |
| **VA** | `0x00588290` |
| **Canonical name** | `CVOGStore_TryAddItemQty_Inferred` |
| **Review date** | `2026-08-04` (WQ8R-A dual) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00588290_CVOGStore_TryAddItemQty_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

---

## 1. Purpose

Host method on an object with **`+0x35c → InventoryGrid*`** (sole observed caller RTTI-gates **`CVOGStore`**): try to add **`qty`** of **`item`** into that grid.

1. Null item or null grid → **0**.
2. Walk grid item list: first peer with same **CBID** and **`Item_IsStackEligible`** → **add qty to peer** (no max-stack check), unlock, return **qty**.
3. Else unlock, **SetQty(item, qty)**, OR item flag **`+0x17c |= 0x10`**, dirty item.
4. Find free: if both InvSize 0 → **FindFreeSlot(2,2,page=-1)**; else **FindFreeForItem(allowStack=1,page=-1)**.
5. On hit → **PlaceItemFootprint** with GetQty; return **qty**. Else **0**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00588290` (2026-08-04) — **bit-identical** to 2026-07-23 raw body |
| Live meta | `analyze_function_complete`, callers/callees, xrefs, `read_memory` epilogue |
| Caller | `FUN_00588450` decompile — `__RTDynamicCast` → `CVOGStore`; `GetQty` then this |
| Nested duals | `Item_IsStackEligible`, `FindFreeSlot`, `FindFreeForItem`, `PlaceItemFootprint` |
| Residual | `a_005714e0` (asm `mov ecx,[ebp+0x35c]` at FindFree site), `a_005713a0` caller table |
| Raw / annotated / clean / records | see function record |
| Scratch | `docs/reconstruction/tmp/a_00588290.md` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, bit-exact.

---

## 3. Sealed facts

| # | Fact | Evidence |
|---|------|----------|
| 1 | Body `0x00588290`–`0x00588440` (`0x1B1` B) | `get_function_by_address` |
| 2 | `__thiscall`, `RET 8` | epilogue `c2 08 00` |
| 3 | Guard: null item or null `*(this+0x35c)` → 0 | decompile |
| 4 | CBID via `item+0xa8 → +0x34` | decompile; family duals |
| 5 | Merge path: GetQty+SetQty add; **no** CanAcceptStackQty | decompile (odd) |
| 6 | Free path: SetQty absolute, `\|0x10` @ +0x17c, dirty | decompile |
| 7 | InvSize 0,0 → FindFreeSlot(2,2,-1) else FindFreeForItem(...,1,-1) | decompile + residual caller table |
| 8 | Place uses FindFree out-coords (decompiler `unaff_*`) | residual + Place dual |
| 9 | Sole code caller `FUN_00588450` | xrefs/callers |
| 10 | Live decompile ≡ raw body | compare |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null guards | **Yes** |
| List traverse + CBID + IsStackEligible merge | **Yes** |
| Unlock on merge return | **Yes** |
| Free-path SetQty / flag / dirty | **Yes** |
| InvSize branch 2×2 vs FindFreeForItem | **Yes** |
| Place + return qty / 0 | **Yes** |
| Clean names for unaff out-params | **Semantic Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI + RET 8 | **High / Sealed** | |
| host+0x35c = grid | **High / Sealed** | decompile + residual asm |
| Stack merge without capacity | **High / Sealed** | preserve odd |
| `this` is CVOGStore | **Probable** | caller RTTI; layout High without product field map |
| Flag `0x10` English | **Open** | |
| Runtime Confirmed | **Open** | Terminal false |

---

## 6. Gaps

1. Product symbol for method and `+0x35c` field.
2. Whether non-store hosts share the layout (only store caller observed).
3. Intent / clamp policy for unbounded merge add.
4. Nested `FUN_00588450` / `FUN_00513200` not owned by this dual.
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
