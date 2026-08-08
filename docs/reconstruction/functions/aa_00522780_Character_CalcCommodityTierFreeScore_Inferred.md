# Function record: Character_CalcCommodityTierFreeScore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522780` |
| **Canonical name** | `Character_CalcCommodityTierFreeScore_Inferred` |
| **Ghidra symbol** | `FUN_00522780` |
| **Address** | `0x00522780` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Dual** | A/B **accept-with-gaps** (R10-036, 2026-08-05) |
| **Parent** | `0x00522710` `Character_SumCommodityTfidRowCost_Inferred` |
| **Bit-for-bit / runtime / diff** | Open (terminal false) |

## Purpose

Score free commodity TFID-row capacity for tiers 1..5:

- **used** = sum commodity slot cost on cargo grid (parent dual).
- **max** = level-scaled tier capacity (`FUN_00520340`).
- **free** = max − used; negative or bad tier → `0`.
- **score** = `(level * scale + (base + free*2)) * 0.01` with fixed per-tier base/scale tables.

Sole caller `FUN_00522860` multiplies per-tier scores into a product fitness value.

## Signature

```c
float __thiscall Character_CalcCommodityTierFreeScore_Inferred(
    Character* self,
    uint32_t tier,              // 1..5
    const uint32_t* tfidRow);   // 5 × {lo,hi}; ret 8
```

## Tier tables

| Tier | base | scale |
|----:|-----:|------:|
| 1 | 50 | 2.5 |
| 2 | 40 | 2.0 |
| 3 | 30 | 1.5 |
| 4 | 20 | 1.0 |
| 5 | 10 | 0.5 |

`level = *(uint8_t*)(self + 0x599)`.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00522780_FUN_00522780.md` |
| Annotated | `docs/reconstruction/raw/aa_00522780_FUN_00522780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_CalcCommodityTierFreeScore_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00522780.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00522780_Character_CalcCommodityTierFreeScore_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00522780_Character_CalcCommodityTierFreeScore_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00522780_FUN_00522780.md` |
| Report | `docs/agents/task-dual-ab-00522780-r10-report.md` |

## Gaps

- Product/PDB method English.
- Semantic product meaning of the composite score.
- Dual seal for `FUN_00520340` / `FUN_00522860`.
- Runtime / bit-exact.

## Confidence

| Claim | Level |
|---|---|
| Role / CF / formula | High |
| Name (Inferred) | Probable |
| Product English | Open |
