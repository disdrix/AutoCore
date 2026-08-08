# Review A (reconstruction fidelity): `aa_00403ee0` StdTree_Rrotate_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403ee0` |
| **VA** | `0x00403ee0`–`0x00403f2f` inclusive (**80 B** / `0x50`) |
| **Canonical name** | `StdTree_Rrotate_Isnil31_Inferred` |
| **Ghidra name** | `FUN_00403ee0` |
| **Review date** | `2026-08-05` (WQ9L-C OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00403ee0_StdTree_Rrotate_Isnil31_Inferred.md` |
| **System** | MSVC `std::_Tree` right-rotate (isnil@+0x31) |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `disassemble_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf **right rotate** about node `x` for trees whose nodes expose **isnil @ +0x31**. Promote `x->left` (`y`) into `x`'s place; hang `x` as `y->right`. Used by isnil31 erase/rebalance `FUN_00408ed0` and insert peer `FUN_00403250`. Twin L-rotate `FUN_00403e90` (same family).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw CF (2026-08-05) |
| Full body hex | 80 B via `read_memory` |
| Assembly listing | `disassemble_function` (not disassemble_bytes) |
| Call sites | erase `00409091`/`004090c2`/`0040911f`; insert peer `00403366`/`0040337a` |
| Peer L-rotate | `FUN_00403e90` decomp confirms isnil@+0x31 + ECX=node shape |

---

## 3. Signature (sealed)

```c
// ECX=node x*; stack tree*; void; RET 4
void __thiscall StdTree_Rrotate_Isnil31_Inferred(
    /*ECX*/ void* x,
    /*stack*/ void* tree);
```

| Formal | Source | Conf |
|---|---|---|
| x (node) | ECX (`MOV EAX,[ECX]` entry) | **Confirmed** |
| tree | `[esp+4]` | **Confirmed** |
| cleanup | `RET 4` ×3 (`C2 04 00`) | **Confirmed** |
| isnil test | `[y->right + 0x31]` (`80 7A 31 00`) | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| y = x.left; x.left = y.right | bytes | **Confirmed** |
| Nil-child parent fixup isnil@+0x31 | `80 7A 31 00` | **Confirmed** |
| y.parent = x.parent | bytes | **Confirmed** |
| Root / right-child / left-child reattach | three RET 4 exits | **Confirmed** |
| y.right = x; x.parent = y | all exits | **Confirmed** |
| No callees / no recolor | leaf; no +0x30 store | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| External callers | `FUN_00408ed0` (3), `FUN_00403250` (2); `xref_count=5` |
| Callees | none |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classical right-rotate CF | **Yes** |
| isnil@+0x31 sealed | **Yes** |
| Shared erase/insert rebalance consumers | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Rrotate_Isnil31_Inferred`** (matches isnil29/isnil2D Rrotate naming; product open → `_Inferred`).

---

## 7. Gaps

- Product/PDB demangle for isnil31 node 0x38 family.
- Peer L-rotate `00403e90` full dual (role sealed as twin; not OWN).
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/isnil/leaf sealed; only product residual → **accept**.
