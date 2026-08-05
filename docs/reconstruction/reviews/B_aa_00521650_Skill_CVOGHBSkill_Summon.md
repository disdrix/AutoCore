# Review B (skeptical / adversarial): `aa_00521650` Skill_CVOGHBSkill_Summon

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00521650_Skill_CVOGHBSkill_Summon.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | All skills use this HB | Falsified — summon family |
| 2 | No cast reaction | Falsified — CastSkillOnTarget |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Summon cast path | High | Broken summons |
| RTTI filter | Tentative | Wrong target type |

---

## 3. Cross-check against raw

```
HB summon: ensure skill; bind; cast on target; type checks.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
CVOGHBSkill_Summon(...):
  summon skill HB execute
  pair CastSkillOnTarget + EnsureLoadedInTree
```

---

## 5. Open questions

1. Seal summon spawn reaction.
2. Live summon cast capture.

**Verdict:** **accept-with-gaps**
