# Dual A/B report — R10-013 OWN-ONLY (`0x00570f50`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-013**  
**Scope:** VA `0x00570f50` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; parent ledgers (WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY); other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual — inventory-transfer thin re-empty under dualed Allocate parent.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` row R10-013.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00570f50` InventoryGrid_RemoveAllAndReEmptyCells_Inferred | **accept-with-gaps** — CF/ABI/list@+0x2c/RemoveAll→Allocate sealed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): free-only / list-as-ECX / twin-collapse / retail-name / “never destroys” overclaims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00570f50` — sealed facts

1. **Body:** `0x00570f50`–`0x00570f62` inclusive (**19 B** / `0x13`); pad `CC` before twin `0x00570f70`.
2. **ABI:** **ECX** = `InventoryGrid*`; void; **tail-JMP** to Allocate (`E9 …` → `0x00570720`).
3. **Semantics:** thin grid re-empty:
   - `list = grid+0x2c`
   - `List_RemoveAll(list)` `0x004bc580`
   - `InventoryGrid_AllocateCellArray_Inferred(grid)` `0x00570720` (tail)
4. **Callers (live sample):** `CVOGCharacter_ApplyCreateFromPacket`, `Vehicle_applyCreatePacket`, `FUN_0052f260` (×3), `FUN_004ffe60`, `FUN_0051f1f0` (×3), `FUN_00588cc0`, `FUN_00884720`, xrefs `0x004f358a` / `0x0058761a` (**13** xrefs).
5. **Callees:** `List_RemoveAll`, `InventoryGrid_AllocateCellArray_Inferred` (both dualed elsewhere).
6. **Twin full:** `FUN_00570f70` / `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` — item walk + detach + RemoveAll + Allocate.
7. **Name:** `InventoryGrid_RemoveAllAndReEmptyCells_Inferred` (Ghidra `FUN_00570f50`). Scaffold `Named_CalleeOf_CVOGCharacter_*` superseded as primary.
8. **Decompile ≡ raw CF**; list ECX restored via `read_memory` hex (no `disassemble_bytes`).

### Gaps

- Product English for thin vs full-clear selection.  
- Retail symbol.  
- Runtime / bit-exact / differential.  
- Residual node dtor details owned by `List_RemoveAll` dual.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00570f50_InventoryGrid_RemoveAllAndReEmptyCells_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00570f50_InventoryGrid_RemoveAllAndReEmptyCells_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00570f50_FUN_00570f50.md` |
| Annotated | `docs/reconstruction/raw/aa_00570f50_FUN_00570f50.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/InventoryGrid_RemoveAllAndReEmptyCells_Inferred.cpp` |
| Clean FUN twin | `docs/reconstruction/reconstructed-exact/FUN_00570f50.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_00570f50_FUN_00570f50.md` |
| Function named | `docs/reconstruction/functions/aa_00570f50_InventoryGrid_RemoveAllAndReEmptyCells_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
InventoryGrid_AllocateCellArray_Inferred  0x00570720  [dualed parent]
List_RemoveAll                            0x004bc580  [dualed]

FUN_00570f50  RemoveAllAndReEmptyCells  [OWN R10-013]
  ├─ List_RemoveAll(grid+0x2c)
  └─ tail → AllocateCellArray(grid)

FUN_00570f70  ClearItemsAndReEmptyCells  [dualed MEGA-090]
  ├─ TraversalLock + item walk/detach
  ├─ List_RemoveAll
  └─ AllocateCellArray

FUN_00884720  cargo/UI clear
  ├─ full clear twin on host cargo grid
  └─ thin 00570f50 on DAT_00d1b6d8+0xce0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00570f50-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00570f50` | Port as **thin InventoryGrid re-empty**: `List_RemoveAll(grid+0x2c)` then re-allocate empty cells. **ECX=grid**. No item-walk detach. |
| Twin | Full clear `00570f70` when items need detach / void-delete path first. |
| Pair with | dualed Allocate `00570720`; dualed List_RemoveAll `004bc580`; dualed twin clear `00570f70`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep later for this VA only:

- `VERIFICATION_MATRIX.md` / coverage ledgers — **not edited** here.
