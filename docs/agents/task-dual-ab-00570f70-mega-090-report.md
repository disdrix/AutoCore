# Dual A/B report — MEGA-090 OWN-ONLY (`0x00570f70`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-090**  
**Scope:** VA `0x00570f70` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/callees/xrefs + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — inventory-transfer nested under complete-dtor / cargo clear.  
**Partition hint:** `InventoryGrid_FreeCellArray` (soft; refined).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00570f70` InventoryGrid_ClearItemsAndReEmptyCells_Inferred | **accept-with-gaps** — CF/ABI/list@+0x2c/item teardown/unlock→RemoveAll→Allocate sealed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): free-only FreeCellArray / list-as-ECX / stack-arg / twin-collapse / retail-name claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00570f70` — sealed facts

1. **Body:** `0x00570f70`–`0x0057100d` inclusive (**158 B** / `0x9E`); pad `CC` before FindItemByCoid `0x00571010`.
2. **ABI:** **ECX** = `InventoryGrid*`; void; bare **`RET`** (`C3`).
3. **Semantics:** full grid **clear**:
   - `list = grid+0x2c`
   - `List_TraversalLock(list)` `0x004294f0`
   - walk `LockedList_TryAdvanceIterator_Inferred` `0x004022a0`:
     - `item->vtbl+0x158(0)` detach
     - `item+0xa4 != 0` → `FUN_004d4790` queue-delete
     - else → scalar-deleting dtor `(*vtbl)(1)`
   - inline TraversalUnlock (`list+0x28` / `LeaveCS(list+4)` = grid `+0x54` / `+0x30`)
   - `List_RemoveAll(list)` `0x004bc580`
   - `InventoryGrid_AllocateCellArray_Inferred(grid)` `0x00570720` (re-empty cells)
4. **Callers (3):** complete-dtor `FUN_005725a0` @ `0x005725cf`; `FUN_005876c0` @ `0x005876ca` (`*(+0x35c)`); `FUN_00884720` @ `0x0088473a` (cargo `*(+0x510)+0xce0`).
5. **Callees:** TraversalLock, IterateNext, vtbl+0x158, `004d4790`, scalar dtor, LeaveCS, RemoveAll, Allocate.
6. **Twin thin:** `FUN_00570f50` — RemoveAll + Allocate only (no item walk).
7. **Name:** `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` (Ghidra `FUN_00570f70`). Partition FreeCellArray incomplete → not sole name.
8. **Decompile ≡ raw CF**; List ECX restored via `disassemble_function` + `read_memory`.

### Gaps

- Product English for vtbl+0x158 and `item+0xa4`.  
- Retail symbol.  
- Runtime / bit-exact / differential.  
- Parent complete-dtor residual (`FUN_005725a0` OWN elsewhere).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00570f70_InventoryGrid_ClearItemsAndReEmptyCells_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00570f70_InventoryGrid_ClearItemsAndReEmptyCells_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00570f70_FUN_00570f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00570f70_FUN_00570f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_ClearItemsAndReEmptyCells_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00570f70.cpp` |
| Function | `docs/reconstruction/functions/aa_00570f70_FUN_00570f70.md` |
| Function named | `docs/reconstruction/functions/aa_00570f70_InventoryGrid_ClearItemsAndReEmptyCells_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_005725a0  InventoryGrid complete-dtor  [residual / partition parent 0x005725a0]
  ├─ FUN_00570f70  ClearItemsAndReEmptyCells  [OWN MEGA-090]
  │     ├─ List_TraversalLock           0x004294f0
  │     ├─ LockedList_TryAdvanceIterator 0x004022a0  [dualed]
  │     ├─ item vtbl+0x158 / 004d4790 / scalar dtor
  │     ├─ LeaveCriticalSection (inline unlock)
  │     ├─ List_RemoveAll               0x004bc580  [dualed]
  │     └─ InventoryGrid_AllocateCellArray_Inferred 0x00570720  [dualed]
  ├─ operator_delete(grid+0x28) cells
  └─ tree teardown @ +0x5c/+0x60 …

FUN_00570f50  thin re-empty  [residual]
  ├─ List_RemoveAll
  └─ AllocateCellArray

FUN_00884720  cargo/UI clear path
  ├─ ClearItemsAndReEmptyCells on *(host+0x510)+0xce0
  └─ thin 00570f50 on DAT_00d1b6d8+0xce0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00570f70-mega-090-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00570f70` | Port as **full InventoryGrid clear**: destroy/queue all list-held items, drain list, re-allocate empty occupancy. **ECX=grid**, bare RET. Embedded list at **`+0x2c`**. Must unlock before RemoveAll. Do **not** treat as free-only of `+0x28`. |
| Twin | Thin re-empty `00570f50` when items should not be destroyed. |
| Pair with | dualed Allocate `00570720`; dualed List_RemoveAll `004bc580`; dualed IterateNext `004022a0`; residual complete-dtor `005725a0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep later for this VA only:

- `VERIFICATION_MATRIX.md` / coverage ledgers — **not edited** here.
