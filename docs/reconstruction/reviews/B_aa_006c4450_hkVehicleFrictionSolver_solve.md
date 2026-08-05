# Review B (skeptical / adversarial): `aa_006c4450` hkVehicleFrictionSolver_solve

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c4450` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_006c4450_hkVehicleFrictionSolver_solve.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is applyAction itself | Falsified — lower-level solver |
| 2 | Replaces calcWheelTorque | Falsified — friction vs drive torque |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Solver participation each tick | High | Ice/slide wrong |
| Param buffer layout | High | Memory smash risk in port |

---

## 3. Cross-check against raw

```
solve(state, ...):
  friction iteration + circleProjection → contact forces for postTick.
Clean large ≡ raw CF; naming residual.
```

---

## 4. Surviving contract for AutoCore

```
Friction core under postTickApplyForces; port with caution (size).
```

---

## 5. Open questions

1. Stryker/targeted tests on friction edge cases.

**Verdict:** accept-with-gaps
