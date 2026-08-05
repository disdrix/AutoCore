# Review B (skeptical / adversarial): `aa_005f9ed0` VehicleNet_TriggerReplay

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f9ed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005f9ed0_VehicleNet_TriggerReplay.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Unpacks ghost vehicle | Falsified — raw buffer clone |
| 2 | In-place mutate without alloc | Falsified — malloc |
| 3 | Finished queue contract | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Buffer clone CF | High | Lost correction payload |
| Size param honesty | High | Overflow / undercopy |
| Queue handoff | Medium | Leak / drop |

---

## 3. Cross-check against raw

```
p=malloc(n); memcpy(p, src, n); (handoff residual).
Clean copy CF ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
TriggerReplay(src, …, n):
  clone blob for prediction replay; pair ReconcilePrediction
  AutoCore client prediction / correction
```

---

## 5. Open questions

1. Document consumer free.
2. Diff with PostCorrectionEvent.

**Verdict:** **accept-with-gaps**
