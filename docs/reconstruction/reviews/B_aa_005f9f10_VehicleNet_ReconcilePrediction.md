# Review B (skeptical / adversarial): `aa_005f9f10` VehicleNet_ReconcilePrediction

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f9f10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005f9f10_VehicleNet_ReconcilePrediction.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is ghost initial pack/unpack | Falsified |
| 2 | Finished blend policy | Overstated |
| 3 | Server-authoritative sim step | Overstated — client reconcile |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Reconcile entry identity | High | Desync unfixed |
| Correction payload contract | High | Bad snaps |
| Blend policy | Medium | Jitter / rubber-band |

---

## 3. Cross-check against raw

```
reconcile prediction against correction/replay inputs.
Clean outline ≡ raw; policy residual.
```

---

## 4. Surviving contract for AutoCore

```
ReconcilePrediction(…):
  client prediction realign; pair TriggerReplay / PostCorrectionEvent
  AutoCore vehicle net prediction
```

---

## 5. Open questions

1. Diff live rubber-banding cases.
2. Map PostCorrectionEvent fields.

**Verdict:** **accept-with-gaps**
