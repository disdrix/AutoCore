# Dual A/B report — R12-019 OWN-ONLY (`0x005206d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-019**  
**Scope:** VA `0x005206d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Role hint:** inventory-transfer residual — Reverse Engineer **cost → required level by tier** (parent required-level `0x0052e1d0`).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent dual `0x0052e1d0` write ownership).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` (R12-019). Dual start **2646**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005206d0` ReverseEngineer_CeilCostToLevelByTier_Inferred | **accept-with-gaps** — CF/ABI/RET8/EAX/int/inv-mult table/sole caller sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): tooltip-self / tinkering-scaffold / thiscall / ECX=character / float-return / merge-with-00520520 / mult-not-inv / floor claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Shared context (parent, not owned)

| Link | Notes |
|------|-------|
| Parent dual | `0x0052e1d0` `Character_ComputeReverseEngineerRequiredLevel_Inferred` (R11-002) — int required RE level |
| Capacity twin | `0x00520520` `Character_GetReverseEngineerSkillCapacityByTier_Inferred` (R10-033) — skill×mult **floor** (inverse scale table) |
| Success twin | `0x0052e640` `Character_ComputeReverseEngineerSuccessFraction_Inferred` (MEGA-117) — float fraction |
| Tooltip | `0x0085ce20` mode 0 consumes parent int as `"Requires At Least %d Reverse Engineering"` |
| Domain | inventory-transfer Reverse Engineer client skill math |

---

## VA `0x005206d0` — sealed facts

1. **Body:** `0x005206d0`–`0x00520829` inclusive (**346 B** / `0x15A`); align `8B FF` @ `0x0052082a`; jump table 6× dword @ `0x0052082c`; pad `CC` after.
2. **ABI:** **stdcall** two stack args (tier, cost); **EAX** int; **`RET 8`** (`C2 08 00`) on all exits. **No this/ECX**.
3. **Semantics:** Reverse Engineer **cost → level by tier**:
   - `CMP tier, 5` / `JA` → 0.
   - Jump table: cases **0 and 1 share** target.
   - Each case: `ceil((float)cost * inv_mult[tier])` → int ROUND.
4. **Constants (`read_memory`):**

   | VA | Float | = 1/mult | Cases |
   |---|---:|---:|---|
   | `0x009cdff4` | 0.2857143 | 3.5 | 0, 1 |
   | `0x009cefcc` | 0.3571429 | 2.8 | 2 |
   | `0x009cefc8` | 0.4761905 | 2.1 | 3 |
   | `0x00aaa7c4` | 0.7142857 | 1.4 | 4 |
   | `0x009cefc4` | 1.4285715 | 0.7 | 5 |

5. **Callees:** `ceil` only.
6. **Callers / xrefs:** sole `FUN_0052e1d0` — 4× UNCONDITIONAL_CALL @ `0x0052e5c6`, `0x0052e5d5`, `0x0052e5fb`, `0x0052e60a`.
7. **Name:** `ReverseEngineer_CeilCostToLevelByTier_Inferred` (Ghidra `FUN_005206d0`). Product English open → `_Inferred`. Retire Named_CalleeOf tinkering scaffold.
8. **Decompile ≡ raw CF**; ABI/int sealed via prologue/epilogue `read_memory` + jump table + parent call graph.

### Gaps

- Product English for tier index vs recipe-row ordinal.  
- Server vs display-only.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005206d0_ReverseEngineer_CeilCostToLevelByTier_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005206d0_ReverseEngineer_CeilCostToLevelByTier_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005206d0_FUN_005206d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005206d0_FUN_005206d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ReverseEngineer_CeilCostToLevelByTier_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005206d0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_005206d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005206d0_FUN_005206d0.md` |
| Function named | `docs/reconstruction/functions/aa_005206d0_ReverseEngineer_CeilCostToLevelByTier_Inferred.md` |
| Report | `docs/agents/task-dual-ab-005206d0-r12-report.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0085ce20  Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred  [dualed]
  mode 0 Reverse Engineer:
    ├─ FUN_0052e640  success fraction  [dualed MEGA-117]
    ├─ FUN_0052e1d0  required RE level (int)  [parent R11-002]
    │    ├─ inline ceil(primary * 1/3.5)
    │    └─ FUN_005206d0  cost→level by tier  [OWN R12-019]
    │         ├─ (row_count, total_secondary)
    │         └─ (tier 1..5, row_cost[tier])
    └─ …

Scale twin (success path; not OWN):
  FUN_00520520  skill×mult floor capacity  [R10-033]
    mults {3.5,3.5,2.8,2.1,1.4,0.7}  ↔  inv mults on this VA
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005206d0` | Port as **pure stdcall** `int CeilCostToLevel(uint tier, int cost)`. **RET 8**, EAX out, **no this**. |
| Formula | `ceil(cost * 1/mult[tier])` with mults matching capacity twin; default 0. |
| Do **not** | Merge with capacity `00520520` (floor/thiscall); treat as character method; use mults instead of inv mults; name as tooltip. |
| Pair with | parent required-level `0052e1d0`; capacity twin `00520520`; success fraction `0052e640`; tooltip `0085ce20`. |

---

## Residual for parent merge (not edited here)

- Count **+1** dual unique when parent merges R12-019 (`005206d0`).
- NAMING_REGISTRY: `ReverseEngineer_CeilCostToLevelByTier_Inferred`.
- VERIFICATION_MATRIX row + `systems/inventory-transfer.md` entry point.
- Parent R11-002 gap “dual helper `005206d0`” can close on merge.

---

## Process

- OWN VA only (`0x005206d0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine twin retained; `Named_CalleeOf_*` scaffold **retired**.  
- `_Inferred` where product English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
