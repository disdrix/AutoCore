# Review B (skeptical / adversarial): `aa_004fe110` Vehicle_EquipWeaponSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fe110` |
| **VA** | `0x004fe110` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004fe110_Vehicle_EquipWeaponSlot.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always attaches even same weapon | **Falsified** | Early return + log |
| 2 | Melee hardpoint `+0x264` | **Falsified** | Uses table `+0x260` + AttachWeapon |
| 3 | Power plant path | **Falsified** | Weapon strings + Attach |
| 4 | Writes outPrev on same-equip | **Falsified** | Return before store |
| 5 | Implements full attach body | **Falsified** | Delegates to `Vehicle_AttachWeapon` |
| 6 | Clears prior without helper | **Partial** | Unbind `+0x158` + `FUN_00518630` before Attach |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Same-equip gate | **High** | Double-bind / stale UI |
| Slot table `+0x260` | **High** | Wrong hardpoint |
| Attach callee | **High** | Missed type checks live in Attach |
| outPrev null-safety | **Tentative** | Crash if caller omits out |

---

## 3. Cross-check spine

```
EquipWeaponSlot(veh, weapon, slot, outPrev):
  cur = *( *(veh+0x260) + slot*4 )
  if weapon == cur && weapon: log same; return
  if cur: helper; unbind cur[+0x158](0)
  *outPrev = cur
  AttachWeapon(veh, weapon, slot, 0)
```

---

## 4. Surviving contract for AutoCore

```
Vehicle.EquipWeaponSlot(weapon, slot, outPrev?):
  idempotent same-ptr reject
  capture previous; AttachWeapon does store/type/bind
```

---

## 5. Open questions

1. `FUN_00518630` product name.
2. Null `outPrev` callers.

**Verdict:** **accept-with-gaps**
