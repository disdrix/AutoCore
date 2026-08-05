# Review A (reconstruction fidelity): `aa_005fd390` Vehicle_buildHavokVehicleFramework

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fd390` |
| **VA** | `0x005fd390` |
| **Canonical name** | `Vehicle_buildHavokVehicleFramework` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fd390_Vehicle_buildHavokVehicleFramework.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Sole vehicle-physics setup: builds every hkVehicle* component from entity / VehicleSpecific, wires them into `hkVehicleFramework`, writes gear-ratio weighted speed-governor constant to **entity+0x110**. Sole caller `Vehicle_createVehicleAction` (`0x4fb660`). Construction order (alloc→ctor): Wheels **0x390** → Chassis **0x40** (rb at chassis+0x3c) → Steering **0x38** (TankSteering iff VehSpec+**0x4c0**==4 else Default) → WheelCollide **0x3c** → Transmission **0x60** → Brake **0x54** → Suspension **0x68** → Aerodynamics **0x50** → AngularVelocityDamper **0x14** → Framework **0x360**. **No hkDefaultEngine** — torque from AA `VehicleAction_calcWheelTorque` + `VehicleEngine_torqueCurve2D`. Desc builders: `BuildSteering/Transmission/Suspension/AerodynamicsDescriptor` + FUN_005fcce0/5fc3d0/5fcb00. Speed precompute uses VehSpec **+0x699** gears, **+0x600** GearRatios, **+0x6b4/+0x6c4**, **+0x5e8/+0x5ec** × DAT_009dd348.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fd390_Vehicle_buildHavokVehicleFramework.md` (or `aa_005fd390_FUN_005fd390.md`) |
| Annotated | `docs/reconstruction/raw/aa_005fd390_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_buildHavokVehicleFramework.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fd390_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Sole physics framework builder` | High | Verified physics doc + sole caller createVehicleAction |
| `Component order Wheels→…→Framework` | High | Plate + fn_005fd390 |
| `Tank steer iff +0x4c0==4` | High | Branch in body |
| `No hkDefaultEngine in AA` | High | Plate + torque path elsewhere |
| `entity+0x110 speed governor write` | High | Tail math |
| `Chassis holds rb at +0x3c` | High | Chassis ctor notes |
| `Full inertia/COM overlay seal` | Medium | Phase0 FUN_005fc620 residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Desc builders → alloc → ctors → framework return | Yes |
| No invented engine component | Yes |

---

## 5. Gaps / open

1. Seal Phase0 vehicle-data desc field map.
2. Name FUN_005fcce0 / FUN_005fc3d0 / FUN_005fcb00.
3. Live-diff entity+0x110 vs AbsoluteTopSpeed claims.

**Verdict:** **accept-with-gaps**
