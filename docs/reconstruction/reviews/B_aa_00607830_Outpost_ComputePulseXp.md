# Review B (skeptical / adversarial): `aa_00607830` Outpost_ComputePulseXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_00607830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00607830_Outpost_ComputePulseXp.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Awards kill XP | Falsified — pulse path |
| 2 | Always uses true-outpost table | Falsified — sibling selects table |
| 3 | Writes XP onto character here | Falsified — returns amount only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x238 gate / +0x21c scalar | High | Wrong or zero pulse |
| Span via cumulative thresholds | High | Wrong amount scale |
| x87 round helper | Medium | Off-by-one XP |

---

## 3. Cross-check against raw

```
ComputePulseXp(outpost, char):
  if +0x238 < 1: return 0
  thrHi/thrLo from GetCumulativeThreshold(level[/ -1])
  percent = GetPulseXpPercent; return round(span*percent*scalar)
FPU residual on helper args.
```

---

## 4. Surviving contract for AutoCore

```
Outpost pulse XP amount for AutoCore idle/capture rewards.
```

---

## 5. Open questions

1. Live-diff one pulse tick amount at known level.

**Verdict:** **accept-with-gaps**
