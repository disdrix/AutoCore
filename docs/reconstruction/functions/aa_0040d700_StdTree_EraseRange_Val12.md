# Function record: StdTree_EraseRange_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d700` |
| **Canonical name** | `StdTree_EraseRange_Val12` (**Inferred** structural) |
| **Ghidra name** | `FUN_0040d700` |
| **Address** | `0x0040d700` |
| **Body** | `0x0040d700`–`0x0040d7b3` (**180 B** / `0xB4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `_Tree` range erase Val12 (isnil@`+0x19`) |
| **Completion status** | **Dual-reviewed** W32-C — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style red-black **range erase** `[first, last)` on a Val12 tree/map facade (`head@+4`, `size@+8`). Full-tree path frees via `StdTree_FreeSubtree_Val12` and resets the sentinel; partial path uses in-order successor + single-node erase `FUN_004188e0`.

## Signature

```c
// ECX = map/tree facade; stack out_it*, first*, last*; RET 0x0C; void
void __thiscall StdTree_EraseRange_Val12(
    StdTreeShell_Val12* map,
    StdTreeNode_Val12** outIt,
    StdTreeNode_Val12* first,
    StdTreeNode_Val12* last);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0040d6d0` @ `0x0040d6e2`; `FUN_0040d7c0` @ `0x0040d7f3` |
| Callees | `StdTree_FreeSubtree_Val12` / `FUN_0040d630`; `FUN_004188e0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d700_FUN_0040d700.md`
- Annotated: `docs/reconstruction/raw/aa_0040d700_FUN_0040d700.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Val12.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0040d700.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d700_StdTree_EraseRange_Val12.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d700_StdTree_EraseRange_Val12.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040d700_FUN_0040d700.md`
- Peer: `aa_004e5120` StdMap_EraseRange_Val12 (W28-P)
- Free dual: `aa_0040d630` StdTree_FreeSubtree_Val12 (W31-A)

## Confidence

| Claim | Level |
|---|---|
| Control flow full vs partial | **High** |
| ABI ECX + 3 stack + RET 0x0C | **High** |
| Val12 isnil@+0x19 successor | **High** |
| Full free via `0040d630` + head reset | **High** |
| Product map T demangle | **Low** |
| Value dtor on full free path | **Med** (none in body; clear owns vtbl) |
