# Review A (reconstruction fidelity): `aa_004cbd50` Map_LowerBoundFindByIntKey_Isnil65

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbd50` |
| **VA** | `0x004cbd50`–`0x004cbdb1` (98 B) |
| **Canonical name** | `Map_LowerBoundFindByIntKey_Isnil65` |
| **Ghidra name** | `FUN_004cbd50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-O) |
| **Counterpart** | `reviews/B_aa_004cbd50_Map_LowerBoundFindByIntKey_Isnil65.md` |
| **System** | ordered map exact-find |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf MSVC-style ordered-tree **exact find** by **signed dword** key:

1. Start at map end/head `*(this+4)`; root = `head[1]`.
2. Lower_bound walk: `key < search` → right else cand=cur, left; stop on isnil `@+0x65`.
3. Accept only if `cand != end && cand.key <= search` (⇒ equality with walk invariant).
4. Else write end. **Read-only** — no insert/erase.

Used by AI DoLogic profile-row lookup (`FUN_00540890` map select + this find on def float `+0x4dc` bits).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cbd50_FUN_004cbd50.md` (+ 2026-07-29 W26-O append) |
| Annotated | `docs/reconstruction/raw/aa_004cbd50_FUN_004cbd50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_LowerBoundFindByIntKey_Isnil65.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cbd50.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cbd50_FUN_004cbd50.md` |
| Named record | `docs/reconstruction/functions/aa_004cbd50_Map_LowerBoundFindByIntKey_Isnil65.md` |
| Live | decompile ≡ raw; `read_memory` 98 B; dual `C2 08 00` |

---

## 3. Signature (sealed)

```c
void __thiscall Map_LowerBoundFindByIntKey_Isnil65(
    void *this, uint32_t **pOutIt, int32_t *pKey);
/* ret 8 */
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX (`param_1`) | **High** |
| pOutIt | Stack[0x4] | **High** |
| pKey | Stack[0x8] | **High** |
| cleanup | `5F 59 C2 08 00` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
end = *(this+4); cand = end; cur = end->parent
if !isnil(cur):
  loop:
    if cur.key < *pKey: cur = right
    else: cand = cur; cur = left
    while !isnil(cur)
if cand != end && cand.key <= *pKey: *pOut = cand
else: *pOut = end
```

| Stage | Match | Conf |
|---|---|---|
| Head/end @ this+4 | **Yes** | **High** |
| Root = head[1] | **Yes** | **High** |
| isnil @ +0x65 | **Yes** (`80 78 65 00`) | **High** |
| key dword @ +0x0C | **Yes** (`39 70 0C` / `3B 4A 0C`) | **High** |
| L/R walk | **Yes** | **High** |
| Exact gate | **Yes** | **High** |
| Leaf | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (98 B):
```
518b51048b420480786500578b7c24107518568b3739700c7d058b4008eb048bd08b008078650074ec5e8b41043bd08954241074188b0f3b4a0c7c118d4424108b108b44240c89105f59c20800894424048d4424048b108b44240c89105f59c20800
```

Dual epilogues both `5F 59 C2 08 00` (hit path + miss path).

---

## 6. Gaps

- Product STL / RTTI type name.
- Full node value_type (isnil @ +0x65 ⇒ large payload; out of unit).
- Runtime bit-exact / differential — open.
- Callers pass float* keys — dword order equals float order only for non-negative keys (AI profile floats); residual if negatives appear.

---

## 7. Verdict

CF/ABI/node slots sealed against live decompile + full body bytes → **accept**.
