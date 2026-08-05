# Function record: Map_TreeInsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051c1c0` |
| **Canonical name** | `Map_TreeInsertAndRebalance_Val12` (Inferred) |
| **Ghidra name** | `FUN_0051c1c0` |
| **Address** | `0x0051c1c0` |
| **Body range** | `0x0051c1c0`–`0x0051c3aa` exclusive (**490** B / `0x1EA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map insert+rebalance (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + string + buynode sealed; rotate product names open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0051c1c0_Map_TreeInsertAndRebalance_Val12.md`, `reviews/B_aa_0051c1c0_Map_TreeInsertAndRebalance_Val12.md` (2026-07-29 W25-G) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_0051c1c0`
- `Named_CalleeOf_Skill_CategoryCooldownMap_Insert_0051c1c0` (legacy xref scaffold — sole live caller is that map; structural role is shared MSVC `_Tree` insert pattern)
- Prior review shorthand: `Map_TreeInsertAndRebalance` (`a_0051d2f0.md`)

## Purpose

Allocate and link a Val12 red-black tree node (`StdTree_Buynode_Val12`), update size / leftmost / rightmost / root, rebalance while parent is red, paint root black, write `*outIt = newNode`. Throw `map/set<T> too long` if size exceeds `0x15555553`.

## Signature

```c
void __thiscall Map_TreeInsertAndRebalance_Val12(
    MapShell_Val12* map,       // ECX; +0x04 head, +0x08 size
    MapNode_Val12** outIt,     // *outIt = inserted node
    char addLeft,              // 1 left, 0 right
    MapNode_Val12* where,      // parent or head
    const Val12* value);       // 3 dwords
// RET 0x10; EAX left as outIt* after store
```

## Algorithm

1. If `map->size > 0x15555553` → throw length_error `"map/set<T> too long"`.
2. `n = StdTree_Buynode_Val12(head, where, head, value, color=0)`.
3. `size++`; link n as first / left / right child; maybe update leftmost/rightmost.
4. RB fixup while parent color red: recolor uncle or rotate (`FUN_00573170` / `FUN_00418c10` / inlined).
5. Paint root black; `*outIt = n`; return.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051c1c0_FUN_0051c1c0.md`
- Annotated: `docs/reconstruction/raw/aa_0051c1c0_FUN_0051c1c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0051c1c0.cpp`
- Legacy alias: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_CategoryCooldownMap_Insert_0051c1c0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0051c1c0-00829ac0-w25g-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005ae220` (StdTree_Buynode_Val12), `FUN_00573170`, `FUN_00418c10`, STL string/exception, `_CxxThrowException` |
| **Callers** | `Skill_CategoryCooldownMap_Insert` @ `0x0051d2f0` only (2 call sites) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0x10` + thiscall ECX=map | **High** |
| Val12 / color@+0x18 / isnil@+0x19 | **High** |
| Buynode = `FUN_005ae220` color 0 | **High** |
| Throw string + max size constant | **High** |
| Sole caller category-cooldown map | **High** (xrefs) |
| Product English / demangle | **Inferred** |
| Rotate helper product names | **Tentative** (out of ownership) |
| Runtime / differential | Open |

## Related

- Node buy: `aa_005ae220` `StdTree_Buynode_Val12` (W24-I **accept**)
- Parent: `aa_0051d2f0` `Skill_CategoryCooldownMap_Insert`
- Peer pattern: `aa_0054de50` `SkillElementTypeMap_TreeInsertAndRebalance` (Val8 / different max size)
