# Review A (reconstruction fidelity): `aa_00824140` UI_SkillPanel_BindAvailableButtons

| Field | Value |
|---|---|
| **Stable ID** | `aa_00824140` |
| **VA** | `0x00824140` |
| **Canonical name** | `UI_SkillPanel_BindAvailableButtons` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00824140_UI_SkillPanel_BindAvailableButtons.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bind skill-panel available-skill buttons from `i_d_s_2d_btn_skill_available` / `btn.xml` templates. UI construction/bind only — walks available skills and attaches widgets. Not cast validation or train authority.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00824140_UI_SkillPanel_BindAvailableButtons.md` (or `aa_00824140_FUN_00824140.md`) |
| Annotated | `docs/reconstruction/raw/aa_00824140_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_SkillPanel_BindAvailableButtons.cpp` |
| Function record | `docs/reconstruction/functions/aa_00824140_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `XML skill_available templates` | High | Plate |
| `Binds available skill buttons` | High | Name + purpose |
| `UI only` | High | No cast |
| `Full skill filter rules` | Medium | Body partial |
| `Widget slot offsets` | Medium | UI residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Create/bind available buttons from XML | Yes |
| No train packet send in bind | Yes |

---

## 5. Gaps / open

1. Which skills qualify as available.
2. Refresh triggers after train.

**Verdict:** **accept-with-gaps**
