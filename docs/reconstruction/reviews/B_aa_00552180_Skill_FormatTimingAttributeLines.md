# Review B (skeptical / adversarial): `aa_00552180` Skill_FormatTimingAttributeLines

| Field | Value |
|---|---|
| **Stable ID** | `aa_00552180` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00552180_Skill_FormatTimingAttributeLines.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Parses tokens from stream | Falsified — emit lines; Parse is sibling |
| 2 | Changes cooldown | Falsified |
| 3 | Finished constants | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Attribute set | High | Missing UI fields |
| Infinite markers | High | Wrong display |
| Caller context | Tentative | Debug vs UI mix |

---

## 3. Cross-check against raw

```
emit cast_time/cooldown/duration/pulse/power/range/tether lines.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
FormatTimingAttributeLines(skill, out):
  timing tooltip/debug; pair ParseTimingAttributeToken
  AutoCore skill detail pane
```

---

## 5. Open questions

1. Seal infinite/instant thresholds.
2. Split debug vs player UI if dual callers.

**Verdict:** **accept-with-gaps**
