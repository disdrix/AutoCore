# Review B (skeptical / adversarial): `aa_00824140` UI_SkillPanel_BindAvailableButtons

| Field | Value |
|---|---|
| **Stable ID** | `aa_00824140` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00824140_UI_SkillPanel_BindAvailableButtons.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Casts skill | Falsified — UI bind |
| 2 | Server train | Falsified |
| 3 | Finished filter | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Available button set | High | Empty skill panel |
| XML assets | High | Missing UI |
| Availability rules | Tentative | Wrong listed skills |

---

## 3. Cross-check against raw

```
bind available skill buttons from XML templates.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
UI_SkillPanel_BindAvailableButtons(panel):
  skill UI chrome; pair QuickBar_BuildSkillButtonWidgets
  AutoCore client skill panel
```

---

## 5. Open questions

1. Seal availability filter.
2. Refresh after rank-up.

**Verdict:** **accept-with-gaps**
