# Review A (reconstruction fidelity): `aa_004d1b80` Skill_Uses_CVOGReaction_ResolveSkillTargets

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d1b80` |
| **VA** | `0x004d1b80` |
| **Canonical name** | `Skill_Uses_CVOGReaction_ResolveSkillTargets` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d1b80_Skill_Uses_CVOGReaction_ResolveSkillTargets.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

String-driven human alias for bulk unit at **0x004d1b80**. Evidence: **"CVOGReaction_ResolveSkillTargets"**. The **real** reaction skill-target resolver is dual-reviewed as `CVOGReaction_ResolveSkillTargets` **`aa_0054c570`**. This bulk VA must not replace that unit. CF accepted as string-alias capture only (~144 lines, multi-return).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d1b80_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004d1b80_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_Uses_CVOGReaction_ResolveSkillTargets.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d1b80_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `String alias ResolveSkillTargets` | High | Clean plate |
| `Real unit aa_0054c570 ≠ this VA` | High | Address split |
| `Bulk multi-return body` | High | Size ~144 |
| `Not product reaction resolver` | High | Ledger policy |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Bulk body ≡ raw | Yes |
| No invent 0x54c570 rewrite | Yes |

---

## 5. Gaps / open

1. Use aa_0054c570 for skill reaction targets.
2. Optional demote this alias in importance scans.

**Verdict:** **accept-with-gaps**
