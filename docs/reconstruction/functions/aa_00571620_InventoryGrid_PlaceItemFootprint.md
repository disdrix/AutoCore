# Function record: InventoryGrid_PlaceItemFootprint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571620` |
| **Canonical name** | `InventoryGrid_PlaceItemFootprint` |
| **Address** | `0x00571620` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual residual stamp/ABI **byte-sealed** (2026-07-29 strengthen); runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** (`A_` / `B_` + residual `a_00571620.md`) |

## Purpose

Place item at `(originX, originY)`: reject disallowed classes; type-4 special path; CanPlace; bind item; stamp COID into every footprint cell (`InvSizeX/Y` at clonebase `+0x406/+0x407`).

## Signature (byte-sealed 2026-07-29)

```c
uint32_t __thiscall InventoryGrid_PlaceItemFootprint(
    InventoryGrid* this,   // ECX
    ItemObject* item,      // stack0
    uint32_t originX,      // stack1
    uint32_t originY,      // stack2
    uint32_t quantity);    // stack3 → vtbl+0x260
// RET 0x10   // epilogue bytes C2 10 00
```

Decompiler label: `FUN_00571620`. Prior `unaff_SI` / `unaff_retaddr` were decompiler failures (sizeX outer bound / quantity). Live decompile still emits them — **do not trust stamp body**.

## Behavioral summary

Reject types `0x12/14/16/36/38/3a`; type 4 light bind (no stamp); min 2×2 on grid type 4; CanPlace; vcall setup; multi-cell stamp of `item+0x160/+0x164`; flag `|0x10`.

### Stamp index (byte-sealed)

```text
index = *(grid+0x0c) * (originX + dx) + (originY + dy)
// dx in [0, sizeX), dy in [0, sizeY)
// cells = *(grid+0x28); store COID lo/hi at cells[index*8 (+4)]
```

| Evidence | Detail |
|----------|--------|
| Bytes @ stamp core | `MOV EDX,[EDI+0xc]; IMUL EDX,[ESP+baseX]; ADD EDX,dy; ADD EDX,originY; MOV [EBX+EDX*8],…` |
| CanPlace `0x00570840` | decompile `*(grid+0xc)*x + y` |
| FindFree `0x005713a0` | free probe same `height*x + y` |

Same family as CanPlace / FindFreeSlot (`height * x + y`).

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature | **Confirmed** (`RET 0x10` bytes + prologue) |
| Control flow | High |
| Stamp formula | **Confirmed** (`read_memory` opcodes) |
| Naming | Probable |
| Side effects | High (cells + item flags) |
| Overall | **High** CF/stamp; **Probable–High** package (runtime open) |

## Open questions

- Runtime multi-cell dump after place (2×3 → six cells at sealed indices)
- Reject type English / enum names
- Differential / bit-exact
- PDB names for vfuncs `+0x158/+0x24c/+0x40/+0x260/+0x1cc`

## Offsets (raw + byte evidence)

**Source:** `aa_00571620` `read_memory` 2026-07-29; callers DropResponse; helpers `aa_00570720` / `aa_005713a0` / `aa_00570840`.

### This unit does **not** read `inventoryType`

Caller resolves grid, then `__thiscall` place.

### InventoryGrid (`this`)

| Offset | Size / shape | Raw use | Evidence |
|--------|--------------|---------|----------|
| `+0x04` | `i32` | Compared to **4**; min footprint 2×2 if sizes zero | place |
| `+0x08` | `i32` | Width (CanPlace/Find bounds) | can / find / alloc |
| `+0x0c` | `i32` | Height + **index multiplier** | place stamp `IMUL`; find / can |
| `+0x1c` | `i32` | Page height (CanPlace) | can / find / alloc |
| `+0x24` | `u32` | Passed to item vfunc `+0x158` | place |
| `+0x28` | ptr | Cell array; **8-byte** COID pairs | place stamp target |
| `+0x2c` | subobject | `FUN_00566f00` **this** (item on stack) | `LEA ECX,[EDI+0x2c]` |

### Item / clonebase

| Location | Raw use |
|----------|---------|
| `item+0xa8` then `+0x38` | Object type id; reject set; type `4` early |
| `+0x3c` via host | Clonebase runtime blob |
| `blob + 0x406` / `+0x407` | InvSizeX / InvSizeY |
| `item+0x160` / `+0x164` | COID lo/hi stamped into cells |
| `item+0x17c` | Flags: bit 6 gfx; success `\| 0x10` |

### DropResponse packet (caller) — place args only

| Packet offset | Use |
|---------------|-----|
| `+0x18` / `+0x19` | origin X / Y into place |
| `+0x1a` | inventoryType (grid select; **not** read by place) |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00571620_InventoryGrid_PlaceItemFootprint.md` |
| Annotated | `raw/aa_00571620_InventoryGrid_PlaceItemFootprint.annotated.md` |
| Clean | `reconstructed-exact/InventoryGrid_PlaceItemFootprint.cpp` |
| Dual residual scratch | `reviews/a_00571620.md` |
| Dual A | `reviews/A_aa_00571620_InventoryGrid_PlaceItemFootprint.md` |
| Dual B | `reviews/B_aa_00571620_InventoryGrid_PlaceItemFootprint.md` |
| Reconstruction review | `reviews/aa_00571620_reconstruction_review.md` |
| Skeptical review | `reviews/aa_00571620_skeptical_review.md` |
