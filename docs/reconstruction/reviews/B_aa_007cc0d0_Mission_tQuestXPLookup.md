# Review B (skeptical / adversarial): `aa_007cc0d0` Mission_tQuestXPLookup

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cc0d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007cc0d0_Mission_tQuestXPLookup.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runtime mission fail notify | Falsified — table load |
| 2 | Player cumulative thresholds | Falsified — quest fractions |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fraction field type/offset | High | Wrong mission XP |
| Loader success path | Medium | Empty quest XP |

---

## 3. Cross-check against raw

```
Mission_tQuestXPLookup(mapCtx):
  load //tQuestXPLookup/row
EnsureQuest callee. Residual COM.
```

---

## 4. Surviving contract for AutoCore

```
Mission XPIndex fraction table for AutoCore mission awards.
```

---

## 5. Open questions

1. Import sample indices 0..9 from XP.md.

**Verdict:** **accept-with-gaps**
