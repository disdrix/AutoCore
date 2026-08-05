# Review B (skeptical / adversarial): `aa_0052dec0` Experience_XpToReachRelativeLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052dec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0052dec0_Experience_XpToReachRelativeLevel.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always returns non-negative | Falsified — de-level can be negative |
| 2 | Uses creature XP table | Falsified — GetCumulativeThreshold |
| 3 | Writes level onto character | Falsified — pure amount compute |
| 4 | Threshold key is cur+delta not -1 | Falsified — clean uses -1 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0xc54 / +0x730 offsets | High | Wrong award size |
| Threshold index -1 | High | Off-by-one levels |
| GetLevel vtbl slot | High | Wrong level source |

---

## 3. Cross-check against raw

```
XpToReachRelativeLevel(char, delta):
  L = GetLevel(+0x27c)
  if L+delta < 1: return 0
  thr = GetCumulativeThreshold(L+delta-1)
  return (int)(thr / *(float)(char+0xc54)) - *(int)(char+0x730) + 1
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
Relative-level XP grant amount for reactions / mission min-level catch-up.
  AutoCore must preserve formula and field offsets.
```

---

## 5. Open questions

1. Live-diff one SetLevel reaction amount.
2. Document personal gain default initialization.

**Verdict:** **accept-with-gaps**
