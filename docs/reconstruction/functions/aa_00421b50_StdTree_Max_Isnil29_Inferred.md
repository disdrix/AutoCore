# Function record: StdTree_Max_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421b50` |
| **Canonical name** | `StdTree_Max_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_00421b50` |
| **Address** | `0x00421b50` |
| **Body** | `0x00421b50`–`0x00421b6c` exclusive (**28** B / `0x1C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std `_Tree` max / rightmost (isnil@+0x29) |
| **Completion status** | **Sealed** — dual A/B accept-with-gaps (WQ9D-G 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00421b50`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_00421b50` (**narrow** — shared tree helper)
- Twin min: `FUN_0051b5d0` (leftmost / isnil@+0x29; OWN WQ9D-B)
- Peer: `StdTree_Max_Val12` (`aa_00418bf0`, isnil@+0x19)

## Purpose

Return the rightmost non-nil node of the subtree rooted at `node` (MSVC `_Tree_max`). isnil@0x29 erase paths use this to recompute the tree head's right link when the erased node was rightmost.

## Signature (sealed)

```c
// __cdecl; stack = node*; returns node* in EAX; RET
int32_t *StdTree_Max_Isnil29_Inferred(int32_t *node);
```

## Layout

| Offset | Field |
|---|---|
| node+0 | left |
| node+4 | parent |
| node+8 | right |
| node+0x28 | color |
| node+0x29 | isnil |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00421b50_FUN_00421b50.md` (+ WQ9D-G re-verify)
- Annotated: `docs/reconstruction/raw/aa_00421b50_FUN_00421b50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Max_Isnil29_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00421b50.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00421b50_StdTree_Max_Isnil29_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00421b50_StdTree_Max_Isnil29_Inferred.md`
- Function FUN: `docs/reconstruction/functions/aa_00421b50_FUN_00421b50.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | *(none — leaf)* |
| **Callers (5)** | `FUN_00409220`, `FUN_004cb740`, `FUN_0051cb40`, `FUN_0058dc30`, `FUN_00603830` |
| **Xrefs** | 5 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| Body size + `C3` ret | **Confirmed** (`read_memory`) |
| Tree_max semantics (bytes) | **Confirmed** |
| Return `node*` in EAX | **Confirmed** (call-site stores; leave EAX) |
| isnil@+0x29 | **Confirmed** |
| Decompiler void CF | **Rejected** (defect) |
| Name product English / demangle | **Inferred** |
| Runtime / differential | Open |
