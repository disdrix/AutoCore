# Review B (skeptical / adversarial): `aa_004f7360` Vehicle_CalcHeatMaximum

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004f7360_Vehicle_CalcHeatMaximum.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Fixed 100 heat | Falsified — multi-term |
| 2 | Writes current heat | Falsified — returns max only |
| 3 | Finished table seal | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Plant capacity term | High | Wrong max heat |
| Race/level tables | High | Level-up heat wrong |
| DAT tables | Tentative | Off-by table |

---

## 3. Cross-check against raw

```
combine plant + race/class tables + +0x1e0 → ceil MaxHeat.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
CalcHeatMaximum(veh) → maxHeat:
  pair EquipPowerPlant / AddHeat clamp
  AutoCore heat pools
```

---

## 5. Open questions

1. Export tables for unit tests.
2. Diff vs client heat bar max.

**Verdict:** **accept-with-gaps**
