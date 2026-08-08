# Function record: Character_SumCommodityTierMaxCapacities_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005226e0` |
| **Canonical name** | `Character_SumCommodityTierMaxCapacities_Inferred` |
| **Ghidra symbol** | `FUN_005226e0` |
| **Address** | `0x005226e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Dual** | A/B **accept-with-gaps** (R13-034 2026-08-05) |
| **Name confidence** | **Inferred** — Σ of dualed max-capacity leaf over tiers 1..5; no PDB string |
| **Partition parent** | `0x00520340` `Character_CalcCommodityTierMaxCapacity_Inferred` |
| **Bit-for-bit / runtime / diff** | Open (terminal false) |

## Purpose

Return the **total max commodity complexity capacity** across all five product tiers by summing the dualed per-tier leaf:

```
// __thiscall Character* this
// RET — no stack args
int total = Character_SumCommodityTierMaxCapacities_Inferred(ch);

// total = Σ_{tier=1..5} floor(level * scale[tier])
// level = *(uint8_t*)(ch + 0x599)   // loaded inside leaf
// scale[1..5] = 3.5, 2.8, 2.1, 1.4, 0.7
```

Read-only. No inventory mutation.

## Body

| Field | Value |
|---|---|
| Start | `0x005226e0` |
| End inclusive | `0x00522709` |
| Size | **42 B** (`0x2A`) |
| Epilog | `C3` RET |

## Related

| Unit | Role |
|---|---|
| `Character_CalcCommodityTierMaxCapacity_Inferred` `0x00520340` | per-tier max leaf (parent dual R12-018) |
| `FUN_005204f0` | sibling Σ max tiers **0..5** (R13-033; do not merge) |
| `Character_CalcCommodityTierFreeScore_Inferred` `0x00522780` | free-score uses **single-tier** max, not this sum |
| `Character_SumCommodityTfidRowCost_Inferred` `0x00522710` | **used** cost peer — distinct |
| `Character_SumCommodityTfidFiveRowCosts_Inferred` `0x005244e0` | multi-row **used** sum — distinct |

## Gaps

- Product English method name
- Zero recovered static callers / data xrefs
- Runtime / bit-exact / differential

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005226e0_FUN_005226e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005226e0_FUN_005226e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_SumCommodityTierMaxCapacities_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005226e0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_005226e0_Character_SumCommodityTierMaxCapacities_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005226e0_Character_SumCommodityTierMaxCapacities_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_005226e0_FUN_005226e0.md` |
| Report | `docs/agents/task-dual-ab-005226e0-r13-report.md` |
