# Review B (skeptical / adversarial): `aa_004fe800` Vehicle_SetEquippedMeleeWeapon

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe800` |
| **VA** | `0x004fe800` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004fe800_Vehicle_SetEquippedMeleeWeapon.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Ranged slot table `+0x260` | **Falsified** | Single pointer `+0x264` |
| 2 | Ornament path | **Falsified** | Melee unhappy string + type 0xc/sub9 |
| 3 | Type fail aborts store | **Falsified** | Store then log then still bind |
| 4 | No side graphics work | **Falsified** | FX rebuild loop |
| 5 | Same as AttachWeapon | **Falsified** | Different hardpoint + FX path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Slot `+0x264` + type gate | **High** | Melee/ranged mixup |
| Bind/notify pattern | **High** | Detached mesh |
| FX rebuild necessity | **Medium** | Missing melee VFX |
| Helper FUN_* English | **Open** | Port naming only |

---

## 3. Cross-check spine

```
SetEquippedMelee(veh, item, outPrev?, skipUnbind):
  maybe *outPrev = veh[+0x264]
  unbind old; veh[+0x264] = item
  if item: typecheck log; bind; notify; rebuild FX list
```

---

## 4. Surviving contract for AutoCore

```
Vehicle.SetEquippedMeleeWeapon(item, outPrev?, skipUnbind=false)
  hardpoint +0x264; type 0xc / melee subtype 9
  equip class map sibling of EquipWeaponSlot
```

---

## 5. Open questions

1. FX object layout `0x14c` / `FUN_00764030`.
2. Interaction with primary weapon slots when both equipped.

**Verdict:** **accept-with-gaps**
