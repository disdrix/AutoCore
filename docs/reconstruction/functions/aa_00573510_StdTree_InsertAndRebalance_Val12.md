# Function record: StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573510` |
| **Canonical name** | `StdTree_InsertAndRebalance_Val12` (Inferred) |
| **Ghidra name** | `FUN_00573510` |
| **Address** | `0x00573510` |
| **Body range** | `0x00573510`–`0x005736FC` exclusive (**492** B / `0x1EC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map insert+rebalance (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + string + buynode sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00573510_StdTree_InsertAndRebalance_Val12.md`, `reviews/B_aa_00573510_StdTree_InsertAndRebalance_Val12.md` (2026-07-29 W27-S) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00573510`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00573510` (legacy xref scaffold — **narrow**)
- Twin algorithm: `Map_TreeInsertAndRebalance_Val12` (`aa_0051c1c0` @ `0x0051c1c0`, W25-G)

## Purpose

Allocate and link a Val12 red-black tree node (`StdTree_Buynode_Val12`), update size / leftmost / rightmost / root, rebalance while parent is red, paint root black, write `*outIt = newNode`. Throw `map/set<T> too long` if size exceeds `0x15555553`.

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

1. If `map->size > 0x15555553` → throw length_error `"map/set<T> too long"`.
2. `n = StdTree_Buynode_Val12(head, where, head, value, color=0)`.
3. `size++`; link n as first / left / right child; maybe update leftmost/rightmost.
4. RB fixup while parent color red: recolor uncle or rotate (`FUN_00573170` / `FUN_00418c10` / inlined).
5. Paint root black; `*outIt = n`; return.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00573510_FUN_00573510.md`
- Annotated: `docs/reconstruction/raw/aa_00573510_FUN_00573510.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00573510.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00573250-00573510-w27s-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005ae220` (StdTree_Buynode_Val12), `FUN_00573170`, `FUN_00418c10`, STL string/exception, `_CxxThrowException` |
| **Callers** | `FUN_00573810` only (2 call sites) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0x10` + thiscall ECX=map | **High** |
| Val12 / color@+0x18 / isnil@+0x19 | **High** |
| Buynode = `FUN_005ae220` color 0 | **High** |
| Throw string + max size constant | **High** |
| Sole live caller `FUN_00573810` | **High** (xrefs) |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Node buy: `aa_005ae220` `StdTree_Buynode_Val12` (W24-I **accept**)
- Twin insert copy: `aa_0051c1c0` `Map_TreeInsertAndRebalance_Val12` (W25-G)
- Parent (this image): `FUN_00573810` lower-bound insert
- Rotates: W26-Q `StdTree_Lrotate_Val12` / `StdTree_Rrotate_Val12`
