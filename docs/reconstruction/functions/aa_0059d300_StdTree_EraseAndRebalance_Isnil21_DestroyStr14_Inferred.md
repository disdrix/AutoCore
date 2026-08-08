# Function record: StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d300` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred` (**Inferred** structural + string plate + DestroyStr14) |
| **Ghidra name** | `FUN_0059d300` |
| **Address** | `0x0059d300` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x0059d300`–`0x0059d5d2` inclusive (**723 B** / `0x2D3`) |
| **System** | skills-abilities — MSVC `std::_Tree` erase + RB rebalance (isnil@+0x21) + DestroyStr14 |
| **Agent** | R12-029 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007) |
| **Dual start** | 2646 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_0059d300`
- Scaffold: partial `aa_0059d300_FUN_0059d300` (2026-07-23)
- Structural: `StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred` (product demangle open)

## Purpose

MSVC-style `_Tree` erase(const_iterator) for nodes with **color @ +0x20** and **isnil @ +0x21** (node size **0x28**). Throw on nil iterator; capture successor via iterator++ isnil21 (`FUN_004e12c0`); unlink + fix head extremities via min/max; rebalance if erased black using isnil21 L/R rotates (`0050e9f0`/`005a27f0`); **DestroyStr14** (free heap at +0x14, zero three dwords); free node; size--; write `*outIt`.

**thiscall RET 8** + **DestroyStr14** distinguish this unit from:
- no-dtor isnil21 erase clones (`0x00405650`, `0x004e3e70`)
- stack-only RET 0xC erase peers (isnil29 RetC `0x00402850`, isnil31 `0x00408ed0`)

## Signature

```c
void __thiscall StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred(
    MapShell_Isnil21 *map,           // ECX
    MapNode_Isnil21_Str14 **outIt,   // stack0
    MapNode_Isnil21_Str14 *node);    // stack1
// RET 8
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C..+0x13 | value head (not freed here) |
| +0x14 | str_ptr (free if non-null) |
| +0x18 | str_size |
| +0x1C | str_res |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil |
| size | **0x28** |

Shell: `head@+4`, `size@+8`.

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_0059d620` @ `0x0059d6bf` |
| Succ | `FUN_004e12c0` (iterator++ isnil21) |
| Min | `FUN_004cb2c0` |
| Max | `FUN_00421a60` |
| Lrotate | `FUN_0050e9f0` (isnil21 dualed) |
| Rrotate | `StdTree_Rrotate_Isnil21_Inferred` @ `0x005a27f0` (R11-007) |
| Free | `operator_delete` on `+0x14` (optional) then node |

## Evidence summary

- Live decompile ≡ raw CF for throw/unlink/rebalance; epilogue sealed via `read_memory` (`ret 8`, size--, `*outIt`, DestroyStr14).
- String `"invalid map/set<T> iterator"` @ `0x00a152f0`; ThrowInfo `DAT_00acc34c`.
- isnil opcode family `+0x21` (`80 78 21 00`); color `+0x20`.
- Call site: `MOV ECX,EDI` then 2× PUSH → thiscall RET 8.
- Do **not** merge with no-dtor isnil21 erase clones, isnil29/31 erase, or StringKey isnil2d.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0059d300.cpp`
- Raw: `docs/reconstruction/raw/aa_0059d300_FUN_0059d300.md`
- Annotated: `docs/reconstruction/raw/aa_0059d300_FUN_0059d300.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_0059d300_StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0059d300_StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.md`
- Report: `docs/agents/task-dual-ab-0059d300-r12-report.md`
- Scaffold function: `docs/reconstruction/functions/aa_0059d300_FUN_0059d300.md`

## Confidence

| Claim | Level |
|---|---|
| Role single-node erase + rebalance | **High** |
| ABI / RET 8 / size-- / outIt | **Confirmed** (bytes) |
| Layout color@+0x20 isnil@+0x21 | **Confirmed** |
| DestroyStr14 | **Confirmed** (bytes) |
| 1 EraseRange caller | **Confirmed** |
| Product English | Open → `_Inferred` |
| Runtime | Open |
