# Review B (skeptical / adversarial): `aa_005535a0` Skill_SetRankAndReevaluate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005535a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005535a0_Skill_SetRankAndReevaluate.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Complex multi-branch | Falsified — two ops |
| 2 | Does not reevaluate | Falsified |
| 3 | Writes +0x5fc id | Falsified — rank only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x5f6 store | High | Stale rank |
| Reevaluate always | High | Scaled stats stale |
| Temp rank restore discipline | Tentative | Sticky wrong rank |

---

## 3. Cross-check against raw

```
skill+0x5f6 = rank; ReevaluateForCurrentRank(skill).
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SetRankAndReevaluate(skill, rank):
  +0x5f6 then reeval; pair train UI + formatters
  AutoCore: careful with temp tooltip rank
```

---

## 5. Open questions

1. Audit callers for rank restore.
2. Server skill rank ownership.

**Verdict:** **accept**
