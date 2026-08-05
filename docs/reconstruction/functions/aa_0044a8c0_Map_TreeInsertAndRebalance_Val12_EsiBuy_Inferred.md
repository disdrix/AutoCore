# Function record: Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044a8c0` |
| **Canonical name** | `Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred` |
| **Ghidra name** | `FUN_0044a8c0` |
| **Address** | `0x0044a8c0` |
| **Body range** | `0x0044a8c0`–`0x0044aa46` exclusive (**390** B / `0x186`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map insert+rebalance (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_0044a8c0_Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.md`, `reviews/B_aa_0044a8c0_Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.md` |
| **Last reviewed** | `2026-07-29` W27-P OWN-ONLY |

## Alias

- `FUN_0044a8c0`
- Structural twin of `Map_TreeInsertAndRebalance_Val12` (`0x0051c1c0`) with **alternate buynode** (`FUN_0046c6c0` + ESI value)

## Purpose

Always-insert a Val12 red-black tree node (buy via `FUN_0046c6c0` with value in **ESI**), link under `where`, rebalance while parent is red, paint root black, write `*outIt = newNode`. Throw `map/set<T> too long` if size exceeds `0x15555553`.

Parent `FUN_0044a730` owns lower-bound walk over a **two-uint key** (`node+0xc` / `+0x10`) and only calls this on true insert.

## Signature

```c
// Retail: map pointer in EDI (not ECX); SEH frame; ret 0x10
void Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred(
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
4. RB fixup while parent color red: recolor uncle or rotate (`FUN_00573170` / `FUN_00418c10`, ECX=map).
5. Paint root black; `*outIt = n`; `ret 0x10`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0044a8c0_FUN_0044a8c0.md`
- Annotated: `docs/reconstruction/raw/aa_0044a8c0_FUN_0044a8c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0044a8c0.cpp`
- Report: `docs/agents/task-dual-ab-00561370-0044a8c0-w27p-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0046c6c0` (Val12 ESI buy); `StdTree_Lrotate_Val12` `0x00573170`; `StdTree_Rrotate_Val12` `0x00418c10`; STL string/`_CxxThrowException` |
| **Callers** | `FUN_0044a730` only (xrefs `0x0044a78e`, `0x0044a7db`) |

## Confidence

| Claim | Level |
|---|---|
| CF + live ≡ raw | **High** |
| `ret 0x10` + 4 stack args | **High** |
| Map in EDI (caller `mov edi,ebx`) | **High** |
| Val12 / color@+0x18 / isnil@+0x19 | **High** |
| Buynode = `FUN_0046c6c0` color 0 + ESI value | **High** |
| Throw string + max size `0x15555553` | **High** |
| Always-insert (no key compare here) | **High** |
| Product demangle / map type | **Inferred** |
| Runtime / differential | Open |

## Related

- Twin insert: `aa_0051c1c0` `Map_TreeInsertAndRebalance_Val12` (W25-G) — ECX thiscall + `FUN_005ae220`
- L/R rotate: `aa_00573170` / `aa_00418c10` (W26-Q **accept**)
- Val12 stack buy: `aa_005ae220` `StdTree_Buynode_Val12` (W24-I) — **not** this unit's buy
- Parent walk: `FUN_0044a730` (not OWN)
