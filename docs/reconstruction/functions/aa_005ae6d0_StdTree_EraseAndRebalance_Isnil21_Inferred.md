# Function record: StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae6d0` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Ghidra name** | `FUN_005ae6d0` |
| **Address** | `0x005ae6d0` |
| **Body range** | `0x005ae6d0`–`0x005ae986` exclusive (**694** B / `0x2B6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities (partition); shared STL `_Tree` erase isnil21 |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (R12-035 OWN-ONLY) |
| **Bit-for-bit / runtime / diff** | Open (not Runtime Confirmed) |
| **Dual A/B** | `reviews/A_aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md`, `reviews/B_aa_005ae6d0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **Last reviewed** | `2026-08-05` |
| **Partition** | `WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-035** |
| **Parent dual** | `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred |
| **Dual start** | 2646 |
| **Terminal** | **false** |

## Alias

- `FUN_005ae6d0`
- Prior scaffold: Partial scaffold only (2026-07-23)

## Purpose

Single-node MSVC `std::_Tree` erase with red-black rebalance for the **isnil@+0x21 / color@+0x20 / node 0x28 / Val16** family. Shared container helper (not skill-product-specific); sole direct caller is range erase `FUN_005af2e0`.

## Signature

```c
void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(
    MapShell_Isnil21* map,       // ECX
    MapNode_Isnil21** outIt,     // stack
    MapNode_Isnil21* node);      // stack
// RET 8  (C2 08 00 @ 0x005ae983)
```

## Algorithm

1. If `node->isnil` (+0x21) → throw `"invalid map/set<T> iterator"`.
2. Successor via `FUN_004e12c0`.
3. Unlink + fix root / leftmost (`FUN_004cb2c0`) / rightmost (`FUN_00421a60`); two-child splice in bytes (decomp gap).
4. If erased black: RB fixup with Lrotate `FUN_0050e9f0` / Rrotate `FUN_005a27f0`.
5. `operator_delete(node)`.
6. If `size > 0` then `size--`; `*outIt = successor`; `ret 8`.

## Layout

| Offset | Field |
|---|---|
| node+0x00 | left |
| node+0x04 | parent |
| node+0x08 | right |
| node+0x0C | value (Val16) |
| node+0x20 | color (0=red, 1=black) |
| node+0x21 | isnil |
| node size | **0x28** |
| map+0x04 | head (sentinel) |
| map+0x08 | size |
| head+0x00 | leftmost |
| head+0x04 | root |
| head+0x08 | rightmost |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ae6d0_FUN_005ae6d0.md`
- Annotated: `docs/reconstruction/raw/aa_005ae6d0_FUN_005ae6d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005ae6d0.cpp`
- Ghidra-named twin record: `docs/reconstruction/functions/aa_005ae6d0_FUN_005ae6d0.md`
- Report: `docs/agents/task-dual-ab-005ae6d0-r12-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `004e12c0` succ; `004cb2c0` min; `00421a60` max; `0050e9f0` Lrot; `005a27f0` Rrot; delete; throw |
| **Callers** | `FUN_005af2e0` only |

## Confidence

| Claim | Level |
|---|---|
| CF + ABI + RET 8 | **High** |
| isnil21 family layout | **High** |
| size-- epilogue | **High** (bytes) |
| Name `_Inferred` | **Inferred** (structural; no PDB) |
| Product map type English | Open |
| Runtime Confirmed | **Never claimed** (Terminal false) |

## Related

- Parent: `aa_005a27f0` Rrotate isnil21
- Insert: `aa_00407200` InsertAndRebalance isnil21
- Buynode: `aa_00408990` Val16 isnil21
- Lrotate: `aa_0050e9f0`
- Peer erase isnil29: `aa_004cb740`
