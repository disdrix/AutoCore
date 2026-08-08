# Review A (reconstruction fidelity): `aa_0042a840` StdTree_Rrotate_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042a840` |
| **VA** | `0x0042a840`–`0x0042a88f` inclusive (**80 B** / `0x50`) |
| **Canonical name** | `StdTree_Rrotate_Isnil2D_Inferred` |
| **Ghidra name** | `FUN_0042a840` |
| **Review date** | `2026-08-05` (WQ9K-J OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0042a840_StdTree_Rrotate_Isnil2D_Inferred.md` |
| **System** | MSVC `std::_Tree` right-rotate (isnil@+0x2D) |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `disassemble_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **right rotate** about node `x` for trees whose nodes expose **isnil @ +0x2D**. Promote `x->left` (`y`) into `x`'s place; hang `x` as `y->right`. Used by StringKey map insert/erase rebalance. Twin L-rotate `FUN_0044e010` (same family, residual).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-05) |
| Full body hex | 80 B via `read_memory` |
| Assembly listing | `disassemble_function` (not disassemble_bytes) |
| Call sites | insert `00430c72`/`00430c86`; erase `0040968a` family; peers |
| Peer L-rotate | `FUN_0044e010` disasm confirms isnil@+0x2D + ECX=node |

---

## 3. Signature (sealed)

```c
// ECX=node x*; stack tree*; void; RET 4
void __thiscall StdTree_Rrotate_Isnil2D_Inferred(
    /*ECX*/ void* x,
    /*stack*/ void* tree);
```

| Formal | Source | Conf |
|---|---|---|
| x (node) | ECX | **Confirmed** |
| tree | `[esp+4]` | **Confirmed** |
| cleanup | `RET 4` ×3 | **Confirmed** |
| isnil test | `[y->right + 0x2D]` | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| y = x.left; x.left = y.right | bytes | **Confirmed** |
| Nil-child parent fixup isnil@+0x2D | `80 7A 2D 00` | **Confirmed** |
| y.parent = x.parent | bytes | **Confirmed** |
| Root / right-child / left-child reattach | three RET 4 exits | **Confirmed** |
| y.right = x; x.parent = y | all exits | **Confirmed** |
| No callees / no recolor | leaf; no +0x2C store | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| External callers | `FUN_00401db0`, `FUN_0042a930`, `FUN_00430b60`, `FUN_004094c0` (`xref_count=10`) |
| Callees | none |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classical right-rotate CF | **Yes** |
| isnil@+0x2D sealed | **Yes** |
| Shared insert/erase rebalance consumers | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Rrotate_Isnil2D_Inferred`** (matches isnil29 family naming; product open → `_Inferred`).

---

## 7. Gaps

- Product/PDB demangle.
- Peer L-rotate `0044e010` full dual (role sealed as twin).
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/isnil/leaf sealed; only product residual → **accept**.
