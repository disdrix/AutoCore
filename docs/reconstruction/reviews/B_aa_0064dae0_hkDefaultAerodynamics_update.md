# Review B (skeptical / adversarial): `aa_0064dae0` hkDefaultAerodynamics_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064dae0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0064dae0_hkDefaultAerodynamics_update.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Computed inside applyAction directly | Falsified — child of tickSubsystems |
| 2 | Is airStabilization AA helper | Falsified — stock aero child |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Coeff offsets | High | Wrong top speed feel |
| Child tick participation | High | Missing drag |

---

## 3. Cross-check against raw

```
aero.update(this):
  framework-backed chassis velocity → drag/lift forces.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Aero child for vehicle framework; AutoCore BuildAerodynamicsDescriptor feeds it.
```

---

## 5. Open questions

1. Live-diff aero at speed.

**Verdict:** accept-with-gaps
