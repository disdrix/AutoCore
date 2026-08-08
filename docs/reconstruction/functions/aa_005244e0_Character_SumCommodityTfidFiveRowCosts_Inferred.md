# Function record: Character_SumCommodityTfidFiveRowCosts_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005244e0` |
| **Canonical name** | `Character_SumCommodityTfidFiveRowCosts_Inferred` |
| **Ghidra symbol** | `FUN_005244e0` |
| **Address** | `0x005244e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Dual** | A/B **accept-with-gaps** (R11-001 2026-08-05) |
| **Name confidence** | **Inferred** — multi-row wrapper over dualed commodity row cost; no PDB string |

## Purpose

Compute **total used commodity-row slot cost** over a fixed table of **five** TFID rows against the character cargo inventory (via dualed per-row worker).

## Contract

```
// __thiscall Character* this
// ret 4 — stack: table* (5 rows × 0x28)
int sum = Character_SumCommodityTfidFiveRowCosts_Inferred(ch, table);

// sum starts at 0
// for rowIndex in [0,4]:
//   row = table + rowIndex * 10 dwords
//   if (row[0] & row[1]) == 0xFFFFFFFF: continue   // null head
//   sum += Character_SumCommodityTfidRowCost_Inferred(ch, rowIndex, row)
// return sum
```

## Body

| Field | Value |
|---|---|
| Start | `0x005244e0` |
| End inclusive | `0x00524518` (`C2 04 00`) |
| Size | **57 B** (`0x39`) |
| Pad | `CC` → `FUN_00524520` @ `0x00524520` |

## Related

| Unit | Role |
|---|---|
| `Character_SumCommodityTfidRowCost_Inferred` `0x00522710` | per-row cost (callee; dualed) |
| `Character_CalcCommodityTierFreeScore_Inferred` `0x00522780` | sibling free-score for **one** tier row (dualed R10-036) — do not merge |
| `InventoryGrid_FindItemByCoid` `0x00571010` | resolve COID (inside callee) |

## Gaps

- Product English name
- Live callers (Ghidra xrefs empty)
- Whether outer 5 rows map to tiers 1..5
- Runtime / bit-exact / differential
