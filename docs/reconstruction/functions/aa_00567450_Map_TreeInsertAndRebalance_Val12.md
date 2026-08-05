# Function record: Map_TreeInsertAndRebalance_Val12 (`0x00567450`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00567450` |
| **Canonical name** | `Map_TreeInsertAndRebalance_Val12` (**Inferred**; clone of `aa_0051c1c0`) |
| **Ghidra name** | `FUN_00567450` |
| **Address** | `0x00567450` |
| **Body** | `0x00567450`–`0x0056763a` exclusive (**490** B / `0x1EA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std map/set red-black insert+rebalance (Val12) |
| **Completion status** | **Sealed** — dual A/B **accept-with-gaps** (W27-R 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00567450_Map_TreeInsertAndRebalance_Val12.md`, `reviews/B_aa_00567450_Map_TreeInsertAndRebalance_Val12.md` |
| **Last reviewed** | `2026-07-29` |

## Alias

- Ghidra: `FUN_00567450`
- Structural: `Map_TreeInsertAndRebalance_Val12`
- Twin VA: `aa_0051c1c0` @ `0x0051c1c0` (category-cooldown sole caller) — **do not merge**

## Purpose

Allocate and link a Val12 red-black tree node (`StdTree_Buynode_Val12`), update size / leftmost / rightmost / root, rebalance while parent is red, paint root black, write `*outIt = newNode`. Throw `map/set<T> too long` if size exceeds `0x15555553`.

## Signature (sealed)

```c
void __thiscall Map_TreeInsertAndRebalance_Val12(
    MapShell_Val12* map,       // ECX; +0x04 head, +0x08 size
    MapNode_Val12** outIt,     // *outIt = inserted node
    char addLeft,              // 1 left, 0 right
    MapNode_Val12* where,      // parent or head
    const Val12* value);       // 3 dwords
// RET 0x10
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00567450_FUN_00567450.md` (+ W27-R append)
- Annotated: `docs/reconstruction/raw/aa_00567450_FUN_00567450.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12_00567450.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00567450.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00567450_FUN_00567450.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005399f0-00567450-w27r-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | `FUN_005ae220` (StdTree_Buynode_Val12), `FUN_00573170`, `FUN_00418c10`, STL string/exception, `_CxxThrowException` |
| **Callers (1)** | `FUN_00567860` (int-key insert-or-find) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 0x10` + thiscall ECX=map | **High** |
| Val12 / color@+0x18 / isnil@+0x19 | **High** |
| Buynode = `FUN_005ae220` color 0 | **High** |
| Throw string + max size constant | **High** |
| Sole caller `FUN_00567860` | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |
