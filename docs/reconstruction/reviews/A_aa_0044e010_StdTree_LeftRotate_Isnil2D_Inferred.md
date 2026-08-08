# Review A (reconstruction fidelity): `aa_0044e010` StdTree_LeftRotate_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e010` |
| **VA** | `0x0044e010`–`0x0044e05b` inclusive (**76 B**) |
| **Canonical name** | `StdTree_LeftRotate_Isnil2D_Inferred` |
| **Ghidra name** | `FUN_0044e010` |
| **Review date** | `2026-08-05` (WQ9K-I dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9K-I) |
| **Counterpart** | `reviews/B_aa_0044e010_StdTree_LeftRotate_Isnil2D_Inferred.md` |
| **System** | MSVC std tree left-rotate (isnil@+0x2D) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` + `analyze_function_complete` + bulk xrefs + `get_assembly_context` |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/assembly context). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Classic **left rotate** on tree node X (isnil@**+0x2D** family):

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

Used by StringKey insert/erase rebalance (`00430b60`, `004094c0`) and peers. Right-rotate twin `0042a840`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044e010_FUN_0044e010.md` (+ WQ9K-I append) |
| Annotated | `docs/reconstruction/raw/aa_0044e010_FUN_0044e010.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_LeftRotate_Isnil2D_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044e010.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044e010_FUN_0044e010.md` |
| Named record | `docs/reconstruction/functions/aa_0044e010_StdTree_LeftRotate_Isnil2D_Inferred.md` |
| Live | decompile ≡ CF; body hex; isnil `+0x2D`; 10 CALL xrefs; call-site ECX/PUSH |

---

## 3. Signature (sealed)

```c
// ECX = node X; stack map*; RET 4; void
void __thiscall StdTree_LeftRotate_Isnil2D_Inferred(void *node_x, void *map);
```

| Slot | Source | Conf |
|---|---|---|
| node X | **ECX** | **High** |
| map | stack `[ESP+4]` after entry | **High** |
| cleanup | **`RET 4`** ×3 exits | **High** |
| isnil | **`+0x2D`** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Y = X.right (+8) | **Yes** | **High** |
| X.right = Y.left; nil parent fix | **Yes** | **High** |
| Root / left / right parent cases | **Yes** | **High** |
| Y.left = X; X.parent = Y | **Yes** | **High** |
| No color writes in body | **Yes** | **High** |
| Leaf (no callees) | **Yes** | **High** |
| Product map English | open | **Inferred** |

---

## 5. Gaps / open

1. Product / English host map type (StringKey inferred from peers).
2. Right-rotate peer dual is WQ9K-J OWN.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**

**Decision:** promote **`StdTree_LeftRotate_Isnil2D_Inferred`**. Reject scaffold `Named_CalleeOf_*`; reject isnil29 rotate merge; reject right-rotate mislabel; reject freelist/CNDHash.
