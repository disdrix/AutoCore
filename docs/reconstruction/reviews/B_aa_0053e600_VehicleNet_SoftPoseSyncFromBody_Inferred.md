# Review B (skeptical / adversarial): `aa_0053e600` VehicleNet_SoftPoseSyncFromBody_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053e600` |
| **VA** | `0x0053e600` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053e600_VehicleNet_SoftPoseSyncFromBody_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Applies network pose | **Falsified** | body→soft / soft→body only; no BitStream |
| 2 | Threshold is 15 (ApplyNetworkPose teleport) | **Falsified** | `DAT_00a0f694` = **30.0** |
| 3 | Always seeds every call | **Falsified** | first call seeds; later compare |
| 4 | Far path uses ApplyNetworkPose | **Falsified** | SetPosition + ApplyImpulseVector on soft contents |
| 5 | Works with null phys | **Falsified** | clears flag and returns |
| 6 | Same as SoftPoseIntegrate | **Falsified** | no dt Euler/quat step |

---

## 2. Surviving contract

```
if !phys || !readyGate: seeded=0; return
if !seeded: copy body pos/vel/ω → soft; seeded=1
elif ‖body.pos-soft.pos‖ > 30: body ← soft pos + soft lin impulse
else: soft.pos/lin ← body
```

**Verdict:** **accept-with-gaps**
