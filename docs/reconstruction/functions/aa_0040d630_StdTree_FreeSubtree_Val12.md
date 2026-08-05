# Function record: StdTree_FreeSubtree_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d630` |
| **Canonical name** | `StdTree_FreeSubtree_Val12` (**Inferred** structural) |
| **Ghidra name** | `FUN_0040d630` |
| **Address** | `0x0040d630` |
| **Body** | `0x0040d630`–`0x0040d664` (**53 B** / `0x35`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `_Tree` free-subtree (Val12 isnil@+0x19) |
| **Completion status** | **Dual-reviewed** W31-A — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Free a Val12 red-black **subtree**: for the given root and then each left child, recursively free the right child subtree, `operator_delete` the current node, advance left. Stop at isnil sentinel. Does **not** run value destroyers (`T*` @ +0x14).

## Signature

```c
// ECX = tree_base (host+4 from clear/erase); stack arg = node*; RET 4; void
void __fastcall StdTree_FreeSubtree_Val12(void* tree_base, StdTreeNode_Val12* node);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `StdTree_Clear_PtrVal_Vtbl0C` / `FUN_0040d5b0` @ `0x0040d5f6`; `FUN_0040d700` @ `0x0040d71c`; self @ `0x0040d647` |
| Callees | self, `operator_delete` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d630_FUN_0040d630.md`
- Annotated: `docs/reconstruction/raw/aa_0040d630_FUN_0040d630.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Val12.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0040d630.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d630_StdTree_FreeSubtree_Val12.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d630_StdTree_FreeSubtree_Val12.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040d630_FUN_0040d630.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes left-walk + recursive right) | **High** |
| ABI ECX + stack arg + RET 4 | **High** |
| Val12 isnil@+0x19 / left@0 / right@8 | **High** |
| No value-destroy in this unit | **High** |
| Product map / node type English | **Low** |
| tree_base use beyond threading | **Med** (unused in body) |
