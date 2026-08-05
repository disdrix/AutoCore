# Review B (skeptical / adversarial): `aa_005fe020` hkDefaultAnalogDriverInput_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe020` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005fe020_hkDefaultAnalogDriverInput_ctor.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Applies driver throttle/steer each tick | Falsified — construction + desc bake only |
| 2 | Ignores descriptor | Falsified — copies and derives slope from desc |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor seeds + vtbl | High | Broken analog deadzone |
| Slope formula bit-exact | High | Bad input curve |

---

## 3. Cross-check against raw

```
ctor(this, desc): zero flags; vtbl; copy desc[0,1,2]+flag; slope = b*(a-c); intercept = (1-slope)/((1-c)-(a-c)); return.
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
Analog driver-input component construction for Havok vehicle DI path.
```

---

## 5. Open questions

1. Confirm deadzone field English vs reflection strings.
2. Runtime DI sample when Launcher approved.

**Verdict:** accept-with-gaps
