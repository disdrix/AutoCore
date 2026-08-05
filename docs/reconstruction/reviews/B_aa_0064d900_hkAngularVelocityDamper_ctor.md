# Review B (skeptical / adversarial): `aa_0064d900` hkAngularVelocityDamper_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064d900` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0064d900_hkAngularVelocityDamper_ctor.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Computes per-tick damping | Falsified — construction only |
| 2 | Allocates heap | Falsified — caller allocates 0x14 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Field order normal/collision/threshold | High | Swapped feel |
| Instance size 0x14 external | High | Overrun |

---

## 3. Cross-check against raw

```
ctor: flag=1; vtbl; this+8..10 = desc[0..2]; ret.
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
AVD action construction for framework build chain.
```

---

## 5. Open questions

1. Pair with buildHavokVehicleFramework AVD inline desc.

**Verdict:** accept-with-gaps
