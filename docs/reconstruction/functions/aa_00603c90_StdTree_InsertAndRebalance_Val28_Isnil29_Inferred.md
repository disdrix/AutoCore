# Function record: StdTree_InsertAndRebalance_Val28_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00603c90` |
| **Canonical name** | `StdTree_InsertAndRebalance_Val28_Isnil29_Inferred` |
| **Ghidra name** | `FUN_00603c90` |
| **Address** | `0x00603c90` |
| **Body range** | `0x00603c90`–`0x00603e7a` exclusive (**490** B / `0x1EA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map always-insert+rebalance (Val28 / isnil@+0x29) |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + max-size + ret 0x10 sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00603c90_StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.md`, `reviews/B_aa_00603c90_StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.md` (2026-08-04 WQ9E-F) |
| **Last reviewed** | `2026-08-04` |
| **Terminal** | **false** |

## Alias

- `FUN_00603c90`
- Scaffold: `aa_00603c90_FUN_00603c90`

## Purpose

MSVC-style always-insert helper: buynode Val28 red node, link under `where`, size++, RB fixup while parent red, root black, `*outIt = new`.

## Signature

```c
void __thiscall StdTree_InsertAndRebalance_Val28_Isnil29_Inferred(
    MapShell* map,     // ECX; +0x04 head, +0x08 size
    Node** outIt,
    char addLeft,      // nonzero → left child
    Node* where,
    Val28* value);
// RET 0x10
```

## Algorithm

1. If `size > 0x9249247` → throw `"map/set<T> too long"` (`DAT_00acc388`).
2. `FUN_00603b10(head, where, head, value, color=0)` — `operator_new(0x2C)` + ctor.
3. `size++`.
4. Link empty tree / left / right; update head leftmost/rightmost.
5. While parent red: uncle red → recolor; else rotate (`FUN_004192a0` / `FUN_004192f0`).
6. Root color = black; `*outIt = n`; return.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00603c90_FUN_00603c90.md`
- Annotated: `docs/reconstruction/raw/aa_00603c90_FUN_00603c90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00603c90.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00603830-00603c90-wq9ef-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00603b10` buynode, `FUN_004192a0` Lrotate, `FUN_004192f0` Rrotate, STL throw chain |
| **Callers** | `FUN_00603f00` only (1 xref @ `0x00603f4a`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0x10` + thiscall + size++ | **High** (bytes) |
| Max size `0x9249247` | **High** |
| isnil@+0x29 / color@+0x28 / node 0x2C | **High** |
| Sole caller | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Erase twin: `aa_00603830` StdTree_EraseAndRebalance_Val28_Isnil29_Inferred (WQ9E-F)
- Rotates: `aa_004192a0` / `aa_004192f0` Isnil29
- Peer Val12 insert: `Map_TreeInsertAndRebalance_Val12*` family
- Peer isnil15 insert: `aa_00438140` StdTree_InsertAndRebalance_Val8_Isnil15_Inferred
