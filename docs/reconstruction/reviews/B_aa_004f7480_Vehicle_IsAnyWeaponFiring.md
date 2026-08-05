# Review B (skeptical / adversarial): `aa_004f7480` Vehicle_IsAnyWeaponFiring

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f7480` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004f7480_Vehicle_IsAnyWeaponFiring.md` |
| **Verdict** | **accept-with-gaps** on table form |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only checks turret | Falsified — 3 hardpoints too |
| 2 | Reads weapon heat | Falsified — firing char only |
| 3 | Writes fire flags | Falsified — pure query |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0xC7 firing flag | High | Cool never slows / always slows |
| Turret + hardpoint layout | High | Missed fire state |
| Table vs inline array | Medium | Wrong memory read |

---

## 3. Cross-check against raw

```
if turret+0xC7: true; for i in 0..2 hardpoints[i]+0xC7: true; else false.
Clean ≡ raw CF; table form residual.
```

---

## 4. Surviving contract for AutoCore

```
IsAnyWeaponFiring(veh) → bool:
  any hardpoint/turret firing; OnTick slows cool when true
  AutoCore combat-pool cool interaction
```

---

## 5. Open questions

1. Disambiguate +0x260 pointer-to-array vs array.
2. Live fire while cooling.

**Verdict:** **accept-with-gaps** on table form
