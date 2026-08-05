# Review B (skeptical / adversarial): `aa_005f7720` VehicleNet_UnpackGhostVehicle

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f7720` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005f7720_VehicleNet_UnpackGhostVehicle.md` |
| **Verdict** | accept-with-gaps |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always equips wheels on delta | Falsified — PostCorrection deferred |
| 2 | sinVehicleFlags is the wire handbrake byte | Falsified — different flags |
| 3 | Same as GhostCreature_UnpackUpdate | Falsified — vehicle-specific pose/combat |
| 4 | Server PackUpdate is this function | Falsified — client unpack |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hardpoint initial vs delta | High | Null wheels / race |
| Combat mask → offset map | High | Wrong pools on wire |
| Owner block forms | High | SpawnOwner mismatch |
| Full width table | Medium | Subtle desync |

---

## 3. Cross-check against raw

```
UnpackGhostVehicle(ghost, stream, isInitial):
  pose → axes → owner → path? → hardpoints(initial equip | delta PostCorrection)
  → combat Heat/Shield/Power/Health.
Clean CF large; plate contracts high; residual widths.
```

---

## 4. Surviving contract for AutoCore

```
Client unpack contract for GhostVehicle:
  AutoCore pack must match field order/masks; hardpoint delta ≠ equip.
```

---

## 5. Open questions

1. Cross-check GhostVehicleWireTests against every branch.
2. Document path-block when AI driving.

**Verdict:** accept-with-gaps
