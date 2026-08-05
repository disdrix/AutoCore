# Review B (skeptical / adversarial): `aa_005a8a90` Drive_CVOGVehicle_UpdateWaterFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a8a90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005a8a90_Drive_CVOGVehicle_UpdateWaterFX.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Authoritative buoyancy | Falsified — FX |
| 2 | Writes drive controller | Falsified — no axes push |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| FX-only scope | High | Wrong physics port |
| Trigger thresholds | Tentative | Missing splash |

---

## 3. Cross-check against raw

```
sample vehicle vs water; update splash/wake FX helpers.
Clean ≡ raw CF; helpers residual.
```

---

## 4. Surviving contract for AutoCore

```
UpdateWaterFX(vehicle,...):
  client VFX only
  AutoCore server: N/A
```

---

## 5. Open questions

1. Name FX helpers.
2. Water height source seal.

**Verdict:** **accept-with-gaps**
