# Function record: StdMap_StringKey_EraseAndRebalance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004094c0` |
| **Canonical name** | `StdMap_StringKey_EraseAndRebalance_Inferred` (**Inferred** structural + string plate) |
| **Ghidra symbol** | `FUN_004094c0` |
| **Address** | `0x004094c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004094c0`–`0x0040977d` exclusive (**701 B** / `0x2BD`) |
| **System** | MSVC `std::_Tree` erase + RB rebalance (StringKey) |
| **Agent** | WQ9J-F OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` erase(const_iterator) for nodes with **color @ +0x2C** and **isnil @ +0x2D** (node size **0x30**, `std::string` key @ **+0x0C**). Throw on nil iterator; unlink + fix head extremities via min/max isnil2d; rebalance if erased black using isnil2d L/R rotates; destroy string; free node; size--; write `*outIt`.

## Signature

```c
void StdMap_StringKey_EraseAndRebalance_Inferred(
    MapShell_StringKey *map,      // stack0
    MapNode_StringKey **outIt,    // stack1
    MapNode_StringKey *node);     // stack2
// RET 0x0C
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C | `std::string` key |
| +0x28 | mapped dword |
| +0x2C | color (0 red / 1 black) |
| +0x2D | isnil |
| size | **0x30** |

Shell: `head@+4`, `size@+8`.

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_00407f90` @ `0x0040802e` |
| Succ prep | `FUN_0042ac40` |
| Min | `FUN_0044e180` |
| Max | `FUN_0042ac20` |
| Lrotate | `FUN_0044e010` |
| Rrotate | `FUN_0042a840` |
| Free | `~basic_string` + `operator_delete` |
| Insert peer | `StdMap_StringKey_InsertNodeAndRebalance` @ `0x00430b60` |

## Evidence summary

- Live decompile ≡ raw CF for throw/unlink/rebalance; epilogue sealed via `read_memory` (`ret 0xC`, size--).
- String `"invalid map/set<T> iterator"`; ThrowInfo `DAT_00acc34c`.
- isnil opcode family `+0x2D`; color `+0x2C`; string dtor @+0x0C.
- Do not merge with isnil29 erase (`0x004cb740`) or isnil31 head (`0x00409180`).

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdMap_StringKey_EraseAndRebalance_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004094c0.cpp`
- Raw: `docs/reconstruction/raw/aa_004094c0_FUN_004094c0.md`
- Annotated: `docs/reconstruction/raw/aa_004094c0_FUN_004094c0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004094c0_StdMap_StringKey_EraseAndRebalance_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004094c0_StdMap_StringKey_EraseAndRebalance_Inferred.md`
- Report: `docs/agents/task-dual-ab-00409180-004094c0-wq9jf-report.md`
