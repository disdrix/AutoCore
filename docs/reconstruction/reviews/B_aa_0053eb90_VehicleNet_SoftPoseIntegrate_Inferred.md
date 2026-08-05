# Review B (skeptical / adversarial): `aa_0053eb90` VehicleNet_SoftPoseIntegrate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053eb90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053eb90_VehicleNet_SoftPoseIntegrate_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Hard-snaps physics body | Buffer-only writes at +0x10/+0x00 | **Falsified body write** |
| 2 | Always runs | Age gate can return 0 | **Falsified always** |
| 3 | dt is second float always | Sibling call uses first float as dt | **Arg-order residual** |
| 4 | Full SLERP blend | Explicit Euler half-ω product + normalize | **Falsified SLERP** |
| 5 | 0x18ff is seconds | Compared to client tick **ms** delta | **ms** |

---

## 2. Surviving contract

```
if flag==0 and age_ms > 6399: return 0
ensure softBuf @ entity+0x28
q = normalize(q + 0.5*ω ⊗ q * dt)
pos += vel * dt
return 1
// no setPosition/setRotation on body here
```

**Verdict:** **accept-with-gaps**
