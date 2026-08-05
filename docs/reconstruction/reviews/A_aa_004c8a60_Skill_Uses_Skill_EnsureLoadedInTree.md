# Review A (reconstruction fidelity): `aa_004c8a60` Skill_Uses_Skill_EnsureLoadedInTree

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8a60` |
| **VA** | `0x004c8a60` |
| **Canonical name** | `Skill_Uses_Skill_EnsureLoadedInTree` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c8a60_Skill_Uses_Skill_EnsureLoadedInTree.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

String-driven human alias for bulk unit at **0x004c8a60**. Evidence: **"Skill_EnsureLoadedInTree"**. The **real** ensure-loaded helper already dual-reviewed as `Skill_EnsureLoadedInTree` **`aa_0051a980`**. This VA is a different bulk body (large walk from param_1 relative offsets **−0x4fc / −0x454**, tree at **+0x520**, etc.). Use `aa_0051a980` for lazy skill-tree load product work.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c8a60_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004c8a60_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_Uses_Skill_EnsureLoadedInTree.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c8a60_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `String alias EnsureLoadedInTree` | High | Clean plate |
| `Real unit is aa_0051a980 ≠ this VA` | High | Address split |
| `Bulk relative-offset walk` | High | Body |
| `Not drop-in for EnsureLoadedInTree` | High | Ledger policy |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Bulk body ≡ raw | Yes |
| No invent aa_0051a980 rewrite | Yes |

---

## 5. Gaps / open

1. Prefer aa_0051a980 dual for product.
2. Explain why string appeared in this bulk unit.

**Verdict:** **accept-with-gaps**
