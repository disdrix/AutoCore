# Review A (reconstruction fidelity): `aa_00409160` StdTree_Min_Isnil31

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409160` |
| **VA** | `0x00409160`–`0x00409172` inclusive (**19 B**) |
| **Canonical name** | `StdTree_Min_Isnil31` |
| **Ghidra name** | `FUN_00409160` |
| **Review date** | `2026-08-05` (WQ9J-E dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-E) |
| **Counterpart** | `reviews/B_aa_00409160_StdTree_Min_Isnil31.md` |
| **System** | shared `client::stdtree` (MSVC `_Tree_min`, isnil @ +0x31) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (19 B) + `disassemble_function` + `get_assembly_context` call site + callers/xrefs |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Return the **leftmost non-nil** node in the subtree rooted at the input node (MSVC `_Tree_min` / leftmost). Used by isnil@+0x31 map erase (`FUN_00408ed0`) to recompute `head->left` after unlinking the old leftmost.

```text
// EAX = node*
left = node->left
if left->isnil(+0x31): return node
do:
  node = left
  left = node->left
while !left->isnil
return node   // EAX
```

Node layout: `+0` left, `+4` parent, `+8` right, `+0x31` nil flag (family of `StdTree_IteratorIncrement_Isnil31`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00409160_FUN_00409160.md` (+ WQ9J-E append) |
| Annotated | `docs/reconstruction/raw/aa_00409160_FUN_00409160.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Min_Isnil31.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409160.cpp` |
| Function record | `docs/reconstruction/functions/aa_00409160_FUN_00409160.md` |
| Named record | `docs/reconstruction/functions/aa_00409160_StdTree_Min_Isnil31.md` |
| Live | decompile walk-left CF; full 19 B hex; 1 caller / 1 xref |
| Call site | `MOV EAX,EDI; CALL; MOV [EBX],EAX` @ `00408f9d` in `FUN_00408ed0` |
| Family | twin `StdTree_Min_Isnil29` @ `0x0051b5d0`; peer iterator++ isnil31 `00408590` |

---

## 3. Signature (sealed)

```c
// EAX = node* in/out; plain RET
node_t *StdTree_Min_Isnil31(node_t *node /*EAX*/);
```

| Slot | Source | Conf |
|---|---|---|
| node in | **EAX** (`MOV ECX,[EAX]` entry; call-site `MOV EAX,EDI`) | **High** |
| node out | **EAX** (call-site `MOV [EBX],EAX`) | **High** |
| ECX | scratch (left walk) | **High** |
| cleanup | plain **`RET`** (`C3`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Load left / isnil guard | **Yes** | **High** |
| Early return when left nil | **Yes** (EAX unchanged) | **High** |
| Walk left while non-nil | **Yes** | **High** |
| isnil every guard `+0x31` | **Yes** (`80 79 31 00`) | **High** |
| No callees | **Yes** | **High** |
| Decomp void wrong for return | **Yes** — EAX sealed by call site | **High** |
| Product template English | role-sealed structural | **High** (role) |

Full hex: `8b0880793100750a8bc18b088079310074f6c3`

---

## 5. Gaps / open

1. Per-map product key/value types for isnil@+0x31 family (shared helper; 1 erase caller sealed).
2. Color bit unused here.
3. Runtime / bit-exact / differential.

**Verdict:** **accept** (product type residual only — same bar as iterator++ isnil31).
