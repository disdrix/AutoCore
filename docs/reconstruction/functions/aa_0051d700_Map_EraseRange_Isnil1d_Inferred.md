# Function record: Map_EraseRange_Isnil1d_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d700` |
| **Canonical name** | `Map_EraseRange_Isnil1d_Inferred` |
| **Ghidra name** | `FUN_0051d700` |
| **Address** | `0x0051d700`–`0x0051d7b4` (**180 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (WQ-009 residual skill-bank helper) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9E-I OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC red-black **range erase** `[first, last)` for **isnil@+0x1d** maps. Full clear frees via `FUN_0051be10`; partial erase loops through `FUN_0051c880`. Writes end iterator to `*out_it`. Peer of `Map_EraseRange` / `Map_EraseRange_B` with different node family.

## Signature (byte-sealed)

```c
void __thiscall Map_EraseRange_Isnil1d_Inferred(
    void *map,        // ECX — head @ +4, size @ +8
    void **out_it,    // stack0
    void *first,      // stack1 inclusive
    void *last);      // stack2 exclusive
// RET 0x0C
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051d700_FUN_0051d700.md`
- Annotated: `docs/reconstruction/raw/aa_0051d700_FUN_0051d700.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Map_EraseRange_Isnil1d_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051d700.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051d700_Map_EraseRange_Isnil1d_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051d700_Map_EraseRange_Isnil1d_Inferred.md`
- Alias record: `docs/reconstruction/functions/aa_0051d700_FUN_0051d700.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_0051e120` | map host complete dtor only @ `0x0051e132` |
| Callee | `FUN_0051be10` | full-tree free isnil@+0x1d |
| Callee | `FUN_0051c880` | single-node erase + rebalance |

## Confidence

| Claim | Level |
|---|---|
| STL range-erase role | **Confirmed** |
| ABI thiscall + ret 0x0c + isnil@+0x1d | **Confirmed** |
| Distinct from Map_EraseRange / _B | **Confirmed** |
| Product/PDB symbol | Open (`_Inferred` structural) |
| Runtime / image diff | Open |
