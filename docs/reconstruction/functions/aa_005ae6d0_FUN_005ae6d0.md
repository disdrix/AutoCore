# Function record: FUN_005ae6d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae6d0` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` (see named record) |
| **Ghidra name** | `FUN_005ae6d0` |
| **Address** | `0x005ae6d0` |
| **Body range** | `0x005ae6d0`–`0x005ae986` exclusive (**694** B / `0x2B6`); `CC` pad to `0x005ae98f` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities partition (shared STL `_Tree` erase; isnil@+0x21) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** R12-035; CF + ABI + throw + size-- sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md`, `reviews/B_aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **Last reviewed** | `2026-08-05` |

## Alias

- `FUN_005ae6d0`
- Role: MSVC `_Tree::erase` single iterator for **isnil@+0x21** / **color@+0x20** / **node 0x28** / **Val16**

## Purpose

Erase one non-nil isnil21 tree node: compute successor, unlink + fix root/begin/end, RB rebalance if black (L/R rotate isnil21), `operator_delete`, decrement size if >0, write `*outIt = successor`. Throw `"invalid map/set<T> iterator"` on nil.

## Signature

```c
void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    MapShell_Isnil21* map,       // ECX; +0x04 head, +0x08 size
    MapNode_Isnil21** outIt,     // *outIt = successor
    MapNode_Isnil21* node);      // node to erase
// RET 8
```

## Artifacts

- Raw (+ R12-035 re-verify): `docs/reconstruction/raw/aa_005ae6d0_FUN_005ae6d0.md`
- Annotated: `docs/reconstruction/raw/aa_005ae6d0_FUN_005ae6d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_005ae6d0.cpp`
- Named function record: `docs/reconstruction/functions/aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md`
- Report: `docs/agents/task-dual-ab-005ae6d0-r12-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_004e12c0`, `FUN_004cb2c0`, `FUN_00421a60`, `FUN_0050e9f0`, `FUN_005a27f0`, `operator_delete`, exception path |
| **Callers** | `FUN_005af2e0` only (range erase @ `0x005af37f`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow unlink + rebalance | **High** |
| `ret 8` + thiscall ECX=map | **High** (bytes + call site `MOV ECX,EDI`) |
| isnil@+0x21 / color@+0x20 | **High** |
| size-- after delete | **High** (bytes; decomp miss) |
| Sole caller FUN_005af2e0 | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Parent dual: `aa_005a27f0` `StdTree_Rrotate_Isnil21_Inferred` (R11-007)
- Lrotate twin: `aa_0050e9f0` `StdTree_Lrotate_Isnil21_Inferred` (R10-030)
- Insert twin: `aa_00407200` `StdTree_InsertAndRebalance_Isnil21_Inferred`
- Buynode: `aa_00408990` `StdTree_Buynode_Val16_Isnil21_Inferred`
- Adjacent Val12 erase: `aa_005ae990` `StdTree_EraseNode_Val12` (different family)
