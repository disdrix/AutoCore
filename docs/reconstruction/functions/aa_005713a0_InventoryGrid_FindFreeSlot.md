# Function record: InventoryGrid_FindFreeSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_005713a0` |
| **Canonical name** | `InventoryGrid_FindFreeSlot` |
| **Address** | `0x005713a0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual A/B + **footprint scan formula residual sealed 2026-07-29**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

First-fit free rectangle search (**Y outer, X inner**). Writes origin to `outX`/`outY`. Empty cell: `(lo & hi) == 0xFFFFFFFF`. Client cell index: `height * x + y` (column-major storage). Logical coordinates match AutoCore `(x,y)`. **Does not place/stamp** (that is `0x00571620`).

## Signature (decompiler-derived)

```c
uint32_t __thiscall InventoryGrid_FindFreeSlot(
    InventoryGrid* this, uint sizeX, uint sizeY,
    uint8_t* outX, uint8_t* outY, char pageIndex); // -1 / 0xFFFFFFFF = whole grid
```

CanPlace probe: `FUN_00570840` (thiscall; last arg `uint* conflictOut`, null here). Degenerate size 0 → success at (0,0).

## Footprint scan formula (SEALED)

Residual: `reviews/a_005713a0.md`. Live decompile ≡ raw 2026-07-29.

```text
null outs → 0
(char)sizeX==0 || (char)sizeY==0 → *outX=*outY=0; return 1

// Y band (char): pageIndex==-1 → [0, height-sizeY]
//                else → [pageH*p, pageH*p + (pageH-sizeY)]  pageH@+0x1c
// X: x ∈ [0, width-sizeX]  via xLimit = (width - (sizeX&0xff)) + 1

for y outer, x inner:
  idx = height(+0x0c) * x + y
  if (cells(+0x28)[idx].lo & .hi) == 0xFFFFFFFF:
    if CanPlace(this, sizeX, sizeY, x, y, NULL): *outX=x; *outY=y; return 1
return 0
```

| Piece | Confidence |
|---|---|
| Scan order Y→X first-fit | **High / Sealed** |
| Free prefilter `(lo&hi)==-1` | **High / Sealed** (alloc fill) |
| CanPlace full rect + page non-span | **High / Sealed** (`0x00570840`) |
| Index family w/ Place | **High / Sealed** (`a_00571620`) |
| Layout `+0x08` W / `+0x0c` H / `+0x1c` pageH / `+0x28` cells | **High / Sealed** |

## Callers (xref complete)

| Address | pageIndex | Note |
|---|---|---|
| `0x00531570` | `0xffffffff` | Whole grid |
| `0x005316c0` | `0xffffffff` | Whole grid |
| `0x00572360` | `0xffffffff` | Repack |
| `0x00572730` | `0xffffffff` | Sort/repack |
| `0x00588290` | `0xffffffff` | 2×2 if InvSize 0; else wrapper `-1` |
| `0x005714e0` | passthrough | Only non-`-1` capability |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature | High (thiscall + 5 stack args) |
| Control flow | High (live decompile ≡ raw 2026-07-29) |
| Footprint scan formula | **High / Sealed** (residual) |
| Naming | Probable (was FUN_005713a0) |
| Side effects | High (out params only) |
| Layout labels | High (`+0x08` W, `+0x0c` H+stride, `+0x1c` pageH, `+0x28` cells) |
| Overall | **Probable / accept-with-gaps** — dual + formula residual sealed; runtime open |

## Open questions

- Runtime / differential pack tests
- i8 truncation if total height > 127 (Y band uses `char`; index mult is full `i32`)
- Callers of `FUN_005714e0` that pass non-`-1` pageIndex (none observed at residual time)

## Dual reviews

| Kind | Path | Verdict |
|---|---|---|
| A (fidelity) | `reviews/A_aa_005713a0_InventoryGrid_FindFreeSlot.md` | accept-with-gaps (2026-07-29 residual) |
| B (skeptical) | `reviews/B_aa_005713a0_InventoryGrid_FindFreeSlot.md` | accept-with-gaps (2026-07-29 residual) |
| Residual scratch | `reviews/a_005713a0.md` | **scan formula sealed** |
| Legacy scaffold | thin wave2 A/B 2026-07-23 | **Superseded** |
| Legacy long-form | `aa_005713a0_reconstruction_review.md` / `_skeptical_review.md` | Historical; B upgrades `needs-more-evidence` → accept-with-gaps after CanPlace/layout/formula seal |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_005713a0_InventoryGrid_FindFreeSlot.md` |
| Annotated | `raw/aa_005713a0_InventoryGrid_FindFreeSlot.annotated.md` |
| Clean | `reconstructed-exact/InventoryGrid_FindFreeSlot.cpp` |
| Server | `InventoryGridPlacement.TryFindFirstFree` |
| CanPlace | `FUN_00570840` @ `0x00570840` |
| Place residual | `reviews/a_00571620.md` |
| Allocate | `InventoryGrid_AllocateCellArray_Inferred` @ `0x00570720` |
