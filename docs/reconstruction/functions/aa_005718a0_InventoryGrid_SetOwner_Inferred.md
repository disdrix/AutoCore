# Function record: InventoryGrid_SetOwner_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005718a0` |
| **Canonical name** | `InventoryGrid_SetOwner_Inferred` |
| **Address** | `0x005718a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual reviewed** (A + B, WQ8R-A 2026-08-04); accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open. Terminal false. |

## Alias

| Name | Status |
|------|--------|
| `FUN_005718a0` | Ghidra default |
| `InventoryGrid_SetOwner_Inferred` | Preferred (_Inferred) |

## Purpose

Bind grid owner pointer and rebind all list items to that owner. See FUN twin record and dual A/B for full evidence.

## Signature (byte-sealed)

```c
void __thiscall InventoryGrid_SetOwner_Inferred(InventoryGrid* this, void* ownerObject);
// ret 4
```

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_SetOwner_Inferred.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_005718a0_InventoryGrid_SetOwner_Inferred.md`, `B_aa_005718a0_InventoryGrid_SetOwner_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_005718a0_FUN_005718a0.md`
