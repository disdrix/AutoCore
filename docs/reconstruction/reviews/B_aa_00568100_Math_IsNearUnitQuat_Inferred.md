# Review B (skeptical / adversarial): `aa_00568100` Math_IsNearUnitQuat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00568100` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00568100_Math_IsNearUnitQuat_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Renormalizes quat | Only writes 0/1 out byte | **Falsified normalize** |
| 2 | Compares component-wise to identity | Uses **length** vs 1 | **Falsified identity-eq** |
| 3 | Threshold is 1e-6 | `_DAT_009d2f1c` ≈ **0.001** | **Falsified** |
| 4 | Hard path uses same gate | Hard path skips this | **Falsified** |

---

## 2. Surviving contract

```
ok = finiteish(q) && |||q|| - 1| < 0.001
// soft apply: write rot only if ok
```

**Verdict:** **accept**
