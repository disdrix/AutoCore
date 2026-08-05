# Review B (skeptical / adversarial): `aa_00933650` Inv_ValidateEquippedClonebaseSlots

| Field | Value |
|---|---|
| **Stable ID** | `aa_00933650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00933650_Inv_ValidateEquippedClonebaseSlots.md` |
| **Verdict** | **accept-with-gaps** on CF; offset table open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Performs equip/unequip | Falsified — validate/log only |
| 2 | Single slot only | Falsified — multi-slot walk |
| 3 | Finished offset map | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type-code gates | High | False invalid equip |
| Empty 0 / -1 skip | High | Spam on empty |
| Full slot offset table | Tentative | Miss trailer/ornament |
| unaff_ESI ABI | Tentative | Wrong this |

---

## 3. Cross-check against raw

```
for each equip slot: if cbid live lookup clonebase; type+0x38 match or log.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
ValidateEquippedClonebaseSlots(equipBlob):
  integrity assert on equipped cbids vs clonebase type
  AutoCore: port as load-time assert / telemetry only
  pair equip response + clonebase catalog
```

---

## 5. Open questions

1. Publish complete slot offset → type table.
2. Confirm call sites (char load / debug).

**Verdict:** **accept-with-gaps** on CF; offset table open
