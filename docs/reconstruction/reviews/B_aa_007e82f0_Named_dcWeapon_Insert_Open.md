# Review B (skeptical / adversarial): `aa_007e82f0` Named_dcWeapon_Insert_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e82f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007e82f0_Named_dcWeapon_Insert_Open.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Weapon_CanFireHeatCheck | Falsified — DB open |
| 2 | ApplyShotHeatAndPowerCost | Falsified — load time |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Weapon column map | High | Wrong heat/power fields |
| Damage child insert | High | Missing damage types |

---

## 3. Cross-check against raw

```
dcWeapon_Insert_Open: DB open weapon + dcDamage children.
```

---

## 4. Surviving contract for AutoCore

```
Weapon template import. Align heat/power columns with fire path.
```

---

## 5. Open questions

1. Cross-check weapon+0xD4/+0xD6 against loaded columns.

**Verdict:** **accept-with-gaps**
