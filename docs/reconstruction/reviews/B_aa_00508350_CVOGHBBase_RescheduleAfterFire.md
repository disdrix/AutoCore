# Review B (skeptical / adversarial): `aa_00508350` CVOGHBBase_RescheduleAfterFire

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00508350_CVOGHBBase_RescheduleAfterFire.md` |
| **Verdict** | **accept-with-gaps** on CF; contract High vs 16ms myth |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Sets combat regen to 16ms | **Falsified — 16 is list status/delay token; regen period separate** |
| 2 | Always zeros delay | **Falsified — counter exhaust path** |
| 3 | Stamps last fire | **Falsified — sibling StampLastFireTime** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| -1000 combat path | High | Wrong pool cadence |
| Counter burst semantics | Tentative | Too many/few fires |
| 16 token meaning | High | Confused with period |

---

## 3. Cross-check against raw

```
if sentinel==-1000: *out=0 Continue
else counter--; *out = counter>0 ? 0 : 16
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
RescheduleAfterFire(hb, &nextDelay):
  combat-pool sentinel keeps Continue; else countdown period counter
  list uses nextDelay; combat 3s/5s is nPeriodMs in TryFire
  AutoCore must not reschedule regen every 16ms
```

---

## 5. Open questions

1. Unify field names nPeriodSentinel vs nPeriodMs in types.
2. Who SetPeriodAndCounter pairs with.

**Verdict:** **accept-with-gaps** on CF; contract High vs 16ms myth
