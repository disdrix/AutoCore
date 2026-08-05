# Function record: StdTree_EraseAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e15a0` |
| **Canonical name** | `StdTree_EraseAndRebalance_Val12` (Inferred) |
| **Ghidra name** | `FUN_005e15a0` |
| **Address** | `0x005e15a0` |
| **Body range** | `0x005e15a0`–`0x005e1856` exclusive (**694** B / `0x2B6`) |
| **Ghidra listed end** | `0x005e1826` (**false** — `operator_delete` noreturn truncate) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map erase+rebalance (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + throw + epilogue size-- sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005e15a0_StdTree_EraseAndRebalance_Val12.md`, `reviews/B_aa_005e15a0_StdTree_EraseAndRebalance_Val12.md` (2026-07-29 W30-L) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005e15a0`
- Peers: `aa_004e4130` / `aa_00573250` / `aa_005399f0` / `aa_005ae990` (same Val12 erase family; distinct VAs)

## Purpose

MSVC-style `_Tree::erase(const_iterator)` for Val12 nodes: nil-iterator throw, unlink, RB rebalance if erased black, `operator_delete`, size--, write out iterator.

## Signature

```c
void __thiscall StdTree_EraseAndRebalance_Val12(
    MapShell_Val12* map,     // ECX; +0x04 head, +0x08 size
    MapNode_Val12** outIt,   // *outIt = successor
    MapNode_Val12* node);    // node to erase
// RET 8
```

## Algorithm

1. If `node->isnil` → throw `"invalid map/set<T> iterator"`.
2. `FUN_005ae0b0()` successor prep.
3. Splice replacement; fix root / leftmost (`FUN_005adfa0`) / rightmost (`FUN_00418bf0`).
4. If erased black → RB fixup with `FUN_00573170` / `FUN_00418c10`.
5. `operator_delete(node)`; if size>0 then `--size`; `*outIt = successor`; `ret 8`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005e15a0_FUN_005e15a0.md`
- Annotated: `docs/reconstruction/raw/aa_005e15a0_FUN_005e15a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val12_005e15a0.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005e15a0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005e15a0-005e18d0-w30l-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005ae0b0`, `FUN_005adfa0`, `FUN_00418bf0`, `FUN_00573170`, `FUN_00418c10`, `operator_delete`, STL throw chain |
| **Callers** | `FUN_005e1990` only (1 xref @ `0x005e1a2f`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 8` + thiscall ECX=map + size-- | **High** (bytes) |
| Val12 color@+0x18 / isnil@+0x19 | **High** |
| Throw string + ThrowInfo | **High** |
| Sole caller `FUN_005e1990` | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Rotates: `aa_00573170` StdTree_Lrotate_Val12, `aa_00418c10` StdTree_Rrotate_Val12 (W26-Q **accept**)
- Inc: `aa_005ae0b0` StdTree_Inc_Val12 (W28-N **accept**)
- Insert-or-find dual unit: `aa_005e18d0` StdMap_InsertOrFindByIntKey_Val12 (this dual)
