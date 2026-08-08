# Review A (reconstruction fidelity): `aa_00408590` StdTree_IteratorIncrement_Isnil31

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408590` |
| **VA** | `0x00408590`–`0x004085db` exclusive (**75 B**) |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil31` |
| **Ghidra name** | `FUN_00408590` |
| **Review date** | `2026-08-04` (WQ9H-H dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9H-H) |
| **Counterpart** | `reviews/B_aa_00408590_StdTree_IteratorIncrement_Isnil31.md` |
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
if (node->isnil(+0x31) == 0):          // real node
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

Classic red-black / MSVC tree successor. Node layout: `+0` left, `+4` parent, `+8` right, `+0x31` nil flag.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00408590_FUN_00408590.md` (+ WQ9H-H append) |
| Annotated | `docs/reconstruction/raw/aa_00408590_FUN_00408590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil31.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408590.cpp` |
| Function record | `docs/reconstruction/functions/aa_00408590_FUN_00408590.md` |
| Named record | `docs/reconstruction/functions/aa_00408590_StdTree_IteratorIncrement_Isnil31.md` |
| Live | decompile ≡ raw CF; full 75 B hex; 2 callers / 2 xrefs |
| Call sites | `LEA EDX` then `CALL` @ `00408f38` (`FUN_00408ed0`), `00944956` (`FUN_00944770`) |
| Family | twins isnil `+0x19` / `+0x29` / `+0x49` |

---

## 3. Signature (sealed)

```c
// EDX = node**; void; plain RET
void StdTree_IteratorIncrement_Isnil31(int32_t *it /*EDX*/);
```

| Slot | Source | Conf |
|---|---|---|
| it | **EDX** (`MOV EAX,[EDX]` entry; call-site `LEA EDX`) | **High** |
| ECX | unused (decompiler phantom) | **High** |
| return | void; stores through `*it` only | **High** |
| cleanup | plain **`RET`** (`C3`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Nil guard early out | **Yes** | **High** |
| Right non-nil → leftmost | **Yes** | **High** |
| Right nil → parent climb while right-child | **Yes** | **High** |
| `*it` store | **Yes** | **High** |
| No callees | **Yes** | **High** |
| isnil every guard `+0x31` | **Yes** (`80 xx 31 00`) | **High** |
| Product template English | role-sealed structural | **Inferred** |

Full hex: `8b028078310075428b480880793100751c8b018078310075118da424000000008bc88b018078310074f6890ac38b40048078310075128b0a3b4808750b89028b40048078310074ee8902c3`

---

## 5. Gaps / open

1. Per-site map key/value product types (shared helper; 2 callers).
2. Color bit offset unused here.
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
