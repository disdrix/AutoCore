# Review A (reconstruction fidelity): `aa_00440ab0` StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00440ab0` |
| **VA** | `0x00440ab0`–`0x00440aeb` exclusive (**59 B** / `0x3B`) |
| **Canonical name** | `StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred` |
| **Ghidra name** | `FUN_00440ab0` |
| **Partition alias** | `StdTree_ClearShell_At04` |
| **Review date** | `2026-08-05` (MEGA-130 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00440ab0_StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.md` |
| **System** | MSVC std tree free-subtree (isnil@+0x3D, val@+0x0C) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `batch_decompile`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Free an isnil@**+0x3D** red-black **subtree** rooted at stack `node*`:

```text
if node.isnil@+0x3D: return
loop:
  FreeSubtree(tree, node.right@+8)
  left = node.left@+0
  DestroyVal(node+0x0C) via FUN_00442720
  operator_delete(node)
  node = left
  if node.isnil@+0x3D: break
RET 4
```

Callers then empty-reset head/size when clearing a shell. Primary product path: **gfxUIWindow** complete dtor frees tree shell at **this+0x04** (partition role `ClearShell_At04`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-130 append) | `docs/reconstruction/raw/aa_00440ab0_FUN_00440ab0.md` |
| Annotated | `docs/reconstruction/raw/aa_00440ab0_FUN_00440ab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00440ab0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00440ab0_FUN_00440ab0.md` |
| Named record | `docs/reconstruction/functions/aa_00440ab0_StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.md` |
| Live | decompile + full 59 B hex + 4 xrefs + call-site context @ `00759e79` / `004413e0` |

---

## 3. Signature (sealed)

```c
// ECX = tree host; stack node*; RET 4; void
void __fastcall StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred(
    void *tree_host, void *node);
```

| Slot | Source | Conf |
|---|---|---|
| tree host | **ECX** (`MOV EBX,ECX`; recursive pass) | **High** |
| node | stack `[ESP+4]` → `MOV EDI,[ESP+0x10]` after 3 pushes | **High** |
| cleanup | **`RET 4`** (`C2 04 00`) | **High** |
| isnil | **`+0x3D`** | **High** |
| value | **`+0x0C`** via `00442720` | **High** |

---

## 4. Control flow (clean ≡ bytes; decompile partial)

| Stage | Match | Conf |
|---|---|---|
| isnil@+0x3D early-out | decompile ≡ bytes | **High** |
| Recurse free right@+8 | decompile ≡ bytes | **High** |
| Left-spine walk after delete | **bytes only** (decompile collapsed) | **High** |
| Value dtor `00442720` before delete | decompile ≡ bytes | **High** |
| `operator_delete` + `ADD ESP,4` | bytes (returns) | **High** |
| No head/size reset in body | bytes + call-site post-fixup | **High** |
| Product map / value English | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | `FUN_00759de0`, `FUN_004413c0`, `Catch@004424ff` |
| Self | recurse right @ `0x00440ac7` |
| xref_count | **4** |
| Callees | self, `FUN_00442720`, `operator_delete` |
| Peers | isnil1D `00440c90`, isnil11 `00440d20` (residual) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Free-subtree CF (right recurse + left walk + delete) | **Yes** |
| isnil@+0x3D distinct from isnil1D/11 peers | **Yes** |
| Value destroy @+0x0C via dedicated trampoline | **Yes** |
| gfxUIWindow+0x04 ClearShell call-site role | **Yes** |
| Product/PDB English for map T | **No** |

**Decision:** promote **`StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred`**.  
Partition alias **`StdTree_ClearShell_At04`** retained as call-site role (not full clear — no sentinel reset in body).  
Retire scaffold **`Named_CalleeOf_Named_gfxUIWindow_00440ab0`**.

---

## 7. Gaps / open

1. Product English for map key/value (`FUN_00440770` / `FUN_00440230` value type).
2. Exact node size (isnil@+0x3D ⇒ ≥0x3E).
3. Peer duals MEGA-131 / MEGA-132 residual.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
