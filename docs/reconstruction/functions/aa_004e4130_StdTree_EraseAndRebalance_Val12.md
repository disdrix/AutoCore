# Function record: StdTree_EraseAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4130` |
| **Canonical name** | `StdTree_EraseAndRebalance_Val12` (Inferred) |
| **Ghidra name** | `FUN_004e4130` |
| **Address** | `0x004e4130` |
| **Body range** | `0x004e4130`–`0x004e43e6` exclusive (**694** B / `0x2B6`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map erase+rebalance (Val12) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + throw + epilogue size-- sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004e4130_StdTree_EraseAndRebalance_Val12.md`, `reviews/B_aa_004e4130_StdTree_EraseAndRebalance_Val12.md` (2026-07-29 W27-Q) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004e4130`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004e4130` (legacy scaffold — **narrow/misleading**)
- Peer isnil@15 clone: `StdMap_EraseIterator_Inferred` @ `0x004baa30`

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

- Raw: `docs/reconstruction/raw/aa_004e4130_FUN_004e4130.md`
- Annotated: `docs/reconstruction/raw/aa_004e4130_FUN_004e4130.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004e4130.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004e4130-00539210-w27q-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005ae0b0`, `FUN_005adfa0`, `FUN_00418bf0`, `FUN_00573170`, `FUN_00418c10`, `operator_delete`, STL throw chain |
| **Callers** | `FUN_004e5120` only (1 xref) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 8` + thiscall ECX=map + size-- | **High** (bytes) |
| Val12 color@+0x18 / isnil@+0x19 | **High** |
| Throw string + ThrowInfo | **High** |
| Sole caller `FUN_004e5120` | **High** |
| Product English / demangle | **Inferred** |
| `FUN_005ae0b0` product name | **Tentative** |
| Runtime / differential | Open |

## Related

- Rotates: `aa_00573170` StdTree_Lrotate_Val12, `aa_00418c10` StdTree_Rrotate_Val12 (W26-Q **accept**)
- Insert peer: `aa_00539210` StdTree_InsertAndRebalance_Val12 (this dual)
- Isnil@15 erase: `aa_004baa30` StdMap_EraseIterator_Inferred
