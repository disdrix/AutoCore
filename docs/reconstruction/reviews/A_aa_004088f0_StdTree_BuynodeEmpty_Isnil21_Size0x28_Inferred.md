# Review A (reconstruction fidelity): `aa_004088f0` StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004088f0` |
| **VA** | `0x004088f0`–`0x00408979` |
| **Canonical name** | `StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred` |
| **Ghidra name** | `FUN_004088f0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9H-I) |
| **Counterpart** | `reviews/B_aa_004088f0_StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.md` |
| **System** | util / MSVC `_Tree` empty-node buy (isnil@+0x21, size 0x28) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **empty tree node buy** for the **size 0x28 / isnil@+0x21** family:

1. SEH + `operator_new(0x28)`.
2. Zero left@+0, parent@+4, right@+8.
3. color@+0x20 = **1**; isnil@+0x21 = **0**.
4. Return **node\*** in EAX.

All four callers install the node as **`_Myhead` sentinel**: set isnil=1, circularize links, size=0.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004088f0_FUN_004088f0.md` (+ 2026-08-04 append) |
| Annotated | `docs/reconstruction/raw/aa_004088f0_FUN_004088f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004088f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004088f0_StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.md` |
| Peer empty-head | `FUN_00408a30` (size 0x30 / isnil@+0x29) — WQ9H-J |
| Peer value buynode | `FUN_00408990` (size 0x28 + `FUN_004099b0`) — WQ9H-J |
| Layout peer | `Map_LowerBoundFindByCharKey` isnil@+0x21 key@+0x0C |
| Live | CF sealed; body 138 B; epilogue `C3`; callers store EAX |

---

## 3. Signature (sealed)

```c
// cdecl; RET 0; EAX = node* | null
NodeIsnil21_Size28* StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| (none) | — | **High** |
| return | EAX (callers `mov [tree+4], eax`) | **High** |
| cleanup | `RET` / `C3` | **High** |

Decompiler `void` display is **rejected**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH setup (LAB_009bc6c0)
node = operator_new(0x28)
if node: left = 0
if &node->parent: parent = 0   // always if node
if &node->right:  right = 0
color(+0x20) = 1
isnil(+0x21) = 0
SEH teardown
return node  // EAX
```

| Stage | Match | Conf |
|---|---|---|
| new(0x28) | **Yes** | **High** |
| Zero three links | **Yes** | **High** |
| color@+0x20=1 isnil@+0x21=0 | **Yes** (`88 58 20 88 50 21`) | **High** |
| Head-init callers set isnil=1 | **Yes** (4 sites) | **High** |
| RET 0 cdecl | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body 138 B @ `0x004088f0`; SEH `55 8B EC 6A FF 68 C0 C6 9B 00 …`; `6A 28` + `operator_new`; stores `88 58 20 88 50 21`; epilogue `5F 5E 5B 8B E5 5D C3`.

---

## 6. Gaps

- Product / demangle for map value_type (Val20 region).
- Dual of WQ9H-J peers `00408990` / `00408a30`.
- Dual of head-init parents.
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — CF/ABI/layout offsets sealed; product English residual.
