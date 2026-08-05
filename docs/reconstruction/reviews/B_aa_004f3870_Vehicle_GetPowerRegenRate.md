# Review B (skeptical / adversarial): `aa_004f3870` Vehicle_GetPowerRegenRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3870` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004f3870_Vehicle_GetPowerRegenRate.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Returns 0 without plant | Falsified — returns 1 |
| 2 | Applies UI scale | Falsified — raw points only |
| 3 | Reads race-item | Falsified — plant only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| plant+0xB8 rate | High | Wrong power regen |
| Default 1 without plant | High | Zero power creep / stall |
| +0x268 plant ptr | High | Wrong equip slot |

---

## 3. Cross-check against raw

```
if plant: return (int)plant.nPowerRegenRate; else 1.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
GetPowerRegenRate(veh) → plant power regen or 1:
  pure getter for combat-pool OnTick
  AutoCore vehicle power regen pulse
```

---

## 5. Open questions

1. Unit-test no-plant default 1.
2. Xref EquipPowerPlant writes to +0x268.

**Verdict:** **accept**
