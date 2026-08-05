# Review B (skeptical / adversarial): `aa_005fc4f0` Vehicle_BuildAerodynamicsDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc4f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005fc4f0_Vehicle_BuildAerodynamicsDescriptor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Complex CF | Falsified — linear copy |
| 2 | Runtime wind sim here | Falsified — desc fill only |
| 3 | Finished coefficient names | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clonebase aero offsets | High | Wrong drag/handling |
| Desc field order | High | Swapped coeffs |
| Coefficient names | Tentative | Doc only |

---

## 3. Cross-check against raw

```
out[0..5] = clonebase aero floats; return.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
BuildAerodynamicsDescriptor(veh, …, out):
  pair buildHavokVehicleFramework step 8
  AutoCore aero feel
```

---

## 5. Open questions

1. Map offsets to Havok aero member names.
2. Sample chassis dump.

**Verdict:** **accept-with-gaps**
