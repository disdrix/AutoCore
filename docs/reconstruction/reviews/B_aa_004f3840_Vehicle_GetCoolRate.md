# Review B (skeptical / adversarial): `aa_004f3840` Vehicle_GetCoolRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3840` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004f3840_Vehicle_GetCoolRate.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Ignores vehicle adjust | Falsified — always adds adjust |
| 2 | Returns 0 without plant | Falsified — adjust+1 |
| 3 | Applies overheat frac | Falsified — pure sum |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| plant+adjust formula | High | Wrong heat cool speed |
| Default adjust+1 | High | Heat stuck / free cool |
| Field offsets +0xBA/+0x1E4 | High | Wrong layout |

---

## 3. Cross-check against raw

```
cool = plant? plant.nCoolRate + adjust : adjust + 1.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
GetCoolRate(veh) → cool points per pulse:
  pure getter; OnTick / AddHeat consume
  AutoCore heat cool pulse
```

---

## 5. Open questions

1. Pair with IsAnyWeaponFiring cool slow path.
2. Test adjust-only no-plant vehicles.

**Verdict:** **accept**
