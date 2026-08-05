# Review B (skeptical / adversarial): `aa_005fc840` Vehicle_BuildTransmissionDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc840` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005fc840_Vehicle_BuildTransmissionDescriptor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Steering desc | Falsified — transmission |
| 2 | Finished gear map | Overstated |
| 3 | UI only | Falsified — physics |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gear ratio fill | High | Wrong top speed / shift |
| Wheel count consistency | High | Mismatch wheels |
| +0x1fc scalar meaning | Tentative | Scale error |

---

## 3. Cross-check against raw

```
build transmission desc (gears/ratios) for Havok component.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
BuildTransmissionDescriptor(veh, …, out):
  pair buildHavokVehicleFramework step 5 + +0x110 governor
  AutoCore drive feel
```

---

## 5. Open questions

1. Dump gear tables from sample chassis.
2. Name FUN_007a4480 log path if any.

**Verdict:** **accept-with-gaps**
