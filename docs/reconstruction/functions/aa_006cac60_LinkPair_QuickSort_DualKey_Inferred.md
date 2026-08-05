# Function record: LinkPair_QuickSort_DualKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cac60` |
| **Canonical name** | `LinkPair_QuickSort_DualKey_Inferred` (Inferred) |
| **Ghidra name** | `FUN_006cac60` |
| **Address** | `0x006cac60` |
| **Body range** | `0x006cac60`–`0x006cad2f` exclusive (**207** B / `0xCF`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | phys / bind link-pair dual-key quicksort |
| **Completion status** | **complete-for-CF-ABI** — dual A/B **accept**; CF + ABI + dual-key sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md`, `reviews/B_aa_006cac60_LinkPair_QuickSort_DualKey_Inferred.md` (2026-07-29 W29-Q) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_006cac60`
- `Named_CalleeOf_…_VOG_DEBUG_ST_006cac60` (legacy scaffold — **narrow**)
- `LinkPair_QuickSort` (short name used by CanonAndSort clean)

## Purpose

Quicksort an array of 8-byte object pairs over inclusive `[lo, hi]` using dual unsigned keys `(a+4, b+4)`. Left partition recurses; right partition continues via outer-loop tail. Nested engine of `LinkPair_CanonAndSort_Inferred`.

## Signature

```c
void __cdecl LinkPair_QuickSort_DualKey_Inferred(
    LinkPair8* array,
    int lo,
    int hi,
    uint32_t unused);  // dead; passed from count&0xffffff00
// plain ret
```

## Algorithm

1. Pivot = mid `(lo+hi)>>1`; dual keys from pivot pair.
2. Partition: advance `i` while pair[i] < pivot; retreat `j` while pivot < pair[j]; swap full pairs.
3. If `lo < j` recurse left.
4. Set `lo = i`; if `hi <= i` return; else continue with right range.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006cac60_FUN_006cac60.md`
- Annotated: `docs/reconstruction/raw/aa_006cac60_FUN_006cac60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LinkPair_QuickSort_DualKey_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_006cac60.cpp`
- Function FUN_*: `docs/reconstruction/functions/aa_006cac60_FUN_006cac60.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0053af20-006cac60-w29q-report.md`
- Scratch: `docs/reconstruction/tmp/a_006cac60.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | self (left recurse @ `006cad11`) |
| **Callers** | `FUN_006cad30` LinkPair_CanonAndSort_Inferred @ `006cad76`; self |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| cdecl plain ret + 4 stack args | **High** |
| Dual-key unsigned @ object+4 | **High** |
| Stride 8 full-pair swap | **High** |
| param_4 unused | **High** |
| Product pointee type | **Inferred** / open |
| Runtime / differential | Open |

## Related

- Canon prep: `aa_006cad30` LinkPair_CanonAndSort_Inferred (W28-Q)
- Sorted merge: `aa_006caaa0` LinkPair_SortedDiffWalk_Inferred (W27-N)
- Commit: `aa_006297e0` Phys_CommitPairListStorage (W27-M)
