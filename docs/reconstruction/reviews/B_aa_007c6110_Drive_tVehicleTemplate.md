# Review B (skeptical / adversarial): `aa_007c6110` Drive_tVehicleTemplate

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c6110` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007c6110_Drive_tVehicleTemplate.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | hkDefaultBrake_update runtime | Falsified — data load |
| 2 | Player input tick | Falsified — template table |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Template schema | High | Wrong vehicle feel |
| ID key to clonebase vehicle | Medium | Missed template |

---

## 3. Cross-check against raw

```
Drive_tVehicleTemplate: load //tVehicleTemplate/row
Residual COM. Clean ≡ raw shape.
```

---

## 4. Surviving contract for AutoCore

```
Vehicle template bring-up for AutoCore vehicle create.
```

---

## 5. Open questions

1. Cross-check template fields vs descriptor builders.

**Verdict:** **accept-with-gaps**
