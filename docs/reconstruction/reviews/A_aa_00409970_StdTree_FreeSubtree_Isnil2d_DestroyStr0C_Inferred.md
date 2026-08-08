# Review A (reconstruction fidelity): `aa_00409970` StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409970` |
| **VA** | `0x00409970`–`0x004099aa` inclusive (**59 B** / `0x3B`) |
| **Canonical name** | `StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred` |
| **Ghidra name** | `FUN_00409970` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-I) |
| **Counterpart** | `reviews/B_aa_00409970_StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred.md` |
| **System** | STL tree free-subtree / isnil@+0x2d + string value destroy @+0x0c |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + `disassemble_function` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`_Tree` free-subtree** for **compact nodes (isnil @ +0x2d)**. Same left-spine free pattern as isnil131 twin: recursive free **right**, **`FUN_00409b80`** (`~basic_string` @ +0x0c), `operator_delete`, advance **left**. Stop at isnil. Used by erase-range full-clear `FUN_00407f90`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | collapsed right-only + false noreturn (≡ scaffold) |
| Bytes authority | `read_memory` 59 B full body + `CC` pad |
| Value dtor | shared `FUN_00409b80` (same as isnil131 free) |
| CF twin (destroy) | `StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred` `0x00409920` |
| Peer no-destroy | `StdTree_FreeSubtree_Isnil29_Inferred` `0x00406c00` |
| Range parent | `FUN_00407f90` full-clear @ `0x00407fb0` |

---

## 3. Signature (sealed)

```c
// ECX = tree_base; stack = node*; RET 4; void
void __fastcall StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred(void* tree_base, void* node);
```

| Formal | Source | Conf |
|---|---|---|
| tree_base | ECX (`MOV EBX,ECX`; recursive pass) | **High** |
| node | stack `[ESP+0x10]` after 3 pushes | **High** |
| cleanup | `C2 04 00` | **High** |
| return | void | **High** |

---

## 4. Control flow (bytes authority)

```
if node.isnil@+0x2d: ret 4
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
| isnil@+0x2d gate | `80 7F 2D 00` / `80 7E 2D 00` | **High** |
| right recursive | `8B 46 08; PUSH; CALL self` | **High** |
| left walk | `8B 36` then `MOV EDI,ESI; JZ loop` | **High** |
| string value dtor | `PUSH EDI; CALL 00409b80` | **High** |
| operator_delete cdecl | `PUSH EDI; CALL; ADD ESP,4` | **High** |
| RET 4 | `C2 04 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (59 B):

```
53 56 57 8B 7C 24 10 80 7F 2D 00 8B D9 8B F7 75 24
8B 46 08 50 8B CB E8 E4 FF FF FF 8B 36 57 E8 EC 01 00 00
57 E8 88 FE 07 00 83 C4 04 80 7E 2D 00 8B FE 74 DC
5F 5E 5B C2 04 00
```

Entry/epilogue same pattern as isnil131 twin. Pad `CC` to node-ctor `0x004099b0`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_00407f90` (1 site) |
| Self | recursive right free |
| Closes | WQ-009 depth-7 residual free-subtree (compact string-value nodes) |

---

## 7. Gaps (residual)

- Product demangle of compact value (string @+0x0c through isnil@+0x2d; color likely +0x2c).
- Undualed `FUN_00409b80` / erase parent `FUN_00407f90` / partial erase `FUN_004094c0`.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals ABI/CF/isnil2d/string-destroy. Product English open → **accept-with-gaps**.
