# Review B (skeptical / adversarial): `aa_0064fac0` hkDefaultSteering_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0064fac0_hkDefaultSteering_ctor.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Applies steer angles each tick | Falsified — ctor; update 0x64f840 |
| 2 | Is tank-only | Falsified — wheeled default; tank subclasses |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Desc → maxAngle/fullSpeed | High | Wrong steer limit |
| Base thiscall | High | Broken component |

---

## 3. Cross-check against raw

```
steer.ctor: base; vtbl; empty doesWheelSteer; FUN_0064f920(desc); return;
Clean ≡ raw CF (fresh batch_decompile 2026-07-29).
```

---

## 4. Surviving contract for AutoCore

```
Default steering construction (wheeled); shared parent of TankSteering.
```

---

## 5. Open questions

1. Pair steering update dual present.

**Verdict:** accept-with-gaps
