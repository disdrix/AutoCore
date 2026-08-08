# Function record: Character_SelectInventoryGridByMode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522020` |
| **Canonical name** | `Character_SelectInventoryGridByMode_Inferred` |
| **Ghidra symbol** | `FUN_00522020` |
| **Address** | `0x00522020` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Dual** | A/B **accept-with-gaps** (MEGA-045 2026-08-05) |
| **Name confidence** | **Inferred** — mode→grid selector + cross-dual invType 1/3/5; no PDB string |

## Purpose

Return the Character inventory grid pointer selected by mode integer (cargo / locker / trade), or null.

## Contract

```
// __thiscall Character* this
// ret 4 — stack: int mode
InventoryGrid* grid = Character_SelectInventoryGridByMode_Inferred(ch, mode);

// mode 1: mid = *(ch+0x250); return mid ? *(mid+0x2B0) : 0   // cargo
// mode 3: return *(ch+0xCBC)                                   // locker
// mode 5: return *(ch+0xCE0)                                   // trade
// else:   return 0
// leaf
```

## Related

| Unit | Role |
|---|---|
| `FUN_00941b20` | sole caller — equip/customize confirm space check |
| DropResponse / GrabApply duals | invType 1/3/5 English map (evidence) |
| `InventoryGrid_*` family | grid operations on returned pointer |
| Commodity cost duals | same cargo path `+0x250/+0x2B0` |

## Gaps

- Product English method name
- Locker/trade labels machine-local vs cross-dual only
- Runtime / bit-exact / differential
- Parent `FUN_00941b20` residual (not owned)
