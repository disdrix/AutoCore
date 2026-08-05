# Review B (skeptical / adversarial): `aa_007f4c50` DB_ReadPowerPlantSpecific

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f4c50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007f4c50_DB_ReadPowerPlantSpecific.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Reads weapon heat only | Falsified — plant heat max + power + rates |
| 2 | Is Vehicle_EquipPowerPlant | Falsified — DB row load only |
| 3 | Out struct larger than 0xC | Falsified — plate 0xC |
| 4 | Always succeeds | Falsified — inactive / bind fail paths |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0xC field order | High | Swapped cool/power regen |
| Clonebase +0xB0..+0xBA map | High | Wrong tick rates |
| IDCloneBase key | High | Wrong plant row |

---

## 3. Cross-check against raw

```
DB_ReadPowerPlantSpecific(db, ctx, out):
  if inactive: error
  SELECT HeatMax, PowerMax, PowerRegen, CoolRate WHERE IDCloneBase=?
  fill out 0xC
Clean CF ≡ raw; COM helpers residual.
```

---

## 4. Surviving contract for AutoCore

```
Power-plant specific table load for AutoCore clonebase / vehicle pools.
  Must feed GetPowerRegenRate / GetCoolRate / heat max.
```

---

## 5. Open questions

1. Cross-check Vehicle_GetPowerRegenRate plant+0xB8.
2. Import retail tPowerPlant samples.

**Verdict:** **accept-with-gaps**
