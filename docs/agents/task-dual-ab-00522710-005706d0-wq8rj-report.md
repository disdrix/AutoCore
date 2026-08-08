# Dual A/B report — WQ8R-J OWN `aa_00522710` + `aa_005706d0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ8R-J  
**Scope:** VAs `0x00522710`, `0x005706d0` only. Dual A/B + trio artifacts.  
**Role hint:** WQ-008 inventory-transfer residual — commodity TFID-row cost leaf + inventory grid dirty mark.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` + `read_memory` + `analyze_function_complete` + xrefs/callers. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq008_residual_partition_map.md` (WQ8R-J).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00522710` Character_SumCommodityTfidRowCost_Inferred | **accept-with-gaps** — thiscall+ret8, cargo FindByCoid, Commodity `0x1A`, cost formula (incl. `+i`) sealed; product English + subblob+0x4C8 label open |
| `aa_005706d0` InventoryGrid_SetDirtyFlag_Inferred | **accept-with-gaps** — 21 B dirty leaf reconfirmed (prior dual 2026-07-29); `+0x21=1` + conditional `00512670` on `+0x24` sealed |

**Terminal coverage:** false (no Launcher / runtime / bit-exact Confirmed).

---

## Shared context (parent, not owned)

Both sit on the **inventory-transfer** graph:

| Link | Notes |
|------|-------|
| Cargo grid | Character `*(*(this+0x250)+0x2B0)` — same path as DropResponse inventoryType **1** |
| FindByCoid | `FUN_00571010` @ `0x00571010` (dualed) — list walk COID `item+0x160/+0x164` |
| Dirty propagate | `FUN_00512670` ORs `0x20000` into object`+0x17c` (+ `+0xac` chain) |
| Place family | `InventoryGrid_PlaceItemFootprint` `0x00571620` tails into dirty mark |

Not the same call chain; paired only by residual partition ownership.

---

## VA `0x00522710` — sealed facts

1. **Body:** `0x00522710`–`0x00522773` exclusive (**99 B** / `0x63`; pad `CC` → `0x00522780`).
2. **ABI:** **`__thiscall`** ECX = Character*; **two stack dwords**; **`ret 8`** (`C2 08 00`). Stack arg0 **unused** in body (callers still pass tier/row index). Stack arg1 = TFID row of **5** `{lo,hi}` pairs.
3. **Semantics:** Commodity TFID-row slot cost:
   - `grid = *(*(this+0x250)+0x2B0)`.
   - `accum = 1`; for `i = 0..4`:
     - skip if `(lo & hi) == 0xFFFFFFFF` (null TFID; both halves `-1`).
     - `item = InventoryGrid_FindItemByCoid(grid, lo, hi)`.
     - if null **or** `*(def+0x38) != 0x1A` → **return accum** (stop walk).
     - `accum += *(uint8_t*)(*(def+0x3C)+0x4C8) + i`.
   - return `accum`.
4. **Type imm:** `0x1A` = **Commodity** (`CloneBaseObjectType` = 26). **Not** a generic container gate.
5. **Classification:** pure read cost worker (no grid mutation).
6. **Callers (2):** `FUN_00522780` (used vs max capacity score); `FUN_005244e0` (sum over 5 rows × 40 B stride).
7. **Callees:** `FUN_00571010` only.
8. **Name:** `Character_SumCommodityTfidRowCost_Inferred` (Ghidra `FUN_00522710`). **Reject** scaffold `Named_CalleeOf_…_00522710`.
9. **Decompile vs bytes:** CF ≡ raw sum loop; **bytes win** on thiscall ECX, dead arg0, and FindByCoid grid this (`+0x250/+0x2B0`). Do **not** drop `+ i` from the cost formula.

### Gaps

- Product/PDB method English.  
- Subblob field `*(def+0x3C)+0x4C8` product label (do not equate to refine-panel `def+0x4C8` without proof).  
- Intent of adding slot index `i`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00522710_Character_SumCommodityTfidRowCost_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00522710_Character_SumCommodityTfidRowCost_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00522710_FUN_00522710.md` |
| Annotated | `docs/reconstruction/raw/aa_00522710_FUN_00522710.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_SumCommodityTfidRowCost_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00522710.cpp` |
| Function | `docs/reconstruction/functions/aa_00522710_FUN_00522710.md` |
| Function named | `docs/reconstruction/functions/aa_00522710_Character_SumCommodityTfidRowCost_Inferred.md` |

---

## VA `0x005706d0` — sealed facts

1. **Body:** `0x005706d0`–`0x005706e5` exclusive (**21 B** / `0x15`; pad `CC`).
2. **ABI:** **`__thiscall`** ECX = InventoryGrid*; **no stack args**; plain **`ret`** (`C3`).
3. **Semantics:** grid dirty mark:
   - if `*(grid+0x24) != 0` → `Object_PropagateDirtyBit0x20000(*(grid+0x24))` (`FUN_00512670`).
   - always `*(uint8_t*)(grid+0x21) = 1`.
4. **Classification:** leaf post-mutation dirty hook (place/merge/refresh family). **No** footprint math.
5. **Callers (4):** `FUN_00571620` PlaceItemFootprint tail; `FUN_0088f500`; `FUN_004f7f80`; `FUN_00522d60` (locker `@+0xcbc` path).
6. **Callees:** `FUN_00512670` only.
7. **Name:** `InventoryGrid_SetDirtyFlag_Inferred` (Ghidra `FUN_005706d0`). Prior dual 2026-07-29 **reconfirmed** live. **Reject** scaffold `Named_CalleeOf_…_005706d0`.
8. **Decompile ≡ raw CF**; ECX reload for callee from `+0x24` sealed by bytes.

### Gaps

- Product English for dirty flag / owner pointer.  
- Who clears `+0x21`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005706d0_InventoryGrid_SetDirtyFlag_Inferred.md` | **accept-with-gaps** (reconfirm WQ8R-J) |
| B | `docs/reconstruction/reviews/B_aa_005706d0_InventoryGrid_SetDirtyFlag_Inferred.md` | **accept-with-gaps** (reconfirm WQ8R-J) |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005706d0_FUN_005706d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005706d0_FUN_005706d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_SetDirtyFlag_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005706d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005706d0_FUN_005706d0.md` |
| Function named | `docs/reconstruction/functions/aa_005706d0_InventoryGrid_SetDirtyFlag_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00522710` | Port as **thiscall** commodity-row cost: walk 5 COIDs on cargo grid; require type **Commodity (26)**; `cost = 1 + Σ(sub[0x4C8] + i)`; early-out on miss/non-commodity. Keep dead stack arg for ABI if matching callers. Pair with max-capacity helper `FUN_00520340` when porting free-slot scores. |
| `005706d0` | Port as **thiscall** dirty leaf: set `grid.dirty (+0x21)=1`; if owner at `+0x24`, propagate object dirty bit `0x20000`. Call after place/merge/refresh mutations. |
| Shared | InventoryGrid layout `+0x21` / `+0x24` already in OBJECT_LAYOUTS; cargo path `+0x250/+0x2B0` matches invType1. |

---

## Residual for parent merge (not edited here)

- Count **+2** dual unique when parent merges WQ8R-J (`00522710` newly dualed; `005706d0` was dualed 2026-07-29 — parent should confirm whether reconfirm counts as new unique or already in 2209).
- NAMING_REGISTRY: `Character_SumCommodityTfidRowCost_Inferred`, `InventoryGrid_SetDirtyFlag_Inferred`.
- Optional follow-up: dual `FUN_00522780` / `FUN_005244e0` / `FUN_00520340` capacity-score trio; subblob+0x4C8 field recovery.
- VERIFICATION_MATRIX rows + systems/inventory-transfer.md entry points.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ analyze/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed/reconfirmed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Names use inventory-domain + `_Inferred` (no invented product plates).
