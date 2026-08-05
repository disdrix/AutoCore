# Review B (skeptical / adversarial): `aa_00553480` Skill_CopyRuntimeFieldsFromTemplate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553480` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00553480_Skill_CopyRuntimeFieldsFromTemplate.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Deep-copies entire object blindly | Overstated — selected fields |
| 2 | Skips reevaluate | Falsified — calls reevaluate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag/channel copies | High | Broken skill instance |
| Clear casting on copy | High | Stuck cast on new skill |
| Rank float→short | Tentative | Rank off-by |

---

## 3. Cross-check against raw

```
memcpy selected runtime fields from template; clear cast; ReevaluateForCurrentRank.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
CopyRuntimeFieldsFromTemplate(runtime, template):
  skill instantiate
  pair EvaluateRankedElements / SetRank
```

---

## 5. Open questions

1. Document each offset meaning.

**Verdict:** **accept-with-gaps**
