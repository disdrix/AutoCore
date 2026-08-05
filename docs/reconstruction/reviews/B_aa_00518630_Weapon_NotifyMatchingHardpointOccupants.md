# Review B (skeptical / adversarial): `aa_00518630` Weapon_NotifyMatchingHardpointOccupants

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00518630_Weapon_NotifyMatchingHardpointOccupants.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is Vehicle_AttachWeapon | **Falsified** — no slot write; parent calls Attach **after** this |
| 2 | Always runs | **Falsified** — null host / null `+0x214` early out |
| 3 | Deletes matching objects | **Falsified** — stamp + `FUN_004d0e90`; not destroy path |
| 4 | `param_2=100` is CBID | **Falsified** — loop cap `iStack_30 < param_2` |
| 5 | operator_delete aborts function | **Falsified as product** — Ghidra noreturn on free; SEH restores |
| 6 | English name finished | **Fail** — inferred from equip role |

---

## 2. Surviving contract

```
thiscall(weapon, maxN, requireMin, stamp):
  if !host || !host.vfunc214(): return
  lock hash(weapon+0x70)
  collect resolved occupants matching linked CBID
  unlock
  notify up to maxN: obj+0xcc = stamp; FUN_004d0e90(obj)
  free vector
```

EquipWeaponSlot dual **cannot** drop this call before unbind.

---

## 3. Open

`FUN_004d0e90` product; stamp semantics; runtime.

**Verdict:** Role sealed as pre-replace occupant notify. **accept-with-gaps.**
