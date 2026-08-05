# Review B (skeptical / adversarial): `aa_005fd390` Vehicle_buildHavokVehicleFramework

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fd390` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005fd390_Vehicle_buildHavokVehicleFramework.md` |
| **Verdict** | **accept-with-gaps** on CF; COM/inertia overlay open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Retail uses stock Havok engine | Falsified — no engine component |
| 2 | Cosmetic only | Falsified — full hkVehicle assembly |
| 3 | Finished COM/inertia seal | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Component construction order | High | Wrong physics sim setup |
| Tank vs default steering branch | High | Tank vehicles unsteerable |
| +0x110 speed constant | High | Wrong top-speed governor |
| Phase0 desc overlay | Tentative | Bad inertia/COM |

---

## 3. Cross-check against raw

```
build descriptors → heap components → hkVehicleFramework*; write +0x110.
Clean ≡ raw CF; ctor sizes/order from plate.
```

---

## 4. Surviving contract for AutoCore

```
buildHavokVehicleFramework(entity, driverInput, …) → framework*:
  sole physics setup; pair createVehicleAction + Build*Descriptor helpers
  AutoCore vehicle physics spawn critical — no stock hkEngine
```

---

## 5. Open questions

1. Publish sealed component table in physics INDEX.
2. Confirm driver-input arg packing into framework.

**Verdict:** **accept-with-gaps** on CF; COM/inertia overlay open
