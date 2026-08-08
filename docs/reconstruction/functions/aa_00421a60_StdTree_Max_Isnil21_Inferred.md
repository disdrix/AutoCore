# Function record: StdTree_Max_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421a60` |
| **Canonical name** | `StdTree_Max_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_00421a60` |
| **Address** | `0x00421a60` |
| **Body** | `0x00421a60`–`0x00421a7c` exclusive (**28** B / `0x1C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std `_Tree` max / rightmost (isnil@+0x21) |
| **Completion status** | **Sealed** — dual A/B accept-with-gaps (R13-001 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00421a60`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00421a60` (**narrow** — shared tree helper)
- Twin min: `FUN_004cb2c0` (leftmost / isnil@+0x21; residual R13-002)
- Peers: `StdTree_Max_Isnil29_Inferred` (`aa_00421b50`, isnil@+0x29); `StdTree_Max_Isnil31` (`aa_004043e0`); `StdTree_Max_Val12` (`aa_00418bf0`, isnil@+0x19)
- Parent erase: `StdTree_EraseAndRebalance_Isnil21_Inferred` (`aa_00405650`)

## Purpose

Return the rightmost non-nil node of the subtree rooted at `node` (MSVC `_Tree_max`). isnil@0x21 erase paths use this to recompute the tree head's right link when the erased node was rightmost.

## Signature (sealed)

```c
// __cdecl; stack = node*; returns node* in EAX; RET
int32_t *StdTree_Max_Isnil21_Inferred(int32_t *node);
```

## Layout

| Offset | Field |
|---|---|
| node+0 | left |
| node+4 | parent |
| node+8 | right |
| node+0x20 | color |
| node+0x21 | isnil |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00421a60_FUN_00421a60.md` (+ R13-001 re-verify)
- Annotated: `docs/reconstruction/raw/aa_00421a60_FUN_00421a60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Max_Isnil21_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00421a60.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00421a60_StdTree_Max_Isnil21_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00421a60_StdTree_Max_Isnil21_Inferred.md`
- Function FUN: `docs/reconstruction/functions/aa_00421a60_FUN_00421a60.md`
- Report: `docs/agents/task-dual-ab-00421a60-r13-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | *(none — leaf)* |
| **Callers (7)** | `FUN_00405650`, `FUN_004e3e70`, `FUN_00511c00`, `FUN_0059d300`, `FUN_005a2ea0`, `FUN_005a4590`, `FUN_005ae6d0` |
| **Xrefs** | 7 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| Body size + `C3` ret | **Confirmed** (`read_memory`) |
| Tree_max semantics (bytes) | **Confirmed** |
| Return `node*` in EAX | **Confirmed** (call-site stores; leave EAX) |
| isnil@+0x21 | **Confirmed** |
| Decompiler void CF | **Rejected** (defect) |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
