# Review B (skeptical / adversarial): `aa_0050c1b0` LootManager_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0050c1b0` |
| **VA** | `0x0050c1b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0050c1b0_LootManager_ctor_Inferred.md` |
| **System** | missions-progression / combat death loot (manager lifecycle) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Per-kill reward helper | `operator_new(0xbc)` + vtables + table loaders | **Falsified** — **ctor** |
| 2 | Raw file is authoritative body | Raw = “Error: Decompilation failed” | **Falsified** — use **live** |
| 3 | Only called from OnDeath | Also `004cd670`, `004ce940` | **Falsified** sole-caller |
| 4 | `DAT_00b041d4` unrelated | Ctor stores arg; 00509010 reads `+0xf14` | **Falsified** as unrelated |
| 5 | Object size unknown | Parent `new(0xbc)` | **Survives** as **0xBC** |
| 6 | Always loads from COM | `DAT_00b04694` switches to baked arrays | **Survives with branch** |
| 7 | Dual seals every loader loop | Truncation + scale | **Open residual** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor role | **High** | Wrong lifecycle port |
| Global DAT_00b037e8 owner | **High** | Null loot manager forever |
| DAT_00b041d4 publish | **High** | Zone walk hash wrong |
| Vtable / alloc skeleton | **High** | |
| Full table taxonomy | **Probable** | Incomplete content load |
| Retail name | **Open** | Cosmetic |

---

## 3. Cross-check

Parent death lazy-init only when `DAT_00b037e8 == 0` before loot list path. Subsequent `FUN_0050aa80` / `FUN_00509010` depend on manager + `DAT_00b041d4`.

---

## 4. Surviving contract

```
// Lazy global loot manager
if (g_lootMgr == null) {
  g_lootMgr = new (0xBC) LootManager(g_appCtx); // FUN_0050c1b0
}
// Ctor must set g_hashRootCtx (DAT_00b041d4) used by zone loot walk.
// Not a per-kill function — do not dual as award helper.
```

---

## 5. What would overturn

1. Evidence function is not entered with ECX = `operator_new` result.
2. Proof `DAT_00b037e8` is not this object.
3. Smaller function boundary (Ghidra merge error) — would require re-analysis of next symbol.

**Verdict:** **accept-with-gaps** — ctor High; raw must be refreshed; sub-table names open.
