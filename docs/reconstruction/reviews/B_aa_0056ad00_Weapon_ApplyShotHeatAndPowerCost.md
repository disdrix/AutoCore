# Review B (skeptical / adversarial): `aa_0056ad00` Weapon_ApplyShotHeatAndPowerCost

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056ad00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0056ad00_Weapon_ApplyShotHeatAndPowerCost.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always charges NPCs same way | Falsified — 0xE gate |
| 2 | Skips heat check | Falsified — CanFire first |
| 3 | Power always required | Falsified — only if +0xD6>0 |
| 4 | Uses cool rate here | Falsified — AddHeat only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0xE gate | High | NPC/player mismatch |
| Order heatcheck→power→heat | High | Spend power when overheated |
| +0xD4/+0xD6 fields | High | Wrong costs |

---

## 3. Cross-check against raw

```
ApplyShotHeatAndPowerCost(wpn):
  if owner type!=0xE: return 1;
  if !CanFireHeatCheck: return 0;
  optional power debit +0xD6; AddHeat(+0xD4); return 1.
```

---

## 4. Surviving contract for AutoCore

```
Client shot cost applicator. AutoCore fire path must:
  overheat gate, optional power, then heat add with same offsets.
```

---

## 5. Open questions

1. Integration test with Vehicle_AddHeat mask 0x20000000 dirty.
2. Confirm server authority vs client prediction.

**Verdict:** **accept-with-gaps**
