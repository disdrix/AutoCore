# Review A (reconstruction fidelity): `aa_00521650` Skill_CVOGHBSkill_Summon

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521650` |
| **VA** | `0x00521650` |
| **Canonical name** | `Skill_CVOGHBSkill_Summon` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00521650_Skill_CVOGHBSkill_Summon.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Heartbeat/skill path for summon skills (`CVOGHBSkill_Summon` string). Ensures skill loaded in tree, looks up active cast binding, may `CVOGReaction_CastSkillOnTarget`, RTTI/type name checks (`strstr` / `type_info::name`). Summon-specific cast execution glue on HB tick — not generic LocalCastValidate.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00521650_Skill_CVOGHBSkill_Summon.md` (or `aa_00521650_FUN_00521650.md`) |
| Annotated | `docs/reconstruction/raw/aa_00521650_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_CVOGHBSkill_Summon.cpp` |
| Function record | `docs/reconstruction/functions/aa_00521650_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `String CVOGHBSkill_Summon` | High | Rename |
| `EnsureLoadedInTree` | High | Callee |
| `LookupActiveCastBinding` | High | Callee |
| `CastSkillOnTarget path` | High | Callee |
| `RTTI name checks` | High | type_info/strstr |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Load skill → bind → cast/summon CF | Yes |
| No invented inventory | Yes |

---

## 5. Gaps / open

1. Summon template cbid source.
2. HB period vs cast time.

**Verdict:** **accept-with-gaps**
