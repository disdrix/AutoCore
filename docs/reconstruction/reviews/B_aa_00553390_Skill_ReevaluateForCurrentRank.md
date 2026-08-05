# Review B (skeptical / adversarial): `aa_00553390` Skill_ReevaluateForCurrentRank

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553390` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00553390_Skill_ReevaluateForCurrentRank.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Changes player rank permanently server-side | Falsified — local recompute |
| 2 | Skips EvaluateRankedElements | Falsified — calls it |
| 3 | Only nulls skill | Falsified |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| id+rank args | High | Wrong scaled CD/power |
| +0x624 targeting | High | Bad target filter |
| FUN_00627be0 | Tentative | Missed side effect |

---

## 3. Cross-check against raw

```
EvaluateRankedElements(id, rank); update +0x624.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
ReevaluateForCurrentRank(skill):
  recompute scaled elements for +0x5f6
  pair EvaluateRankedElements + SetRankAndReevaluate
  AutoCore must re-run after rank change
```

---

## 5. Open questions

1. Document +0x624 bits.
2. Name FUN_00627be0.

**Verdict:** **accept-with-gaps**
