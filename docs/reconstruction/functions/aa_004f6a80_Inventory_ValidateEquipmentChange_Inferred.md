# Function record: Inventory_ValidateEquipmentChange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f6a80` |
| **Canonical name** | `Inventory_ValidateEquipmentChange_Inferred` |
| **Address** | `0x004f6a80` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual A/B MEGA-056 2026-08-05; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Alias

- Ghidra: `FUN_004f6a80`
- Retired: `Named_CalleeOf_Client_SendInventoryUnequip_004f6a80`
- Partition soft hint: `Inventory_HasSpaceForItem` (incomplete — space is ret **2** only)

## Purpose

Pre-flight **equipment change** validator used before C2S unequip (`0x203E`) and hardpoint grab (`0x2034`):

1. Reject null item (**8**).
2. Reject arena lock on inventory state `+0xf6` (**0xf**).
3. Probe free space via dualed `InventoryGrid_FindFreeForItem` on host grid `+0x2b0` (**2** on fail).
4. Dispatch on item type class; require TFID match against host hardpoint/container fields, with special town (**1**), hazard (**0xd**), and must-swap (**0xa**) outcomes.
5. Default reject (**8**).

Does **not** place items, send packets, or stamp grid cells.

## Signature (sealed)

```c
uint32_t __thiscall Inventory_ValidateEquipmentChange_Inferred(
    void* inventory,   // ECX
    void* item);       // stack0 — Item*
// callee cleans 4 stack bytes (ret 4)
```

## Status codes (this unit → UI `0x00931db0`)

| Code | Retail message (via 00931db0) |
|---|---|
| 0 | success (no message) |
| 1 | "This item can only be changed in town." |
| 2 | "There is not enough space in your inventory for this equipment." |
| 8 | "This item cannot be equipped." |
| 0xa | "This item must be swapped directly with another item." |
| 0xd | "Cannot change this item while in Hazard Mode!" |
| 0xf | "This equipment cannot be changed in an arena." |

## Host offsets used

| Offset | Use |
|---|---|
| `+0x254` | type `0x1c` slot* |
| `+0x258` | type `0x10` slot* |
| `+0x260` | type `0xc` flag-selected slot array |
| `+0x264` | type `0xc` subtype-9 slot* |
| `+0x268` | type `0xa` slot* |
| `+0x26c` | type `6` subtype 10 slot* |
| `+0x270` | type `6` subtype 11 slot* |
| `+0x2b0` | InventoryGrid* for FindFreeForItem |

## Control flow (summary)

```
null → 8
arena(+0xf6) → 0xf
!FindFreeForItem(+0x2b0) → 2
type dispatch / TFID / specials → 0|1|0xa|0xd
default → 8
```

## Notable callers

| Address / name | Role |
|---|---|
| `Client_SendInventoryUnequip` `0x00862c00` | Gate before C2S `0x203E` |
| `Client_SendInventoryGrab_Hardpoint` `0x00862d90` | Gate before C2S `0x2034` |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | **High** |
| Signature / convention | **High / Sealed** |
| Status-code emission | **High** |
| FindFree integration | **High** (dualed callee) |
| Slot product English | Tentative |
| Retail symbol | Open (`_Inferred`) |
| Runtime / differential | Open |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004f6a80_FUN_004f6a80.md`
- Annotated: `docs/reconstruction/raw/aa_004f6a80_FUN_004f6a80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Inventory_ValidateEquipmentChange_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004f6a80.cpp`
- Dual A/B: `docs/reconstruction/reviews/A|B_aa_004f6a80_Inventory_ValidateEquipmentChange_Inferred.md`
- Report: `docs/agents/task-dual-ab-004f6a80-mega-056-report.md`
