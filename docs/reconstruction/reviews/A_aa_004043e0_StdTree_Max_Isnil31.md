# Review A (reconstruction fidelity): `aa_004043e0` StdTree_Max_Isnil31

| Field | Value |
|---|---|
| **Stable ID** | `aa_004043e0` |
| **VA** | `0x004043e0`–`0x004043fb` inclusive (**28 B**) |
| **Canonical name** | `StdTree_Max_Isnil31` |
| **Ghidra name** | `FUN_004043e0` |
| **Review date** | `2026-08-05` (WQ9L-C dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-C) |
| **Counterpart** | `reviews/B_aa_004043e0_StdTree_Max_Isnil31.md` |
| **System** | shared `client::stdtree` (MSVC `_Tree_max`, isnil @ +0x31) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (28 B) + `disassemble_function` + `get_assembly_context` call site + callers/xrefs |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Return the **rightmost non-nil** node in the subtree rooted at the input node (MSVC `_Tree_max` / rightmost). Used by isnil@+0x31 map erase (`FUN_00408ed0`) to recompute `head->right` after unlinking the old rightmost.

```text
// EAX = node*
right = node->right
if right->isnil(+0x31): return node
do:
  node = right
  right = node->right
while !right->isnil
return node   // EAX
```

Node layout: `+0` left, `+4` parent, `+8` right, `+0x31` nil flag (family of `StdTree_Min_Isnil31` / erase parent).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004043e0_FUN_004043e0.md` (+ WQ9L-C append) |
| Annotated | `docs/reconstruction/raw/aa_004043e0_FUN_004043e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Max_Isnil31.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004043e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004043e0_FUN_004043e0.md` |
| Named record | `docs/reconstruction/functions/aa_004043e0_StdTree_Max_Isnil31.md` |
| Live | decompile walk-right CF; full 28 B hex; 1 caller / 1 xref |
| Call site | `MOV EAX,EDI; CALL; MOV [EBX+8],EAX` @ `00408fbf` in `FUN_00408ed0` |
| Family | twin `StdTree_Min_Isnil31` @ `0x00409160`; peer max isnil29 `00421b50` |

---

## 3. Signature (sealed)

```c
// EAX = node* in/out; plain RET
node_t *StdTree_Max_Isnil31(node_t *node /*EAX*/);
```

| Slot | Source | Conf |
|---|---|---|
| node in | **EAX** (`MOV ECX,[EAX+8]` entry; call-site `MOV EAX,EDI`) | **High** |
| node out | **EAX** (call-site `MOV [EBX+8],EAX`) | **High** |
| ECX | scratch (right walk) | **High** |
| cleanup | plain **`RET`** (`C3`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Load right / isnil guard | **Yes** | **High** |
| Early return when right nil | **Yes** (EAX unchanged) | **High** |
| Walk right while non-nil | **Yes** | **High** |
| isnil every guard `+0x31` | **Yes** (`80 79 31 00`) | **High** |
| No callees | **Yes** | **High** |
| Decomp void wrong for return | **Yes** — EAX sealed by call site | **High** |
| Product template English | role-sealed structural | **High** (role) |

Full hex: `8b48088079310075128da424000000008bc18b48088079310074f5c3`

---

## 5. Gaps / open

1. Per-map product key/value types for isnil@+0x31 family (shared helper; 1 erase caller sealed).
2. Color bit unused here.
3. Runtime / bit-exact / differential.

**Verdict:** **accept** (product type residual only — same bar as min/iterator++ isnil31).
