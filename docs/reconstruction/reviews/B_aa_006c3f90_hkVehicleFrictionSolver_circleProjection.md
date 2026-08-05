# Review B (skeptical / adversarial): `aa_006c3f90` hkVehicleFrictionSolver_circleProjection

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c3f90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_006c3f90_hkVehicleFrictionSolver_circleProjection.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is full friction solve | Falsified — projection helper only |
| 2 | Applies chassis impulse | Falsified — mutates force pair in place |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Circle clamp math | High | Tire force explode |
| Table identity | Medium | Scale wrong |

---

## 3. Cross-check against raw

```
circleProjection(state, out):
  if scaled force outside unit circle: table walk + blend; rewrite +0x80/+0x84.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Friction force saturation helper for solver.solve.
```

---

## 5. Open questions

1. Unit-test synthetic force pairs.

**Verdict:** accept-with-gaps
