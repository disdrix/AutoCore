# Review B (skeptical / adversarial): `aa_00553130` Skill_LocalRangeTargetCheck

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553130` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00553130_Skill_LocalRangeTargetCheck.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always 0 | Falsified — multi-code |
| 2 | Server LOS authority | Falsified — local |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Range metric | High | Cast in/out of range wrong |
| Fail codes | High | Wrong toast |
| RandomUnitScalar role | Tentative | Nondeterminism |

---

## 3. Cross-check against raw

```
if target in range/filters: 0 else eSkillResponses code.
Clean ≡ raw CF outline.
```

---

## 4. Surviving contract for AutoCore

```
LocalRangeTargetCheck(...):
  local range gate for cast UX
  pair LocalCastValidate
  AutoCore client: match before C2S cast
```

---

## 5. Open questions

1. Seal distance formula.
2. Code table vs FormatFailureMessage.

**Verdict:** **accept-with-gaps**
