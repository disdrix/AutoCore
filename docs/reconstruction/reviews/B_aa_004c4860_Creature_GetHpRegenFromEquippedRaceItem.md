# Review B (skeptical / adversarial): `aa_004c4860` Creature_GetHpRegenFromEquippedRaceItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4860` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004c4860_Creature_GetHpRegenFromEquippedRaceItem.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always walks race-item | Falsified — delegates |
| 2 | Returns 0 without vehicle | Falsified — returns 1 |
| 3 | Shield regen too | Falsified — HP only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x250 vehicle link | High | No regen / wrong vehicle |
| Default 1 | High | Zero HP regen on foot |
| Delegate identity | High | Duplicate formula drift |

---

## 3. Cross-check against raw

```
if creature+0x250: return Vehicle_GetHpRegenRate(*); else 1.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Creature_GetHpRegenFromEquippedRaceItem(cre):
  vehicle glue → GetHpRegenRate or 1
  AutoCore combat-pool owner HP path
```

---

## 5. Open questions

1. Unit-test foot vs mounted.
2. Pair with GetShieldRegenRate creature twin if any.

**Verdict:** **accept**
