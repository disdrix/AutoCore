# Review A (reconstruction fidelity): `aa_005535a0` Skill_SetRankAndReevaluate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005535a0` |
| **VA** | `0x005535a0` |
| **Canonical name** | `Skill_SetRankAndReevaluate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005535a0_Skill_SetRankAndReevaluate.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** |

---

## 1. Purpose

Trivial setter: store new rank at skill **`+0x5f6`**, then call `Skill_ReevaluateForCurrentRank`. Small but high-value rank pipeline entry used by UI train / load / tooltip formatters that temporarily re-rank for display.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005535a0_Skill_SetRankAndReevaluate.md` (or `aa_005535a0_FUN_005535a0.md`) |
| Annotated | `docs/reconstruction/raw/aa_005535a0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_SetRankAndReevaluate.cpp` |
| Function record | `docs/reconstruction/functions/aa_005535a0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Writes rank +0x5f6` | High | Body |
| `Always calls ReevaluateForCurrentRank` | High | Callee |
| `No other side effects in body` | High | Tiny function |
| `Used by formatters with temp rank` | Medium | Callers like nullify format |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Store rank → reevaluate | Yes |
| No invented train packet | Yes |

---

## 5. Gaps / open

1. Whether callers restore prior rank after tooltip temp set.
2. Server train path vs client-only.

**Verdict:** **accept**
