# Review B (skeptical / adversarial): `aa_004e8b60` Math_QuatExtractUp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8b60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e8b60_Math_QuatExtractUp_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Extracts forward | Formula is column 1 (up), not col 2 | **Falsified forward** |
| 2 | Extracts right | Right is `004e8ad0` | **Falsified** |
| 3 | Scalar is UI level-up value | Shared float plate misnamed; algebra requires **2** | **Name residual only** |
| 4 | Writes 3 floats only | Writes **4** with w=0 | **4 floats** |
| 5 | Vehicle-only | Many non-vehicle xrefs | **Shared math** |

---

## 2. Surviving contract

```
QuatExtractUp(q, out4):
  out = (2(xy-zw), 1-2(x²+z²), 2(zy+xw), 0)
// body up in world; used for upright / tilt tests
```

**Verdict:** **accept**
