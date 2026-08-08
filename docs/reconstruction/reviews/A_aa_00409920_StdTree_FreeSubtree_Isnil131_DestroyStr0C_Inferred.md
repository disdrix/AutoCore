# Review A (reconstruction fidelity): `aa_00409920` StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409920` |
| **VA** | `0x00409920`–`0x00409960` inclusive (**65 B** / `0x41`) |
| **Canonical name** | `StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred` |
| **Ghidra name** | `FUN_00409920` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-I) |
| **Counterpart** | `reviews/B_aa_00409920_StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred.md` |
| **System** | STL tree free-subtree / isnil@+0x131 + string value destroy @+0x0c |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + `disassemble_function` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`_Tree` free-subtree** for **large nodes (isnil @ +0x131)**. For each node on the left spine of the given root: recursively free the **right** child, run value dtor `FUN_00409b80` (**`~basic_string` at node+0x0c**), `operator_delete` the node, advance to **left**. Stop at isnil sentinel. Used by erase-range full-clear `FUN_00407b70`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | collapsed right-only + false noreturn (2026-08-05 ≡ raw 2026-07-23) |
| Bytes authority | `read_memory` 65 B full body + `CC` pad |
| Value dtor | `FUN_00409b80` decompile + bytes (`RET 4`; string @ +0x0c) |
| Peer no-destroy | `StdTree_FreeSubtree_Isnil29_Inferred` `0x00406c00` (same left-walk shape, no dtor) |
| CF twin (destroy) | `StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred` `0x00409970` (OWN pair; isnil@+0x2d) |
| Range parent | `FUN_00407b70` full-clear @ `0x00407b8f` |

---

## 3. Signature (sealed)

```c
// ECX = tree_base (threaded; unused in body except recursive pass)
// stack = node*; RET 4; void
void __fastcall StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred(void* tree_base, void* node);
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
if node.isnil@+0x131: ret 4
loop:
  FreeSubtree(tree_base, node.right@+8)
  left = node.left@+0
  FUN_00409b80(node)      // stdcall RET4; ~basic_string @ +0x0c
  operator_delete(node)   // cdecl; ADD ESP,4
  node = left
  if !node.isnil: continue
ret 4
```

| Stage | Match | Conf |
|---|---|---|
| isnil@+0x131 gate | `80 BF 31 01 00 00 00` / `80 BE 31 01 00 00 00` | **High** |
| right recursive | `8B 46 08; PUSH; CALL self` | **High** |
| left walk | `8B 36` then `MOV EDI,ESI; JZ loop` | **High** |
| string value dtor | `PUSH EDI; CALL 00409b80` (no add esp — stdcall) | **High** |
| operator_delete cdecl | `PUSH EDI; CALL; ADD ESP,4` | **High** |
| RET 4 | `C2 04 00` | **High** |
| Decompiler left-walk | **Missing** — bytes override | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (65 B):

```
53 56 57 8B 7C 24 10 80 BF 31 01 00 00 00 8B D9 8B F7 75 27
8B 46 08 50 8B CB E8 E1 FF FF FF 8B 36 57 E8 39 02 00 00
57 E8 D5 FE 07 00 83 C4 04 80 BE 31 01 00 00 00 8B FE 74 D9
5F 5E 5B C2 04 00
```

Entry: `PUSH EBX/ESI/EDI; MOV EDI,[ESP+0x10]`. Epilogue: `POP EDI/ESI/EBX; RET 4`. Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_00407b70` (1 site) |
| Self | recursive right free |
| Closes | WQ-009 depth-7 residual free-subtree near string-value erase path |

---

## 7. Gaps (residual)

- Product demangle of large value (string @+0x0c + POD through isnil@+0x131).
- Undualed value dtor `FUN_00409b80` and erase-range parent `FUN_00407b70`.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals ABI/CF/isnil131/string-destroy. Product English open → **accept-with-gaps**.
