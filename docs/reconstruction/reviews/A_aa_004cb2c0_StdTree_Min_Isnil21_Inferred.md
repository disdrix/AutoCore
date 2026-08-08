# Review A (reconstruction fidelity): `aa_004cb2c0` StdTree_Min_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb2c0` |
| **VA** | `0x004cb2c0`–`0x004cb2da` inclusive (**27 B**) |
| **Canonical name** | `StdTree_Min_Isnil21_Inferred` |
| **Ghidra name** | `FUN_004cb2c0` |
| **Review date** | `2026-08-05` (R13-002 dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R13-002) |
| **Counterpart** | `reviews/B_aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md` |
| **System** | shared `client::stdtree` (MSVC `_Tree_min`, isnil @ +0x21); partition **skills-abilities** |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (28 B) + `get_assembly_context` call sites + callers/xrefs |
| **Verdict** | **accept** |

**Tools:** decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`. No Launcher. **Never Runtime Confirmed.**

---

## 1. Purpose

Return the **leftmost non-nil** node in the subtree rooted at the input node (MSVC `_Tree_min` / leftmost). Used by isnil@+0x21 map erase plates (parent `FUN_00405650` and six peers) to recompute `head->left` after unlinking the old leftmost.

```text
// [esp+4] = node*
left = node->left
if left->isnil(+0x21): return node
do:
  node = left
  left = node->left
while !left->isnil
return node   // EAX
```

Node layout: `+0` left, `+4` parent, `+8` right, color@**+0x20**, isnil@**+0x21** (family of parent erase `StdTree_EraseAndRebalance_Isnil21_Inferred`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cb2c0_FUN_004cb2c0.md` (+ R13-002 append) |
| Annotated | `docs/reconstruction/raw/aa_004cb2c0_FUN_004cb2c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Min_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cb2c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cb2c0_FUN_004cb2c0.md` |
| Named record | `docs/reconstruction/functions/aa_004cb2c0_StdTree_Min_Isnil21_Inferred.md` |
| Live | decompile walk-left CF; full 27 B hex; 7 callers / 7 xrefs |
| Call plate | `PUSH EDI; CALL; ADD ESP,4; MOV [EBX],EAX` at all 7 sites |
| Family | twin `StdTree_Min_Isnil29` @ `0x0051b5d0`; peer `StdTree_Min_Isnil31` @ `0x00409160` |

---

## 3. Signature (sealed)

```c
// stack arg node* in; returns node* in EAX; plain RET; caller ADD ESP,4
node_t *StdTree_Min_Isnil21_Inferred(node_t *node /*[esp+4]*/);
```

| Slot | Source | Conf |
|---|---|---|
| node in | **stack** `MOV EAX,[ESP+4]` entry; call-site `PUSH EDI` | **High** |
| node out | **EAX** (call-site `MOV [EBX],EAX` after `ADD ESP,4`) | **High** |
| ECX | scratch (left walk) | **High** |
| cleanup | plain **`RET`** (`C3`); caller cleans 4 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Load left / isnil guard | **Yes** | **High** |
| Early return when left nil | **Yes** (EAX unchanged) | **High** |
| Walk left while non-nil | **Yes** | **High** |
| isnil every guard `+0x21` | **Yes** (`80 79 21 00`) | **High** |
| No callees | **Yes** | **High** |
| Decomp void wrong for return | **Yes** — EAX sealed by call sites | **High** |
| Product template English | role-sealed structural | **High** (role) |

Full hex: `8b4424048b0880792100750e8d6424008bc18b088079210074f6c3`

---

## 5. Gaps / open

1. Per-map product key/value types for isnil@+0x21 family (shared helper; 7 erase callers sealed).
2. Color bit unused here (color@+0x20 sealed only via parent erase dual).
3. Runtime / bit-exact / differential.

**Verdict:** **accept** (product type residual only — same bar as Min isnil29/31 peers). `_Inferred` retained (no product demangle).
