# Review B (skeptical / adversarial): `aa_005002d0` Vehicle_CalcMaxHitPoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_005002d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005002d0_Vehicle_CalcMaxHitPoints.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Flat 1000 HP always | Falsified — multi-term formula |
| 2 | Ignores armor equip | Falsified — +0x254 path |
| 3 | Finished NPC path bit-exact | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Player formula terms | High | Wrong max HP |
| Armor factor | High | Equip armor noop |
| +0x1d8 add | Tentative | Off-by chassis |

---

## 3. Cross-check against raw

```
if owner: race/class/level/tech/armor formula ceil; else NPC fallback.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
CalcMaxHitPoints(veh) → maxHp:
  pool max for RecalcCombatPools; AutoCore VehicleHitPointCalculator
  pair SetEquippedArmor
```

---

## 5. Open questions

1. Export tables to C# calculator tests.
2. Live-diff vs client displayed max.

**Verdict:** **accept-with-gaps**
