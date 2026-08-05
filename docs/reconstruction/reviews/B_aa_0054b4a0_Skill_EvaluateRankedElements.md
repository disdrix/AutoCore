# Review B (skeptical / adversarial): `aa_0054b4a0` Skill_EvaluateRankedElements

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054b4a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0054b4a0_Skill_EvaluateRankedElements.md` |
| **Verdict** | **accept-with-gaps**; equation table open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Ignores rank | Falsified — rank offset used |
| 2 | Only formats tooltip | Falsified — writes runtime |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CD +0x10 ms | High | Wrong recharge |
| Rank scaling | High | Wrong power |
| Equation type table | Tentative | Miss element |

---

## 3. Cross-check against raw

```
for elements at rank: eval equation → cost/cd/charge/range/dmg fields.
Clean ≡ raw CF; type table residual.
```

---

## 4. Surviving contract for AutoCore

```
EvaluateRankedElements(skill, rankOffset):
  recompute runtime from template at rank
  pair CopyRuntimeFieldsFromTemplate + SetRank
```

---

## 5. Open questions

1. Publish equation type enum.
2. Live rank-up recompute capture.

**Verdict:** **accept-with-gaps**; equation table open
