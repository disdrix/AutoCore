# Review A (reconstruction fidelity): `aa_0040d630` StdTree_FreeSubtree_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d630` |
| **VA** | `0x0040d630`–`0x0040d664` (**53 B**) |
| **Canonical name** | `StdTree_FreeSubtree_Val12` |
| **Ghidra name** | `FUN_0040d630` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-A) |
| **Counterpart** | `reviews/B_aa_0040d630_StdTree_FreeSubtree_Val12.md` |
| **System** | MSVC `_Tree` free-subtree / Val12 |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Free a Val12 subtree: recursive free of each node's **right** child, `operator_delete` current, walk **left**. Stop at isnil@+0x19. No value destroy.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-A append) | `docs/reconstruction/raw/aa_0040d630_FUN_0040d630.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d630_FUN_0040d630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Val12.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0040d630.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040d630_StdTree_FreeSubtree_Val12.md` |
| Parent clear dual | `aa_0040d5b0` StdTree_Clear_PtrVal_Vtbl0C (W30-P **accept-with-gaps**) |
| Live | decompile collapsed; free path sealed from 53 B hex |

---

## 3. Signature (sealed)

```c
// ECX = tree_base; stack arg = node*; RET 4; void
void __fastcall StdTree_FreeSubtree_Val12(void* tree_base, StdTreeNode_Val12* node);
```

| Formal | Source | Conf |
|---|---|---|
| tree_base | ECX (`8B D9`; recursive `8B CB`) | **High** |
| node | stack `[esp+4]` (`8B 7C 24 10` after 3 pushes) | **High** |
| cleanup | `C2 04 00` | **High** |
| return | void | **High** |

---

## 4. Control flow (bytes authority)

```
if node.isnil: ret 4
loop:
  FreeSubtree(tree_base, node.right)
  left = node.left
  operator_delete(node)   // cdecl ADD ESP,4
  node = left
  if !node.isnil: continue
ret 4
```

| Stage | Match | Conf |
|---|---|---|
| isnil@+0x19 gate | `80 7F 19 00` / `80 7E 19 00` | **High** |
| right @ +8 recursive | `8B 46 08; PUSH; CALL self` | **High** |
| left @ +0 walk | `8B 36` then loop | **High** |
| operator_delete cdecl | `PUSH EDI; CALL; ADD ESP,4` | **High** |
| RET 4 | `C2 04 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (53 B) — see raw W31-A append.

Entry: `53 56 57 8B 7C 24 10` (push ebx/esi/edi; load arg).  
Epilogue: `5F 5E 5B C2 04 00`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0040d5b0` clear free path; `FUN_0040d700` erase free path; self |
| Callees | self, `operator_delete` |

---

## 7. Gaps

1. Product/MSVC demangle for node / map instantiation.  
2. tree_base is unused in body (threading only) — confirm no sibling read.  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI, Val12 isnil/left/right, recursive-right + left-walk free loop sealed by full-body hex. Residual product types → **accept-with-gaps**.
