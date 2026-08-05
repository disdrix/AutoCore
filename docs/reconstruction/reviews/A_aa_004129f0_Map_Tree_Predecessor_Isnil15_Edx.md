# Review A (reconstruction fidelity): `aa_004129f0` Map_Tree_Predecessor_Isnil15_Edx

| Field | Value |
|---|---|
| **Stable ID** | `aa_004129f0` |
| **VA** | `0x004129f0` |
| **Canonical name** | `Map_Tree_Predecessor_Isnil15_Edx` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004129f0_Map_Tree_Predecessor_Isnil15_Edx.md` |
| **System** | shared map/tree helper (isnil `+0x15` family) |
| **Wave** | W38-M OWN |
| **Verdict** | **accept** |

---

## 1. Purpose

**Leaf** helper: advance `*it` to the in-order **predecessor** of a red-black tree node whose **isnil** flag is at **`+0x15`**.

| Offset | Field |
|---|---|
| `+0x00` | left* |
| `+0x04` | parent* |
| `+0x08` | right* |
| `+0x15` | isnil (u8); non-zero ⇒ head/end sentinel |

Control flow (sealed):

1. **`cur = *it`**. If **`cur->isnil`**: `*it = cur->right` and return.
2. Else if **`cur->left` not isnil**: set `*it` to **rightmost** of left subtree.
3. Else climb parents while `cur == parent->left`; if final parent not isnil, `*it = parent`.

**No** allocation, rebalance, key compare, color touch, or map-shell access.

**ABI:** **`EDX = Node**`** (bytes `mov eax,[edx]`); bare **`C3`**; no stack args. Distinct from ECX peer `Map_Tree_Predecessor_Isnil15` @ `0x005a2850`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004129f0_FUN_004129f0.md` (+ W38-M append) |
| Annotated | `docs/reconstruction/raw/aa_004129f0_FUN_004129f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004129f0.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/Map_Tree_Predecessor_Isnil15_Edx.cpp` |
| Function record | `docs/reconstruction/functions/aa_004129f0_Map_Tree_Predecessor_Isnil15_Edx.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x004129f0` — CF ≡ raw 2026-07-23 |
| Body image | Ghidra `read_memory` 81 B — leaf; isnil `cmp byte [reg+0x15],0`; entry load `[edx]` |
| Callers | `analyze_function_complete` — 8 static callers; `get_assembly_context` shows `lea edx,[esp+…]` |
| Peer dual | `A|B_aa_005a2850_Map_Tree_Predecessor_Isnil15` (ECX) |

**Not performed:** `disassemble_bytes`, Launcher, runtime, bit-exact image diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| **EDX = Node****; no stack args | Body `8b 02` = `mov eax,[edx]`; callers `lea edx,…`; exits **`C3`** | **High** |
| void; mutates `*it` only | Stores only through `[edx]` | **High** |
| isnil at **`+0x15`** | Bytes: `80 78 15 00` / `80 79 15 00` | **High** |
| left `+0`, parent `+4`, right `+8` | loads at 0 / +4 / +8 | **High** |
| isnil path → right child | First arm | **High** |
| left-subtree max via right walk | Second arm | **High** |
| climb while `cur == parent->left` | `cmp [edx],[eax]` style | **High** |
| Leaf (no callees) | analyze empty; no `E8` | **High** |
| Role = **predecessor** (not successor/insert) | Algorithm + peer dual | **High** |
| Body 81 B sealed | `0x004129f0`–`0x00412a40` + CC pad | **High** |
| Product English / MSVC template name | No string this pass | **Open** |
| Runtime / bit-exact | Not run | **Open** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

Clean `Map_Tree_Predecessor_Isnil15_Edx.cpp` matches decompile three-arm predecessor and byte ABI (EDX). Scaffold Mission Named_CalleeOf alias **rejected**.

---

## 5. Residual gaps

1. Product / demangle English.
2. Per-caller key/value node schemas (color/value not touched here).
3. Runtime edge cases; bit-exact image diff.

---

## 6. Verdict

**accept** — algorithm, layout, body bound, and **EDX** ABI sealed by decompile + bytes + call-site context. Residual gaps are naming/runtime only (not CF).
