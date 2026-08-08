# Review A (reconstruction fidelity): `aa_00440c90` StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00440c90` |
| **VA** | `0x00440c90`–`0x00440cca` inclusive (**59 B** / `0x3B`) |
| **Canonical name** | `StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred` |
| **Ghidra name** | `FUN_00440c90` |
| **Review date** | `2026-08-05` (MEGA-131 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00440c90_StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred.md` |
| **System** | `skills-abilities` — STL free-subtree for gfxUIWindow tree shell@+0x10 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body hex) + xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **tree free-subtree** for the mid-size node family (**isnil @ +0x1d**) with **per-node value destroy**. For each node on the left spine of the given root: recursively free the **right** child, run `FUN_00442730` (EAX=node) to destroy the **embedded nested tree** at **node+0x10**, `operator_delete` the node, advance to **left**. Stop at isnil sentinel.

Primary host pattern: dualed `gfxUIWindow_CompleteDtor` (`0x00759de0`) clears shell at **this+0x10** (`LEA EDI,[ESI+0x10]`; push `head->parent`; CALL this; reset head links; size=0). Same clear-shell sequence in `FUN_00758c80` and erase-range full-clear `FUN_00441720`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | collapsed right-only + false noreturn (≡ raw 2026-07-23) |
| Bytes authority | `read_memory` 59 B full body + `CC` pad; `disassemble_function` |
| Parent dual | `gfxUIWindow_CompleteDtor` `aa_00759de0` (WQ9L-F) — shell@+0x10 free open → this OWN |
| Peer no-dtor free | dualed `Map_FreeSubtree_Isnil1d` @ `0x0051be10` |
| Peer shell+04 free | `FUN_00440ab0` isnil@+0x3d + `FUN_00442720` |
| Value dtor | `FUN_00442730` disasm: `ADD EDI,0x10` + erase `FUN_004413c0` + delete head |
| Xrefs | 4 UNCONDITIONAL_CALL |

---

## 3. Signature (sealed)

```c
// ECX = tree_shell (threaded; unused in body except recursive pass)
// stack = node*; RET 4; void
void __fastcall StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred(
    void *tree_shell, void *node);
```

| Formal | Source | Conf |
|---|---|---|
| tree_shell | ECX (`MOV EBX,ECX`; recursive `MOV ECX,EBX`) | **High** |
| node | stack `[ESP+0x10]` after 3 pushes (`MOV EDI,[ESP+0x10]`) | **High** |
| cleanup | `C2 04 00` | **High** |
| return | void | **High** |

---

## 4. Control flow (bytes authority — decompiler incomplete)

```
if node.isnil@+0x1d: ret 4
loop:
  FreeSubtree(tree_shell, node.right@+8)
  left = node.left@+0
  FUN_00442730(EAX=node)     // destroy embedded tree @ node+0x10
  operator_delete(node)      // cdecl; ADD ESP,4
  node = left
  if !node.isnil: continue
ret 4
```

| Stage | Match | Conf |
|---|---|---|
| isnil@+0x1d gate | `80 7F 1D 00` / `80 7E 1D 00` | **High** |
| right @ +8 recursive | `8B 46 08; PUSH; CALL self` | **High** |
| left @ +0 walk | `8B 36` then `MOV EDI,ESI; JZ loop` | **High** |
| value dtor EAX=node | `8B C7; CALL FUN_00442730` | **High** |
| operator_delete cdecl | `PUSH EDI; CALL; ADD ESP,4` | **High** |
| RET 4 | `C2 04 00` | **High** |
| Decompiler left-walk | **Missing** — bytes override | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (59 B):

```
53 56 57 8B 7C 24 10 80 7F 1D 00 8B D9 8B F7 75 25
8B 46 08 50 8B CB E8 E4 FF FF FF 8B 36 8B C7 E8 7B 1A 00 00
57 E8 67 8B 04 00 83 C4 04 80 7E 1D 00 8B FE 74 DB
5F 5E 5B C2 04 00
```

Entry: `PUSH EBX/ESI/EDI; MOV EDI,[ESP+0x10]`. Epilogue: `POP EDI/ESI/EBX; RET 4`. Pad `CC` @ `0x00440ccb+`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_00441720` full-clear; `gfxUIWindow_CompleteDtor`; `FUN_00758c80` |
| Self | right recurse |
| Parent shell offset | **+0x10** on gfxUIWindow (`LEA …,[reg+0x10]`) |

---

## 7. Naming

| Name | Status |
|---|---|
| `StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred` | **Accept** — structural High; product map English open → `_Inferred` |
| `StdTree_ClearShell_At10` (partition hint) | **Reject as this VA's name** — clear-shell is parent inline (free + reset head/size); this unit is free-subtree only |
| `Named_CalleeOf_Named_gfxUIWindow_00440c90` | **Retire** — scaffold; role is STL free not generic UI helper |
| Collapse into `Map_FreeSubtree_Isnil1d` | **Reject** — this has `FUN_00442730` value destroy; different host |
| Collapse into `FUN_00440ab0` | **Reject** — isnil@+0x3d / different value dtor / shell+0x04 |

---

## 8. Gaps

1. Product `map<K,V>` / nested tree English for isnil1d + embedded isnil3d@+0x10.  
2. tree_shell unused in body (threading only).  
3. Full host inventory beyond three external callers.  
4. `FUN_00442730` / `FUN_004413c0` residual duals.  
5. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
