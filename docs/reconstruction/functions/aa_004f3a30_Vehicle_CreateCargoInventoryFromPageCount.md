# Function record: Vehicle_CreateCargoInventoryFromPageCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3a30` |
| **Canonical name** | `Vehicle_CreateCargoInventoryFromPageCount` |
| **Address** | `0x004f3a30` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** + **dual A/B accept-with-gaps** (2026-07-29 refresh) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Destroy prior cargo grid at `vehicle+0x2b0`; unless flag `+0x2ac`, allocate `InventoryGrid(6, nPages*13, nPages)`, set owner flag at `grid+0x4`, bind owner object at `grid+0x24` (vfunc `+0x18` / `FUN_005718a0`) and secondary owner at `grid+0x58` (vfunc `+0x14` / `0x00573900`).

## Signature (decompiler-derived)

```c
void __thiscall Vehicle_CreateCargoInventoryFromPageCount(void* this, short nPages);
```

`nPages` = chassis InventorySlots (pages, not total cells). Callisto X `1` → 78 cells.

## Behavioral summary

Scalar-deleting dtor on old grid → null → optional new grid + owner bind. Empty cells only (ctor/`AllocateCellArray`).

## Callers

| Address | Name | Notes |
|--------:|------|------|
| `0x00505270` | `Vehicle_applyCreatePacket` | iff packet opcode `0x201e`; pages = `(short)packet[0x35e]` |
| `0x005252f0` | `FUN_005252f0` | pages = `*(short*)(veh+0x1e6)` |

## Callees

| Address | Name |
|--------:|------|
| `0x00489892` | `operator_new` |
| `0x00572650` | `InventoryGrid_ctor_Inferred` |
| `0x00570600` | `InventoryGrid_SetOwnerFlag_Inferred` |
| (vtbl) | dtor `FUN_00573910`, bind `FUN_005718a0`, bind `0x00573900` |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature | High |
| Control flow | High |
| Geometry 6×pages×13 | Confirmed |
| Naming | High |
| Side effects | High |
| Owner field types | Probable |
| `+0x2ac` English | Probable |
| Overall | **High** on contract; dual **accept-with-gaps** |

## Open questions

- Meaning / full writer set of skip flag `+0x2ac`
- Exact type of pointer stored at `grid+0x58`
- Runtime / diff / bit-exact

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount.md` |
| Annotated | `raw/aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount.annotated.md` |
| Clean | `reconstructed-exact/Vehicle_CreateCargoInventoryFromPageCount.cpp` |
| Review A | `reviews/A_aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount.md` |
| Review B | `reviews/B_aa_004f3a30_Vehicle_CreateCargoInventoryFromPageCount.md` |
| Scratch | `tmp/a_004f3a30.md` |
