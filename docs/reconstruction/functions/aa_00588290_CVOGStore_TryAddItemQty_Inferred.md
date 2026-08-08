# Function record: CVOGStore_TryAddItemQty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00588290` |
| **Canonical name** | `CVOGStore_TryAddItemQty_Inferred` |
| **Address** | `0x00588290` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual reviewed** (A + B, WQ8R-A 2026-08-04); accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open. Terminal false. |

## Alias

| Name | Status |
|------|--------|
| `FUN_00588290` | Ghidra default |
| `CVOGStore_TryAddItemQty_Inferred` | Preferred |

## Purpose

Store inventory add-with-stack-or-place. See FUN twin record and dual A/B.

## Signature (byte-sealed)

```c
int __thiscall CVOGStore_TryAddItemQty_Inferred(
    CVOGStore* this, InventoryItem* item, int qty);
// ret 8; returns qty or 0
```

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/CVOGStore_TryAddItemQty_Inferred.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00588290_CVOGStore_TryAddItemQty_Inferred.md`, `B_aa_00588290_CVOGStore_TryAddItemQty_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_00588290_FUN_00588290.md`
