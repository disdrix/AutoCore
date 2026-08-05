# Review B (skeptical / adversarial): `aa_00502460` Vehicle_SetEquippedRaceItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502460` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00502460_Vehicle_SetEquippedRaceItem.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Armor +0x254 | Falsified — race +0x270 |
| 2 | No type check | Falsified |
| 3 | Finished combat effect list | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x270 / subtype | High | Wrong race equip |
| Recalc pools | High | Stale HP/armor |
| Subtype chase | Tentative | False reject |

---

## 3. Cross-check against raw

```
set +0x270; type6+0xb; bind; RecalcCombatPools.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SetEquippedRaceItem(veh, item, outPrev?):
  race hardpoint; pair EquipFromCreate / InventoryEquip
  AutoCore vehicle race item
```

---

## 5. Open questions

1. Document race combat modifiers.
2. Live equip capture.

**Verdict:** **accept-with-gaps**
