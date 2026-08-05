# Review B (skeptical / adversarial): `aa_005fcff0` Vehicle_BuildSuspensionDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fcff0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005fcff0_Vehicle_BuildSuspensionDescriptor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Cosmetic only | Falsified — physics desc |
| 2 | Also builds transmission | Falsified — suspension only |
| 3 | Finished float table | Overstated |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Desc fill CF | High | Wrong suspension feel |
| Wheel count source | High | Array overrun |
| Per-wheel params | Tentative | Bouncy/stiff mismatch |

---

## 3. Cross-check against raw

```
build suspension desc from clonebase/chassis wheel data.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
BuildSuspensionDescriptor(veh, …, outDesc):
  pair buildHavokVehicleFramework step 7
  AutoCore physics parity needs retail suspension constants
```

---

## 5. Open questions

1. Name FUN_004f5560 / FUN_005b3300.
2. Capture sample desc dump live.

**Verdict:** **accept-with-gaps**
