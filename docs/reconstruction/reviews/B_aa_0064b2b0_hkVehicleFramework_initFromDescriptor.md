# Review B (skeptical / adversarial): `aa_0064b2b0` hkVehicleFramework_initFromDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064b2b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0064b2b0_hkVehicleFramework_initFromDescriptor.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runs every applyAction tick | Falsified — ctor/init only |
| 2 | Applies drive torque | Falsified — precompute only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Inertia precompute | High | Wrong handling |
| Contact aggregate | High | Friction solver wrong inputs |

---

## 3. Cross-check against raw

```
initFromDescriptor(fw, desc):
  inverse inertia; solver ratios; per-wheel rest geometry → +0x1fc.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
One-shot framework math setup for AutoCore Havok port parity.
```

---

## 5. Open questions

1. Unit-test inertia numbers vs sample clonebase.

**Verdict:** accept-with-gaps
