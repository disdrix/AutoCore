# Function record: StdTree_EraseRange_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbaa0` |
| **Canonical name** | `StdTree_EraseRange_Isnil29_Inferred` |
| **Ghidra name** | `FUN_004cbaa0` |
| **Address** | `0x004cbaa0`–`0x004cbb54` exclusive (**180 B** / `0xB4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | STL / map-set (isnil@+0x29 range erase; pairs StdTree erase/rebalance) |
| **Classification** | worker (shared map range erase) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9F-C OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

## Alias

- `FUN_004cbaa0` (Ghidra)
- `Named_CalleeOf_Named_VOG_DEBUG_STOP_004cbaa0` (**narrow** — multi-caller STL helper)

## Purpose

MSVC red-black **range erase** `[first, last)` for nodes with **isnil@+0x29**. Full clear frees via `FUN_004cb550`; partial erase loops dualed `StdTree_EraseAndRebalance_Isnil29_Inferred` (`0x004cb740`). Writes end iterator to `*outIt`. Both exits **RET 0x0C**.

Distinct from dualed `Map_EraseRange` / `Map_EraseRange_B` (same isnil offset and 180 B shape; **different free + single-erase callees**).

## Signature (byte-sealed)

```c
void __thiscall StdTree_EraseRange_Isnil29_Inferred(
    void *map,        // ECX — head @ +4, size @ +8
    void **out_it,    // stack0
    void *first,      // stack1 inclusive
    void *last);      // stack2 exclusive
// RET 0x0C
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cbaa0_FUN_004cbaa0.md`
- Annotated: `docs/reconstruction/raw/aa_004cbaa0_FUN_004cbaa0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil29_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_004cbaa0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md`
- Alias record: `docs/reconstruction/functions/aa_004cbaa0_FUN_004cbaa0.md`
- Report: `docs/agents/task-dual-ab-004c8780-004cbaa0-wq9fc-report.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_004cc3d0` | map-shell clear + delete head @ `0x004cc3e2` |
| Caller | `FUN_004c9f80` | creature dtor path @ `0x004ca113` |
| Caller | `FUN_004ea350` | ×3 sites (`0x004ea63f`, `0x004ea94d`, `0x004eabd1`) |
| Caller | parent @ `0x005dd8cb` | additional site |
| Callee | `FUN_004cb550` | full-tree free (isnil@+0x29 residual) |
| Callee | `StdTree_EraseAndRebalance_Isnil29_Inferred` `0x004cb740` | single-node erase (WQ9E-E dual) |

## Confidence

| Claim | Level |
|---|---|
| STL range-erase role | **High** / Confirmed structural |
| ABI thiscall + ret 0x0c + isnil@+0x29 | **High** |
| Distinct free/erase pair vs Map_EraseRange* | **High** |
| Product/PDB English / K/V | Open (`_Inferred`) |
| Runtime / image diff | Open |
