# Review A (reconstruction fidelity): `aa_00404000` StdTree_IteratorIncrement_Isnil131

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404000` |
| **VA** | `0x00404000`–`0x00404057` inclusive (**88 B** / `0x58`) |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil131` |
| **Ghidra name** | `FUN_00404000` |
| **Prior scaffold** | `Named_CalleeOf_*` / `StdTree_IteratorIncrement_Isnil131` plate |
| **Review date** | `2026-08-05` (WQ9L-A OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00404000_StdTree_IteratorIncrement_Isnil131.md` |
| **System** | shared `client::stdtree` (MSVC `_Tree_iterator::operator++`) |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `disassemble_function` + `analyze_function_complete` + `read_memory` (full 88 B) + `get_assembly_context` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

In-place **tree/map iterator successor** (`operator++`) for the large-node family with **isnil @ +0x131**. Advances the node pointer stored in the iterator object. Nil-at-current is a no-op (already `end()`).

```text
// EDX = iterator*  (holds node*)
node = *it
if (node->isnil(+0x131) == 0):          // real node
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

Classic red-black / MSVC tree successor. Node layout: `+0` left, `+4` parent, `+8` right, `+0x131` nil flag.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-A re-verify) | `docs/reconstruction/raw/aa_00404000_FUN_00404000.md` |
| Annotated | `docs/reconstruction/raw/aa_00404000_FUN_00404000.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil131.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00404000.cpp` |
| Function record | `docs/reconstruction/functions/aa_00404000_FUN_00404000.md` |
| Named record | `docs/reconstruction/functions/aa_00404000_StdTree_IteratorIncrement_Isnil131.md` |
| Live | decompile ≡ raw CF; full 88 B hex; 6 xrefs / 3 caller functions |
| Call sites | `LEA EDX` then `CALL` @ `00407bc6` (`FUN_00407b70`), `00408b37` (`FUN_00408ad0` OWN peer), 4× `FUN_00957820` |
| Family | twins isnil `+0x31` / `+0x19` / `+0x29` / `+0x49` |

### Full body hex (sealed)

```
8b0280b83101000000754c8b480880b93101000000751b8b0180b83101000000750d
8bc88b0180b8310100000074f3890ac38b400480b8310100000075178bff8b0a3b48
08750e89028b400480b8310100000074eb8902c3
```

Every isnil guard is displacement **`0x131`** (`80 xx 31 01 00 00`). Both exits are plain **`RET`** (`C3` @ `0x00404031`, `0x00404057`).

---

## 3. Signature (sealed)

```c
// EDX = node**; void; plain RET
// ECX unused at entry (decompiler phantom param_1)
void StdTree_IteratorIncrement_Isnil131(int32_t *it /*EDX*/);
```

| Slot | Source | Conf |
|---|---|---|
| it | **EDX** (`MOV EAX,[EDX]` entry; call-site `LEA EDX`) | **Confirmed** |
| ECX | unused at entry (body reuses as walk scratch) | **Confirmed** |
| return | void; stores through `*it` only | **Confirmed** |
| cleanup | plain **`RET`** (`C3`) | **Confirmed** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Nil guard early out | **Yes** | **Confirmed** |
| Right non-nil → leftmost | **Yes** | **Confirmed** |
| Right nil → parent climb while right-child | **Yes** | **Confirmed** |
| `*it` store | **Yes** | **Confirmed** |
| No callees (leaf) | **Yes** | **Confirmed** |
| isnil every guard `+0x131` | **Yes** (`80 xx 31 01`) | **Confirmed** |
| Product template English | role-sealed structural | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf / MSVC `_Tree_iterator::operator++` successor |
| External xrefs | **6** UNCONDITIONAL_CALL |
| Caller functions | `FUN_00407b70` (erase-range), `FUN_00408ad0` (OWN peer erase), `FUN_00957820` (×4) |
| Callees | none |
| Site role | advance iterator / capture successor before erase |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classic successor CF (right→leftmost / parent climb) | **Yes** |
| isnil @ +0x131 sealed in every branch | **Yes** |
| EDX iterator ABI + plain RET | **Yes** |
| Call sites `LEA EDX` then CALL | **Yes** |
| Family peer of dualed isnil31 `00408590` | **Yes** |
| Product/PDB English host type | **No** |

**Decision:** promote **`StdTree_IteratorIncrement_Isnil131`**. Offset-qualified family peer; algorithm proven → no `_Inferred` suffix (matches isnil31/19/49 peers). Reject scaffold `Named_CalleeOf_*` product labels.

---

## 7. Gaps

1. Per-site map key/value product types (shared helper; multi-caller).
2. Color bit offset unused here (not part of successor).
3. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/isnil@+0x131 with only product-English residual → **accept**.
