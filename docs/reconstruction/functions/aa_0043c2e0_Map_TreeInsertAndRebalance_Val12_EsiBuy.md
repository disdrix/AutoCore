# Function record: Map_TreeInsertAndRebalance_Val12_EsiBuy

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c2e0` |
| **Canonical name** | `Map_TreeInsertAndRebalance_Val12_EsiBuy` |
| **Ghidra name** | `FUN_0043c2e0` |
| **Address** | `0x0043c2e0` |
| **Body range** | `0x0043c2e0`–`0x0043c45f` exclusive (**383** B / `0x17F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map insert+rebalance (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_0043c2e0_Map_TreeInsertAndRebalance_Val12_EsiBuy.md`, `reviews/B_aa_0043c2e0_Map_TreeInsertAndRebalance_Val12_EsiBuy.md` |
| **Last reviewed** | `2026-07-29` W29-D OWN-ONLY |

## Alias

- `FUN_0043c2e0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_0043c2e0` (caller-family provenance only; not exclusive role)
- Structural twin of `aa_0044a8c0` `Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred` (same `FUN_0046c6c0` buy; alternate rotates)

## Purpose

Always-insert a Val12 red-black tree node (buy via `FUN_0046c6c0` with value in **ESI**), link under `where`, rebalance while parent is red, paint root black, write `*outIt = newNode`. Throw `map/set<T> too long` if size exceeds `0x15555553`.

## Signature

```c
// Retail: map pointer in EDI (not ECX); SEH frame; ret 0x10
void Map_TreeInsertAndRebalance_Val12_EsiBuy(
    /*EDI*/ MapShell_Val12* map,  // +0x04 head, +0x08 size
    MapNode_Val12** outIt,
    char addLeft,                 // 1 left, 0 right
    MapNode_Val12* where,
    const uint32_t value[3]);     // 12-byte Val12; loaded to ESI for buy
```

## Algorithm

1. If `map->size > 0x15555553` → throw length_error `"map/set<T> too long"` (`0x00a1530c` / `DAT_00acc388`).
2. `n = FUN_0046c6c0(head, where, head, color=0)` with **ESI = value*** (`operator_new(0x1c)`, copy 3 dwords, isnil=0).
3. `size++`; link first / left / right; update leftmost/rightmost on head sentinel.
4. RB fixup while parent color red: recolor uncle or rotate (`FUN_00446b10` L / `FUN_0040b910` R, ECX=map).
5. Paint root black; `*outIt = n`; `ret 0x10`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0043c2e0_FUN_0043c2e0.md`
- Annotated: `docs/reconstruction/raw/aa_0043c2e0_FUN_0043c2e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12_EsiBuy.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0043c2e0.cpp`
- Report: `docs/agents/task-dual-ab-007b65d0-0043c2e0-w29d-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0046c6c0` (Val12 ESI buy, W28-T); `FUN_00446b10` L; `FUN_0040b910` R; STL string / `FUN_00401a40` / `_CxxThrowException` |
| **Callers** | `FUN_0043be60`, `FUN_00445680`, `FUN_0046c450`, `FUN_0046c5c0`, `FUN_0046f6e0`, `FUN_0046f810` (23 xrefs) |

## Confidence

| Claim | Level |
|---|---|
| CF + live ≡ raw | **High** |
| `ret 0x10` + 4 stack args | **High** |
| Map in EDI | **High** |
| Val12 / color@+0x18 / isnil@+0x19 | **High** |
| Buynode = `FUN_0046c6c0` color 0 + ESI value | **High** |
| Throw string + max size `0x15555553` | **High** |
| Always-insert (no key compare here) | **High** |
| Rotate pair identity (L/R Val12 clones) | **High** structural / unowned duals |
| Product demangle / map type | **Inferred** |
| Runtime / differential | Open |

## Related

- Twin EsiBuy: `aa_0044a8c0` (W27-P) — rotates `00573170`/`00418c10`
- Buynode: `aa_0046c6c0` StdTree_Buynode_Val12_EsiValue (W28-T **accept**)
- Stack-buy twin insert: `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12 (W25-G)
