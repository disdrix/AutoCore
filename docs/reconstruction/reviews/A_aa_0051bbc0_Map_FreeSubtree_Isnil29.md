# Review A (reconstruction fidelity): `aa_0051bbc0` Map_FreeSubtree_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bbc0` |
| **VA** | `0x0051bbc0`–`0x0051bbf4` inclusive (**53 B** / `0x35`) |
| **Canonical name** | `Map_FreeSubtree_Isnil29` |
| **Ghidra name** | `FUN_0051bbc0` |
| **Review date** | `2026-08-04` (WQ9E-H OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051bbc0_Map_FreeSubtree_Isnil29.md` |
| **System** | STL / map-set (skill residual helper; free-subtree for isnil@+0x29 family) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body hex) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **map free-subtree** for the large-node family (**isnil @ +0x29**). For each node on the left spine of the given root: recursively free the **right** child, `operator_delete` the node, advance to **left**. Stop at isnil sentinel. No value destroy. Sole external caller: dualed `Map_EraseRange` (`0x0051c7c0`) full-clear path (`push head->parent`).

Byte-identical control shape to `MapFloatTfid_FreeSubtree_Isnil29_Inferred` (`0x0058da00`) and Val12 peer `StdTree_FreeSubtree_Val12` (`0x0040d630`, isnil@+0x19) — distinct VA / map instantiation.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | collapsed right-only + false noreturn (2026-08-04 ≡ raw 2026-07-23) |
| Bytes authority | `read_memory` 53 B full body + `CC` pad |
| Parent dual | `Map_EraseRange` `aa_0051c7c0` (WQ9D-H) — free callee open → this OWN |
| Twin CF | `MapFloatTfid_FreeSubtree_Isnil29_Inferred` @ `0x0058da00` |
| Peer family free | `FUN_0051be90` (Map_EraseRange_B discriminator — different VA) |
| Caller site | `0x0051c7dc` CALL after push root |

---

## 3. Signature (sealed)

```c
// ECX = map/tree_base (threaded; unused in body except recursive pass)
// stack = node*; RET 4; void
void __fastcall Map_FreeSubtree_Isnil29(void *tree_base, void *node);
```

| Formal | Source | Conf |
|---|---|---|
| tree_base | ECX (`MOV EBX,ECX`; recursive `MOV ECX,EBX`) | **High** |
| node | stack `[esp+4]` after 3 pushes (`MOV EDI,[ESP+0x10]`) | **High** |
| cleanup | `C2 04 00` | **High** |
| return | void | **High** |

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
| isnil@+0x29 gate | `80 7F 29 00` / `80 7E 29 00` | **High** |
| right @ +8 recursive | `8B 46 08; PUSH; CALL self` | **High** |
| left @ +0 walk | `8B 36` then `MOV EDI,ESI; JZ loop` | **High** |
| operator_delete cdecl | `PUSH EDI; CALL; ADD ESP,4` | **High** |
| RET 4 | `C2 04 00` | **High** |
| Decompiler left-walk | **Missing** — bytes override | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (53 B):

```
53 56 57 8B 7C 24 10 80 7F 29 00 8B D9 8B F7 75 1E
8B 46 08 50 8B CB E8 E4 FF FF FF 8B 36 57 E8 3E DC F6 FF
83 C4 04 80 7E 29 00 8B FE 74 E2 5F 5E 5B C2 04 00
```

Entry: `PUSH EBX/ESI/EDI; MOV EDI,[ESP+0x10]`. Epilogue: `POP EDI/ESI/EBX; RET 4`. Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `Map_EraseRange` (`FUN_0051c7c0`) full-clear only |
| Self | recursive right free |
| Callees | self, `operator_delete` (`0x00489822`) |

---

## 7. Naming gate

| Evidence | Present? |
|---|---|
| STL free-subtree structure | **Yes** (bytes) |
| isnil@+0x29 family with Map_EraseRange | **Yes** |
| Reject `Named_CalleeOf_*Aggro*` chain | **Yes** — generic map helper, multi-use via EraseRange |
| Product map`<K,V>` English | **No** |

**Decision:** promote **`Map_FreeSubtree_Isnil29`** (structural; pairs `Map_EraseRange` / `Map_EraseNode`). Discriminator vs Val12 / Isnil15 / `FUN_0051be90`.

---

## 8. Gaps

1. Exact `map<K,V>` / value size / dtor ownership (values destroyed elsewhere before free).  
2. tree_base unused in body — confirm no sibling map field read.  
3. Full inventory of all map hosts sharing this free (beyond aggro EraseRange).  
4. Runtime / bit-exact / differential open.

---

## 9. Verdict

ABI, isnil/left/right layout, recursive-right + left-walk free loop sealed by full-body hex. Residual product types → **accept-with-gaps**.
