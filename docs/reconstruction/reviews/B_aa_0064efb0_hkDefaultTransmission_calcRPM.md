# Review B (skeptical / adversarial): `aa_0064efb0` hkDefaultTransmission_calcRPM

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064efb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0064efb0_hkDefaultTransmission_calcRPM.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Writes wheel torque +0x28 | Falsified — RPM only |
| 2 | Is torqueCurve2D | Falsified — separate AA table |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RPM source fields | High | Wrong tach / shift |

---

## 3. Cross-check against raw

```
calcRPM(trans): aggregate wheel spins → RPM.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
RPM helper; AutoCore torque still via AA calcWheelTorque.
```

---

## 5. Open questions

1. UI tach binding xref.

**Verdict:** accept-with-gaps
