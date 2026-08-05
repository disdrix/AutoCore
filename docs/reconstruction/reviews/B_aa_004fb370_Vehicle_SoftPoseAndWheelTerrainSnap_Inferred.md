# Review B (skeptical / adversarial): `aa_004fb370` Vehicle_SoftPoseAndWheelTerrainSnap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb370` |
| **VA** | `0x004fb370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004fb370_Vehicle_SoftPoseAndWheelTerrainSnap_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Is SoftPoseSyncFromBody itself | **Falsified** | **calls** `0x0053e600`; adds wheel terrain snap after |
| 2 | Always snaps Y | **Falsified** | needs gate flags + wheels ready + a wheel within −0.1 of terrain |
| 3 | Threshold is 30.0 (soft far) | **Falsified** | snap uses `DAT_00aaa6d4` = **−0.1**; 30.0 is inside callee |
| 4 | Uses network BitStream | **Falsified** | no stream; height sample + SetPosition |
| 5 | Iterates all wheels applying force | **Falsified** | first contact breaks; may return without snap if none |
| 6 | Wheel stride is 0x40 / sizeof(float3) | **Falsified** | `local_28 += 0xC0` |

---

## 2. Surviving contract

```
if soft_or_flag_gate:
  SoftPoseSyncFromBody(...)
  if wheels_ready:
    for each wheel (stride 0xC0):
      if wheel.y - terrainY(x,z) < -0.1:
        SetPosition(x, terrainY+1, z); return
```

**Verdict:** **accept-with-gaps**
