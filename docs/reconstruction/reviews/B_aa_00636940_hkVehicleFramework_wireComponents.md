# Review B (skeptical / adversarial): `aa_00636940` hkVehicleFramework_wireComponents

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00636940_hkVehicleFramework_wireComponents.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Allocates components | Falsified — wires existing ptrs |
| 2 | Installs stock engine | Falsified — no engine slot |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Slot map | High | Wrong child tick |
| Backptr +8 | High | Component update NPE |

---

## 3. Cross-check against raw

```
wireComponents(fw, desc):
  fw slots ← desc[]; child+8 = fw.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
Framework wiring after Vehicle_buildHavokVehicleFramework.
  AutoCore init must match slot layout for tickSubsystems.
```

---

## 5. Open questions

1. Diff against buildHavokVehicleFramework emit order.

**Verdict:** accept-with-gaps
