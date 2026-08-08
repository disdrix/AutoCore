# Review A (reconstruction fidelity): `aa_004cb550` StdTree_FreeSubtree_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb550` |
| **VA** | `0x004cb550`–`0x004cb584` inclusive (**53 B** / `0x35`) |
| **Canonical name** | `StdTree_FreeSubtree_Isnil29_Inferred` |
| **Ghidra name** | `FUN_004cb550` |
| **Review date** | `2026-08-04` (WQ9G-A OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004cb550_StdTree_FreeSubtree_Isnil29_Inferred.md` |
| **System** | skills-abilities / std map-set (isnil@+0x29 free-subtree for StdTree_EraseRange) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style red-black **tree free-subtree** for the large-node family (**isnil @ +0x29**). For each node on the left spine of the given root: recursively free the **right** child, `operator_delete` the node, advance to **left**. Stop at isnil sentinel. No value destroy. Sole external caller: dualed `StdTree_EraseRange_Isnil29_Inferred` (`0x004cbaa0`) full-clear path (`push head->parent`).

Byte-identical control shape to dualed `Map_FreeSubtree_Isnil29` (`0x0051bbc0`) — **distinct VA / EraseRange pair**; do not merge.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9G-A append) | `docs/reconstruction/raw/aa_004cb550_FUN_004cb550.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb550_FUN_004cb550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil29_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004cb550.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cb550_StdTree_FreeSubtree_Isnil29_Inferred.md` |
| Parent dual | `StdTree_EraseRange_Isnil29_Inferred` / `aa_004cbaa0` (WQ9F-C) — free residual open → this OWN |
| Twin CF | `Map_FreeSubtree_Isnil29` @ `0x0051bbc0` (WQ9E-H) |
| Live | decompile incomplete; 53 B hex seals left-walk |

---

## 3. Signature (sealed)

```c
// ECX = tree_base (threaded; unused in body except recursive pass)
// stack = node*; RET 4; void
void __fastcall StdTree_FreeSubtree_Isnil29_Inferred(void *tree_base, void *node);
```

| Formal | Source | Conf |
|---|---|---|
| tree_base | ECX (`MOV EBX,ECX`; recursive `MOV ECX,EBX`) | **Confirmed** |
| node | stack `[esp+4]` after 3 pushes (`MOV EDI,[ESP+0x10]`) | **Confirmed** |
| cleanup | `C2 04 00` | **Confirmed** |
| return | void | **Confirmed** |

---

## 4. Control flow (bytes authority — decompiler incomplete)

```
if node.isnil@+0x29: ret 4
loop:
  FreeSubtree(tree_base, node.right@+8)
  left = node.left@+0
  operator_delete(node)   // cdecl; ADD ESP,4
  node = left
  if !node.isnil: continue
ret 4
```

| Stage | Match | Conf |
|---|---|---|
| isnil@+0x29 gate | `80 7F 29 00` / `80 7E 29 00` | **Confirmed** |
| right @ +8 recursive | `8B 46 08; PUSH; CALL self` | **Confirmed** |
| left @ +0 walk | `8B 36` then `MOV EDI,ESI; JZ loop` | **Confirmed** |
| operator_delete cdecl | `PUSH EDI; CALL; ADD ESP,4` | **Confirmed** |
| RET 4 | `C2 04 00` | **Confirmed** |
| Decompiler left-walk | **Missing** — bytes override | **Confirmed** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (53 B):

```
53 56 57 8B 7C 24 10 80 7F 29 00 8B D9 8B F7 75 1E
8B 46 08 50 8B CB E8 E4 FF FF FF 8B 36 57 E8 AE E2 FB FF
83 C4 04 80 7E 29 00 8B FE 74 E2 5F 5E 5B C2 04 00
```

Entry: `PUSH EBX/ESI/EDI; MOV EDI,[ESP+0x10]`. Epilogue: `POP EDI/ESI/EBX; RET 4`. Pad `CC`.

---

## 6. Callers / classification

| Item | Value | Conf |
|---|---|---|
| Classification | worker (shared STL free-subtree) | **High** |
| External callers | `StdTree_EraseRange_Isnil29_Inferred` (`0x004cbaa0`) full-clear only | **Confirmed** |
| Self | recursive right free | **Confirmed** |
| Callees | self, `operator_delete` | **Confirmed** |

---

## 7. Naming gate

| Evidence | Present? |
|---|---|
| Free-subtree CF (right recurse + left walk + isnil@+0x29) | **Yes** (bytes) |
| Sole EraseRange pair with dualed `StdTree_EraseRange_Isnil29` | **Yes** |
| Distinct from `Map_FreeSubtree_Isnil29` @ `0x0051bbc0` | **Yes** (VA + caller pair) |
| Product/PDB demangle / value_type English | **No** |

**Decision:** promote **`StdTree_FreeSubtree_Isnil29_Inferred`** — role High (CF + EraseRange caller); product English **Inferred**.

Reject: identity merge with `Map_FreeSubtree_Isnil29`; scaffold VOG_DEBUG_STOP path name; value-destroying free.

---

## 8. Gaps

1. Product/PDB demangle for map value_type of EraseRange callers.
2. Whether any value dtor is required before free for this instantiation (none in body).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
