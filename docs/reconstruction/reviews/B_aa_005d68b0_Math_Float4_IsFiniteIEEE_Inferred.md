# Review B (skeptical / adversarial): `aa_005d68b0` Math_Float4_IsFiniteIEEE_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d68b0` |
| **VA** | `0x005d68b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005d68b0_Math_Float4_IsFiniteIEEE_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Checks ‖q‖≈1 | **Falsified** | only Inf/NaN exp bits; unit test is parent |
| 2 | Rejects denormals | **Falsified** | only exp==0xff class |
| 3 | Returns bool in EAX only | **Falsified** | writes `*out` byte |
| 4 | Soft apply drops pos if fail | **Falsified** | parent only gates **rot** write |
| 5 | Threshold 0.001 here | **Falsified** | no float compare in unit |

---

## 2. Surviving contract

```
for i in 0..3:
  if (q[i] bits & 0x7f800000) == 0x7f800000: *ok=0; return
*ok=1
```

**Verdict:** **accept**
