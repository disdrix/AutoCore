# Review B (skeptical / adversarial): `aa_004c3ff0` Character_GetTechForPoolCalcs

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3ff0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004c3ff0_Character_GetTechForPoolCalcs.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Uncapped tech can exceed 250 | Falsified — hard 250 |
| 2 | Raw tech used without 200 cap | Falsified — min(Tech,200) before bonus |
| 3 | Returns float | Falsified — int |
| 4 | Reads vehicle plant fields | Falsified — character only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x13c / +0x144 | High | Wrong pool base |
| [1,250] clamp | High | HP pool explode/zero |
| 200 pre-cap | High | Overbuff tech |

---

## 3. Cross-check against raw

```
GetTechForPoolCalcs(char):
  t = min(Tech(+0x13c), 200) + bonus(+0x144)
  if t < 2: return 1
  if t < 250: return t
  return 250
Clean ≡ raw (redundant re-caps).
```

---

## 4. Surviving contract for AutoCore

```
Tech input for player vehicle max HP / pool calcs.
  AutoCore VehicleHitPointCalculator must match clamps.
```

---

## 5. Open questions

1. Unit-test boundaries 0/1/199/200/201 + bonus.
2. Trace who writes +0x144 bonus.

**Verdict:** **accept-with-gaps**
