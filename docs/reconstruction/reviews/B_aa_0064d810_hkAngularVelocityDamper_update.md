# Review B (skeptical / adversarial): `aa_0064d810` hkAngularVelocityDamper_update

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064d810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0064d810_hkAngularVelocityDamper_update.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is air-stab upright restore | Falsified — pure spin damping scale; air-stab is 0x598320 |
| 2 | Adds torque impulses | Falsified — scales existing angVel only |
| 3 | Threshold is linear speed | Falsified — |w|² vs threshold² |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Damping selection branch | High | Wrong spin feel in collision |
| Context chassis→RB chain | High | Null/wrong body |

---

## 3. Cross-check against raw

```
ctx.body = *(param_3+0x30); rb=*(body+0x3c); w=rb.angVel;
if |w|^2 <= thr^2: d=normal else collision; s=max(0,1-d*dt); setAngVel(w*s).
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
Continuous angular-velocity scale damper (Havok AVD action).
```

---

## 5. Open questions

1. Pair runtime with air-stab isolation tests.
2. Helper assert path residual.

**Verdict:** accept-with-gaps
