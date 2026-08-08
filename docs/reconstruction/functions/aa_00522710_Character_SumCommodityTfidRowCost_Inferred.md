# Function record: Character_SumCommodityTfidRowCost_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522710` |
| **Canonical name** | `Character_SumCommodityTfidRowCost_Inferred` |
| **Ghidra symbol** | `FUN_00522710` |
| **Address** | `0x00522710` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Dual** | A/B **accept-with-gaps** (WQ8R-J 2026-08-04) |
| **Name confidence** | **Inferred** — Commodity type imm + cargo FindByCoid + cost accum; no PDB string |

## Purpose

Compute used **commodity-row slot cost** from a 5-slot COID/TFID array against the character cargo inventory grid.

## Contract

```
// __thiscall Character* this
// ret 8 — stack: (unused dword, tfidRow*)
int cost = Character_SumCommodityTfidRowCost_Inferred(ch, unused, tfidRow);

// cost starts at 1
// for i in [0,4]:
//   skip if tfid null (lo==hi==0xFFFFFFFF)
//   item = InventoryGrid_FindItemByCoid(*(*(ch+0x250)+0x2B0), lo, hi)
//   if !item || def.type != Commodity(0x1A): return cost
//   cost += *(uint8*)(*(def+0x3C)+0x4C8) + i
// return cost
```

## Related

| Unit | Role |
|---|---|
| `InventoryGrid_FindItemByCoid` `0x00571010` | resolve COID on cargo grid |
| `FUN_00520340` | max capacity for tier (caller pair) |
| `FUN_00522780` | free-slot float score using this as "used" |
| `FUN_005244e0` | sum costs over 5 TFID rows |

## Gaps

- Product English name
- Subblob+0x4C8 field label
- Runtime / bit-exact
