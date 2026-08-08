# Function record: StdTree_Min_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b5d0` |
| **Canonical name** | `StdTree_Min_Isnil29` |
| **Ghidra name** | `FUN_0051b5d0` |
| **Address** | `0x0051b5d0`–`0x0051b5ea` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Tree` / map (isnil @ +0x29); skill map erase consumer among others |
| **Name confidence** | **High** role (leftmost / `_Tree_min`); product English open |
| **Completion status** | **Dual residual sealed 2026-08-04 WQ9D-B** — accept |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Return the **leftmost non-nil** node in a red-black subtree (MSVC `_Tree_min`). Erase helpers (`Map_EraseNode` `0x0051cb40`, `FUN_00409220`, …) recompute `head->left` after unlink when the replacement subtree is non-nil.

## Signature

```c
StdTreeNode_Isnil29* StdTree_Min_Isnil29(StdTreeNode_Isnil29 *node);
// __cdecl; bare ret; EAX = leftmost non-nil
// Node: left@+0x00; isnil@+0x29
```

## Sealed facts

| Claim | Confidence |
|---|---|
| isnil @ **+0x29** | **High** (`cmp [ecx+0x29],0`) |
| Leftmost walk via `*node` | **High** |
| EAX return (not void) | **High** (bytes + callers) |
| Leaf | **High** |
| Map/set erase consumer | **High** |
| Product symbol | **Open** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051b5d0_FUN_0051b5d0.md`
- Annotated: `docs/reconstruction/raw/aa_0051b5d0_FUN_0051b5d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Min_Isnil29.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0051b5d0.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_0051b5d0_StdTree_Min_Isnil29.md`, `B_aa_0051b5d0_StdTree_Min_Isnil29.md`
- Scaffold record: `docs/reconstruction/functions/aa_0051b5d0_FUN_0051b5d0.md`

## Prior alias

`Named_CalleeOf_Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_0051b5d0` — superseded by role name.

## Twins / peers

- `StdTree_Min_Val12` `aa_005adfa0` (isnil @ +0x19)
- Rightmost peer used by same erase family: `FUN_00421b50` (not OWN this dual)
