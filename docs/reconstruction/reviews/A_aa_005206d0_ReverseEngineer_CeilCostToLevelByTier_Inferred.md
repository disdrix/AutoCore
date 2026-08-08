# Review A (reconstruction fidelity): `aa_005206d0` ReverseEngineer_CeilCostToLevelByTier_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005206d0` |
| **VA** | `0x005206d0`–`0x00520829` inclusive (**346 B** / `0x15A`) |
| **Canonical name** | `ReverseEngineer_CeilCostToLevelByTier_Inferred` |
| **Ghidra name** | `FUN_005206d0` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_005206d0` (**retired**) |
| **Review date** | `2026-08-05` (R12-019 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005206d0_ReverseEngineer_CeilCostToLevelByTier_Inferred.md` |
| **System** | inventory-transfer / reverse-engineer cost→level by tier |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `read_memory` (body, jump table, five inv floats). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Integer **material cost × tier inv-multiplier → required RE level** helper:

```text
ReverseEngineer_CeilCostToLevelByTier_Inferred(tier, cost) -> int
  inv = {1/3.5, 1/3.5, 1/2.8, 1/2.1, 1/1.4, 1/0.7}[tier]  // tier 0..5
  return ceil(cost * inv)                                  // tier > 5 → 0
```

Sole parent `Character_ComputeReverseEngineerRequiredLevel_Inferred` (`0x0052e1d0`) uses the return as:

1. **Aggregate path** — `this(row_count, total_secondary_cost)` folded into `max(required, …)`.
2. **Per-tier path** — `this(tier, row_cost[tier])` for tiers **1..5**, same max fold.

Parent inlines the primary-cost base `ceil(primary * 1/3.5)` separately (same float as cases 0/1).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF (switch 0..5 + default 0; ceil×5) |
| Body bounds | `read_memory` prologue/epilogue + analyze disasm → `0x005206d0`–`0x00520829` |
| Jump table | 6 dwords @ `0x0052082c` (cases 0/1 share `0x005206ec`) |
| Floats | `read_memory` 4 B LE at five DAT addresses |
| Callers | only `FUN_0052e1d0` — 4 UNCONDITIONAL_CALL sites |
| Callees | `ceil` via IAT `[0x009c6588]` |
| Parent context | dualed R11-002 required-level plate |
| Scale twin | dualed R10-033 capacity mults (inverse) |

---

## 3. Signature (sealed)

```c
// stack tier; stack cost; EAX = level; RET 8; no this
int __stdcall ReverseEngineer_CeilCostToLevelByTier_Inferred(
    unsigned tier,
    int cost);
```

| Formal | Source | Conf |
|---|---|---|
| tier | stack `[EBP+8]` | **Confirmed** |
| cost | stack `[EBP+0xC]` (`FILD`) | **Confirmed** |
| return | **EAX** int level | **Confirmed** |
| cleanup | **`RET 8`** (`C2 08 00`) all exits | **Confirmed** |
| this/ECX | **unused** | **Confirmed** |
| jump table | `0x0052082c` 6 dwords | **Confirmed** |
| inv mults | `read_memory` floats | **Confirmed** |

**Note:** Ghidra `analyze` signature display `undefined FUN_005206d0(void)` is **incorrect**.

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Frame + load tier; `CMP 5` / `JA default` | body bytes | **Confirmed** |
| Jump table cases 0/1 share target | table dwords identical | **Confirmed** |
| Each case: FILD cost × float → ceil → ROUND int EAX | decompile + bytes | **Confirmed** |
| Default XOR EAX,EAX | `@0x00520822` | **Confirmed** |
| Worker (ceil only) | analyze callees | **Confirmed** |
| Product English for tier vs row-count | open | **Inferred** |

Decompile ≡ raw CF. ROUND is MSVC FPU control-word path after `ceil` (not a separate CRT call).

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** (CRT `ceil`) |
| External callers | **1** function, **4** call sites |
| Site roles | aggregate total + per-tier max into required level |
| Parent system | inventory-transfer RE (partition R12-019; parent `0x0052e1d0`) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Pure cost→level ceil by tier (no this) | **Yes** |
| Inv mults inverse of dualed capacity table | **Yes** (`read_memory`) |
| RE required-level parent dual (R11-002) | **Yes** |
| In-body product string | **No** |
| Named_CalleeOf tinkering plate | **No** — retired scaffold |

**Decision:** promote **`ReverseEngineer_CeilCostToLevelByTier_Inferred`**. Keep `_Inferred` until product English / tier semantics sealed. Not `Character_*` (no ECX/this).

---

## 7. Gaps

1. Product English for tier index vs recipe-row ordinal (`row_count` at aggregate site).
2. Whether server enforces same mapping (client sealed only).
3. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/inv-mult table/sole-parent role with only product-English residual → **accept-with-gaps**.
