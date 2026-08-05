# Function record: InventoryGrid_AllocateCellArray_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570720` |
| **Canonical name** | `InventoryGrid_AllocateCellArray_Inferred` |
| **Address** | `0x00570720` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual A/B **strengthened 2026-07-29** (accept-with-gaps); runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Free prior cell buffer; compute `totalCells = width * height` and page-derived dims; allocate `totalCells * 8` bytes filled with `0xFFFFFFFF` (empty COID half). Does **not** place/stamp items.

## Signature (decompiler-derived)

```c
void __fastcall InventoryGrid_AllocateCellArray_Inferred(InventoryGrid* pGrid); // ECX
```

## Behavioral summary

| Step | Effect |
|---|---|
| Free `grid+0x28` | `operator_delete__` if non-null |
| Store total / page dims | `+0x10 = w*h`; `+0x1c = (n/pages)/w`; `+0x18 = n/h` |
| Alloc + fill | dword loop `0xFFFFFFFF`; residual byte loop (0 iters when aligned) |

## Layout (body-backed)

| Offset | Role |
|--------|------|
| `+0x08` | width (read) |
| `+0x0c` | height (read; find/place stride) |
| `+0x10` | total cells (write) |
| `+0x14` | pages (read) |
| `+0x18` | derived `n/h` (≈ width) |
| `+0x1c` | page height `(n/pages)/w` (cargo → 13) |
| `+0x28` | cell array `*` (8 B/cell) |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High (Ghidra + live re-decompile 2026-07-29) |
| Signature | Probable (`__fastcall` / ECX) |
| Control flow | High (decompiler ≡ clean) |
| Naming | Probable (INFERRED) |
| Side effects | High (heap + grid fields) |
| Dual A/B | **accept-with-gaps** (strengthened) |
| Overall | Probable — clean refined; not complete |

## Callers (Ghidra)

| VA | Notes |
|----|-------|
| `0x00572650` | ctor — clamp dims ≥1 then allocate |
| `0x00570f50` | thin re-empty |
| `0x00570f70` | clear items + re-empty |
| `0x00572360` | rebuild empty buffer |
| `0x00572730` | sort/rebuild (two sites) |

## Open questions

- Retail symbol name
- Runtime observation / differential equivalence
- OOM behavior of `operator_new__`

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00570720_InventoryGrid_AllocateCellArray_Inferred.md` |
| Annotated | `raw/aa_00570720_InventoryGrid_AllocateCellArray_Inferred.annotated.md` |
| Clean | `reconstructed-exact/InventoryGrid_AllocateCellArray_Inferred.cpp` |
| Dual A | `reviews/A_aa_00570720_InventoryGrid_AllocateCellArray_Inferred.md` |
| Dual B | `reviews/B_aa_00570720_InventoryGrid_AllocateCellArray_Inferred.md` |
| Scratch | `tmp/a_00570720.md` |
