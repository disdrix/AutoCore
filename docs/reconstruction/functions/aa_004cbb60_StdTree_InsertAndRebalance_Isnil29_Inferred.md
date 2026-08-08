# Function record: StdTree_InsertAndRebalance_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbb60` |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil29_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_004cbb60` |
| **Address** | `0x004cbb60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004cbb60`–`0x004cbd4b` exclusive (**491 B** / `0x1EB`) |
| **System** | MSVC `std::_Tree` insert + RB rebalance |
| **Agent** | WQ9E-E OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

MSVC-style `_Tree` always-insert helper for nodes with **color @ +0x28** and **isnil @ +0x29**. Parent owns lower-bound / uniqueness walk. This unit: length guard, buynode, link left/right, RB fixup, write `*outIt`.

## Signature

```c
void __thiscall StdTree_InsertAndRebalance_Isnil29_Inferred(
    MapShell_Isnil29 *map,       // ECX
    MapNode_Isnil29 **outIt,     // *outIt = new node
    char addLeft,                // 1 left of where; 0 right
    MapNode_Isnil29 *where,      // parent or head
    const Val24_Isnil29 *value); // 6 dwords → +0x10
// RET 0x10
```

## Layout / constants

| Item | Value |
|---|---|
| Node size | `0x30` (`FUN_005a2de0` / `operator_new`) |
| Value | 6× int32 @ +0x10 |
| Color / isnil | +0x28 / +0x29 |
| Max size before insert | `0xAAAAAA8` (throw if greater) |
| Throw string | `"map/set<T> too long"` / `DAT_00acc388` |

## Call graph

| Role | Target |
|---|---|
| **Callers** | `FUN_004cbe20`, `FUN_004cbee0`, `FUN_004cc220` (11 sites) |
| Buynode | `FUN_005a2de0` |
| Lrotate | `FUN_004192a0` |
| Rrotate | `FUN_004192f0` |

## Evidence summary

- Live decompile ≡ raw CF; RET 0x10 sealed via `read_memory`.
- Buynode seals node 0x30 + isnil@+0x29 + 6-dword payload.
- Prior GetTargetFromAggro callee alias **narrow**.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil29_Inferred.cpp`
- Raw: `docs/reconstruction/raw/aa_004cbb60_FUN_004cbb60.md`
- Annotated: `docs/reconstruction/raw/aa_004cbb60_FUN_004cbb60.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md`
