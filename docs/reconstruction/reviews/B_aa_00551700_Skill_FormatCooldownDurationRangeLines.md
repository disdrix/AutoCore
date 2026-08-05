# Review B (skeptical / adversarial): `aa_00551700` Skill_FormatCooldownDurationRangeLines

| Field | Value |
|---|---|
| **Stable ID** | `aa_00551700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00551700_Skill_FormatCooldownDurationRangeLines.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Server combat math | Falsified — tooltip format |
| 2 | Cooldown only | Falsified — multi metric |
| 3 | Tiny | Falsified — large CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Metric labels | High | Wrong skill UI |
| Range min-max | High | Bad range display |
| Offsets complete | Tentative | Misread values |

---

## 3. Cross-check against raw

```
if metric live: append Cooldown/Duration/Power/Range/… lines.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
FormatCooldownDurationRangeLines(skill, buf):
  compact combat tooltip; pair TimingAttributeLines
  AutoCore client skill pane
```

---

## 5. Open questions

1. Map each line to runtime field.
2. Compare live tooltip text.

**Verdict:** **accept-with-gaps**
