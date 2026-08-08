# Function record: Character_CalcCommodityTierMaxCapacity_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520340` |
| **Canonical name** | `Character_CalcCommodityTierMaxCapacity_Inferred` |
| **Ghidra symbol** | `FUN_00520340` |
| **Address** | `0x00520340` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Dual** | A/B **accept-with-gaps** (R12-018 2026-08-05) |
| **Name confidence** | **Inferred** — level×tier-scale max capacity; UI "Complexity" is display label only; no PDB string |
| **Partition parent** | `0x005244e0` Character_SumCommodityTfidFiveRowCosts_Inferred (wave host; not a structural caller) |

## Purpose

Return the **maximum commodity complexity capacity** for a single product tier given the character level byte at `this+0x599`:

```
// __thiscall Character* this
// ret 4 — stack: tier (1..5)
int max = Character_CalcCommodityTierMaxCapacity_Inferred(ch, tier);

// if tier ∉ {1..5}: return 0
// level = *(uint8_t*)(ch + 0x599)
// return (int)floor(level * scale[tier])
// scale[1..5] = 3.5, 2.8, 2.1, 1.4, 0.7   // = 0.7 * (6 - tier)
```

Read-only. No inventory mutation.

## Body

| Field | Value |
|---|---|
| Start | `0x00520340` |
| End inclusive | `0x005204cd` |
| Size | **398 B** (`0x18E`) |
| Jump table | `0x005204d0` |

## Related

| Unit | Role |
|---|---|
| `Character_CalcCommodityTierFreeScore_Inferred` `0x00522780` | free-score uses this as **max** (dualed R10-036) |
| `Character_SumCommodityTfidRowCost_Inferred` `0x00522710` | **used** cost peer (dualed) |
| `Character_SumCommodityTfidFiveRowCosts_Inferred` `0x005244e0` | multi-row used-cost sum (dualed R11-001; partition parent) |
| `FUN_008e41b0` | UI formats `"Complexity: %i/%i"` with this as max |

## Gaps

- Product English method name
- Semantic proof that +0x599 is character level (family consensus only)
- Runtime / bit-exact / differential
- Dual of sum wrappers / UI hosts open
