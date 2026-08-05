# Function record: FUN_006cac60

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cac60` |
| **Canonical name** | `FUN_006cac60` (prefer `LinkPair_QuickSort_DualKey_Inferred`) |
| **Address** | `0x006cac60` |
| **Body range** | `0x006cac60`–`0x006cad2f` exclusive (**207** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | phys / bind link-pair dual-key quicksort |
| **Completion status** | **complete-for-CF-ABI** — dual A/B **accept** (W29-Q) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md`, `reviews/B_aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md` |
| **Last reviewed** | `2026-07-29` |

## Alias

- `LinkPair_QuickSort_DualKey_Inferred` (inferred named clean)
- `Named_CalleeOf_…_VOG_DEBUG_ST_006cac60` (legacy scaffold — **narrow**)

## Purpose

Dual-key quicksort of 8-byte link pairs; nested engine of CanonAndSort.

## Signature

```c
void __cdecl FUN_006cac60(LinkPair8* array, int lo, int hi, uint32_t unused);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006cac60_FUN_006cac60.md`
- Annotated: `docs/reconstruction/raw/aa_006cac60_FUN_006cac60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LinkPair_QuickSort_DualKey_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_006cac60.cpp`
- Named record: `docs/reconstruction/functions/aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md`
- Report: `docs/agents/task-dual-ab-0053af20-006cac60-w29q-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | self |
| **Callers** | `FUN_006cad30` (CanonAndSort); self (2 xrefs) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **High** |
| Dual-key + stride 8 | **High** |
| Product type | Open |
