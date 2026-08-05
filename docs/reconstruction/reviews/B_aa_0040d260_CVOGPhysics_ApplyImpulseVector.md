# Review B (skeptical / adversarial): `CVOGPhysics_ApplyImpulseVector` @ `0x0040d260`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0040d260_CVOGPhysics_ApplyImpulseVector.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always no-op if body null unchecked | Attack — need null path seal |
| 2 | Angular impulse on same vtbl | Falsified for this helper — linear path |
| 3 | Creates rigid body | Falsified — uses existing +0x3c |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| body +0x3c / vtbl+0x50 | High | No motion / crash |
| Readiness +0x44 path | Medium | Dropped impulse |
| Vec layout | Tentative | Bad push direction |

---

## 3. Cross-check against raw

```
probe ready; maybe prepare(+0x44); body=*(+0x3c); (*vtbl+0x50)(vec).
```

---

## 4. Surviving contract for AutoCore

```
ApplyImpulseVector(phys, vec):
  ensure ready; body = phys.rigid(+0x3c)
  body->setLinearVelOrImpulse(vec)  // vtbl+0x50
  network soft-apply + boost/airStab consumers
```

---

## 5. Open questions

1. Confirm Havok method at vtbl+0x50.
2. Null body behavior.

**Verdict:** **accept-with-gaps**
