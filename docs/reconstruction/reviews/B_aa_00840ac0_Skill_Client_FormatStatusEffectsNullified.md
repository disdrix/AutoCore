# Review B (skeptical / adversarial): `aa_00840ac0` Skill_Client_FormatStatusEffectsNullified

| Field | Value |
|---|---|
| **Stable ID** | `aa_00840ac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00840ac0_Skill_Client_FormatStatusEffectsNullified.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Applies cleanse server-side | Falsified — client format |
| 2 | Tiny stub | Falsified — large CF |
| 3 | Finished bit-exact | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Nullify tooltip exists | High | Missing combat log line |
| Not apply path | High | Wrong port layer |
| Full name list source | Tentative | Incomplete toast |

---

## 3. Cross-check against raw

```
format Status Effects Nullified line via rank + target-filter helpers.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
FormatStatusEffectsNullified(skill/ctx):
  tooltip/combat log only; pair FormatTargetFilterTooltip
  AutoCore: client UX; server cleanse separate
```

---

## 5. Open questions

1. Seal selector flags for this formatter.
2. Capture live nullify log line.

**Verdict:** **accept-with-gaps**
