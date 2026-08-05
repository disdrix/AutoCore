# Review B (skeptical / adversarial): `aa_0053eec0` VehicleNet_ApplyNetworkPose_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053eec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053eec0_VehicleNet_ApplyNetworkPose_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Always hard-snaps body | Soft path only snaps if error>15; hard writes visual only | **Falsified always-snap** |
| 2 | Fully-ready Havok gets soft vel | Fully ready → hard visual path, no soft buffer | **Falsified** |
| 3 | Rot always soft-written | Unit-quat gate can drop rot | **Falsified always-rot** |
| 4 | Teleport threshold 10 | `DAT_009d000c` = **15.0** | **Falsified** |
| 5 | Vel floor is zero | Floor **0.01** → zero plate | **Falsified** |
| 6 | Drive axes written here | Thr/steer/HB written by caller before call | **Falsified this unit** |

---

## 2. Surviving contract

```
if phys ok mass and notFullyReady:
  fill softBuf; optional teleport>15; optional integrateDt
else if ||pos||>eps:
  visualPos/Rot only
// thr/steer/handbrake NOT this function
```

**Verdict:** **accept-with-gaps**
