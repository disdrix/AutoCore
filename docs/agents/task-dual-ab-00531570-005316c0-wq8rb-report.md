# Dual A/B report — WQ8R-B `0x00531570` + `0x005316c0` (type-0x1a inventory exchange/craft)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ8R-B**  
**Scope:** OWN ONLY VAs `0x00531570`, `0x005316c0`. Trio + clean meaningful names + dual A/B.  
**Work item:** **WQ-008** residual inventory-transfer (priority 94).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems maps (parent merge).  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` (+ callees, xrefs). **No** `disassemble_bytes`. **No** Launcher.

---

## Verdict

| Unit | Canonical | Verdict |
|------|-----------|---------|
| `aa_00531570` | `CVOGCharacter_TryType1aSimpleExchange_Inferred` | **accept-with-gaps** |
| `aa_005316c0` | `CVOGCharacter_TryType1aCraft_Inferred` | **accept-with-gaps** |

Path A (fidelity): **accept-with-gaps** on both  
Path B (adversarial): **accept-with-gaps** on CF + dual-grid ECX; overclaims on product English / place-stamp **rejected**

Never claim runtime **Confirmed** (no Launcher).

---

## Sealed facts

### Shared

1. **Domain:** inventory-transfer character methods that **consume** ingredients from **cargo + locker** and **grant** product CBIDs via `FUN_005310a0` (give-by-cbid × qty, callee `ret 8`).
2. **Grids (High):** cargo `*(*(char+0x250)+0x2b0)`; locker `*(char+0xcbc)` — same DropResponse type **1** / **3** pointers.
3. **Space probe:** both call `InventoryGrid_FindFreeSlot` on **cargo only**, InvSize from def blob `+0x406/+0x407`, **pageIndex = -1** (whole grid). Outs not used to stamp cells in these units.
4. **Remove pattern:** `CVOGReaction_RemoveInventoryItem` on cargo first, remainder on locker.
5. **Decompiler hazard (sealed by bytes):** repeated `CountItemsByCbid(cbid,0)` is **not** double-count of one grid — ECX alternates cargo/locker.
6. **Callers:** **zero** direct code xrefs to either entry (vtable / unbound residual).
7. **Live decompile ≡ 2026-07-23 raw** body for both VAs.

### `0x00531570` — simple exchange

1. **ABI:** `__thiscall`, **`ret 8`** — `(character, type1aObject, requestQty) → 0|1`.
2. **Type gate:** `object+0x38 == 0x1a`; blob `object+0x3c`.
3. **Ingredient:** CBID `blob+0x4c0`; product mult `u8 blob+0x4c9`; product CBID **`object+0x34`**.
4. **Success path:** have ≥ qty → free cargo slot → remove qty → give `mult*qty` of product → **1**.

### `0x005316c0` — multi-ingredient craft

1. **ABI:** `__thiscall`, **`ret 12`** — `(character, object, craftQty, mode) → 0|1`.
2. **Soft no-op:** if `FUN_00522060` reports no craftable batches → **return 1** (not 0).
3. **Hard fail:** `craftQty > available`, missing grids/blob, or FindFree miss → **0**.
4. **Mode:** **1** skips primary bank; **2** skips secondary list (not inventoryType 1/3/5).
5. **Primary:** CBID `blob+0x4d0`, cost/batch `char blob+0x4d4`; may split batches with secondary when stock short.
6. **Secondary:** up to 5 CBIDs `blob+0x498…+0x4a8`; bound via `FUN_00599dd0`.
7. **Product CBID:** **`*(blob+4)`** (distinct from simple twin’s `object+0x34`).

---

## Gaps (both)

1. Product/RTTI English for clone type **`0x1a`** and recipe blob schema beyond offsets used.
2. Static dispatch callers (vtable index / reaction map).
3. Full dual ownership of helpers `FUN_00522060`, `FUN_00599dd0`, `FUN_005310a0`, `FUN_004f1e20` (summarized only).
4. Runtime / CE / bit-exact image verification.
5. Soft-success product rationale for craft unit.

---

## Files

| Kind | `0x00531570` | `0x005316c0` |
|------|--------------|--------------|
| Review A | `docs/reconstruction/reviews/A_aa_00531570_CVOGCharacter_TryType1aSimpleExchange_Inferred.md` | `…/A_aa_005316c0_CVOGCharacter_TryType1aCraft_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00531570_CVOGCharacter_TryType1aSimpleExchange_Inferred.md` | `…/B_aa_005316c0_CVOGCharacter_TryType1aCraft_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00531570_CVOGCharacter_TryType1aSimpleExchange_Inferred.md` | `…/aa_005316c0_CVOGCharacter_TryType1aCraft_Inferred.md` |
| Alias FUN record | `docs/reconstruction/functions/aa_00531570_FUN_00531570.md` | `…/aa_005316c0_FUN_005316c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryType1aSimpleExchange_Inferred.cpp` | `…/CVOGCharacter_TryType1aCraft_Inferred.cpp` |
| Scaffold clean | `…/FUN_00531570.cpp` | `…/FUN_005316c0.cpp` |
| Raw | `docs/reconstruction/raw/aa_00531570_FUN_00531570.md` | `…/aa_005316c0_FUN_005316c0.md` |
| Annotated | `docs/reconstruction/raw/aa_00531570_FUN_00531570.annotated.md` | `…/aa_005316c0_FUN_005316c0.annotated.md` |
| This report | `docs/agents/task-dual-ab-00531570-005316c0-wq8rb-report.md` | |

Related (not owned): `InventoryGrid_FindFreeSlot` `aa_005713a0` (lists these as callers); `InventoryGrid_CountItemsByCbid` `aa_005711c0`; `CVOGReaction_RemoveInventoryItem` `aa_005721c0`; give helper `aa_005310a0`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`.

---

## AutoCore impact

- Client **type-0x1a** flows can **destroy ingredients on both cargo and locker** and spawn product via the same give path missions use (`FUN_005310a0` / AddItem). Server craft/exchange parity should dual-count those two grids the same way.
- Space check is **cargo footprint only** (locker stock can feed ingredients without needing free locker cells for the product).
- Craft **mode** is a **bank mask** (primary vs secondary), not bag inventoryType.
- Soft-success when craftable count is zero: do not treat as hard inventory error on that edge.
- Parent merge (not this agent): VERIFICATION_MATRIX rows, NAMING_REGISTRY, `systems/inventory-transfer.md` entry points, WORK_QUEUE/RESUME/CHANGE_LOG/progress.

---

## Parent merge checklist (for integrator — not done here)

- [ ] VERIFICATION_MATRIX: `aa_00531570`, `aa_005316c0`
- [ ] NAMING_REGISTRY + rename history for both canonical names
- [ ] `systems/inventory-transfer.md` entry table
- [ ] WORK_QUEUE / RESUME / CHANGE_LOG / progress.json dual count
