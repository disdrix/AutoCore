# Review A (reconstruction fidelity): `aa_0051be10` Map_FreeSubtree_Isnil1d

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051be10` |
| **VA** | `0x0051be10`–`0x0051be44` inclusive (**53 B** / `0x35`) |
| **Canonical name** | `Map_FreeSubtree_Isnil1d` |
| **Ghidra name** | `FUN_0051be10` |
| **Review date** | `2026-08-04` (WQ9F-E OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051be10_Map_FreeSubtree_Isnil1d.md` |
| **System** | STL / map-set free-subtree for isnil@+0x1d family |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body hex) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **map free-subtree** for the mid-size node family (**isnil @ +0x1d**). For each node on the left spine of the given root: recursively free the **right** child, `operator_delete` the node, advance to **left**. Stop at isnil sentinel. No value destroy.

Sole external caller: dualed `Map_EraseRange_Isnil1d_Inferred` (`0x0051d700`) full-clear path (`push head->parent`).

Byte-identical control shape to `Map_FreeSubtree_Isnil29` (`0x0051bbc0`) with only isnil offset / delete target differing.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | collapsed right-only + false noreturn (2026-08-04 ≡ raw 2026-07-23) |
| Bytes authority | `read_memory` 53 B full body + `CC` pad |
| Parent dual | `Map_EraseRange_Isnil1d_Inferred` `aa_0051d700` (WQ9E-I) — free callee open → this OWN |
| Twin CF isnil29 | `Map_FreeSubtree_Isnil29` @ `0x0051bbc0` |
| Peer free B | `Map_FreeSubtree_B` @ `0x0051be90` |
| Caller site | `0x0051d71c` CALL after push root |

---

## 3. Signature (sealed)

```c
// ECX = map/tree_base (threaded; unused in body except recursive pass)
// stack = node*; RET 4; void
void __fastcall Map_FreeSubtree_Isnil1d(void *tree_base, void *node);
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
if node.isnil@+0x1d: ret 4
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
| isnil@+0x1d gate | `80 7F 1D 00` / `80 7E 1D 00` | **High** |
| right @ +8 recursive | `8B 46 08; PUSH; CALL self` | **High** |
| left @ +0 walk | `8B 36` then `MOV EDI,ESI; JZ loop` | **High** |
| operator_delete cdecl | `PUSH EDI; CALL; ADD ESP,4` | **High** |
| RET 4 | `C2 04 00` | **High** |
| Decompiler left-walk | **Missing** — bytes override | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (53 B):

```
53 56 57 8B 7C 24 10 80 7F 1D 00 8B D9 8B F7 75 1E
8B 46 08 50 8B CB E8 E4 FF FF FF 8B 36 57 E8 EE D9 F6 FF
83 C4 04 80 7E 1D 00 8B FE 74 E2 5F 5E 5B C2 04 00
```

Entry: `PUSH EBX/ESI/EDI; MOV EDI,[ESP+0x10]`. Epilogue: `POP EDI/ESI/EBX; RET 4`. Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `Map_EraseRange_Isnil1d_Inferred` (`FUN_0051d700`) full-clear only |
| Self | right recurse |

---

## 7. Naming

| Name | Status |
|---|---|
| `Map_FreeSubtree_Isnil1d` | **Accept** — structural High; pairs dualed range erase isnil1d |
| Collapse into `Map_FreeSubtree_Isnil29` | **Reject** — different isnil offset / host |

---

## 8. Gaps

1. Product `map<K,V>` / value size for isnil1d family.  
2. tree_base unused (threading only).  
3. Full host inventory beyond EraseRange_Isnil1d.  
4. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
