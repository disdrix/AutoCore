# Function record: SoftCastHitList_QuickSortRange_KeyFloat14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489f20` |
| **Canonical name** | `SoftCastHitList_QuickSortRange_KeyFloat14_Inferred` |
| **Ghidra name** | `FUN_00489f20` |
| **Address** | `0x00489f20`–`0x0048a05d` inclusive (**318 B** / `0x13E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | MEGA-115 |
| **Completion status** | **Dual A/B sealed 2026-08-05 (MEGA-115)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; terminal false) |

## Alias

- Ghidra / scaffold: `FUN_00489f20`
- No `Named_CalleeOf_*` scaffold to retire

## Purpose

In-place **Hoare quicksort** of a soft-cast hit array over inclusive index range `[lo, hi]`:

- Element stride **0x30**
- Ascending sort key = **float at +0x14**
- Mid-index pivot `((lo+hi)>>1)`
- Partial swap: `+0x00,+0x04,+0x08,+0x0C,+0x10,+0x14,+0x20` (sticky: `+0x18,+0x1C,+0x24..+0x2C`)
- Left partition recursive; right partition iterative (tail)
- 4th arg cookie unused (parent seeds `this & 0xFFFFFF00`)

## Signature

```c
void __cdecl SoftCastHitList_QuickSortRange_KeyFloat14_Inferred(
    SoftCastHitElem0x30 *base, int lo, int hi, uint32_t cookie /* unused */);
// bare RET (C3); caller ADD ESP,0x10
```

## Callers / callees

| Role | Target |
|---|---|
| External caller | `SoftCastHitList_SortIfCountGt1_Inferred` (`0x0048a060`) @ `0x0048a079` |
| Self | recurse @ `0x0048a040` |
| Callees | self only |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00489f20_FUN_00489f20.md` |
| Annotated | `docs/reconstruction/raw/aa_00489f20_FUN_00489f20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00489f20.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00489f20_SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00489f20_SoftCastHitList_QuickSortRange_KeyFloat14_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00489f20_FUN_00489f20.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / qsort | **Confirmed** |
| Soft-cast hit-list role via parent dual | **High** |
| Product key English (distance vs score) | **Inferred** |
| Unswapped field semantics | **Open** |
| Runtime | **Open** |
