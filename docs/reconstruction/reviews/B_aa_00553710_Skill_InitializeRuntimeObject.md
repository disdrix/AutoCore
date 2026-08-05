# Review B (skeptical / adversarial): `aa_00553710` Skill_InitializeRuntimeObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553710` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00553710_Skill_InitializeRuntimeObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only sets rank | Falsified — multi-field init |
| 2 | Skips reevaluate | Falsified — always calls |
| 3 | Finished all offsets | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Key offsets +0x5e8/+0x5fc/+0x614 | High | Broken cast |
| Defer +0x61c | High | Wrong cast-again |
| Full zero table | Tentative | Stale fields |

---

## 3. Cross-check against raw

```
init id/cat/flags; clear cast; maybe defer +0x61c; ReevaluateForCurrentRank.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
InitializeRuntimeObject(skill, template…):
  runtime from template + rank reeval
  pair CopyRuntimeFieldsFromTemplate / SetRankAndReevaluate
  AutoCore skill runtime spawn path
```

---

## 5. Open questions

1. Seal remaining cleared fields.
2. Name FUN_00418820.

**Verdict:** **accept-with-gaps**
