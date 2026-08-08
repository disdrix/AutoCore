# Function record: StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405650` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` (**Inferred** structural + string plate + ABI) |
| **Ghidra name** | `FUN_00405650` |
| **Address** | `0x00405650` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00405650`–`0x004058e4` exclusive (**660 B** / `0x294`) |
| **System** | skills-abilities — MSVC `std::_Tree` erase + RB rebalance (isnil@+0x21) |
| **Agent** | R12-009 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007) |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` erase(const_iterator) for nodes with **color @ +0x20** and **isnil @ +0x21** (node size **0x28**). Throw on nil iterator; capture successor via iterator++ isnil21 (`FUN_004e12c0`); unlink + fix head extremities via min/max; rebalance if erased black using isnil21 L/R rotates (`0050e9f0`/`005a27f0`); free node (no value dtor); size--; write `*outIt`.

**Thiscall RET 8** distinguishes this unit from stack-only RET 0xC erase peers (isnil29 RetC `0x00402850`, isnil31 `0x00408ed0`).

## Signature

```c
void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    MapShell_Isnil21 *map,      // ECX
    MapNode_Isnil21 **outIt,    // stack0
    MapNode_Isnil21 *node);     // stack1
// RET 8
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C..+0x1F | value payload (trivial — no dtor call sealed; Val16) |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil |
| size | **0x28** |

Shell: `head@+4`, `size@+8`.

## Call graph

| Role | Target |
|---|---|
| **Callers (2)** | `FUN_00407140` @ `0x004071df`; `FUN_00932c80` @ `0x00933018` |
| Succ | `FUN_004e12c0` (iterator++ isnil21) |
| Min | `FUN_004cb2c0` |
| Max | `FUN_00421a60` |
| Lrotate | `FUN_0050e9f0` (isnil21 dualed) |
| Rrotate | `StdTree_Rrotate_Isnil21_Inferred` @ `0x005a27f0` (R11-007) |
| Throw ctor | `FUN_00401bc0` (`Std_OutOfRange_CtorFromString`) |
| Free | `operator_delete` only (no `~basic_string` / value dtor) |

## Evidence summary

- Live decompile ≡ raw CF for throw/unlink/rebalance; epilogue sealed via `read_memory` (`ret 8`, size--, `*outIt`).
- String `"invalid map/set<T> iterator"` @ `0x00a152f0`; ThrowInfo `DAT_00acc34c`.
- isnil opcode family `+0x21` (`80 78 21 00`); color `+0x20`.
- Call sites: `MOV ECX,<map>` then 2× PUSH → thiscall RET 8.
- Do **not** merge with isnil29 thiscall erase (`0x004cb740`), isnil29 RetC (`0x00402850`), isnil31 (`0x00408ed0`), or StringKey isnil2d (`0x004094c0`).

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00405650.cpp`
- Raw: `docs/reconstruction/raw/aa_00405650_FUN_00405650.md`
- Annotated: `docs/reconstruction/raw/aa_00405650_FUN_00405650.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00405650_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00405650_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-00405650-r12-report.md`
