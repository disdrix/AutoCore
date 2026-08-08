# Review A (reconstruction fidelity): `aa_00403e90` StdTree_Lrotate_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403e90` |
| **VA** | `0x00403e90`–`0x00403edb` inclusive (**76 B** / `0x4C`) |
| **Canonical name** | `StdTree_Lrotate_Isnil31_Inferred` |
| **Ghidra name** | `FUN_00403e90` |
| **Review date** | `2026-08-05` (WQ9L-B OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00403e90_StdTree_Lrotate_Isnil31_Inferred.md` |
| **System** | MSVC std tree left-rotate (isnil@+0x31) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `disassemble_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Classic **left rotate** on tree node X (isnil@**+0x31** family, node size **0x38**):

```text
Y = X.right
X.right = Y.left
if Y.left non-nil: Y.left.parent = X
Y.parent = X.parent
if X is root: root = Y
elif X is left of parent: parent.left = Y
else: parent.right = Y
Y.left = X
X.parent = Y
```

Used by dualed erase rebalance `StdTree_EraseAndRebalance_Isnil31_Inferred` (`0x00408ed0`) and insert peer `FUN_00403250`. Right-rotate twin `00403ee0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00403e90_FUN_00403e90.md` (+ WQ9L-B append) |
| Annotated | `docs/reconstruction/raw/aa_00403e90_FUN_00403e90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Isnil31_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00403e90.cpp` |
| Function record | `docs/reconstruction/functions/aa_00403e90_FUN_00403e90.md` |
| Named record | `docs/reconstruction/functions/aa_00403e90_StdTree_Lrotate_Isnil31_Inferred.md` |
| Live | decompile ≡ CF; body hex; isnil `+0x31`; 5 CALL xrefs; call-site ECX/PUSH |

---

## 3. Signature (sealed)

```c
// ECX = node X; stack map*; RET 4; void
void __thiscall StdTree_Lrotate_Isnil31_Inferred(void *node_x, void *map);
```

| Slot | Source | Conf |
|---|---|---|
| node X | **ECX** | **High** |
| map | stack `[ESP+4]` after entry | **High** |
| cleanup | **`RET 4`** ×3 exits | **High** |
| isnil | **`+0x31`** | **High** |

**Note:** Decompiler of parent erase may show `FUN_00403e90(map)` with inverted this/arg; assembly (`MOV ECX,node` / `PUSH map`) seals ECX=node.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Y = X.right (+8) | **Yes** | **High** |
| X.right = Y.left; nil parent fix @+0x31 | **Yes** | **High** |
| Root / left / right parent cases | **Yes** | **High** |
| Y.left = X; X.parent = Y | **Yes** | **High** |
| No color writes in body | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |
| Product map English | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| External callers | `FUN_00408ed0` (3), `FUN_00403250` (2); **xref_count=5** |
| Site roles | RB rebalance Lrot when erased black / insert fixup |
| Callees | none |
| Twin | Rrotate `FUN_00403ee0` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classic Lrotate CF + isnil@+0x31 | **Yes** |
| Erase isnil31 parent dualed | **Yes** |
| Distinct from isnil29/isnil2D peers | **Yes** |
| Product/PDB English for map T | **No** |

**Decision:** promote **`StdTree_Lrotate_Isnil31_Inferred`**. Reject mission-seed plate; reject right-rotate mislabel; reject isnil29/2D merge.

---

## 7. Gaps / open

1. Product / English host map type (0x38 isnil31 family).
2. Right-rotate peer dual is WQ9L-C OWN residual.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
