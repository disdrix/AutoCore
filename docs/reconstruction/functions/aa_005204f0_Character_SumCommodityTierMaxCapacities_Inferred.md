# Function record: Character_SumCommodityTierMaxCapacities_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005204f0` |
| **Canonical name** | `Character_SumCommodityTierMaxCapacities_Inferred` |
| **Ghidra symbol** | `FUN_005204f0` |
| **Address** | `0x005204f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Dual** | A/B **accept-with-gaps** (R13-033 2026-08-05) |
| **Name confidence** | **Inferred** — Σ of dualed tier max capacities; no PDB string; no recovered UI format string on this VA |
| **Partition parent** | `0x00520340` Character_CalcCommodityTierMaxCapacity_Inferred (structural callee) |

## Purpose

Return the **total maximum commodity complexity capacity** across parent tiers 0..5 for a character:

```
// __thiscall Character* this
// ret 0 — no stack args
int total = Character_SumCommodityTierMaxCapacities_Inferred(ch);

// sum = 0
// for tier in 0..5:
//   sum += Character_CalcCommodityTierMaxCapacity_Inferred(ch, tier)
// tier 0 → 0 (parent default); effective Σ over tiers 1..5
```

Read-only. No inventory mutation.

## Body

| Field | Value |
|---|---|
| Start | `0x005204f0` |
| End inclusive | `0x00520517` |
| Size | **40 B** (`0x28`) |

## Related

| Unit | Role |
|---|---|
| `Character_CalcCommodityTierMaxCapacity_Inferred` `0x00520340` | per-tier max leaf (dualed R12-018; **partition parent**) |
| `FUN_005226e0` | sibling Σ max over tiers **1..5** only (R13-034; not owned) |
| `Character_CalcCommodityTierFreeScore_Inferred` `0x00522780` | per-tier free-score (uses parent as max; dualed R10-036) |
| `Character_SumCommodityTfidFiveRowCosts_Inferred` `0x005244e0` | multi-row **used** cost sum — do not merge |
| `FUN_008e41b0` | UI formats `"Complexity: %i/%i"` using **parent** as max (not this sum) |

## Gaps

- Product English method name
- No recovered static callers (orphan / possible dead code)
- Why 0..5 wrapper coexists with 1..5 sibling `005226e0`
- Runtime / bit-exact / differential
