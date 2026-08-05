# Review B (skeptical / adversarial): `aa_004fea90` Vehicle_SetWheelset

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fea90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004fea90_Vehicle_SetWheelset.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Armor equip | Falsified — wheelset |
| 2 | Drive axis push | Falsified — equip |
| 3 | Finished scale formula | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x258 / type 0x10 | High | Missing wheels |
| Per-wheel scale | High | Wrong wheel size / physics |
| wheelCount +0xb0 | High | Loop OOB |

---

## 3. Cross-check against raw

```
store +0x258; type 0x10; bind; for wheels scale from chassis+0x600.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SetWheelset(veh, wheelset):
  wheel hardpoint; pair EquipFromCreate / InventoryEquip 0x203C
  AutoCore create-vehicle wheels critical
```

---

## 5. Open questions

1. Name FUN_005a6e00.
2. Live create packet wheel CBID path.

**Verdict:** **accept-with-gaps**
