# Review A (reconstruction fidelity): `aa_004e12c0` StdTree_IteratorIncrement_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e12c0` |
| **VA** | `0x004e12c0`–`0x004e130b` exclusive (**75 B** / `0x4B`) |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil21_Inferred` |
| **Ghidra name** | `FUN_004e12c0` |
| **Prior scaffold** | `Named_CalleeOf_*` / scaffold `FUN_004e12c0` |
| **Review date** | `2026-08-05` (R13-003 OWN dual start **2686**) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004e12c0_StdTree_IteratorIncrement_Isnil21_Inferred.md` |
| **System** | skills-abilities (partition); role = shared `client::stdtree` (MSVC `_Tree_iterator::operator++`) |
| **Parent dual** | `0x00405650` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full 75 B + pad) + `get_function_callers` / `get_function_xrefs` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

In-place **tree/map iterator successor** (`operator++`) for the isnil21 family. Advances the node pointer stored in the iterator object. Nil-at-current is a no-op (already `end()`).

```text
// ECX = iterator*  (holds node*)
node = *it
if (node->isnil(+0x21) == 0):          // real node
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

Classic red-black / MSVC tree successor. Node layout: `+0` left, `+4` parent, `+8` right, `+0x21` nil flag. Matches parent erase layout (color@+0x20 unused here).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R13-003 re-verify) | `docs/reconstruction/raw/aa_004e12c0_FUN_004e12c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e12c0_FUN_004e12c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e12c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e12c0_FUN_004e12c0.md` |
| Named record | `docs/reconstruction/functions/aa_004e12c0_StdTree_IteratorIncrement_Isnil21_Inferred.md` |
| Live | decompile ≡ raw CF; full 75 B hex; 8 xrefs / 8 caller functions |
| Call sites | all `LEA ECX,[stack_it]` then `CALL` (erase/hint plates) |
| Family | twins isnil `+0x19` / `+0x29` / `+0x31` / `+0x49` / `+0x131` |

### Full body hex (sealed)

```
8b018078210075428b5008807a2100751c8b028078210075118da42400000000
8bd08b028078210074f68911c38b40048078210075128b113b5008750b89018b
40048078210074ee8901c3
```

Every isnil guard is displacement **`0x21`** (`80 xx 21 00`). Both exits are plain **`RET`** (`C3` @ `0x004e12ec`, `0x004e130a`). Entry `MOV EAX,[ECX]` seals **ECX** formal.

---

## 3. Signature (sealed)

```c
// ECX = node**; void; plain RET
void StdTree_IteratorIncrement_Isnil21_Inferred(int32_t *it /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| it | **ECX** (`MOV EAX,[ECX]` entry; call-site `LEA ECX`) | **High** |
| EDX | walk scratch (right / left_walk) | **High** |
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
| No callees (leaf) | **Yes** | **High** |
| isnil every guard `+0x21` | **Yes** (`80 xx 21 00`) | **High** |
| Product template English | role-sealed structural | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf / MSVC `_Tree_iterator::operator++` successor |
| External xrefs | **8** UNCONDITIONAL_CALL |
| Caller functions | `FUN_00405650`, `FUN_00406560`, `FUN_004e3e70`, `FUN_00511c00`, `FUN_0059d300`, `FUN_005a2ea0`, `FUN_005a4590`, `FUN_005ae6d0` |
| Callees | none |
| Site role | capture successor before erase / advance iterator in insert-hint |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classic successor CF (right→leftmost / parent climb) | **Yes** |
| isnil @ +0x21 sealed in every branch | **Yes** |
| ECX iterator ABI + plain RET | **Yes** |
| Call sites `LEA ECX` then CALL | **Yes** |
| Family peer of dualed isnil31/19/49/131 | **Yes** |
| Parent erase R12-009 names this as succ isnil21 | **Yes** |
| Product/PDB English host type | **No** |

**Decision:** promote **`StdTree_IteratorIncrement_Isnil21_Inferred`**. Offset-qualified family peer; product English open → **`_Inferred`**. Reject scaffold `Named_CalleeOf_*`. Do not merge with EDX-ABI isnil31/131 or other isnil offsets.

---

## 7. Gaps

1. Per-site map key/value product types (shared helper; 8 callers).
2. Color bit offset unused here (family color@+0x20 from erase peers).
3. Runtime / bit-exact / differential — **not Runtime Confirmed**.

---

## 8. Verdict

Fidelity path accepts CF/ABI/isnil@+0x21 with only product-English residual → **accept-with-gaps** (`_Inferred`; Terminal **false**).
