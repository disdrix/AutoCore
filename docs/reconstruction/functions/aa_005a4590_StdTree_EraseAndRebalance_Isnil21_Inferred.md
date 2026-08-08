# Function record: StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4590` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_005a4590` |
| **Address** | `0x005a4590` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x005a4590`–`0x005a4862` inclusive (**723 B** / `0x2D3`) |
| **System** | MSVC `std::_Tree` erase + RB rebalance (isnil@+0x21) |
| **Agent** | R12-032 OWN-ONLY dual 2026-08-05 |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007) |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` erase(const_iterator) for nodes with **color @ +0x20** and **isnil @ +0x21** (node size **0x24** in this neighborhood; value frees heap buffer @ **+0x14**). Throw on nil iterator; unlink + fix head extremities via min/max isnil21; rebalance if erased black using dualed isnil21 L/R rotates; free value buffer + node; size--; write `*outIt`.

## Signature

```c
void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    MapShell_Isnil21 *map,      // ECX
    MapNode_Isnil21 **outIt,    // successor out
    MapNode_Isnil21 *node);     // node to erase
// RET 8
```

## Layout

| Offset | Field |
|---|---|
| +0x00 | left |
| +0x04 | parent |
| +0x08 | right |
| +0x0C | key dword |
| +0x10 | val aux |
| +0x14 | heap begin (owned; `operator_delete` if non-null) |
| +0x18 | heap end |
| +0x1C | heap cap |
| +0x20 | color (0 red / 1 black) |
| +0x21 | isnil |
| size | **0x24** |

Shell: `head@+4`, `size@+8`.

## Call graph

| Role | Target |
|---|---|
| **Callers (1)** | `FUN_005a4c30` (erase-range shell) |
| Succ prep | `FUN_004e12c0` (iterator++ isnil21) |
| Min | `FUN_004cb2c0` (leftmost isnil21) |
| Max | `FUN_00421a60` (rightmost isnil21) |
| Lrotate | `FUN_0050e9f0` (`StdTree_Lrotate_Isnil21_Inferred`, R10-030) |
| Rrotate | `FUN_005a27f0` (`StdTree_Rrotate_Isnil21_Inferred`, R11-007 parent) |
| Free | `operator_delete` (value buffer + node) |

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x0050e9f0` | Lrotate isnil21 | dualed R10-030 |
| `0x005a27f0` | Rrotate isnil21 | dualed R11-007 (parent) |
| `0x00407200` | InsertAndRebalance isnil21 (Val16/0x28) | dualed WQ9I-B — related family, different node size |
| `0x005a4870` | buynode 0x24 isnil21 (sibling) | residual |
| `0x005a4950` | InsertAndRebalance-like isnil21 near unit | R12-033 residual |
| `0x004cb740` | EraseAndRebalance isnil29 | peer family (do not merge) |
| `0x00408ed0` | EraseAndRebalance isnil31 | peer family (do not merge) |

## Evidence summary

- Live decompile ≡ raw CF for throw/unlink/rebalance/value free; epilogue sealed via `read_memory` (`ret 8`, size--, `*outIt`).
- String `"invalid map/set<T> iterator"` @ `0x00a152f0`; ThrowInfo `DAT_00acc34c`.
- isnil opcode `80 78 21 00`; color tests at `+0x20`.
- Parent dual Rrotate isnil21 used in black-erase fixup.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005a4590.cpp`
- Raw: `docs/reconstruction/raw/aa_005a4590_FUN_005a4590.md`
- Annotated: `docs/reconstruction/raw/aa_005a4590_FUN_005a4590.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_005a4590_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005a4590_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-005a4590-r12-report.md`

## Confidence

| Claim | Level |
|---|---|
| Role always-erase + rebalance | **High** |
| ABI / RET 8 / size gate | **High** (byte-sealed) |
| Layout color@+0x20 isnil@+0x21 node 0x24 | **High** |
| Product English / demangle | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
