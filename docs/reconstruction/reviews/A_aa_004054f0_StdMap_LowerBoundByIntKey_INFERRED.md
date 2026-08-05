# Review A (reconstruction fidelity): `aa_004054f0` StdMap_LowerBoundByIntKey_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_004054f0` |
| **VA** | `0x004054f0` |
| **Canonical name** | `StdMap_LowerBoundByIntKey_INFERRED` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004054f0_StdMap_LowerBoundByIntKey_INFERRED.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

INFERRED MSVC **std::map lower_bound** for **int** keys. `__thiscall(this, ppOutNode, pKey)`. Walks tree via node `+0x1d` color/nil flag; key at node **[3]**; left/right child pointers. Writes `*ppOutNode` to matching node or **end** sentinel (`*(this+4)`). Dependency of `Experience_GetCumulativeThreshold` and other level-map lookups. Not fully verified against STL symbols — session XP RE dependency only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004054f0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004054f0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_LowerBoundByIntKey_INFERRED.cpp` |
| Function record | `docs/reconstruction/functions/aa_004054f0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Int-key lower_bound tree walk | High | Clean loop |
| End sentinel = *(this+4) | High | Clean |
| Key compare at node[3] | High | Clean |
| Nil flag at +0x1d | High | Clean |
| Exact MSVC red-black layout | Medium | INFERRED STL |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| walk until nil; pick lower_bound node or end | Yes |

---

## 5. Gaps / open

1. Optional: seal against known MSVC7/8 map node layout.
2. Confirm all XP maps share this helper vs Map_LowerBoundFindByIntKey.

**Verdict:** **accept-with-gaps**
