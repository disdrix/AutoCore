# Function record: StdTree_EraseAndRebalance_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb740` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil29_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_004cb740` |
| **Address** | `0x004cb740` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004cb740`–`0x004cb9f5` exclusive (**693 B** / `0x2B5`) |
| **System** | MSVC `std::_Tree` erase + RB rebalance |
| **Agent** | WQ9E-E OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` erase(const_iterator) for nodes with **color @ +0x28** and **isnil @ +0x29** (node size **0x30**, value **6 dwords @ +0x10** via peer buynode). Throw on nil iterator; unlink + fix head extremities via min/max isnil29; rebalance if erased black using isnil29 L/R rotates; free node; size--; write `*outIt`.

## Signature

```c
void __thiscall StdTree_EraseAndRebalance_Isnil29_Inferred(
    MapShell_Isnil29 *map,      // ECX
    MapNode_Isnil29 **outIt,    // successor out
    MapNode_Isnil29 *node);     // node to erase
// RET 8
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x10 | value (6× int32) |
| +0x28 | color (0 red / 1 black) |
| +0x29 | isnil |
| size | **0x30** |

Shell: `head@+4`, `size@+8`.

## Call graph

| Role | Target |
|---|---|
| **Callers (3)** | `FUN_004c8610`, `FUN_004c8780`, `FUN_004cbaa0` |
| Succ prep | `FUN_004cb270` |
| Min | `FUN_0051b5d0` (`StdTree` min isnil29) |
| Max | `FUN_00421b50` (`StdTree_Max_Isnil29_Inferred`) |
| Lrotate | `FUN_004192a0` (`StdTree_Lrotate_Isnil29`) |
| Rrotate | `FUN_004192f0` (`StdTree_Rrotate_Isnil29_Inferred`) |
| Free | `operator_delete` |

## Evidence summary

- Live decompile ≡ raw CF; epilogue sealed via `read_memory` (`ret 8`, size--).
- String `"invalid map/set<T> iterator"`; ThrowInfo `DAT_00acc34c`.
- isnil opcode family `+0x29`; color `+0x28`.
- Prior VOG_DEBUG_STOP callee alias **narrow**.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil29_Inferred.cpp`
- Raw: `docs/reconstruction/raw/aa_004cb740_FUN_004cb740.md`
- Annotated: `docs/reconstruction/raw/aa_004cb740_FUN_004cb740.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004cb740_StdTree_EraseAndRebalance_Isnil29_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004cb740_StdTree_EraseAndRebalance_Isnil29_Inferred.md`
