# Review B (skeptical / adversarial): `aa_004fdf20` Vehicle_AttachWeapon

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fdf20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004fdf20_Vehicle_AttachWeapon.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Unlimited slots | Falsified — slot<3 |
| 2 | Ignores type | Falsified — type 0xc check |
| 3 | Finished all side effects | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x260 slot table | High | Wrong weapon attach |
| Type 0xc gate | High | Bad equip |
| Track zero +0x630 | Tentative | Stale track |

---

## 3. Cross-check against raw

```
if slot<3: detach old; store weapon@+0x260[slot]; parent/scale; type check.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
AttachWeapon(veh, weapon, slot, keep?):
  hardpoint attach; pair EquipFromCreate / CreateWeaponTrackAction
  AutoCore vehicle combat loadout
```

---

## 5. Open questions

1. Document 3 hardpoint layout vs turret.
2. Name detach helpers.

**Verdict:** **accept-with-gaps**
