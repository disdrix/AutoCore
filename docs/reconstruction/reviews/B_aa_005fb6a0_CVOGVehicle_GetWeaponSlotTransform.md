# Review B (skeptical / adversarial): `CVOGVehicle_GetWeaponSlotTransform` @ `0x005fb6a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fb6a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005fb6a0_CVOGVehicle_GetWeaponSlotTransform.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Stride 0x80 like some mesh tables | Falsified — 0xc0 |
| 2 | Applies impulse | Falsified — transform out only |
| 3 | No even/odd special case | Falsified — when +0xc>2 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| slot*0xc0 + table+0x80 | High | Wrong hardpoint |
| Even-slot branch | Medium | Mirrored weapon wrong |
| Compose math | Tentative | Muzzle offset |

---

## 3. Cross-check against raw

```
slot = i*0xC0 + *(+0x80); maybe even-slot flag;
load +0x40.. basis; write outs.
```

---

## 4. Surviving contract for AutoCore

```
GetWeaponSlotTransform(veh, ..., slotIndex, outA, outB):
  entry = weaponTable[+0x80] + slotIndex*0xC0
  compose local slot xform to world/parent
  pairs TacArc / fire VFX; not hit detection alone
```

---

## 5. Open questions

1. Document weapon slot struct (0xc0).
2. Seal parent transform multiply.

**Verdict:** **accept-with-gaps**
