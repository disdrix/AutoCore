# Review A (reconstruction fidelity): `aa_00441720` StdTree_EraseAll_Shell10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00441720` |
| **VA** | `0x00441720`–`0x004417d1` inclusive (**178 B** / `0xB2`) |
| **Canonical name** | `StdTree_EraseAll_Shell10_Inferred` |
| **Ghidra name** | `FUN_00441720` |
| **Review date** | `2026-08-05` (MEGA-135 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00441720_StdTree_EraseAll_Shell10_Inferred.md` |
| **System** | STL map/set range erase (isnil@+0x1d / Shell10); partition skills-abilities residual of `gfxUIWindow_CompleteDtor` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **`_Tree::erase(first, last)`** for **isnil@+0x1d** nodes with **0x10-byte value shell** (color@+0x1c):

- **Full clear** when `first == head->left && last == head`: `FUN_00440c90(head->parent)` + head reset + `size=0` + `*outIt = begin`.
- **Partial**: in-order successor (isnil@+0x1d) then `FUN_00442000(tree, tmp, victim)` per node.

Both known call sites only use the full-clear path during `gfxUIWindow` tree-shell teardown.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-135 append) | `docs/reconstruction/raw/aa_00441720_FUN_00441720.md` |
| Annotated | `docs/reconstruction/raw/aa_00441720_FUN_00441720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAll_Shell10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00441720.cpp` |
| Function record | `docs/reconstruction/functions/aa_00441720_FUN_00441720.md` |
| Named record | `docs/reconstruction/functions/aa_00441720_StdTree_EraseAll_Shell10_Inferred.md` |
| Live | decompile ≡ raw CF; body hex; isnil `+0x1d`; 2 CALL xrefs; EDI/RET0xC sealed |

---

## 3. Signature (sealed)

```c
// EDI = tree; stack (outIt*, first, last); RET 0xC; EAX = outIt
node **StdTree_EraseAll_Shell10_Inferred(node **outIt, node *first, node *last /* EDI=tree */);
```

| Slot | Source | Conf |
|---|---|---|
| tree | **EDI** (callers `MOV EDI,tree`; body `[EDI+4]/`[EDI+8]`) | **High** |
| outIt | stack0 after entry | **High** |
| first / last | stack1 / stack2 | **High** |
| cleanup | **`RET 0xC`** ×2 | **High** |
| isnil | **`+0x1d`** | **High** |
| Shell10 | value `[+0x0c,+0x1c)` ⇒ **0x10** | **High** |

**Note:** Decompiler shows `unaff_EDI` + 3 stack params. Free-subtree callee is **ECX=tree** (set at call site `MOV ECX,EDI`).

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Full-range gate begin/end | **Yes** | **High** |
| Free `00440c90` + head reset + size 0 | **Yes** | **High** |
| Successor walk isnil@+0x1d | **Yes** | **High** |
| Partial `FUN_00442000(tree,out,node)` | **Yes** | **High** |
| `*outIt` + `RET 0xC` both exits | **Yes** | **High** |
| Product map K/V English | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (`analyze_function_complete`) |
| External xrefs | **2** UNCONDITIONAL_CALL |
| `FUN_004401d0` @ `0x004401e0` | full erase(begin,end) + `operator_delete(head)` (EH residual) |
| `FUN_00759de0` @ `0x0075a09c` | `gfxUIWindow_CompleteDtor` tree-shell clear (dualed WQ9L-F) |
| Callees | `FUN_00440c90`, `FUN_00442000` |
| Twin shape | `FUN_00441960` isnil@+0x11 |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| STL erase-range CF + full-clear fast path | **Yes** |
| isnil@+0x1d + Shell10 (value 0x10) | **Yes** |
| Partition hint `StdTree_EraseAll_Shell10` | **Yes** |
| Distinct from isnil11 / isnil29 / `0051d700` instances | **Yes** |
| Product/PDB English for map T | **No** |

**Decision:** promote **`StdTree_EraseAll_Shell10_Inferred`**. Reject ECX-thiscall-as-body; reject merge into `Map_EraseRange_Isnil1d` `0051d700` (different free/erase pair); reject product UI method name (pure STL shell).

---

## 7. Gaps / open

1. Product / English host map type for Shell10 under `gfxUIWindow`.
2. Callee duals (`00440c90`, `00442000`, value destroy `00442730`) residual.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
