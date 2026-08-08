# Function record: StdTree_EraseAndRebalance_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408ed0` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil31_Inferred` (**Inferred** structural + string plate) |
| **Ghidra name** | `FUN_00408ed0` |
| **Address** | `0x00408ed0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00408ed0`–`0x00409160` exclusive (**656 B** / `0x290`) |
| **System** | MSVC `std::_Tree` erase + RB rebalance (isnil@+0x31) |
| **Agent** | WQ9K-E OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` erase(const_iterator) for nodes with **color @ +0x30** and **isnil @ +0x31** (node size **0x38**). Throw on nil iterator; unlink + fix head extremities via min/max isnil31; rebalance if erased black using isnil31 L/R rotates; free node (no value dtor); size--; write `*outIt`.

## Signature

```c
void StdTree_EraseAndRebalance_Isnil31_Inferred(
    MapShell_Isnil31 *map,      // stack0
    MapNode_Isnil31 **outIt,    // stack1
    MapNode_Isnil31 *node);     // stack2
// RET 0x0C
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C..+0x2F | value payload (trivial — no dtor call sealed) |
| +0x30 | color (0 red / 1 black) |
| +0x31 | isnil |
| size | **0x38** |

Shell: `head@+4`, `size@+8`.

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_00407cb0` @ `0x00407d4e` |
| Succ | `StdTree_IteratorIncrement_Isnil31` @ `0x00408590` |
| Min | `StdTree_Min_Isnil31` @ `0x00409160` |
| Max | `FUN_004043e0` |
| Lrotate | `FUN_00403e90` |
| Rrotate | `FUN_00403ee0` |
| Free | `operator_delete` only (no `~basic_string`) |

## Evidence summary

- Live decompile ≡ raw CF for throw/unlink/rebalance; epilogue sealed via `read_memory` (`ret 0xC`, size--).
- String `"invalid map/set<T> iterator"`; ThrowInfo `DAT_00acc34c`.
- isnil opcode family `+0x31`; color `+0x30`.
- Do not merge with isnil29 erase (`0x004cb740`) or StringKey isnil2d erase (`0x004094c0`).

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil31_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00408ed0.cpp`
- Raw: `docs/reconstruction/raw/aa_00408ed0_FUN_00408ed0.md`
- Annotated: `docs/reconstruction/raw/aa_00408ed0_FUN_00408ed0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00408ed0_StdTree_EraseAndRebalance_Isnil31_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00408ed0_StdTree_EraseAndRebalance_Isnil31_Inferred.md`
- Report: `docs/agents/task-dual-ab-00408ed0-00833d50-wq9ke-report.md`
