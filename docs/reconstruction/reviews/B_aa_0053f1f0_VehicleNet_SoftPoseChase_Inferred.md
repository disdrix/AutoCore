# Review B (skeptical / adversarial): `aa_0053f1f0` VehicleNet_SoftPoseChase_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053f1f0` |
| **VA** | `0x0053f1f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053f1f0_VehicleNet_SoftPoseChase_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Same as ApplyNetworkPose `0x0053eec0` | **Falsified** | chase/blend; not wire apply |
| 2 | Always hard-snaps body via setPos | **Falsified** | buffer + out params; integrate optional |
| 3 | Empty soft buffer still chases | **Falsified** | ‖pos‖≤ε → return 0 |
| 4 | Direct code callers | **Falsified** | DATA vtable only |
| 5 | Global names prove UI/XP math | **Falsified** | Ghidra labels likely reused; treat as floats |
| 6 | Writes thr/steer | **Falsified** | pose only |

---

## 2. Surviving contract

```
if no soft pos (‖buf.pos‖≤ε): return 0
chase ioPos/ioVel/ioRot toward buf using dt + snapRadius
optional SoftPoseIntegrate gate may zero vels
return dirty
```

**Verdict:** **accept-with-gaps**
