# Review B (skeptical / adversarial): `aa_004fe1b0` Vehicle_EquipPowerPlant

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe1b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004fe1b0_Vehicle_EquipPowerPlant.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Armor hardpoint | Falsified — power plant +0x268 |
| 2 | Format only | Falsified — mutator |
| 3 | No heat recalc | Falsified |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x268 / type 10 | High | Wrong equip |
| Heat +0x244 | High | Wrong heat pool |
| Notify cascade | Tentative | Stale UI/state |

---

## 3. Cross-check against raw

```
swap +0x268; type10; bind; COID; CalcHeatMaximum.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
EquipPowerPlant(veh, plant, outPrev?):
  hardpoint mutator; pair InventoryEquip 0x203C / EquipFromCreate
  AutoCore vehicle power plant equip
```

---

## 5. Open questions

1. Seal notify side effects.
2. Live equip packet capture.

**Verdict:** **accept-with-gaps**
