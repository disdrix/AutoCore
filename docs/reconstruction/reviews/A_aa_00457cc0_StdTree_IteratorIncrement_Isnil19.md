# Review A (reconstruction fidelity): `aa_00457cc0` StdTree_IteratorIncrement_Isnil19

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457cc0` |
| **VA** | `0x00457cc0`–`0x00457d0b` exclusive (**75 B**) |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil19` |
| **Ghidra name** | `FUN_00457cc0` |
| **Review date** | `2026-08-04` (W38-B dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-B) |
| **Counterpart** | `reviews/B_aa_00457cc0_StdTree_IteratorIncrement_Isnil19.md` |
| **System** | shared `client::stdtree` (MSVC `_Tree_iterator::operator++`) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 75 B) + `analyze_function_complete` + `get_assembly_context` call sites |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

In-place **tree/map iterator successor** (`operator++`). Advances the node pointer stored in the iterator object. Nil-at-current is a no-op (already `end()`).

```text
// EDX = iterator*  (holds node*)
node = *it
if (node->isnil(+0x19) == 0):          // real node
  right = node->right(+8)
  if (right->isnil == 0):
    // successor = leftmost of right subtree
    walk left(+0) while child not nil
    *it = that
    return
  // else climb parents(+4) while was right-child
  parent = node->parent
  while (!parent->isnil && *it == parent->right)
    *it = parent; parent = parent->parent
  *it = parent
// if already nil: no-op
```

Classic red-black / MSVC tree successor. Node layout: `+0` left, `+4` parent, `+8` right, `+0x19` nil flag (Val12 family).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00457cc0_FUN_00457cc0.md` (+ W38-B append) |
| Annotated | `docs/reconstruction/raw/aa_00457cc0_FUN_00457cc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil19.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457cc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00457cc0_FUN_00457cc0.md` |
| Named record | `docs/reconstruction/functions/aa_00457cc0_StdTree_IteratorIncrement_Isnil19.md` |
| Live | decompile ≡ raw CF; full 75 B hex; 9 callers / 10 xrefs |
| Call sites | `LEA EDX` then `CALL` @ `004473b0`, `00971114`, `0040b4a0`, `0097160a` |
| Family | twins isnil `+0x29` / `+0x49`; Val12 find `0043d5e0` |

---

## 3. Signature (sealed)

```c
// EDX = node**; void; plain RET
void StdTree_IteratorIncrement_Isnil19(int32_t *it /*EDX*/);
```

| Slot | Source | Conf |
|---|---|---|
| it | **EDX** (`MOV EAX,[EDX]`; call-site `LEA EDX`) | **High** |
| ECX | unused (decompiler phantom) | **High** |
| return | void; stores through `*it` only | **High** |
| cleanup | plain **`RET`** (`C3`) | **High** |

Decompiler `void __fastcall FUN_00457cc0(undefined4, int *param_2)` is correct on EDX formal; do not invent ECX-this or stack args.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Nil guard early out | **Yes** | **High** |
| Right non-nil → leftmost | **Yes** | **High** |
| Right nil → parent climb while right-child | **Yes** | **High** |
| `*it` store | **Yes** | **High** |
| No callees | **Yes** | **High** |
| isnil every guard `+0x19` | **Yes** (`80 xx 19 00`) | **High** |
| Product template English | role-sealed structural | **Inferred** |

Full hex: `8b028078190075428b480880791900751c8b018078190075118da424000000008bc88b018078190074f6890ac38b40048078190075128b0a3b4808750b89028b40048078190074ee8902c3`

---

## 5. Gaps / open

1. Per-site map key/value product types (shared helper across AssPreloader + others).
2. Color bit offset unused here.
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
