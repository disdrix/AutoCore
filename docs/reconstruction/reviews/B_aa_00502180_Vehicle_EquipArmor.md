# Review B (skeptical / adversarial): `aa_00502180` Vehicle_EquipArmor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502180` |
| **VA** | `0x00502180` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00502180_Vehicle_EquipArmor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | This is `Vehicle_SetEquippedArmor` | **Falsified** | Thin wrapper; callee at `0x00502090` |
| 2 | Type-check armor 0x1c here | **Falsified** | No type check in body |
| 3 | Always mutates hardpoint | **Falsified** | Same-ptr early out |
| 4 | outPrev optional | **Falsified** (on set path) | Unconditional `*outPrev` store |
| 5 | Ornament/plant slot | **Falsified** | `+0x254` armor |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Same-equip + forward | **High** (image) | Double equip |
| Slot identity via callee | **High** | Wrong pools if mis-wired |
| outPrev null-safety | **High** that write is unguarded | Port must pass scratch |

---

## 3. Cross-check spine

```
EquipArmor(veh, armor, outPrev, skipUnbind):
  cur = veh[+0x254]
  if armor == cur && armor: log; return
  *outPrev = cur
  SetEquippedArmor(veh, armor, skipUnbind)
```

---

## 4. Surviving contract for AutoCore

```
Vehicle.EquipArmor(armor, outPrev, skipUnbind=false)
  same-ptr reject; capture previous; SetEquippedArmor does bind/recalc
  RecvInventoryEquip class 0x1c
```

---

## 5. Open questions

1. Whether any path intentionally passes null outPrev.
2. SkipUnbind true cases from unequip-notify.

**Verdict:** **accept-with-gaps**
