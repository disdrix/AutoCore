# Review B (skeptical / adversarial): `aa_0040ba20` Combat_rlWeaponHeatMultiplier

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ba20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0040ba20_Combat_rlWeaponHeatMultiplier.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Applies heat to vehicle +0x150 | Falsified — table manager |
| 2 | Is CanFireHeatCheck | Falsified — distinct |
| 3 | UI only string dump | Falsified — real map insert CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Multiplier semantics | High | Wrong heat gain |
| Key identity | High | Missed mult |

---

## 3. Cross-check against raw

```
Combat_rlWeaponHeatMultiplier:
  map insert/manage for weapon heat multipliers
≠ ApplyShotHeat. Residual FUN_*.
```

---

## 4. Surviving contract for AutoCore

```
Heat multiplier table for AutoCore weapon heat economy.
```

---

## 5. Open questions

1. Cross-ref Weapon_ApplyShotHeatAndPowerCost consumers.

**Verdict:** **accept-with-gaps**
