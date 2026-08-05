# Review A (reconstruction fidelity): `aa_00442760` Skill_Uses_SkillSet_GetEntryCount_00442760

| Field | Value |
|---|---|
| **Stable ID** | `aa_00442760` |
| **VA** | `0x00442760` |
| **Canonical name** | `Skill_Uses_SkillSet_GetEntryCount_00442760` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00442760_Skill_Uses_SkillSet_GetEntryCount_00442760.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

String-driven human alias bulk unit at **0x00442760** (originally `FUN_00442760`). Evidence string **"SkillSet_GetEntryCount"** for coverage ledger only. Body: ~96 lines; FUN_00442b00/42a90 + SkillSet_GetEntryCount. **Not** interchangeable with thin `SkillSet_GetEntryCount` (`aa_00402d80`). Some call sites may *invoke* the real GetEntryCount — that does not make this function itself the length helper.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00442760_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00442760_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_Uses_SkillSet_GetEntryCount_00442760.cpp` |
| Function record | `docs/reconstruction/functions/aa_00442760_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `String alias SkillSet_GetEntryCount` | High | Clean naming plate |
| `VA 0x00442760 distinct from thin 0x402d80` | High | Address |
| `Bulk body with residual FUN_*` | High | ~96 lines; FUN_00442b00/42a90 + SkillSet_GetEntryCount |
| `May call real GetEntryCount as callee` | Medium | Callee list in readability |
| `Product identity = thin helper` | Low | Alias only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Bulk CF from raw preserved | Yes |
| No rewrite into thin vector formula | Yes |

---

## 5. Gaps / open

1. Treat as coverage alias; seal only if product path proven.
2. If a callee is real GetEntryCount, document call edge separately.

**Verdict:** **accept-with-gaps**
