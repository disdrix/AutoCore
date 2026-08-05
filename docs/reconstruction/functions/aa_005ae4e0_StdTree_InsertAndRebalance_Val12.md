# Function record: StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae4e0` |
| **Canonical name** | `StdTree_InsertAndRebalance_Val12` (Inferred) |
| **Ghidra name** | `FUN_005ae4e0` |
| **Address** | `0x005ae4e0` |
| **Body range** | `0x005ae4e0`–`0x005ae6ca` exclusive (**490** B / `0x1EA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map insert+rebalance (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + string + buynode sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md`, `reviews/B_aa_005ae4e0_StdTree_InsertAndRebalance_Val12.md` (2026-07-29 W27-T) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005ae4e0`
- `Named_CalleeOf_Named_CalleeOf_Mission_MissionStopLimit_005ae4e0` (legacy xref scaffold — **narrow**)
- Role: MSVC `_Tree` always-insert + rebalance for **Val12** nodes (0x1c)
- Peer clone: `Map_TreeInsertAndRebalance_Val12` (`aa_0051c1c0`) — **do not merge**

## Purpose

Allocate and link a Val12 red-black tree node (`StdTree_Buynode_Val12`), update size / leftmost / rightmost / root, rebalance while parent is red, paint root black, write `*outIt = newNode`. Throw if size exceeds `0x15555553`.

## Signature

```c
void __thiscall StdTree_InsertAndRebalance_Val12(
    MapShell_Val12* map,       // ECX; +0x04 head, +0x08 size
    MapNode_Val12** outIt,     // *outIt = inserted node
    char addLeft,              // 1 left, 0 right
    MapNode_Val12* where,      // parent or head
    const Val12* value);       // 3 dwords
// RET 0x10
```

## Algorithm

1. If `map->size > 0x15555553` -> throw length_error `"map/set<T> too long"`.
2. `n = StdTree_Buynode_Val12(head, where, head, value, color=0)`.
3. `size++`; link n as first / left / right child; maybe update leftmost/rightmost.
4. RB fixup while parent color red: recolor uncle or rotate (`FUN_00573170` / `FUN_00418c10` / inlined L).
5. Paint root black; `*outIt = n`; return.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ae4e0_FUN_005ae4e0.md`
- Annotated: `docs/reconstruction/raw/aa_005ae4e0_FUN_005ae4e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005ae4e0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005ae4e0-005ae990-w27t-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005ae220` (StdTree_Buynode_Val12), `FUN_00573170`, `FUN_00418c10`, STL string/exception, `_CxxThrowException` |
| **Callers** | `FUN_005aed20` only (2 call sites: 005aed79, 005aedb0) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live equiv raw | **High** |
| `ret 0x10` + thiscall ECX=map | **High** |
| Val12 / color@+0x18 / isnil@+0x19 | **High** |
| Buynode = `FUN_005ae220` color 0 | **High** |
| Throw string + max size constant | **High** |
| Sole caller FUN_005aed20 | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Node buy: `aa_005ae220` `StdTree_Buynode_Val12` (W24-I **accept**)
- Rotates: `aa_00573170` Lrotate, `aa_00418c10` Rrotate (W26-Q)
- Peer insert clone: `aa_0051c1c0` `Map_TreeInsertAndRebalance_Val12` (W25-G)
- Sibling erase (this wave): `aa_005ae990` `StdTree_EraseNode_Val12`
