# Review B (skeptical / adversarial): `aa_00597f90` VehicleAction_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00597f90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00597f90_VehicleAction_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Builds full hk framework | Falsified — ctor only |
| 2 | Finished field map | Overstated |
| 3 | No EH | Falsified |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor identity | High | Wrong action object |
| Param wiring | Medium | Bad framework link |
| Member init completeness | Medium | Uninit fields |

---

## 3. Cross-check against raw

```
ctor: EH + FUN_00636370 + global stamps + member init.
Clean ≡ raw outline; param roles residual.
```

---

## 4. Surviving contract for AutoCore

```
VehicleAction_ctor(this, …):
  action object init; pair createVehicleAction / framework
  AutoCore vehicle physics spawn
```

---

## 5. Open questions

1. Document +0x1a0 handle layout after ctor.
2. Name DAT_* stamped fields.

**Verdict:** **accept-with-gaps**
