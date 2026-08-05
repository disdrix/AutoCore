# Function record: FUN_004bcca0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcca0` |
| **Canonical name** | `FUN_004bcca0` (Ghidra scaffold) |
| **Named** | `CNDHash_FreeBuckets_009cb45c` |
| **Address** | `0x004bcca0`–`0x004bccd4` (**52 B / `0x34`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / CNDHash |
| **Completion status** | **Dual A/B present** (2026-07-29 W31-M) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

| Name | Status |
|---|---|
| `CNDHash_FreeBuckets_009cb45c` | **Accept** role name (primary object family) |
| `Named_CalleeOf_Named_VOG_DEBUG_STOP_004bcca0` | **Reject** as product id |

## Purpose

CNDHash FreeBuckets: zero count → owning reclaim (`FUN_004e2bd0`) → free sentinel slab + delete[] bucket table.

## Signature

```c
void __thiscall CNDHash_FreeBuckets_009cb45c(CNDHash *this); // plain ret
// Ghidra: void __fastcall FUN_004bcca0(int param_1)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bcca0_FUN_004bcca0.md`
- Annotated: `docs/reconstruction/raw/aa_004bcca0_FUN_004bcca0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004bcca0.cpp`
- Named: `docs/reconstruction/reconstructed-exact/CNDHash_FreeBuckets_009cb45c.cpp`
- Named function: `docs/reconstruction/functions/aa_004bcca0_CNDHash_FreeBuckets_009cb45c.md`
- Dual A/B: `docs/reconstruction/reviews/A_aa_004bcca0_CNDHash_FreeBuckets_009cb45c.md`, `B_…`

## Confidence

| Claim | Level |
|---|---|
| CF from decompile ≡ bytes | **Confirmed** |
| `__thiscall` plain ret | **Confirmed** |
| free(*buckets) slab + delete[] table | **Confirmed** |
| Role FreeBuckets | **High** |
| Product/PDB symbol | **Open** |
