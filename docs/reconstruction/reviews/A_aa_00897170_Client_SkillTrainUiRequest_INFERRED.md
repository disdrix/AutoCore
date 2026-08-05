# Review A (reconstruction fidelity): `aa_00897170` Client_SkillTrainUiRequest_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_00897170` |
| **VA** | `0x00897170` |
| **Canonical name** | `Client_SkillTrainUiRequest_INFERRED` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00897170_Client_SkillTrainUiRequest_INFERRED.md` |
| **System tag** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_SkillTrainUiRequest_INFERRED.cpp` |
| Raw | `docs/reconstruction/raw/aa_00897170_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Skill-train UI request. Gates: FUN_0052dc20 availability; rank skill+0x5f6 < max@+0x5f4 and < 0x32; level/skill-point checks. On first-rank train of active skill, auto-maps first empty QuickBar slot (item COID both 0xFFFFFFFF and skillId==-1), CVOGCharacter_SetQuickBarSkill, sends **QuickBarUpdate 0x2062** + **SkillIncrement 0x2059**. Toasts for unavailable/SP/level/max. Name INFERRED; full prereq UI outside QB surface open.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Availability FUN_0052dc20 / hash skill def | High | Plate |
| Rank +0x5f6 vs max +0x5f4 and <0x32 | High | Plate |
| Empty QB: item COID FFFFFFFF and skillId -1 | High | Plate |
| SetQuickBarSkill then 0x2062 + 0x2059 | High | Plate + callees |
| Failure toasts SP/level/unavailable/max | High | Strings |
| MaybeShowFirstTimeTip | High | Callee |
| INFERRED name / partial RE | Tentative | Plate tag |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| gates → optional QB auto-slot → send 0x2062/0x2059 or toast fail | Yes |

---

## 4. Gaps

1. Full prereq matrix beyond plate.
2. When first-rank auto-QB is skipped.

**Verdict:** **accept-with-gaps**
