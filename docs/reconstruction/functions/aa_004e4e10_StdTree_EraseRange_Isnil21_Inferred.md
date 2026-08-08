# Function record: StdTree_EraseRange_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4e10` |
| **Canonical name** | `StdTree_EraseRange_Isnil21_Inferred` |
| **Ghidra name** | `FUN_004e4e10` |
| **Address** | `0x004e4e10`–`0x004e4ec4` exclusive (**180 B** / `0xB4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL map-set (isnil@+0x21 range erase) |
| **Classification** | worker (shared map range erase) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-05 (R13-024 OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |
| **Terminal** | **false** |
| **Parent dual** | `0x004e3e70` `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Dual start** | 2686 |

## Alias

- `FUN_004e4e10` (Ghidra)
- `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e4e10` (**reject** as product identity)

## Purpose

MSVC red-black **range erase** `[first, last)` for nodes with **isnil@+0x21**. Full clear frees via `FUN_004e2e00`; partial erase loops dualed `StdTree_EraseAndRebalance_Isnil21_Inferred` (`0x004e3e70`). Writes end iterator to `*outIt`. Both exits **RET 0x0C**.

Distinct from twin `FUN_004e52a0` (same erase callee; free via `FUN_004e2e40`) and from Val12 / Isnil29 range families.

## Signature (byte-sealed)

```c
void __thiscall StdTree_EraseRange_Isnil21_Inferred(
    void *map,        // ECX — head @ +4, size @ +8
    void **out_it,    // stack0
    void *first,      // stack1 inclusive
    void *last);      // stack2 exclusive
// RET 0x0C
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e4e10_FUN_004e4e10.md`
- Annotated: `docs/reconstruction/raw/aa_004e4e10_FUN_004e4e10.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil21_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_004e4e10.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004e4e10_StdTree_EraseRange_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004e4e10_StdTree_EraseRange_Isnil21_Inferred.md`
- Alias record: `docs/reconstruction/functions/aa_004e4e10_FUN_004e4e10.md`
- Report: `docs/agents/task-dual-ab-004e4e10-r13-report.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_004e7320` @ `0x004e7332` | sole xref — erase(begin,end) then `operator_delete(head)` |
| Callee | `FUN_004e2e00` | full-tree free (isnil@+0x21; residual algebra) |
| Callee | `StdTree_EraseAndRebalance_Isnil21_Inferred` `0x004e3e70` | single-node erase (parent dual R12-013) |

## Confidence

| Claim | Level |
|---|---|
| STL range-erase role | **High** / Confirmed structural |
| ABI thiscall + ret 0x0c + isnil@+0x21 | **High** / Confirmed (bytes) |
| Full-clear free `004e2e00` + partial erase `004e3e70` | **High** |
| Sole caller `004e7320` | **High** |
| Distinct free pair vs twin `004e52a0` | **High** |
| Product/PDB English / K/V | Open (`_Inferred`) |
| Runtime / image diff | Open |
