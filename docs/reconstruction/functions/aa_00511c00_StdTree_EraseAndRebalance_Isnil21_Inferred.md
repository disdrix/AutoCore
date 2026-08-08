# Function record: StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00511c00` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` (**Inferred** structural + string plate + ABI) |
| **Ghidra name** | `FUN_00511c00` |
| **Address** | `0x00511c00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00511c00`–`0x00511ed3` exclusive (**723 B** / `0x2D3`) |
| **System** | MSVC `std::_Tree` erase + RB rebalance (isnil@+0x21, thiscall RET 8) |
| **Agent** | R12-015 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x005a27f0` `StdTree_Rrotate_Isnil21_Inferred` (R11-007) |
| **Partition** | `WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-015** (skills-abilities) |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` erase(const_iterator) for nodes with **color @ +0x20** and **isnil @ +0x21** (node family **0x28**). Throw on nil iterator; unlink + fix head extremities via min/max isnil21; rebalance if erased black using isnil21 L/R rotates (`0050e9f0`/`005a27f0`); free optional value heap @ **+0x14**; free node; size--; write `*outIt`.

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
| +0x0C.. | value payload (product open) |
| +0x14 | optional heap ptr (freed if non-null) |
| +0x18 | related size/count (zeroed) |
| +0x1c | related capacity (zeroed) |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil |
| size | **0x28** (family) |

Shell: `head@+4`, `size@+8`.

## Call graph

| Role | Target |
|---|---|
| **Callers** | **none** recovered in Ghidra (0 xrefs) |
| Succ | `FUN_004e12c0` (iterator++ isnil21) |
| Min | `FUN_004cb2c0` |
| Max | `FUN_00421a60` |
| Lrotate | `FUN_0050e9f0` (`StdTree_Lrotate_Isnil21_Inferred`, R10-030) |
| Rrotate | `FUN_005a27f0` (`StdTree_Rrotate_Isnil21_Inferred`, R11-007) |
| Free | `operator_delete` (value heap + node) |
| Throw | `"invalid map/set<T> iterator"` / `DAT_00acc34c` |

## Evidence summary

- Live decompile ≡ raw CF for throw/unlink/rebalance; epilogue sealed via `read_memory` (`ret 8`, size--, `*outIt`).
- String `"invalid map/set<T> iterator"` @ `0x00a152f0`; ThrowInfo `DAT_00acc34c`.
- isnil opcode family `+0x21`; color `+0x20`.
- Two-child splice plate asm-live @ `0x00511d1d` (decomp "unreachable" wrong).
- Do **not** merge with isnil29/31 erases or stack-RET0xC family.
- Not skill-specific product logic — shared STL helper; partition tag is residual-score only.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00511c00.cpp`
- Raw: `docs/reconstruction/raw/aa_00511c00_FUN_00511c00.md`
- Annotated: `docs/reconstruction/raw/aa_00511c00_FUN_00511c00.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00511c00_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00511c00_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-00511c00-r12-report.md`
