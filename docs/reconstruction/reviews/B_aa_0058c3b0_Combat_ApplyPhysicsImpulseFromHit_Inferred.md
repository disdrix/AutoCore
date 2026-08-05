# Review B (skeptical / adversarial): `aa_0058c3b0` Combat_ApplyPhysicsImpulseFromHit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058c3b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058c3b0_Combat_ApplyPhysicsImpulseFromHit_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Modifies HP/shield pools | No pool vtbls; only phys | **Falsified** as damage |
| 2 | Always applies impulse | Null target / null phys / gate fails return | **Survives** as gated |
| 3 | Attacker must be physics | Cast fail → zero orient, still may impulse target | **Survives** soft attacker |
| 4 | Same as `004d78e0` | Nested helper only | **Falsified** merge |
| 5 | Character flag skip is death | Flag `+0x6b9` semantics open | **Survives** as Probable gap |

---

## 2. Live ≡ raw

Live matches RTTI casts, type 0xe branch, normalize/scale, `0058d980`. Parent `004d78e0` dual labels this as type-3 phys impulse.

---

## 3. Surviving contract

```
// cast attacker/target to CVOGPhysicsBase (vehicle type 0xe special)
// build direction (forward or target−attacker), scale by param_3 + Y boost
// if phys body live and gates clear: ApplyImpulse(dir, bodyPoint+param_4)
```

**Gaps kept:** gate helper names; eps constant; flag +0x6b9 meaning.

**Verdict:** **accept-with-gaps**.
