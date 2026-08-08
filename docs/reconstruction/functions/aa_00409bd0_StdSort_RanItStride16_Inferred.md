# Function record: StdSort_RanItStride16_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409bd0` |
| **Canonical name** | `StdSort_RanItStride16_Inferred` (**Inferred** — no RTTI demangle) |
| **Ghidra name** | `FUN_00409bd0` |
| **Prior scaffold** | `Named_CalleeOf_*PollBoundActions*` / `FUN_00409bd0` (**retired** misname) |
| **Address** | `0x00409bd0`–`0x00409cb9` inclusive (**234 B** / `0xEA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Sort` (stride-16 random-access introsort) |
| **Agent** | MEGA-043 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Classic **MSVC introsort** over a contiguous array of **16-byte** records:

```text
count = (last - first) / 16
if count ≤ 32:
  if count > 1: InsertionSort(first, last, pred)     // FUN_0040a410
  return
if ideal ≤ 0:
  if count > 32:
    if span > 16: MakeHeap(first, last, pred)        // FUN_0040a820
    SortHeap(first, last, pred)                      // FUN_0040a380
  return (or fall to insertion if count ≤ 32)
Partition → (mid_lo, mid_hi)                         // FUN_00409f90
ideal = ideal/2 + (ideal/2)/2                        // ¾
recurse smaller half; loop on larger half
```

## Signature

```c
// __cdecl; plain RET; void
void __cdecl StdSort_RanItStride16_Inferred(
    Elem16 *first,
    Elem16 *last,
    int ideal,
    bool (__cdecl *pred)(const Elem16 *, const Elem16 *));
```

| Formal | Role |
|---|---|
| first | begin pointer (inclusive) |
| last | end pointer (exclusive) |
| ideal | remaining depth budget (caller seeds with element count) |
| pred | less-than predicate |

## Element / algorithm facts

| Fact | Value | Conf |
|---|---|---|
| Element size | **16** (`SAR 4`) | **Confirmed** |
| Insertion threshold | **32** (`0x20`) | **Confirmed** |
| Depth reduction | **¾** per partition level | **Confirmed** |
| ABI | **cdecl**, plain **`RET`** | **Confirmed** |
| Body size | **234 B** (`0xEA`) | **Confirmed** |

## Call graph

| Role | Target |
|---|---|
| **External callers (1)** | `FUN_00930360` @ `0x009305fc` — builds/sorts target-score vector; pred `LAB_0092cdd0` (float@+4 less) |
| Self recurse | `0x00409c3e`, `0x00409c4f` |
| Partition | `FUN_00409f90` |
| Insertion | `FUN_0040a410` |
| Make heap | `FUN_0040a820` |
| Sort heap | `FUN_0040a380` |

## Partition-map note

MEGA-043 row listed system `interaction-activation` / hint `PollBoundActions nested` under parent `0x00925d60`. **Live xrefs** show sole external parent `FUN_00930360` (sort-target-list). Treat partition hint as **lineage scaffold**, not direct call-graph fact.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdSort_RanItStride16_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00409bd0.cpp`
- Raw: `docs/reconstruction/raw/aa_00409bd0_FUN_00409bd0.md`
- Annotated: `docs/reconstruction/raw/aa_00409bd0_FUN_00409bd0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00409bd0_StdSort_RanItStride16_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00409bd0_StdSort_RanItStride16_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_00409bd0_FUN_00409bd0.md`
- Report: `docs/agents/task-dual-ab-00409bd0-mega-043-report.md`

## Confidence

| Claim | Level |
|---|---|
| Introsort CF / thresholds | **Confirmed** |
| Stride 16 | **Confirmed** |
| cdecl + plain RET | **Confirmed** |
| Caller set (Ghidra xrefs) | **Confirmed** |
| Product English | Medium → `_Inferred` |
| Runtime / bit-exact | Open |
