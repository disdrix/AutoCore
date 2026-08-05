# Dual A/B report — `aa_0040abf0` Item_CanAcceptStackQty (stack capacity check)

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x0040abf0`. Dual A/B + artifacts. Seal stack capacity predicate.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040abf0` Item_CanAcceptStackQty | **accept-with-gaps** — formula / u16 mask / callers **sealed** |

---

## Sealed facts

1. **Role:** Boolean **stack capacity** check — can destination item absorb `addQty` more units.  
   **Not** eligibility (`Item_IsStackEligible` / `aa_00513e70`).

2. **ABI:** `__thiscall`  
   - `ECX` = destination `Item*`  
   - stack `uint16_t addQty`  
   - return **bool in AL** (`setle`; decompiler `CONCAT31` is noise)  
   - `ret 4`

3. **Max-stack formula:**
   - `clonebase = *(item + 0xA8)`
   - if `*(clonebase + 0x38) == 4` → load **999999** (`0x000F423F`)
   - else `max = *(uint16_t*)(*(clonebase + 0x3C) + 0x4BA)`; if **0** → **200**
   - compare uses **`(max & 0xFFFF)`** (`movzx edx, si`)
   - type-4 **effective** cap = **16959** (`0x423F`), not 999999

4. **Quantity:** `qty = this->vtbl[+0x25C]()`; predicate  
   `(qty + addQty) <= (max & 0xFFFF)`.

5. **Callers (exactly 5 sites / 4 functions):**

   | Site | Function |
   |------|----------|
   | `0x004fae64` | `Inventory_SerializeAddItemPacket` |
   | `0x00571558` | `FUN_005714e0` |
   | `0x0094564b` | `FUN_00945540` |
   | `0x00801406` | `FUN_008012f0` |
   | `0x0080159c` | `FUN_008012f0` |

   All sites: **ECX = existing stack**, **push = incoming qty** (from source `vtbl+0x25C`).

6. **Sibling:** same max formula **inlined** in `InventoryGrid_FindItemByCbid` (`aa_005710c0`); this VA is the **shared leaf** used by merge callers.

7. **No mutation** of inventory state; leaf aside from virtual qty.

---

## Gaps

1. Product name of clonebase type class **4** (currency/quest/special — interpretive).  
2. Product name of def field `+0x4BA` (role sealed as max stack).  
3. Whether AutoCore **server** stack policy must mirror type-4 **16959** mask quirk.  
4. Original PDB symbol.  
5. Runtime / bit-exact image verification.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0040abf0_Item_CanAcceptStackQty.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0040abf0_Item_CanAcceptStackQty.md` |
| Function record | `docs/reconstruction/functions/aa_0040abf0_Item_CanAcceptStackQty.md` |
| Alias record | `docs/reconstruction/functions/aa_0040abf0_FUN_0040abf0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_CanAcceptStackQty.cpp` |
| Raw (authoritative + live) | `docs/reconstruction/raw/aa_0040abf0_FUN_0040abf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040abf0_FUN_0040abf0.annotated.md` |
| Naming registry | `docs/reconstruction/NAMING_REGISTRY.md` (`Item_CanAcceptStackQty` row) |
| Scratch | `tmp/a_0040abf0.md` |
| This report | `docs/agents/task-dual-ab-0040abf0-stack-capacity-report.md` |

Legacy scaffold names retained on disk:  
`reconstructed-exact/FUN_0040abf0.cpp`,  
`reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryAddItem_0040abf0.cpp`.

---

## AutoCore impact

- Client merge accept = **`(destQty + addQty) <= effectiveMax`** with effectiveMax always **u16-truncated**.
- Def max stack at **`*(clonebase+0x3C)+0x4BA`**, default **200** when zero; type **4** loads 999999 then masks to **16959** on this path.
- Keep eligibility (`Item_IsStackEligible` / Broken bit19 / CBID match) in callers — this unit does not gate those.
- Server stack recombine should at minimum respect per-item max; decide separately whether type-4 mask quirk is required for parity.
