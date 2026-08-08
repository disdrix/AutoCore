# Dual A/B report — R13-015 OWN-ONLY (`0x008e55e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-015** (retry after prior hang)  
**Scope:** VA `0x008e55e0` (`aa_008e55e0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual rewrite.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-015**.  
**Work item:** Residual dual seal — inventory-transfer craft host **enable + status** refresh (partition parent dual `0x00520340`).  
**Hint retired:** scaffold `FUN_008e55e0` / `Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e55e0`.  
**Terminal:** **false** (no runtime Confirmed).  
**Dual start:** 2686 (wave).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008e55e0` UI_CraftHost_RefreshCraftEnableAndStatus_Inferred | **accept-with-gaps** — EAX-host / plain RET / enable AND-gate / ceil(price×0.85) credits / int status ladder / 3 callers sealed; product demangle + residual helpers open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): ECX-thiscall / EDI-host / RET4 / mission-only scaffold / float-poison status / live-chance-on-success / tier-max-store / material-list-merge / runtime-confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008e55e0` — sealed facts

1. **Body:** `0x008e55e0`–`0x008e598d` inclusive (**942 B** / `0x3AE`); plain **`C3`**; pad `CC CC` then sibling bind `FUN_008e5990`.
2. **ABI:** host in **EAX** on entry (`MOV EBX,EAX`); **no stack args**; void; plain **`RET`**. **Not** ECX-thiscall; **not** EDI-host (contrast `008e5e00`).
3. **Semantics:** craft/RE host **refresh of craft-button enable + status/cost/chance text**:
   - Early-out if `DAT_00d1b6d8 == 0`.
   - `host+0x7d8 = 1`; residual `FUN_008e54a0`.
   - Loop tiers 1..5: dualed `Character_CalcCommodityTierMaxCapacity(char, tier)` — **returns discarded**.
   - `station_ok` ← dualed `Character_Craft_HasMatchingStationInRange(char, host+0x7cc)`.
   - If residual `FUN_005202d0(char, tfid)`: cost = `(int)ceil(Item_GetStoreSellPrice(obj) * 0.85f)`; `afford_ok` vs i64 credits `(char+0x720)−(char+0x728)`.
   - `ready` ← residual `FUN_0052d450(char, obj, &status)`.
   - **Enable** iff `ready && station_ok && host+0x7d8 && afford_ok`: button vtbl+`0xd4`(1); **"Chance of Success"** with hardcoded **100.0** (`DAT_00aaa708`) as `%.1f%%`.
   - **Else** disable button if was on; message ladder (select/broken/components/memory-cost/station/int %).
   - Always: color, residual Complexity UI `FUN_008e41b0`, button/status refresh.
4. **Decompiler traps sealed via asm:**
   - Status codes **2 / 4 / 5** are integers (`CMP`), not denormal floats.
   - Success % does **not** use live chance out-float.
5. **Constants:** `DAT_00aaa680` = **0.85f**; `DAT_00aaa708` = **100.0** double.
6. **Classification:** worker.
7. **Xrefs / callers (3):**  
   - `UI_CraftHost_BindResolvedObject_Inferred` `0x008e5990` @ `0x008e5caa` (`MOV EAX,ESI`)  
   - `Client_RefreshOpenMissionUiWindows` @ `0x0093a9c1` (`MOV EAX,EDI`)  
   - Craft tick site @ `0x008e63e3` (`MOV EAX,EDI`)
8. **Name:** `UI_CraftHost_RefreshCraftEnableAndStatus_Inferred` (Ghidra `FUN_008e55e0`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/status/cost sealed via `disassemble_function` + `read_memory` + call-site context.
10. **Partition parent** `0x00520340` is the dualed tier-max leaf (consumer of this UI loop only as discarded probe) — **not** rewritten this pass.

### Gaps

- Product / MSVC demangle for craft host / widgets.  
- Dual seals for residual helpers (`008e54a0`, `0052d450`, `005202d0`, `008e41b0`, `008e3820`, `008e3940`).  
- Intent of discarded 1..5 tier-max loop.  
- Whether success-path 100.0% is intentional product UX.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008e55e0_UI_CraftHost_RefreshCraftEnableAndStatus_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008e55e0_UI_CraftHost_RefreshCraftEnableAndStatus_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R13-015 re-verify append) | `docs/reconstruction/raw/aa_008e55e0_FUN_008e55e0.md` |
| Annotated | `docs/reconstruction/raw/aa_008e55e0_FUN_008e55e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_CraftHost_RefreshCraftEnableAndStatus_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008e55e0.cpp` |
| Function | `docs/reconstruction/functions/aa_008e55e0_FUN_008e55e0.md` |
| Function named | `docs/reconstruction/functions/aa_008e55e0_UI_CraftHost_RefreshCraftEnableAndStatus_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
UI_CraftHost_BindResolvedObject_Inferred  FUN_008e5990  [dualed MEGA-032]
  └─ FUN_008e55e0  refresh enable+status   [OWN R13-015]
  └─ FUN_008e47d0  residual sibling

Client_RefreshOpenMissionUiWindows  FUN_0093a940
  └─ FUN_008e55e0  same
  └─ FUN_008e41b0 / FUN_008e2f40 / FUN_008e5e00 / FUN_008e47d0

craft tick site 0x008e63e3
  └─ FUN_008e2d60 → FUN_008e55e0 → FUN_008e41b0 → FUN_008e5e00 …

FUN_008e55e0 callees (partial):
  ├─ FUN_008e54a0                          [residual]
  ├─ Character_CalcCommodityTierMaxCapacity  FUN_00520340  [dualed R12-018; returns discarded]
  ├─ Character_Craft_HasMatchingStationInRange FUN_0052eb90 [dualed R12-021]
  ├─ FUN_005202d0                          [residual TFID gate]
  ├─ Item_GetStoreSellPrice                FUN_005142a0  [dualed]
  ├─ ceil (CRT) × 0.85f
  ├─ FUN_0052d450                          [residual readiness/status]
  └─ FUN_008e41b0                          [residual Complexity UI]
```

Partition host **inventory-transfer** matches craft/commodity family.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008e55e0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008e55e0` | Port as **craft-host enable + status refresh**. **EAX host**, no stack args, plain RET. Gate craft button on readiness ∧ station ∧ `+0x7d8` ∧ credits≥ceil(sell×0.85). Status message ladder from product strings + int codes 2/4/5. Do **not** treat as mission-only (scaffold retired). Keep distinct from material-list `008e5e00` and bind `008e5990`/`008e5ce0`. Ignore decompiler float compares on status. |
| Pair with | dualed parent `Character_CalcCommodityTierMaxCapacity_Inferred` `00520340`; dualed station `0052eb90`; dualed sell price `005142a0`; dualed bind `008e5990`; dualed material list `008e5e00`; residual `008e54a0` / `0052d450` / `005202d0` / `008e41b0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` inventory-transfer residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Do not** edit those from this agent.
