# Function record: StdTree_EraseAndRebalance_Isnil29_RetC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402850` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil29_RetC_Inferred` (**Inferred** structural + string plate + ABI) |
| **Ghidra name** | `FUN_00402850` |
| **Address** | `0x00402850` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00402850`–`0x00402ae0` exclusive (**656 B** / `0x290`) |
| **System** | MSVC `std::_Tree` erase + RB rebalance (isnil@+0x29, stack RET 0xC) |
| **Agent** | MEGA-034 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` erase(const_iterator) for nodes with **color @ +0x28** and **isnil @ +0x29**. Throw on nil iterator; unlink + fix head extremities via min/max isnil29; rebalance if erased black using isnil29 L/R rotates (`00407a60`/`00403200`); free node (no value dtor); size--; write `*outIt`.

**RetC** distinguishes this stack-arg / `ret 0x0C` instantiation from thiscall isnil29 erase `0x004cb740` (`StdTree_EraseAndRebalance_Isnil29_Inferred`, RET 8).

## Signature

```c
void StdTree_EraseAndRebalance_Isnil29_RetC_Inferred(
    MapShell_Isnil29_RetC *map,      // stack0
    MapNode_Isnil29_RetC **outIt,    // stack1
    MapNode_Isnil29_RetC *node);     // stack2
// RET 0x0C
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C..+0x27 | value payload (trivial — no dtor call sealed) |
| +0x28 | color (0 red / 1 black) |
| +0x29 | isnil |

Shell: `head@+4`, `size@+8`.

## Call graph

| Role | Target |
|---|---|
| **Callers** | `FUN_004079a0` @ `0x00407a3e`; `FUN_00407bf0` @ `0x00407c8e`; `Client_Input_OnKeyDown_MatchAction` @ `0x00911260`; `FUN_00942e20` @ `0x00943060`; `FUN_00944d50` @ `0x00944e83`; bare xref `0x00957e8c` |
| Succ | `FUN_004040a0` (isnil29 iterator++) |
| Min | `FUN_004031e0` |
| Max | `FUN_004031c0` |
| Lrotate | `FUN_00407a60` |
| Rrotate | `FUN_00403200` |
| Throw ctor | `FUN_00401bc0` (`Std_OutOfRange_CtorFromString`) |
| Free | `operator_delete` only (no `~basic_string` / value dtor) |

## Evidence summary

- Live decompile ≡ raw CF for throw/unlink/rebalance; epilogue sealed via `read_memory` (`ret 0xC`, size--).
- String `"invalid map/set<T> iterator"` @ `0x00a152f0`; ThrowInfo `DAT_00acc34c`.
- isnil opcode family `+0x29`; color `+0x28`.
- Do **not** merge with thiscall isnil29 erase (`0x004cb740`), Val28 isnil29 (`0x00603830`), or isnil31 erase (`0x00408ed0`).
- Scaffold `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_00402850` **retired**.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00402850.cpp`
- Raw: `docs/reconstruction/raw/aa_00402850_FUN_00402850.md`
- Annotated: `docs/reconstruction/raw/aa_00402850_FUN_00402850.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00402850_StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00402850_StdTree_EraseAndRebalance_Isnil29_RetC_Inferred.md`
- Report: `docs/agents/task-dual-ab-00402850-mega-034-report.md`
