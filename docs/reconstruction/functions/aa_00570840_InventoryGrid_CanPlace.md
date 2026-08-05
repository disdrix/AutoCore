# Function record: InventoryGrid_CanPlace

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570840` |
| **Canonical name** | `InventoryGrid_CanPlace` |
| **Ghidra name** | `FUN_00570840` |
| **Address** | `0x00570840` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual sealed (accept-with-gaps)** — index + page rule High; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual reviews** | `reviews/A_aa_00570840_InventoryGrid_CanPlace.md`, `reviews/B_aa_00570840_InventoryGrid_CanPlace.md` |
| **Residual** | `reviews/a_00570840.md` |

## Alias

Former scaffold: `FUN_00570840` / `Named_CalleeOf_Named_CalleeOf_Client_UI_InventoryDropToGrid_00570840`.

## Purpose

Full-rectangle **can-place** test: grid bounds, **page non-span**, every cell empty (or single conflict COID). Does **not** place/stamp (`0x00571620`) or search free origins (`0x005713a0`).

## Signature (decompiler-derived, sealed 2026-07-29)

```c
uint __thiscall InventoryGrid_CanPlace(
    InventoryGrid* this,
    byte sizeX,
    byte sizeY,
    byte originX,
    byte originY,
    uint* conflictOut /* nullable; 2×u32 COID */);
```

## Sealed formulas

| Formula | Expression | Confidence |
|---------|------------|------------|
| Cell index | `idx = height(+0x0c) * x + y` | **High / Sealed** |
| Page non-span | `(originY % pageH(+0x1c)) + sizeY <= pageH` | **High / Sealed** |
| Empty cell | `(lo & hi) == 0xFFFFFFFF` | **High** |
| X bound | `width(+0x08) >= originX + sizeX` | **High** |
| Y bound | `height >= originY + sizeY` | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00570840_FUN_00570840.md`
- Annotated: `docs/reconstruction/raw/aa_00570840_FUN_00570840.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_CanPlace.cpp`
- Legacy scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00570840.cpp` (superseded by named clean)
- Dual residual: `docs/reconstruction/reviews/a_00570840.md`

## Callers / callees

**Callees:** none (leaf; no FUN_* calls).

**Callers (Ghidra 2026-07-29):**

| VA | Name (inferred / sibling) |
|----|---------------------------|
| `0x00570af0` | FUN_00570af0 |
| `0x005713a0` | InventoryGrid_FindFreeSlot |
| `0x005715d0` | FUN_005715d0 |
| `0x00571620` | InventoryGrid_PlaceItemFootprint |
| `0x00572360` | FUN_00572360 (repack) |
| `0x0085f220` | FUN_0085f220 (UI) |

FindFree/Place pass **null** conflictOut.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** (live ≡ raw) |
| Index `height*x+y` | **High / Sealed** |
| Page non-span rule | **High / Sealed** |
| Parameter semantic names | **High** (loop roles + callers) |
| conflictOut producers | Tentative / partial |
| Runtime / bit-exact | Open |
