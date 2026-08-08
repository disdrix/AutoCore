# Function record: Map_EraseRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c7c0` |
| **Canonical name** | `Map_EraseRange` |
| **Ghidra name** | `FUN_0051c7c0` |
| **Address** | `0x0051c7c0`–`0x0051c873` (**180 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (WQ-009 residual skill-bank helper) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9D-H OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC red-black **range erase** `[first, last)` for large-node maps (`isnil@+0x29`). Full clear frees via `FUN_0051bbc0`; partial erase loops through `Map_EraseNode`. Writes end iterator to `*out_it`.

## Signature (byte-sealed)

```c
void __thiscall Map_EraseRange(
    void *map,        // ECX — head @ +4, size @ +8
    void **out_it,    // stack0
    void *first,      // stack1 inclusive
    void *last);      // stack2 exclusive
// RET 0x0C
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051c7c0_FUN_0051c7c0.md`
- Annotated: `docs/reconstruction/raw/aa_0051c7c0_FUN_0051c7c0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_EraseRange.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051c7c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051c7c0_Map_EraseRange.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051c7c0_Map_EraseRange.md`
- Alias record: `docs/reconstruction/functions/aa_0051c7c0_FUN_0051c7c0.md`
- Rejected scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_0051c7c0.cpp`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `CVOGHBAIBase_GetTargetFromAggro` | `0x00639170`, `0x006391d0` |
| Caller | `FUN_0051da30` | map host complete dtor @ `0x0051da42` |
| Callee | `FUN_0051bbc0` | full-tree free |
| Callee | `Map_EraseNode` `0x0051cb40` | single-node erase |

## Confidence

| Claim | Level |
|---|---|
| STL range-erase role | **Confirmed** |
| ABI thiscall + ret 0x0c + isnil@+0x29 | **Confirmed** |
| Family with Map_EraseNode | **Confirmed** |
| Product/PDB symbol | Open (`Map_EraseRange` structural) |
| Runtime / image diff | Open |
