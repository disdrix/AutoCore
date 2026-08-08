# Review A (reconstruction fidelity): `aa_00406c00` StdTree_FreeSubtree_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406c00` |
| **VA** | `0x00406c00`–`0x00406c34` inclusive (**53 B** / `0x35`) |
| **Canonical name** | `StdTree_FreeSubtree_Isnil29_Inferred` |
| **Ghidra name** | `FUN_00406c00` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9G-G) |
| **Counterpart** | `reviews/B_aa_00406c00_StdTree_FreeSubtree_Isnil29_Inferred.md` |
| **System** | STL tree free-subtree / isnil@+0x29 (insert/erase neighborhood of `00406c40`) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`_Tree` free-subtree** for large nodes (**isnil @ +0x29**). For each node on the left spine of the given root: recursively free the **right** child, `operator_delete` the node, advance to **left**. Stop at isnil sentinel. **No** value destroy. Used by range full-clear (`FUN_00407d70`) and Phy reinit map empties.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | collapsed right-only + false noreturn (2026-08-04 ≡ raw 2026-07-23) |
| Bytes authority | `read_memory` 53 B full body + `CC` pad |
| Twin CF | `Map_FreeSubtree_Isnil29` `0x0051bbc0` (WQ9E-H) — same body except delete rel32 |
| Peer shape | `StdTree_FreeSubtree_Val12` `0x0040d630` (isnil@+0x19) |
| Neighborhood | dualed insert `StdTree_InsertAndRebalance_Isnil29_Inferred` `0x00406c40` (WQ9E-G) |
| Range parent | `FUN_00407d70` full-clear @ `0x00407d8c` |

---

## 3. Signature (sealed)

```c
// ECX = tree_base (threaded; unused in body except recursive pass)
// stack = node*; RET 4; void
void __fastcall StdTree_FreeSubtree_Isnil29_Inferred(void* tree_base, void* node);
```

| Formal | Source | Conf |
|---|---|---|
| tree_base | ECX (`MOV EBX,ECX`; recursive `MOV ECX,EBX`) | **High** |
| node | stack `[ESP+0x10]` after 3 pushes | **High** |
| cleanup | `C2 04 00` | **High** |
| return | void | **High** |

---

## 4. Control flow (bytes authority)

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
| isnil@+0x29 gate | `80 7F 29 00` / `80 7E 29 00` | **High** |
| right recursive | `8B 46 08; PUSH; CALL self` | **High** |
| left walk | `8B 36` then `MOV EDI,ESI; JZ loop` | **High** |
| operator_delete cdecl | `PUSH EDI; CALL; ADD ESP,4` | **High** |
| RET 4 | `C2 04 00` | **High** |
| Decompiler left-walk | **Missing** — bytes override | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (53 B):

```
53 56 57 8B 7C 24 10 80 7F 29 00 8B D9 8B F7 75 1E
8B 46 08 50 8B CB E8 E4 FF FF FF 8B 36 57 E8 FE 2B 08 00
83 C4 04 80 7E 29 00 8B FE 74 E2 5F 5E 5B C2 04 00
```

Entry: `PUSH EBX/ESI/EDI; MOV EDI,[ESP+0x10]`. Epilogue: `POP EDI/ESI/EBX; RET 4`. Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_00407d70`, `FUN_0092f3b0`, `FUN_009463b0` |
| Self | recursive right free |
| Closes | WQ-009 depth-4 tree neighborhood residual near dualed insert `00406c40` |

---

## 7. Gaps

- Product / MSVC demangle for map value type vs twin `0051bbc0`.
- Range parent `FUN_00407d70` undualed.
- tree_base unused beyond threading.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity seals free-subtree CF/ABI/isnil29/callers. Product residual → **accept-with-gaps**.
