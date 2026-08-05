# Review B (skeptical / adversarial): `aa_004f70f0` Vehicle_HasEquippedTFID_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f70f0` |
| **VA** | `0x004f70f0` |
| **Canonical name** | `Vehicle_HasEquippedTFID_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004f70f0_Vehicle_HasEquippedTFID_Inferred.md` |
| **System** | vehicle equip |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Unequips / removes item | Pure predicate; no stores | **Falsified** mutator |
| 2 | Only checks weapon mounts | Also `+0x270..+0x254` family | **Falsified** mounts-only |
| 3 | Matches by object pointer equality | Compares TFID dwords only | **Falsified** pointer-eq |
| 4 | `600` is magic unrelated | `600 == 0x258` equip slot | **Agree** hex alias |
| 5 | Returns mount pointer | Returns 0/1 only (`004f5680` return used as bool) | **Falsified** ptr-return |
| 6 | Inventory grid occupancy | Equip slots on vehicle object, not bag cells | **Falsified** grid |

---

## 2. Live ≡ raw

```
Live ≡ raw: 004f5680 OR six slot TFID checks → 1 else 0
```

---

## 3. Surviving contract

```
// bool thiscall Vehicle_HasEquippedTFID(Vehicle*, tfid_a, tfid_b)
// True if any mount/equip slot holds that TFID.
```

**Verdict:** **accept-with-gaps.**
