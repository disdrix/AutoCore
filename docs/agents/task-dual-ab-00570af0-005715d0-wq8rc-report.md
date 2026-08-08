# Dual A/B report — WQ8R-C OWN `aa_00570af0` + `aa_005715d0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ8R-C  
**Scope:** VAs `0x00570af0`, `0x005715d0` only. Trio + clean + dual A/B.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `read_memory` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Wave:** WQ-008 residual — grid inventory helpers.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00570af0` InventoryGrid_MoveItemFootprint_Inferred | **accept-with-gaps** — move CF + ABI + clear/stamp index sealed; no Ghidra callers; product English residual |
| `aa_005715d0` InventoryGrid_CanPlaceItem | **accept** — leaf InvSize→CanPlace wrapper; ABI + handoff sealed; multi-site callers |

---

## VA `0x00570af0` — sealed facts

1. **Body:** `0x00570af0`–`0x00570cfb` (~523 B; **`RET 0x0C`**).
2. **ABI:** **ECX**=`InventoryGrid*`; stack `item*`, `originX`, `originY`; return **1**/`0` in `AL`.
3. **Semantics:** **Move/relocate** already-bound item footprint:
   - `CanPlace(InvSizeX, InvSizeY, originX, originY, local conflictOut)` — non-null conflictOut ⇒ same-COID overlap tolerated
   - clear old footprint at current GetX/GetY (`vtbl+0x250/+0x254`) to empty `0xFFFFFFFF` pairs
   - `vtbl+0x24c(originX, originY)` set origin
   - stamp COID `item+0x160/+0x164` full InvSize rect
   - optional `FUN_00512670(*(grid+0x24))`; dirty `grid+0x21 = 1`
4. **Index (byte-sealed):** clear `height*x+y`; stamp `height*(originX+dx)+(originY+dy)`; `height=*(grid+0x0c)`; cells `*(grid+0x28)` ×8.
5. **InvSize:** clonebase blob `+0x406/+0x407` via `item+0xa8` → `+0x3c`.
6. **Callees:** `InventoryGrid_CanPlace` `0x00570840`; `FUN_00512670`.
7. **Callers:** Ghidra xrefs **none** (orphan / indirect residual).
8. **Name:** `InventoryGrid_MoveItemFootprint_Inferred` (Ghidra `FUN_00570af0`).
9. **Decompiler:** CF usable; **stamp `unaff_retaddr` / `(byte)param_2` corrupted** — bytes override (same class of bug as Place residual).
10. **Twin family:** Place `0x00571620` (first stamp); Remove `0x00571b80` (clear+detach); CanPlace `0x00570840`.

### Gaps

- No Ghidra callers (live use / dead code open).  
- Product/PDB English.  
- Runtime overlapping-move cell dump.  
- Bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00570af0_FUN_00570af0.md` |
| Annotated | `docs/reconstruction/raw/aa_00570af0_FUN_00570af0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_MoveItemFootprint_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00570af0.cpp` |
| Function | `docs/reconstruction/functions/aa_00570af0_FUN_00570af0.md` |
| Function named | `docs/reconstruction/functions/aa_00570af0_InventoryGrid_MoveItemFootprint_Inferred.md` |
| Residual | `docs/reconstruction/reviews/a_00570af0.md` |
| Scratch | `docs/reconstruction/tmp/a_00570af0.md` |

---

## VA `0x005715d0` — sealed facts

1. **Body:** `0x005715d0`–`0x0057161d` (~78 B; leaf; **`RET 0x10`**).
2. **ABI:** **ECX**=`InventoryGrid*`; stack `item*`, `originX`, `originY`, `conflictOut*`; return CanPlace **1**/`0`.
3. **Semantics:** Null item → **0**; else load InvSizeX/Y from item clonebase and **tail to** `InventoryGrid_CanPlace`. **No** stamp/clear/bind.
4. **InvSize path:** `item+0xa8` → host `+0x3c` blob → `+0x406/+0x407` (u8).
5. **Callee:** `InventoryGrid_CanPlace` `0x00570840` only.
6. **Callers (sample / 18 xrefs):** `FUN_008012f0`, `Client_ConfirmEquipOrCustomizeItem` `0x00941b20`, `FUN_00952bc0`, `FUN_00955010` — equip / space-probe before Place or FindFree.
7. **Name:** `InventoryGrid_CanPlaceItem` (Ghidra `FUN_005715d0`).
8. **Decompile ≡ bytes** for CF; decompiler hides thiscall — **`PUSH ECX` + CanPlace this** seal grid ownership.
9. **Twin:** FindFreeForItem `0x005714e0` (search); Place `0x00571620` (mutate); this unit is pure probe.

### Gaps

- Product/PDB English only (non-blocking).  
- Runtime non-null conflictOut via this wrapper (callers often pass `0`).  
- Bit-exact open (leaf).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005715d0_InventoryGrid_CanPlaceItem.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005715d0_InventoryGrid_CanPlaceItem.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005715d0_FUN_005715d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005715d0_FUN_005715d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_CanPlaceItem.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005715d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005715d0_FUN_005715d0.md` |
| Function named | `docs/reconstruction/functions/aa_005715d0_InventoryGrid_CanPlaceItem.md` |
| Residual | `docs/reconstruction/reviews/a_005715d0.md` |
| Scratch | `docs/reconstruction/tmp/a_005715d0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00570af0` | Grid **move** helper — preserve local conflictOut (overlap-safe), clear-before-stamp order, index `height*x+y`, InvSize from clonebase, dirty `+0x21`. Do **not** port decompiler stamp `unaff_*`. Confirm whether any AutoCore path needs this vs Place+Remove compose. |
| `005715d0` | Item-aware CanPlace probe — use before Place/FindFree on equip paths; ECX must be the target grid; pass through conflictOut; no cell writes. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Supersedes 2026-07-23 scaffold for both units.  
- This report: `docs/agents/task-dual-ab-00570af0-005715d0-wq8rc-report.md`
