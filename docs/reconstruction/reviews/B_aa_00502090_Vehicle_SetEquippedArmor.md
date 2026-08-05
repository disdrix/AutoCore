# Review B (skeptical / adversarial): `aa_00502090` Vehicle_SetEquippedArmor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502090` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00502090_Vehicle_SetEquippedArmor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Power plant equip | Falsified — armor |
| 2 | No HP impact | Falsified — RecalcCombatPools |
| 3 | Type 10 | Falsified — 0x1c |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x254 / 0x1c | High | Wrong armor |
| Recalc HP | High | Wrong max HP |
| MI clonebase chase | Tentative | Bad type read |

---

## 3. Cross-check against raw

```
set +0x254; type 0x1c; bind; RecalcCombatPools.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SetEquippedArmor(veh, armor, outPrev?):
  armor hardpoint; pair EquipFromCreate / InventoryEquip
  AutoCore vehicle armor equip
```

---

## 5. Open questions

1. Seal ArmorFactor source field.
2. Live armor equip capture.

**Verdict:** **accept-with-gaps**
